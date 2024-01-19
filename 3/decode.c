#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1000

typedef int (*DecodeFunction)(char*, char*, int, void*);
typedef void* (*CreateCodecFunction)(char[62]);
typedef void (*FreeCodecFunction)(void*);

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        return 0;
    }

    // Load the codec library dynamically
    void* library_handle = dlopen("./libCodec.so", RTLD_LAZY);
    if (!library_handle) {
        fprintf(stderr, "Error loading library: %s\n", dlerror());
        return 0;
    }

    // Load functions from the library
    CreateCodecFunction createCodec = (CreateCodecFunction)dlsym(library_handle, "createCodec");
    DecodeFunction decode = (DecodeFunction)dlsym(library_handle, "decode");
    FreeCodecFunction freeCodec = (FreeCodecFunction)dlsym(library_handle, "freeCodec");

    if (!createCodec || !decode || !freeCodec) {
        fprintf(stderr, "Error loading functions: %s\n", dlerror());
        dlclose(library_handle);
        return 0;
    }

    // Create the codec
    void* codec = createCodec("defghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890abc");
    if (!codec) {
        fprintf(stderr, "Error creating codec\n");
        dlclose(library_handle);
        return 0;
    }

    // Read input file
    FILE* input_file = fopen(argv[1], "r");
    if (!input_file) {
        fprintf(stderr, "Error opening input file\n");
        freeCodec(codec);
        dlclose(library_handle);
        return 0;
    }

    // Read content and decode
    char input_buffer[MAX_BUFFER_SIZE];
    char output_buffer[MAX_BUFFER_SIZE];
    size_t len;

    while ((len = fread(input_buffer, 1, sizeof(input_buffer), input_file)) > 0) {
        decode(input_buffer, output_buffer, len, codec);

        // Write decoded content to output file
        FILE* output_file = fopen(argv[2], "a");
        if (!output_file) {
            fprintf(stderr, "Error opening output file\n");
            freeCodec(codec);
            fclose(input_file);
            dlclose(library_handle);
            return 0;
        }

        fwrite(output_buffer, 1, len, output_file);
        fclose(output_file);
    }

    // Clean up
    freeCodec(codec);
    fclose(input_file);
    dlclose(library_handle);

    return 0;
}

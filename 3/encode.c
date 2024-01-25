#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <string.h>
#include "codec.h"

#define MAX_BUFFER_SIZE 1000

// for loading functions from library
typedef int (*EncodeFunction)(char*, char*, int, void*);
typedef void* (*CreateCodecFunction)(char[62]);
typedef void (*FreeCodecFunction)(void*);

int main(int argc, char* argv[]) {
    // make sure program gets 3 argc's (name, txtin, txtout)
    if (argc != 3) {
        printf( "Usage: %s input_file output_file\n", argv[0]);
        return 0;
    }

    // Load the codec library dynamically with lazyloading
    void* library_handle = dlopen("./libCodec.so", RTLD_LAZY);
    if (!library_handle) {
        printf( "Error loading library: %s\n", dlerror());
        return 0;
    }

    // Load functions from the library
    CreateCodecFunction createCodec = (CreateCodecFunction)dlsym(library_handle, "createCodec");
    EncodeFunction encode = (EncodeFunction)dlsym(library_handle, "encode");
    FreeCodecFunction freeCodec = (FreeCodecFunction)dlsym(library_handle, "freeCodec");

    // if cant load any one of the functions print error close library and return 0
    if ( !encode || !freeCodec || !createCodec) {
        printf( "Error loading functions: %s\n", dlerror());
        dlclose(library_handle);
        return 0;
    }

    // Create the codec 
    //TODO MAY NEED TO CHANGE
    char key[62];
    printf("please enter a legal key[62] key for the codec:\n");
    scanf("%s", key);
    void* codec = createCodec(key);
    // if failed print error close library and return 0
    if (codec == NULL) {
        printf( "Error creating codec\n");
        dlclose(library_handle);
        return 0;
    }

    // Read input file
    FILE* input_file = fopen(argv[1], "r");
    if (!input_file) {
        printf( "Error opening input file\n");
        freeCodec(codec);
        dlclose(library_handle);
        return 0;
    }

    // Read content and encode
    char input_buffer[MAX_BUFFER_SIZE];
    char output_buffer[MAX_BUFFER_SIZE];
    size_t len;
    
    while ((len = fread(input_buffer, 1, sizeof(input_buffer), input_file)) > 0) {
        encode(input_buffer, output_buffer, len, codec);

        // Write encoded content to output file
        FILE* output_file = fopen(argv[2], "w");
        if (!output_file) {
            printf( "Error opening output file\n");
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

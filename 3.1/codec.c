#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "codec.h"
#include <ctype.h>

void *createCodec(char key[62])
{
    // Check for invalid key length
    if(strlen(key)!= 62){
        printf("key not eql to 62 for codec\n");
        return NULL;
    }
    //allocate memory for Codec
    Codec *globalCodec = (Codec *)malloc(sizeof(Codec));
    // Check if memory was allocated
    if (globalCodec == NULL)
    {   
        printf("global Codec not created in malloc function\n");
        return NULL;
    }
    // Check if all the charaters exist and that there are only one existence for each character
    //just one long array of 127 all values from a - 0

    int allCharacter[127] = {0}; // array of all 0's
    
    for (int i = 0; i < 62; i++)
    {
        int currentPos = key[i];

        if (allCharacter[currentPos] == 1) // OPS already exists!
        {   
            printf("global codec charaters exist and that there are only one existence for each character ERROR\n");
            free(globalCodec);
            return NULL;
        }
        allCharacter[currentPos] = 1;
    }
    strcpy(globalCodec->key, key);
    return globalCodec;
}

int encode(char *textin, char *textout, int len, void *codec)
{
    if (textin == NULL || textout == NULL || codec == NULL)
    {
        return -1;
    }

    Codec *myCodec = (Codec *)codec;
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        char current = textin[i];
        int index = -1;
        for (int j = 0; j < 62; j++)
        {
            if (ABC[j] == current)
            {
                index = j;
                break;
            }
        }
        if (index != -1)
        {
            count = count + 1;
            textout[i] = myCodec->key[index];
        }
    }

    return count;
}

int decode(char *textin, char *textout, int len, void *codec)
{
    if (textin == NULL || textout == NULL || codec == NULL)
    {
        return -1;
    }

    Codec *myCodec = (Codec *)codec;
    int count = 0;

    for (int i = 0; i < len; i++)
    {
        char current = textin[i];
        int index = -1;

        for (int j = 0; j < 62; j++)
        {
            if (myCodec->key[j] == current)
            {
                index = j;
                break;
            }
        }

        if (index != -1)
        {
            textout[i] = ABC[index];
            count = count + 1;
        }
    }

    return count;
}

void freeCodec(void *codec)
{
    if (codec == NULL)
    {
        fprintf(stderr, "Error: freeCodec called without codec initialization.\n");
        return;
    }

    free(codec);
}

// int main(int argc, char *argv[])
// {
//     int MAX_BUFFER_SIZE = 1000;

//     void *codec = createCodec("defghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890abc");

//     if (!codec)
//         return 0;

//     // // Read input file
//     // FILE *input_file = fopen(argv[1], "r");
//     // if (!input_file)
//     // {
//     //     fprintf(stderr, "Error opening input file\n");
//     //     dlclose(codec);
//     //     return 1;
//     // }

//     // Read content and encode
//     int len = 6;
//     char *input = malloc(len);
//     char *input1 = "abcdef";
//     for (int i = 0; i < len; i++)
//     {
//         input[i] = input1[i];
//     }
//     char *output = malloc(len);
//     int data = encode(input, output, len, codec);

//     data = decode(output, input, len, codec);
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "codec.h"

// Global variable for the codec

typedef struct{
    char key[62];
} Codec;

static Codec *globalCodec = NULL;

int findPosition(char letter)
{
    char firstChar;

    if ('a' <= letter && letter <= 'z')
    {
        firstChar = 'a';
    }
    else if ('A' <= letter && letter <= 'Z')
    {
        firstChar = 'A' - 'a';
    }
    else if ('0' <= letter && letter <= '9')
    {
        firstChar = '0' - 'a' - 'A';
    }
    else
    {
        // Handle invalid input
        return -1;
    }

    return letter - firstChar;
}

void *createCodec(char key[62])
{

    if (globalCodec != NULL)
    {
        fprintf(stderr, "Error: createCodec called multiple times.\n");
        return NULL;
    }
    Codec *globalCodec = (Codec *)malloc(sizeof(Codec));

    // Check if all the charaters exist and that there are only one existence for each character
    int allCharacter[62];

    // Check if memory was allocated

    if (globalCodec == NULL)
    {
        return NULL;
    }

    int keyLength = strlen(key);
    // Check for invalid key length
    if (keyLength != 62)
    {
        free(globalCodec);
        globalCodec = NULL;
        return NULL;
    }
    for (int i = 0; i < keyLength; i++)
    {
        int currentPos = findPosition(key[i]);

        if (allCharacter[currentPos] == 1)
        {
            free(globalCodec);
            globalCodec = NULL;
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
    if (globalCodec == NULL)
    {
        fprintf(stderr, "Error: freeCodec called without codec initialization.\n");
        return;
    }

    free(globalCodec);
    globalCodec = NULL;
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

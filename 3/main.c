#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ABC "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"

typedef struct {
    char key[62];
} Codec;

void* createCodec(char key[62]){
    Codec *codec = (Codec*)malloc(sizeof(Codec));
    //check memory was allocated
    if(codec == NULL){
        return NULL;
    }

    int keyLength = strlen(key);
    //if invalid free memory and exit gracfully
    if(keyLength != 62){
        free(codec);
        return NULL;
    }

    strcpy(codec->key, key);
    return codec;
}

int encode(char* textin, char* textout, int len, void* codec){
    if(textin ==NULL || textout==NULL || codec ==NULL){
        return -1;
    }

    Codec *myCodec = (Codec *)codec;

    // textin [h,e,l,l,o ]
    // key [d,e,f,g,h,i......abc]
    // our abc [a,b,c,d,e,f,g......]

    for(int i = 0; i< len; i++){
        char current = textin[i];
        //find corosponding character in the key
        int index = -1;
        for(int j = 0; j<62 ;j++){
            if(ABC[j] == current){
                index =j;
                break;
            }
        }
    
        //if found encode it
        if(index!=-1){
            textout[i] = myCodec->key[index];
        }else{
            return -1;
        }
    }

    return len;
}

int decode(char* textin, char* textout, int len, void* codec){
    if(textin ==NULL || textout==NULL || codec ==NULL){
        return -1;
    }

    Codec *myCodec = (Codec *)codec;

    for(int i = 0; i< len; i++){
        char current = textin[i];
        //find corosponding character in the key
        int index = -1;
        for(int j = 0; j<62 ;j++){
            if(myCodec->key[j] == current){
                index =j;
                break;
            }
        }
    
        //if found encode it
        if(index!=-1){
            textout[i] = ABC[index];
        }else{
            return -1;
        }
    }

    return len;
}

void freeCodec(void* codec){
    free(codec);
}

int main(){

    Codec cod = createCodec("defghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890abc");

    return 0;
}
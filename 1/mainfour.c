#include <stdio.h>

int main(){
    
    int arr[] = {1,2,3};
    for(int i =0; i<6;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("enter a number greater than 3\n");
    int num;
    scanf("%d", &num);
    arr[num] = 6;
    printf("%d",arr[num]);
    return 0;
}
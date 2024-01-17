#include <stdio.h>
#include <math.h>
int main(){
    printf("enter 3 integers for triangle sides\n");
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if(pow(a,2) + pow(b,2) == pow(c,2)){
        double aa, ba, ca;
        //furmula found on calculator.net/triangle
        aa = acos((pow(b,2) + pow(c,2) - pow(a,2))/(2*b*c));
        ba = acos((pow(a,2) + pow(c,2) - pow(b,2))/(2*a*c));
        ca = acos((pow(a,2) + pow(b,2) - pow(c,2))/(2*a*b));
        printf("%f %f %f",aa, ba, ca );
    }else{
        printf("\nError\n");
        return 0;
    }
    return 0;
}
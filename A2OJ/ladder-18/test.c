#include<string.h>
#include<stdio.h>
#include<malloc.h>
char * characterAt(char* input1, int input2){
    input2--;
    for(int i = 0;i<strlen(input1) && input2>=0;i+=2){
        input2-=input1[i+1]-'0';
        if(input2<=0){
            return &(input1[i]);;
        }
    }
    char *x = (char*)malloc(2*sizeof(char));
    x[0] ='-';
    x[1] = '1';
    return x;
}
int main(){
    char c[] = "a1b1c3";
    printf("%s",characterAt(c,7));
    return 0;
}
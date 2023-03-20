#include <stdio.h>

char* chomp(char* str){
    int i = 0;
    while(1){
        if(str[i] == '\n'){
            str[i] = '\0';
        }
        if(str[i] == '\0'){
            break;
        }
        i++;
    }
    return str;
}
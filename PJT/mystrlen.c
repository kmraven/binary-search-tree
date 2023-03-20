#include "interCheck.h"

int mystrlen(const char* str){
    int len = 0;
    if(str == NULL) {
        return len;
    }
    while(str[len] != '\0'){
        len++;
    }
    return len;
}
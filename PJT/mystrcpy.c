#include "interCheck.h"

char* mystrcpy(char* s1, const char* s2){
    int i = 0;
    while(1){
        s1[i] = s2[i];
        if(s2[i] == '\0'){
            break;
        }
        i++;
    }
    return s1;
}
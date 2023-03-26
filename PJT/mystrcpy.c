#include "interCheck.h"

char* mystrcpy(char* s1, const char* s2){
    int i = 0;
    int s2_len = mystrlen(s2);
    while(i < s2_len){
        s1[i] = s2[i];
        // if(s2[i] == '\0'){
        //     break;
        // }
        i++;
    }
    s1[i] = '\0';
    return s1;
}
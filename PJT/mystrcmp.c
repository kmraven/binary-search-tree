#include "interCheck.h"

int mystrcmp(const char* s1, const char* s2){
    int i = 0, s1_len = mystrlen(s1), s2_len = mystrlen(s2);
    while(i < s1_len || i < s2_len){
        if(s1[i] > s2[i] || (s1[i] != '\0' && s2[i] == '\0')){
            return 1;
        } else if(s1[i] < s2[i] || (s1[i] == '\0' && s2[i] != '\0')){
            return -1;
        } else if(s1[i] == '\0' && s2[i] == '\0'){
            return 0;
        }
        i++;
    }
    return 0; // 両方\0
}
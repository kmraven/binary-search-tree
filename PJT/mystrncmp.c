#include "interCheck.h"

int mystrncmp(const char* s1, const char* s2, const int n){
    for(int i = 0; i < n; i++){
        if(s1[i] > s2[i]){
            return 1;
        } else if(s1[i] < s2[i]){
            return -1;
        } else if(s1[i] == '\0' && s2[i] == '\0'){
            break;
        }
    }
    return 0; // n文字目までで同じだったら
}
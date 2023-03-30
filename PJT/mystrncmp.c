#include "interCheck.h"

int mystrncmp(const char* s1, const char* s2, const int n){
    int i = 0;
    if(n == 0){
        return 0; // 対象が0文字だったら無条件に等しい
    }
    while(i < n){
        if(s1[i] > s2[i] || (s1[i] == '\0' && s2[i] != '\0')){
            return 1;
        } else if(s1[i] < s2[i] || (s1[i] != '\0' && s2[i] == '\0')){
            return -1;
        } else if(s1[i] == '\0' && s2[i] == '\0'){
            return 0;
        }
        i++;
    }
    return 0; // n文字目までで同じだったら
}
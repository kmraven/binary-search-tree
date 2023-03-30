#include "interCheck.h"

char* mystrsubst(const char* s1, const char* s2, const char* s3){
    // s1中のs2をs3に置換したnew_strを返す
    int i, i_new_str = 0, s1_len = mystrlen(s1), s2_len = mystrlen(s2), s3_len = mystrlen(s3);
    // new_strの領域を適当にmalloc
    char* new_str = (char*)malloc(sizeof(char) * (s1_len + s1_len * s3_len + 1));
    // s1を1文字ずつ見ていって
    for(i = 0; i < mystrlen(s1); i++){
        if (mystrncmp(&s1[i], s2, s2_len) == 0){
            // s3に変更
            mystrcpy(&new_str[i_new_str], s3);
            i += s2_len - 1; // forの頭でi++されるから
            i_new_str += s3_len;
        } else{
            // new_strにs1[i]を追加
            mystrncpy(&new_str[i_new_str], &s1[i], 1);
            i_new_str += 1;
        }
    }
    char* return_str = (char*)malloc(sizeof(char) * (mystrlen(new_str) + 1));
    mystrcpy(return_str, new_str);  // mallocサイズを整えておく
    free(new_str);
    return return_str;
}
#include "interCheck.h"

int validateArgs(char *argv) {
    /*
    -sと-rに渡された引数のバリデーションを行う関数
    引数が正常な場合は0を、不適切な場合は1を返す
    最初と最後が'/'かつ'/'が3つであればOK
    */
    int i = 0, slash_cnt = 0;
    if(argv[i] != '/') {return 1;} // 最初の文字が'/'ではない
    for(i = 0; i < mystrlen(argv); i++) {
        if(argv[i] == '/') {slash_cnt += 1;}
    }
    if(slash_cnt != 3) {return 1;} // '/'の数が3つではない
    if(argv[i - 1] != '/') {return 1;} // 最後の文字が'/'ではない
    return 0;
}
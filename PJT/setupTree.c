#include "interCheck.h"

void setupTree(BinSTreeNode** rootNode, FILE* fp) {
    /* 入力データをTreeに格納する関数(rootNode=NULLのケースを考えて**で扱っている) */
    int i, j;
    char* str = (char*)malloc(sizeof(char) * N);
    char* str_buff = (char*)malloc(sizeof(char) * N);
    while(fgets(str, N, fp) != NULL) {
        //strを空白 or \n区切りで読み込み、単語をlistに格納していく
        for(i = 0; i < mystrlen(str) + 1; i++){
            if(str[i] != ' ' && str[i] != '\n' && str[i] != '\0'){
                // 空白と\n以外が来るまで回す -> 文字が来たらiを保持
                for(j = i + 1; j < mystrlen(str) + 1; j++){
                    if(str[j] == ' ' || str[j] == '\n' || str[j] == '\0'){
                        // また空白か\nが来るまで回す -> 空白か\nがきたらiから(j-i)文字をcopy
                        mystrncpy(str_buff, &str[i], j - i);
                        if(*rootNode == NULL) {
                            *rootNode = createNode(str_buff);
                        } else {
                            addNode(*rootNode, createNode(str_buff));
                        }
                        break;
                    }
                }
                i = j; // 読んだところまでカウンタを更新
            }
        }
    }
    free(str);
    free(str_buff);
    return;
}
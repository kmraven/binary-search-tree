#include "interCheck.h"

void printTree(BinSTreeNode *rootNode, int order){
    /*
    引数 order で指定された走査順に基づいて、与えられた2分探索木の各ノードの文字列を順に表示する。
    0:前順走査, 1:間順走査, 2:後順走査
    */
    if(rootNode != NULL) {
        if(order == 0) {
            // 前順走査
            if(rootNode->word != NULL) {
                printf("%s\n", rootNode->word); // データの出力
            }
            printTree(rootNode->left, order); // 左ノードへ移動
            printTree(rootNode->right, order); // 右ノードへ移動
        } else if(order == 1) {
            // 間順走査
            printTree(rootNode->left, order); // 左ノードへ移動
            if(rootNode->word != NULL) {
                printf("%s\n", rootNode->word); // データの出力
            }
            printTree(rootNode->right, order); // 右ノードへ移動
        } else if(order == 2) {
            // 後順走査
            printTree(rootNode->left, order); // 左ノードへ移動
            printTree(rootNode->right, order); // 右ノードへ移動
            if(rootNode->word != NULL) {
                printf("%s\n", rootNode->word); // データの出力
            }
        }
    }
    return;
}
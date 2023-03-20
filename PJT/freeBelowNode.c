#include "interCheck.h"

void freeBelowNode(BinSTreeNode* rootNode){
    /*
    与えられたノードを含め、それ以下ノードを削除する。
    なお、全体のrootNodeが与えられた場合はfreeせず、wordをNULLにして返す
    */
    if(rootNode != NULL) {
        // 後順走査
        clearBinSTree(rootNode->left); // 左ノードへ移動
        clearBinSTree(rootNode->right); // 右ノードへ移動

        free(rootNode->word);
        if(rootNode->pare != NULL) {
            // 親が存在する -> 親から自分の情報を削除
            if(rootNode->pare->left == rootNode) {
                rootNode->pare->left = NULL;
            } else if(rootNode->pare->right == rootNode) {
                rootNode->pare->right = NULL;
            }
        } else {
            // 親が存在しない = 全体のrootNodeなのでポインタはfreeしない
            rootNode->word = NULL;
            return;
        }
        free(rootNode);
    }
    return;
}
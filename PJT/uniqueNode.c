#include "interCheck.h"

void uniqueNode(BinSTreeNode* rootNode) {
    /*
    wordに重複があったらそのノードを削除する関数
    前順走査で右の子以下から自分のwordを持つnodeを全て削除する
    */
    if(rootNode != NULL) {
        if(rootNode->right != NULL) {
            removeNode(rootNode->right, rootNode->word, 0);
        }
        uniqueNode(rootNode->left);
        uniqueNode(rootNode->right);
    }
}
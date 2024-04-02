#include "interCheck.h"

void addNode(BinSTreeNode* rootNode, BinSTreeNode* node){
    /* 2分探索木に対してノードを新たに追加する。*/
    if(mystrcmp(rootNode->word, node->word) > 0){
        if(rootNode->left != NULL) {
            addNode(rootNode->left, node);
        } else {
            rootNode->left = node;  // 自分より小さかったら左に格納
            rootNode->left->pare = rootNode;
        }
    } else {
        if(rootNode->right != NULL) {
            addNode(rootNode->right, node);
        } else {
            rootNode->right = node;  // 自分以上だったら右に格納
            rootNode->right->pare = rootNode;
        }
    }
}
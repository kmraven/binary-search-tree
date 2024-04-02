#include "interCheck.h"

BinSTreeNode* recreateNode(BinSTreeNode* rootNode, BinSTreeNode* new_rootNode) {
    /* 新しくTreeを作り直す関数(new_rootNode=NULLのケースを考えて**で扱っている) */
    if(rootNode != NULL) {
        if(new_rootNode == NULL) {
            new_rootNode = createNode(rootNode->word);
        } else {
            addNode(new_rootNode, createNode(rootNode->word));
        }
        recreateNode(rootNode->left, new_rootNode);
        recreateNode(rootNode->right, new_rootNode);
    }
    return new_rootNode;
}
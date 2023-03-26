#include "interCheck.h"

void recreateNode(BinSTreeNode* rootNode, BinSTreeNode** new_rootNode) {
    if(rootNode != NULL) {
        if(*new_rootNode == NULL) {
            *new_rootNode = createNode(rootNode->word);
        } else {
            addNode(*new_rootNode, createNode(rootNode->word));
        }
        recreateNode(rootNode->left, new_rootNode);
        recreateNode(rootNode->right, new_rootNode);
    }
    return;
}
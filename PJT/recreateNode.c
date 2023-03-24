#include "interCheck.h"

BinSTreeNode* recreateNode(BinSTreeNode* rootNode, BinSTreeNode* new_rootNode) {
    if(rootNode != NULL) {
        if(new_rootNode == NULL) {
            new_rootNode = createNode(rootNode->word);
        } else {
            addNode(new_rootNode, createNode(rootNode->word));
        }
        new_rootNode = recreateNode(rootNode->left, new_rootNode);
        new_rootNode = recreateNode(rootNode->right, new_rootNode);
    }
    return new_rootNode;
}
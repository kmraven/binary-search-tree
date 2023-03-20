#include "interCheck.h"

BinSTreeNode* getMax(BinSTreeNode* rootNode) {
    /* rootNodeより下の最大値を返す関数 */
    if(rootNode->right != NULL) {
        return getMax(rootNode->right);
    }
    return rootNode;
}
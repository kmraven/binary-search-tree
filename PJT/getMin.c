#include "interCheck.h"

BinSTreeNode* getMin(BinSTreeNode* rootNode) {
    /* rootNodeより下の最小値を返す関数 */
    if(rootNode->left != NULL) {
        return getMax(rootNode->left);
    }
    return rootNode;
}
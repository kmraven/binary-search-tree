#include "interCheck.h"

void clearBinSTree(BinSTreeNode *rootNode){
    /*
    与えられた2分探索木のすべてのノードを削除する。
    プログラムにて2分探索木の利用が完了した後で呼び出す。
    */
    if(rootNode != NULL) { // 後順走査
        clearBinSTree(rootNode->left); // 左ノードへ移動
        clearBinSTree(rootNode->right); // 右ノードへ移動
        free(rootNode->word);
        free(rootNode);
    }
}
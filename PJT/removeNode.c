#include "interCheck.h"

void removeNode(BinSTreeNode* rootNode, const char *word, int delall){
    /*
    与えられた2分探索木から、引数 word で与えられる文字列を持つノードを削除する。
    該当文字列を持つノードが複数存在する場合、delall が真 (0) であれば全て削除し、偽 (それ以外) であれば root ノードから最も近いノードのみを削除する。
    ノードを削除する際には、malloc によって動的に確保されたメモリを解放する。
    */
    if(rootNode != NULL) {
        BinSTreeNode* tmp;
        int cmp = mystrcmp(rootNode->word, word);
        if(cmp == 0) { // wordを含むなら
            if(rootNode->left != NULL) {
                // 左に子があればそれより下の最大値を持ってくる
                tmp = getMax(rootNode->left);
                mystrcpy(rootNode->word, tmp->word);
                removeNode(tmp, tmp->word, 1);
            } else if(rootNode->right != NULL) {
                // 右に子があればそれより下の最小値を持ってくる
                tmp = getMin(rootNode->right);
                mystrcpy(rootNode->word, tmp->word);
                removeNode(tmp, tmp->word, 1);
            } else {
                // 子がなければそのまま削除
                freeBelowNode(rootNode);
                return;
            }
            if(delall == 0) {
                // 全て削除なので再発火(削除対象をrootに代入しているかもしれない)
                removeNode(rootNode, word, delall);
            } else {
                // 近いもの1つ見つけたら終了
                return;
            }
        } else if(cmp == 1) {
            removeNode(rootNode->left, word, delall);
        } else if(cmp == -1) {
            removeNode(rootNode->right, word, delall);
        }
    }
    return;
}
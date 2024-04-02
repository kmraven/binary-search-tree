#include "interCheck.h"

BinSTreeNode* removeNode(BinSTreeNode* rootNode, const char *word, int delall){
    /*
    与えられた2分探索木から、引数 word で与えられる文字列を持つノードを削除する。
    該当文字列を持つノードが複数存在する場合、delall が真 (0) であれば全て削除し、偽 (それ以外) であれば root ノードから最も近いノードのみを削除する。
    ノードを削除する際には、malloc によって動的に確保されたメモリを解放する。
    */
    if(rootNode != NULL) {
        int cmp = mystrcmp(rootNode->word, word);
        if(cmp == 0) { // wordを含むなら
            if(rootNode->left != NULL || rootNode->right != NULL) {
                BinSTreeNode* tmp;
                if(rootNode->right != NULL) {
                    // 右を優先 (自分と同じwordのnodeがあれば、delallの処理効率的にそれをrootに持ってきたい)
                    tmp = getMin(rootNode->right); // 右に子があればそれより下の最小値を持ってくる
                } else {
                    tmp = getMax(rootNode->left); // 左に子があればそれより下の最大値を持ってくる
                }
                free(rootNode->word);
                rootNode->word = (char*)malloc(sizeof(char) * (mystrlen(tmp->word) + 1));
                mystrcpy(rootNode->word, tmp->word);
                removeNode(tmp, tmp->word, 1);
                if(delall == 0) {
                    rootNode = removeNode(rootNode, word, delall); // 全て削除なので再発火
                }
            } else { // 子供なし
                if (rootNode->pare != NULL) {
                    if(rootNode->pare->left == rootNode) {
                        rootNode->pare->left = NULL;
                    } else {
                        rootNode->pare->right = NULL;
                    }
                }
                clearBinSTree(rootNode);
                rootNode = NULL;
            }
        } else {
            removeNode(rootNode->left, word, delall);
            removeNode(rootNode->right, word, delall);
        }
    }
    return rootNode;
}
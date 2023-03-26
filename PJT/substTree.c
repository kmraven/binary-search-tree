#include "interCheck.h"

int substTree(BinSTreeNode* rootNode, const char *sstr, const char *rstr, int replaced) {
    if(rootNode != NULL) {
        // 間順走査
        replaced = substTree(rootNode->left, sstr, rstr, replaced); // 左ノードへ移動

        char *before, *after;
        before = (char*)malloc(sizeof(char) * (mystrlen(rootNode->word) + 1));
        mystrcpy(before, rootNode->word);
        after = mystrsubst(rootNode->word, sstr, rstr); // substの返り値がmallocされてるので変数に格納しといてfreeする
        free(rootNode->word);
        rootNode->word = after;
        if(mystrcmp(before, rootNode->word) != 0) {replaced += 1;} // 変わってたらreplacedに1を加算
        free(before);

        replaced = substTree(rootNode->right, sstr, rstr, replaced); // 右ノードへ移動
    }
    return replaced;
}
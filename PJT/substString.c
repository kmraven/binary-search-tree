#include "interCheck.h"

int substString(BinSTreeNode* rootNode, const char *sstr, const char *rstr, int replaced){
    /*
    2分探索木の各ノードについて、引数 sstr で与えられる文字列が各ノードが持つ文字列の部分文字列となっている場合、その部分文字列を引数 rstr で与えられた文字列で置換する。
    返り値として、置換を受けたノードの数を返す。
    なお、部分文字列の置換を行った場合、2分探索木の条件が崩れる可能性があるため、置換後に後述の sortBinSTree 関数を実行する。
    */
    if(rootNode != NULL) {
        // 間順走査
        replaced = substString(rootNode->left, sstr, rstr, replaced); // 左ノードへ移動

        char *before, *after;
        before = (char*)malloc(sizeof(char) * (mystrlen(rootNode->word) + 1));
        mystrcpy(before, rootNode->word);
        after = mystrsubst(rootNode->word, sstr, rstr); // substの返り値がmallocされてるので変数に格納しといてfreeする
        free(rootNode->word);
        rootNode->word = after;
        if(mystrcmp(before, rootNode->word) != 0) {replaced += 1;} // 変わってたらreplacedに1を加算
        free(before);

        replaced = substString(rootNode->right, sstr, rstr, replaced); // 右ノードへ移動
    }
    return replaced;
}
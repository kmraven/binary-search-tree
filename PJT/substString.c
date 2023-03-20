#include "interCheck.h"

int substString(BinSTreeNode* rootNode, const char *sstr, const char *rstr){
    /*
    2分探索木の各ノードについて、引数 sstr で与えられる文字列が各ノードが持つ文字列の部分文字列となっている場合、その部分文字列を引数 rstr で与えられた文字列で置換する。
    返り値として、置換を受けたノードの数を返す。
    なお、部分文字列の置換を行った場合、2分探索木の条件が崩れる可能性があるため、置換後に後述の sortBinSTree 関数を実行する。
    */
    int replaced = 0;
    return substTree(rootNode, sstr, rstr, replaced);
}
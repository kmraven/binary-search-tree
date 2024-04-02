#include "interCheck.h"

BinSTreeNode* sortBinSTree(BinSTreeNode* rootNode){
    /*
    与えられた木に対して、親ノードと子ノード間のデータの大小関係が2分探索木の条件を満たすようにソートする (必要に応じて親ノードと子ノードを入れ替える)。
    recreateNode関数で、前順走査でaddNodeをして、完了したら旧rootNodeをfreeして新rootNodeのアドレスに差し替え
    */
    BinSTreeNode* tmp_rootNode = NULL;
    tmp_rootNode = recreateNode(rootNode, tmp_rootNode);
    clearBinSTree(rootNode);
    return tmp_rootNode;
}
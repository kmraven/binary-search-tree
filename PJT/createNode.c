#include "interCheck.h"

BinSTreeNode* createNode(const char *word){
    /*
    引数 word で与えられた単語 (文字列) を持つ (2分探索木の) ノードを動的に生成し、生成されたノードを返す (失敗した場合には NULL を返す)。
    与えられた文字列についても、動的にメモリを確保する。
    */
    BinSTreeNode* new_node = (BinSTreeNode*)malloc(sizeof(BinSTreeNode));
    new_node->word = (char*)malloc(sizeof(char) * (mystrlen(word) + 1));  // \0が入る余地
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->pare = NULL;
    mystrcpy(new_node->word, word);
    return new_node;
}
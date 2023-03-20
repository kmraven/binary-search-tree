#include "interCheck.h"

BinSTreeNode* createNode(const char *word){
    /*
    引数 word で与えられた単語 (文字列) を持つ (2分探索木の) ノードを動的に生成し、生成されたノードを返す (失敗した場合には NULL を返す)。
    与えられた文字列についても、動的にメモリを確保する。
    */
    BinSTreeNode* new_node = NULL;
    char* word_buff = (char*)malloc(sizeof(char) * mystrlen(word));
    mystrcpy(word_buff, word);
    new_node = (BinSTreeNode*)malloc(sizeof(BinSTreeNode));
    new_node->word = (char*)malloc(sizeof(char) * mystrlen(word));  // [不安] \0が入る余地ある？
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->pare = NULL;
    mystrcpy(new_node->word, chomp(word_buff));
    free(word_buff);
    return new_node;
}
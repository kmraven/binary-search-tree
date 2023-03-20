#include "interCheck.h"

void sortBinSTree(BinSTreeNode* rootNode){
    /*
    与えられた木に対して、親ノードと子ノード間のデータの大小関係が2分探索木の条件を満たすようにソートする (必要に応じて親ノードと子ノードを入れ替える)。
    これを後順走査で下からやっていけば良さそう。
    */
    if(rootNode != NULL) {
        // 後順走査
        sortBinSTree(rootNode->left); // 左ノードへ移動
        sortBinSTree(rootNode->right); // 右ノードへ移動

        if(rootNode->left != NULL && rootNode->right != NULL) {
            // 左右に子がいるなら,左右をソート
            if(mystrcmp(rootNode->left->word, rootNode->right->word) == 1) {
                // 左右入れ替え
                char* tmp;
                tmp = (char*)malloc(sizeof(char) * mystrlen(rootNode->left->word));
                mystrcpy(tmp, rootNode->left->word);
                mystrcpy(rootNode->left->word, rootNode->right->word);
                mystrcpy(rootNode->right->word, tmp);
                free(tmp);
            }
        }
        if(rootNode->left != NULL) {
            // 左の子がいるなら,親と左をソート abb abbb
            if(mystrcmp(rootNode->word, rootNode->left->word) == -1) {
                // 親左入れ替え
                char* tmp;
                tmp = (char*)malloc(sizeof(char) * mystrlen(rootNode->word));
                mystrcpy(tmp, rootNode->word);
                mystrcpy(rootNode->word, rootNode->left->word);
                mystrcpy(rootNode->left->word, tmp);
                free(tmp);
            }
        }
        if(rootNode->right != NULL) {
            // 右の子がいるなら,親と右をソート
            if(mystrcmp(rootNode->word, rootNode->right->word) == 1) {
                // 親右入れ替え
                char* tmp;
                tmp = (char*)malloc(sizeof(char) * mystrlen(rootNode->word));
                mystrcpy(tmp, rootNode->word);
                mystrcpy(rootNode->word, rootNode->right->word);
                mystrcpy(rootNode->right->word, tmp);
                free(tmp);
            }
        }
    }
    return;
}
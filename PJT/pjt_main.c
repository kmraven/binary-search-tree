#include "interCheck.h"

int main2(int argc, char* argv[]) {
    int i, p_flag = 1, u_flag = 0, stdin_flag = 1, opt_read = 0;
    FILE* fp = NULL;
    BinSTreeNode* rootNode = NULL;

    // コマンドの引数をチェック
    for(i = 1; i < argc; i++) {
        if(*argv[i] == '-') {
            if(opt_read) {
                // ファイル引数の後にオプションが存在する場合
                printf("usage:ERROR (incorrect command format, input file paths after options)\n");
                clearBinSTree(rootNode);
                return 1;
            }
            // ハイフンの次の文字によって分岐
            switch(*(argv[i] + 1)){
                case 'p':
                    i += 1;
                    switch(*argv[i]) {
                        case '0':
                            p_flag = 0;
                            break;
                        case '1':
                            p_flag = 1;
                            break;
                        case '2':
                            p_flag = 2;
                            break;
                        default:
                            printf("usage:ERROR (incorrect -p format, follow -p [0:pre order, 1:between order, 2:post order])\n");
                            clearBinSTree(rootNode);
                            return 1;
                    }
                    break;
                case 's':
                    i += 1;
                    if(validateArgs(argv[i])) {
                        printf("usage:ERROR (incorrect -s format, follow -s /match/replace/)\n");
                        clearBinSTree(rootNode);
                        return 1;
                    }
                    break;
                case 'u':
                    u_flag = 1;
                    break;
                case 'r':
                    i += 1;
                    if(validateArgs(argv[i])) {
                        printf("usage:ERROR (incorrect -r format, follow -r /rmvmatch/delall/)\n");
                        clearBinSTree(rootNode);
                        return 1;
                    }
                    break;
                default:
                    printf("usage:ERROR (options are invalid)\n");
                    clearBinSTree(rootNode);
                    return 1;
            }
        } else {
            stdin_flag = 0; // ファイル引数が存在
            opt_read = 1; // これ以降にオプションは登場しない
            fp = fopen(argv[i], "r");
            if(fp == NULL){
                printf("usage:ERROR (File is NULL(read file))\n");
                fclose(fp);
                clearBinSTree(rootNode);
                return 1;
            }
            rootNode = setupTree(rootNode, fp);
            fclose(fp);
        }
    }
    if(stdin_flag) {
        // ファイル引数が存在しないならNULLを渡してstdinから読み込む
        rootNode = setupTree(rootNode, fp);
    }

    char* opt_arg1 = (char*)malloc(sizeof(char) * N);
    char* opt_arg2 = (char*)malloc(sizeof(char) * N);
    printf("---BinSTree---\n");
    // オプションに応じた処理
    // -s,-u,-rの処理を実行、バリデーション通過済みなので最低限の処理のみでOK
    for(i = 1; i < argc; i++) {
        if(*argv[i] == '-') {
            // ハイフンの次の文字によって分岐
            switch(*(argv[i] + 1)){
                case 'p':
                    i += 1;
                    break;
                case 's':
                    i += 1;
                    parseArgs(argv[i], opt_arg1, opt_arg2); // 引数をparse
                    substString(rootNode, opt_arg1, opt_arg2);
                    sortBinSTree(rootNode);
                    break;
                case 'r':
                    i += 1;
                    parseArgs(argv[i], opt_arg1, opt_arg2); // 引数をparse
                    if(*opt_arg2 == '0') {
                        removeNode(rootNode, opt_arg1, 0);
                    } else {
                        removeNode(rootNode, opt_arg1, 1);
                    }
                    sortBinSTree(rootNode);
                    break;
            }
        } else {
            break; // ファイル引数に達したらオプション走査終了
        }
    }
    if(u_flag) {}
    removeNode(rootNode, "", 0);
    if(rootNode->word == NULL) {
        printf("There is no node\n");
    }
    printTree(rootNode, p_flag);
    clearBinSTree(rootNode);
    free(opt_arg1);
    free(opt_arg2);
    return 0;
}
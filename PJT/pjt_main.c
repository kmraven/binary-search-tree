#include "interCheck.h"

int main(int argc, char* argv[]) {
    int i, p_arg = 1, p_flag = 0, u_arg = 0, u_flag = 0, stdin_flag = 1, opt_read = 0;
    FILE* fp = NULL;
    BinSTreeNode* rootNode = NULL;

    /* --- コマンドをバリデーション & Tree作成 --- */
    for(i = 1; i < argc; i++) {
        if(*argv[i] == '-') {
            if(opt_read) {
                // ファイル引数の後にオプションが存在する場合
                printf("usage:ERROR (incorrect command format, input file paths after options)\n");
                clearBinSTree(rootNode);
                return 1;
            }
            // ハイフンの次の文字によって分岐
            if(mystrcmp(argv[i], "-p") == 0) {
                if(p_flag) {
                    printf("usage: p option should not duplicate\n");
                    clearBinSTree(rootNode);
                    return 1;
                } else {
                    p_flag = 1;
                    if(i + 1 < argc) { // 次の引数があるなら
                        if(mystrcmp(argv[i + 1], "0") == 0 || mystrcmp(argv[i + 1], "1") == 0 || mystrcmp(argv[i + 1], "2") == 0) {
                            fp = fopen(argv[i + 1], "r");
                            if(fp != NULL) {
                                printf("usage:ERROR (There is a text file named %c which is same as -p argument)\n", *argv[i + 1]);
                                fclose(fp);
                                clearBinSTree(rootNode);
                                return 1;
                            }
                            fclose(fp);
                            if(mystrcmp(argv[i + 1], "0") == 0) {
                                p_arg = 0;
                                p_flag = 2;
                                i += 1;
                            } else if(mystrcmp(argv[i + 1], "1") == 0) {
                                p_arg = 1;
                                p_flag = 2;
                                i += 1;
                            } else if(mystrcmp(argv[i + 1], "2") == 0) {
                                p_arg = 2;
                                p_flag = 2;
                                i += 1;
                            }
                        }
                    }
                }
            } else if(mystrcmp(argv[i], "-s") == 0) {
                i += 1;
                if(i >= argc) {
                    printf("usage: s option needs string format /match/replace/ after it\n");
                    clearBinSTree(rootNode);
                    return 1;
                }
                if(validateArgs(argv[i])) {
                    printf("usage:ERROR (incorrect -s format, follow -s /match/replace/)\n");
                    clearBinSTree(rootNode);
                    return 1;
                }
            } else if(mystrcmp(argv[i], "-u") == 0) {
                if(u_flag) {
                    printf("usage: u option should not duplicate\n");
                    clearBinSTree(rootNode);
                    return 1;
                } else {
                    u_flag = 1;
                    u_arg = 1;
                }
            } else if(mystrcmp(argv[i], "-r") == 0) {
                i += 1;
                if(i >= argc) {
                    printf("usage: r option needs string format [/string/[0|1|else]/] after it\n");
                    clearBinSTree(rootNode);
                    return 1;
                }
                if(validateArgs(argv[i])) {
                    printf("usage:ERROR (incorrect -r format, follow -r /rmvmatch/delall/)\n");
                    clearBinSTree(rootNode);
                    return 1;
                }
            } else {
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
            setupTree(&rootNode, fp);
            fclose(fp);
        }
    }
    if(stdin_flag) {
        printf("---standard input---\n");
        setupTree(&rootNode, stdin); // ファイル引数が存在しないならNULLを渡してstdinから読み込む
    }

    /* --- オプションに応じた処理 --- */
    char* opt_arg1 = (char*)malloc(sizeof(char) * N);
    char* opt_arg2 = (char*)malloc(sizeof(char) * N);
    printf("---BinSTree---\n");
    // -s,-u,-rの処理を実行、バリデーション通過済みなので最低限の処理のみでOK
    for(i = 1; i < argc && rootNode != NULL; i++) {
        if(*argv[i] == '-') {
            if(mystrcmp(argv[i], "-p") == 0 && p_flag == 2) {
                i += 1;
            } else if(mystrcmp(argv[i], "-s") == 0) {
                i += 1;
                parseArgs(argv[i], opt_arg1, opt_arg2); // 引数をparse
                if(substString(rootNode, opt_arg1, opt_arg2, 0)) {
                    rootNode = sortBinSTree(rootNode);
                    rootNode = removeNode(rootNode, "", 0);
                }
            } else if(mystrcmp(argv[i], "-r") == 0) {
                i += 1;
                parseArgs(argv[i], opt_arg1, opt_arg2); // 引数をparse
                if(mystrcmp(opt_arg2, "0") == 0) {
                    rootNode = removeNode(rootNode, opt_arg1, 0);
                } else {
                    rootNode = removeNode(rootNode, opt_arg1, 1);
                }
            }
        } else {
            break; // ファイル引数に達したらオプション走査終了
        }
    }
    if(rootNode == NULL) {
        printf("There is no node\n");
    } else {
        if(u_arg) {
            uniqueNode(rootNode);
            rootNode = sortBinSTree(rootNode);
        }
        printTree(rootNode, p_arg);
    }
    clearBinSTree(rootNode);
    free(opt_arg1);
    free(opt_arg2);
    return 0;
}
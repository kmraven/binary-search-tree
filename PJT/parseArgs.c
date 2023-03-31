#include "interCheck.h"

void parseArgs(char* argv, char* opt_arg1, char* opt_arg2) {
    /*
    引数文字列を'/'区切りでparseする関数
    argvはバリデーションによって、最初と最後の文字は'/'で、'/'は3つあることが確定している
    */
    int i, slash2 = 0, slash3 = mystrlen(argv) - 1, argv_len = mystrlen(argv);
    for(i = 1; i < argv_len; i++) {
        if(argv[i] == '/') {
            slash2 = i;
            break;
        }
    }
    mystrncpy(opt_arg1, &argv[1], slash2 - 1);
    mystrncpy(opt_arg2, &argv[slash2 + 1], slash3 - slash2 - 1);
}
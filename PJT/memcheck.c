// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>

// //プロトタイプ宣言
// int main(int argc, char* argv[]);

// //メモリリークチェック
// int main (int argc, char **argv) {
//     int ret = main2(argc, argv);
//     char buf[256];
//     printf("\n");
//     printf("\n");
//     printf("##### memCheck result #####\n");
//     sprintf(buf, "leaks %d", getpid());
//     system(buf);
//     return ret;
// }
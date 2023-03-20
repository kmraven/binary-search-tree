#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1024*1024
#define debug_flag 0

//define BinSTreeNode
typedef struct _BinSTreeNode{
  char *word;
  struct _BinSTreeNode *left;
  struct _BinSTreeNode *right;
  struct _BinSTreeNode *pare;
}BinSTreeNode;

//required functions
BinSTreeNode* createNode(const char *word);
void addNode(BinSTreeNode* rootNode, BinSTreeNode* node);
void printTree(BinSTreeNode *rootNode, int order);
int substString(BinSTreeNode* rootNode, const char *sstr, const char *rstr);
void sortBinSTree(BinSTreeNode* rootNode);
void clearBinSTree(BinSTreeNode* rootNode);
void removeNode(BinSTreeNode* rootNode, const char *word, int delall);

//your additional functions
char* chomp(char* str);
int mystrcmp(const char* s1, const char* s2);
char* mystrcpy(char* s1, const char* s2);
int mystrlen(const char* str);
int mystrncmp(const char* s1, const char* s2, const int n);
char* mystrncpy(char* s1, const char* s2, const int n);
char* mystrsubst(const char* s1, const char* s2, const char* s3);
int mystrstr(const char* s1, const char* s2);

BinSTreeNode* getMax(BinSTreeNode* rootNode);
BinSTreeNode* getMin(BinSTreeNode* rootNode);
int substTree(BinSTreeNode* rootNode, const char *sstr, const char *rstr, int replaced);
BinSTreeNode* setupTree(BinSTreeNode* rootNode, FILE* fp);
int validateArgs(char* argv);
void parseArgs(char* argv, char* opt_arg1, char* opt_arg2);
void freeBelowNode(BinSTreeNode* rootNode);
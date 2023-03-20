PROG = pjt
# OBJSに実行に必要なオブジェクトファイルを追加
OBJS = pjt_main.o createNode.o addNode.o printTree.o substString.o sortBinSTree.o clearBinSTree.o removeNode.o memcheck.o $(MYOBJS) $(MYSTROBJS)
MYOBJS = substTree.o setupTree.o validateArgs.o parseArgs.o getMax.o getMin.o freeBelowNode.o
MYSTROBJS = chomp.o mystrcmp.o mystrcpy.o mystrlen.o mystrncmp.o mystrncpy.o mystrsubst.o
CC = gcc
CFLAGS = -Wall -O0 -g
LDFLAGS = -lm
.PHONY: all
all: $(PROG)

.SUFFIXES: .o.c
.c.o:
	$(CC) $(CFLAGS) -c $<
$(PROG): $(OBJS)
	$(CC) -g -o $@ $^ $(LDFLAGS)
.PHONY: clean
clean:
	rm -f $(PROG) $(OBJS)

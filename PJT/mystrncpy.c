#include "interCheck.h"

char* mystrncpy(char* s1, const char* s2, const int n) {
    char* p = s1;
    int i = n;
    while ( *s2 && i-- ) {
        *s1++ = *s2++;
    }
    *s1 = '\0';
    return p;
}
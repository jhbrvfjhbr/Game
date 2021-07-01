#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

int mystrlen(const char* str1) {
    int i;
    for(i = 0; str1[i] != '\0'; i++) {
    }
    return i + 1;
}

char* mystrcpy(char* str1, const char* str2) {
    delete[] str1;
    str1 = new char[mystrlen(str2) + 1];
    int i;
    for (i = 0; str2[i]; i++) {
        str1[i] = str2[i];
    }
    str1[i] = '\0';
    return str1;
}

char* mystrcat(char* str1, const char* str2) {
    for (int i = strlen(str1), j = 0; i < (strlen(str1) + strlen(str2)); i++) {
        str1[i] = str2[j];
        j++;
    }
    return str1;
}

char* mystrchr(char* str,const char* s) {
    for (int i = 0; str[i] != '\n'; i++) {
        if (str[i] == s[0]) {
            return (str + i);
        }
    }
    return 0;
}

char* mystrstr(char* str, const char* str2) { //»щет слово в слове. “ипа если str = "Jotaro", а str2 = "ta", то return "taro"
    for (int i = 0, j = 0; i < strlen(str); i++) {
        if (str[i] == str2[j]) {
            for (int g = i, f = j; str2; g++, f++) {
                if (str[g] != str2[f]) {
                    break;
                }
            }
            return (str + i);
        }
    }
    return str;
}


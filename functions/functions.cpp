#include "functions.h"

int divi(int a, int b) {
    return a/b;
}

int add(int a, int b) {
    return a + b;
}

int mul(int a, int b) {
    return a * b;
}

int sous(int a ,int b) {
    return a - b;
}

int modulo(int a ,int b) {
    return a % b;
}

int absF(int a) {
    return a < 0 ? -a : a;
}

int pow(int a ,int b) {
    int res = 1;
    for(int i = 0; i < b; i++) {
        res *= a;
    }
    return res;
}

int exp(int a) {
    return exp(a);
}

int log(int a) {
    return log(a);
}

int log10(int a) {
    return log10(a);
}

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a > b ? b : a;
}

int fibo(int a) {
    int n = 0;
    int N = 1;
    for(int i = 0; i < a; i++) {
        int tmp = N;
        N += n;
        n = tmp;
    }
    return n;
}


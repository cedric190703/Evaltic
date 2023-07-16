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

int sub(int a ,int b) {
    return a - b;
}

int modulo(int a ,int b) {
    return a % b;
}

int absf(int a) {
    return a < 0 ? -a : a;
}

int power(int a ,int b) {
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

int isFunction(string e) {
    return (e == "div" || e == "add" || e == "mul" || e == "sub" ||
    e == "mod" || e == "abs" || e == "pow" || e == "exp" || e == "log" ||
    e == "max" || e == "min" || e == "fibo") ? 1 : 0;
}
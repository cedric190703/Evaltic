#include "convertion.h"

int priorite(char op) {
    switch(op) {
        case '+' :
        case '-' :
            return 1;
        case '*' :
        case '/' :
        case '%' :
            return 2;
        case '^' :
            return 3;
        case '>' :
        case '<' :
        case '=' :
            return 4;
        default :
            return -1;
    }
}

const char* convertExpressionRecursive(const string& expression, size_t size,
    stack<char>& operators, stringstream& postfix, size_t* i, int isFun) {
    if (*i >= size) {
        while (!operators.empty()) {
            postfix << operators.top();
            operators.pop();
        }
        string postfixStr = postfix.str();
        return postfixStr.c_str();
    }

    char e = expression[*i];

    if (e == ';') {
        while (!operators.empty()) {
            postfix << operators.top();
            operators.pop();
        }
        postfix << e;
    } else if (isOperatorConversion(e) || islogicalOpConversion(e)) {
        while (!operators.empty() && operators.top() != '(' && priorite(e) <= priorite(operators.top())) {
            postfix << operators.top();
            operators.pop();
        }
        operators.push(e);
    } else if (e == '(') {
        operators.push(e);
    } else if (e == ')') {
        while (!operators.empty() && operators.top() != '(') {
            postfix << operators.top();
            operators.pop();
        }
        if (!operators.empty() && operators.top() == '(') {
            operators.pop();
        }
        if(isFun) {
            postfix << ')';
            isFun = 0;
        }
    } else if (isalpha(e)) {
        // Function call
        string functionName;
        size_t j = *i;
        while (isalpha(expression[j])) {
            functionName += expression[j];
            ++j;
        }
        *i = j - 1;
        if(*i < size - 1) {
            if(expression[*i+1] == '(') {
                postfix << functionName;
                postfix << '(';
                ++*i;
                convertExpressionRecursive(expression, size, operators, postfix, i, 1);
            } else {
                postfix << functionName;
            }
        }
        
    } else {
        postfix << e;
    }
    ++*i;
    return convertExpressionRecursive(expression, size, operators, postfix, i, isFun);
}
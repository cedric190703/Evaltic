#include "convertion.h"

int priorite(string op) {
    switch(op[0]) {
        case '+':
        case '-':
            return 1;
        case '*' :
        case '/' :
        case '%' :
            return 2;
        case '^' :
            return 3;
        case '<' :
        case '>' :
        case '?' :
        case ':' :
            return 4;
        default :
            if(op == "<=" || op == ">=" || op == "!=" || op == "==") {
                return 4;
            }
            return -1;
    }
}

int* resizeArrayFun(int* arr, int currentSize, int newSize) {
    int* resizedArray = new int[newSize];
    // Copy elements from the original array to the resized array
    for (int i = 0; i < currentSize && i < newSize; ++i) {
        resizedArray[i] = arr[i];
    }
    // Delete the original array
    delete[] arr;
    return resizedArray;
}

stack<string> reverseStack(stack<string> original) {
    stack<string> destination;
    while(!original.empty()) {
        destination.push(original.top());
        original.pop();
    }
    return destination;
}

void convertExpressionRecursive(
const string& expression,
size_t size,
stack<string>& operators,
stack<string>& res,
size_t* i, 
LinkedList list) {
    if (*i >= size) {
        while (!operators.empty()) {
            res.push(operators.top());
            operators.pop();
        }
        return;
    }
    char e = expression[*i];
    string ep = string(1,e);
    if (isOperatorConversion(e) || isTernaryOp(e)) {
        while (!operators.empty() && operators.top()[0] != '(' && priorite(ep) <= priorite(operators.top())) {
            res.push(operators.top());
            operators.pop();
        }
        operators.push(ep);
    } else if(islogicalOperator(e)) {
        string p;
        p += e;
        if(*i < size-1) {
            if(expression[*i+1] == '=') {
                p += '=';
                ++*i;
            } else if(e == '=') {
                res.push(p);
            }
        }
        operators.push(p);
    } else if (e == '(') {
        operators.push(string(1,e));
    } else if (e == ')') {
        while (!operators.empty() && operators.top()[0] != '(') {
            res.push(operators.top());
            operators.pop();
        }
        if (operators.empty() || operators.top()[0] != '(') {
            throw runtime_error("Synthax error - parentheses.");
        }
        operators.pop();
        // Check if there is a functionName to insert
        if(list.getSize() > 0) {
            int isVirgule;
            string name = list.deleteFirstElement(&isVirgule);
            if(isVirgule) {
                res.push(name);
            } else {
                if(name == "fibo" || name == "abs" || name == "log" || name == "exp") {
                    res.push(name);
                } else {
                    throw runtime_error("Synthax error - member missing in the function assignement.");
                }
            }
        }
    } else if (isalpha(e)) {
        // Function call
        size_t j = *i;
        string functionName;
        while (isalpha(expression[j])) {
            functionName += expression[j];
            ++j;
        }
        *i = j - 1;
        if(*i < size - 1) {
            if(expression[*i+1] == '(') {
                ++*i;
                list.addElement(functionName);
                convertExpressionRecursive(expression, size, operators, res, i, list);
            } else {
                res.push(functionName);
            }
        } else {
            res.push(functionName);
        }
    } else if(isdigit(e)) {
        size_t j = *i;
        int val = 0;
        while (isdigit(expression[j])) {
            val = val * 10 + (expression[j] - '0');
            ++j;
        }
        *i = j - 1;
        res.push(to_string(val));
    } else {
        if(e != ',') {
            res.push(string(1,e));
        } else {
            if(*i > 0) {
                if(expression[*i-1] != '(' && *i < size - 1 && expression[*i+1] != ')') {
                    list.setVirgule();
                    while (!operators.empty() && operators.top()[0] != '(') {
                        res.push(operators.top());
                        operators.pop();
                    }
                } else {
                    throw runtime_error("Synthax error - function assignement - second part.");
                }
            } else {
                throw runtime_error("Synthax error - function assignement - first part.");
            }
            
        }
    }
    ++*i;
    return convertExpressionRecursive(expression, size, operators, res, i, list);
}
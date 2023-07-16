#include "convertion.h"

int priorite(char op) {
    switch(op) {
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
        case '=' :
            return 4;
        default :
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
stack<char>& operators,
stack<string>& res,
size_t* i, 
LinkedList list) {
    if (*i >= size) {
        while (!operators.empty()) {
            res.push(string(1,operators.top()));
            operators.pop();
        }
        return;
    }

    char e = expression[*i];
    if (isOperatorConversion(e) || islogicalOpConversion(e)) {
        while (!operators.empty() && operators.top() != '(' && priorite(e) <= priorite(operators.top())) {
            res.push(string(1,operators.top()));
            operators.pop();
        }
        operators.push(e);
    } else if (e == '(') {
        operators.push(e);
    } else if (e == ')') {
        while (!operators.empty() && operators.top() != '(') {
            res.push(string(1,operators.top()));
            operators.pop();
        }
        if (operators.empty() || operators.top() != '(') {
            throw runtime_error("Synthax error");
        }
        operators.pop();
        // Check if there is a functionName to insert
        if(list.getSize() > 0) {
            string name = list.deleteFirstElement();
            res.push(name);
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
        }
    }
    ++*i;
    return convertExpressionRecursive(expression, size, operators, res, i, list);
}
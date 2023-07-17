#include "process/process.h"
#include "convertion/convertion.h"

void freedMemory(char** expression, int size) {
    for(int i = 0; i < size; i++) {
        free(expression[i]);
    }
    free(expression);
}

int main(int argc, char* argv[]) {
    if(argc != 2) {
        cerr << "Not the correct number of arguments have been given." << endl;
        return 4;
    }

    // Preprocessing part
    int size = 0;
    char** expression = preprocessExpression(argv[1], &size);
    for(int x = 0; x < size; x++) {
        printf("%s", expression[x]);
    }
    cout << endl;

    // Convert part
    stack<string> res;
    for(int x = 0; x < size; x++) {
        stack<string> operators;
        LinkedList list;
        size_t size = getSize(expression[x]);
        size_t i = 0;
        convertExpressionRecursive(expression[x], size, operators, res, &i, list);
        res.push(string(1,';'));
    }
    
    stack<string> postfix = reverseStack(res);

    /*while(!postfix.empty()) {
        cout << postfix.top() << " | ";
        postfix.pop();
    }
    cout << endl;*/
    cout << "process part" << endl;

    // Processing part
    int result = processExpression(postfix);
    cout << result << endl;

    // Free memory here
    freedMemory(expression, size);
    return 0;
}
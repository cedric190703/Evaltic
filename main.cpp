#include "process/process.h"
#include "convertion/convertion.h"

int main(int argc, char* argv[]) {
    if(argc != 2) {
        cerr << "Not the correct number of arguments have been given." << endl;
        return 4;
    }
    // Preprocessing part
    char* expression = preprocessExpression(argv[1]);
    printf("%s\n", expression);

    // Convert part
    stack<char> operators;
    stringstream postfix;
    size_t size = getSize(expression);
    size_t i = 0;
    const char* convert  = convertExpressionRecursive(expression, size, operators, postfix, &i, 0);
    printf("%s\n", convert);

    // Processing part
    // TODO

    // Free memory here
    free(expression);
    return 0;
}

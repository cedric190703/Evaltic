#include "process/process.h"

int main(int argc, char* argv[]) {
    if(argc != 2) {
        cerr << "Not the correct number of arguments have been given." << endl;
        return 4;
    }
    // Preprocessing part
    char* expression = preprocessExpression(argv[1]);
    printf("%s\n", expression);

    // Processing part
    // TODO

    // Free memory here
    free(expression);
    return 0;
}

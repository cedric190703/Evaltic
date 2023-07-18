#include "process/process.h"
#include "convertion/convertion.h"

void freedMemory(char** expression, int size) {
    for(int i = 0; i < size; i++) {
        free(expression[i]);
    }
    free(expression);
}

int test(char* exp, int correctOut, int* output) {
    // Preprocessing part
    int size = 0;
    char** expression = preprocessExpression(exp, &size);

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

    // Get the reverse stack
    stack<string> postfix = reverseStack(res);

    // Processing part
    *output = processExpression(postfix);

    // Free memory
    freedMemory(expression, size);

    // Assert
    return (*output == correctOut) ? 1 : 0;
}

// In the case you just want to test one expression and prompt it to the program : 
int testOneExpression(int argc, char* argv[]) {
  if(argc != 3) {
        cerr << "Not the correct number of arguments have been given." << endl;
        return 4;
    }
    // Preprocessing part
    int size = 0;
    cout << endl;
    cout << "Preprocessing part :" << endl << endl;
    char** expression = preprocessExpression(argv[2], &size);
    for(int x = 0; x < size; x++) {
        printf("%s", expression[x]);
    }
    cout << endl << endl;
    cout << "----------------------" << endl << endl;

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
    
    // Displaying postfix stack part
    stack<string> postfix = reverseStack(res);
    cout << "Convert into a postix expression :" << endl << endl;
    stack<string> display(postfix);
    while(!display.empty()) {
        cout << display.top() << " | ";
        display.pop();
    }
    cout << endl << endl;
    cout << "----------------------" << endl << endl;
    cout << "process part :" << endl;

    // Processing part
    int result = processExpression(postfix);
    cout << endl;
    cout << "result -> " << result << endl;

    // Free memory here
    freedMemory(expression, size);
    return 0;
}

// We need 3 parameter in the case you just want to test an expression : (object name i.e(a.out) ) + 1(parameter) + expression
// We just need 2 otherwise : (object name i.e(a.out) ) + 0(parameter) or any other number
int main(int argc, char** argv) {
  if(argc < 2 || argc > 3) {
      cerr << "Not the correct number of arguments have been given." << endl;
      return 4;
  } else if(argv[1][0] == '1') {
    testOneExpression(argc, argv);
    return 0;
  }
  cout << argv[1][0] << endl;
  cout << "Tests for Abacus : " << endl;
  cout << "-----------------------------" << endl << endl;
  const int SIZE = 10;
  char* expressions[SIZE];
  int results[SIZE];

  // First expression
  const char* str = "7+9+1";
  expressions[0] = new char[strlen(str) + 1];
  results[0] = 17;
  strcpy(expressions[0], str);

  // Second expression
  str = "a = 53; b = 98; c = max(a,max(a,b))";
  expressions[1] = new char[strlen(str) + 1];
  results[1] = 98;
  strcpy(expressions[1], str);

  // Third expression
  str = "a = fibo(7); b = a + 14; c = max(b, (2>1 ? 42 : 2))";
  expressions[2] = new char[strlen(str) + 1];
  results[2] = 42;
  strcpy(expressions[2], str);

  // Fourth expression
  str = "a = (42 >= 42 ? 42 : 16);b = a + 5^2; c = max(a, b);";
  expressions[3] = new char[strlen(str) + 1];
  results[3] = 67;
  strcpy(expressions[3], str);

  // Fifth expression
  str = "a = (9/3)*4+5*(3+4)";
  expressions[4] = new char[strlen(str) + 1];
  results[4] = 47;
  strcpy(expressions[4], str);

  // Sixth expression
  str = "35+add(9+5,6)";
  expressions[5] = new char[strlen(str) + 1];
  results[5] = 55;
  strcpy(expressions[5], str);

  // Seventh expression
  str = "42+mul(5,5)+ sub(25,0)+add(42,0)+sub(83,0)";
  expressions[6] = new char[strlen(str) + 1];
  results[6] = 1;
  strcpy(expressions[6], str);

  // Eighth expression
  str = "(42+mul(5,5)+ sub(25,0)+add(42,0)+sub(83,0))*(42+mul(5,5)+ sub(25,0)+add(42,0)+sub(83,0)+1)+40";
  expressions[7] = new char[strlen(str) + 1];
  results[7] = 42;
  strcpy(expressions[7], str);

  // Ninth expression
  str = "(42+mul(5,5)+ sub(25,0)+add(42,0)+sub(83,0))*(42+mul(5,5)+ sub(25,0)+add(42,0)+sub(83,0)+1)+max(38+min(42,2),5)";
  expressions[8] = new char[strlen(str) + 1];
  results[8] = 42;
  strcpy(expressions[8], str);

  // Tenth expression
  str = "(42+mul(5,5)+ sub(25,0)+add(42,0)+sub(83,0))*(42+mul(5,5)+ sub(25,0)+add(42,0)+sub(83,0)+1)+40 - 42";
  expressions[9] = new char[strlen(str) + 1];
  results[9] = 0;
  strcpy(expressions[9], str);

  // Tests
  int correctOut = 0;
  int output;
  for(int i = 0; i < 10; i++) {
    char* e = expressions[i];
    int result = results[i];
    cout << "Test (" << i << "/" << SIZE << ") :" << endl;
    cout << "Expression : " << e << endl;
    cout << "-----------------------------" << endl;
    cout << "Expected result : " << result << endl;
    cout << "-----------------------------" << endl;
    if(test(e, result, &output)) {
      correctOut++;
      cout << "\t\t  \033[32m" << output << "\033[0m" << endl;
    } else {
      cout << "\t\t  \033[31m" << output << "\033[0m" << endl;
    }
    cout << "-----------------------------" << endl << endl;
  }
  cout << "Number of correct outputs : " << correctOut << "/" << SIZE << endl;

  // Free memory
  for (int i = 0; i < SIZE; ++i) {
    delete[] expressions[i];
  }
}
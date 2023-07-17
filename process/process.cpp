#include "process.h"

int evaluateFunction(string functionName, stack<int>& arguments) {
    // Check the number of parameters for each 
    if(functionName == "div") {
        if(arguments.size() >= 2) {
            int a = arguments.top();
            arguments.pop();
            int b = arguments.top();
            arguments.pop();
            return divi(a,b);
        } else {
            throw runtime_error("Synthax error - div");
        }
    } else if(functionName == "add") {
        if(arguments.size() >= 2) {
            int a = arguments.top();
            arguments.pop();
            int b = arguments.top();
            arguments.pop();
            return add(a,b);
        } else {
            throw runtime_error("Synthax error - add");
        }
    } else if(functionName == "sub") {
        if(arguments.size() >= 2) {
            int a = arguments.top();
            arguments.pop();
            int b = arguments.top();
            arguments.pop();
            return sub(a,b);
        } else {
            throw runtime_error("Synthax error - sub");
        }
    } else if(functionName == "mul") {
        if(arguments.size() >= 2) {
            int a = arguments.top();
            arguments.pop();
            int b = arguments.top();
            arguments.pop();
            return mul(a,b);
        } else {
            throw runtime_error("Synthax error - mul");
        }
    } else if(functionName == "mod") {
        if(arguments.size() >= 2) {
            int a = arguments.top();
            arguments.pop();
            int b = arguments.top();
            arguments.pop();
            return modulo(a,b);
        } else {
            throw runtime_error("Synthax error - mod");
        }
    } else if(functionName == "abs") {
        if(arguments.size() >= 1) {
            int a = arguments.top();
            arguments.pop();
            return abs(a);
        } else {
            throw runtime_error("Synthax error - abs");
        }
    } else if(functionName == "pow") {
        if(arguments.size() >= 2) {
            int a = arguments.top();
            arguments.pop();
            int b = arguments.top();
            arguments.pop();
            return power(a,b);
        } else {
            throw runtime_error("Synthax error - pow");
        }
    } else if(functionName == "exp") {
        if(arguments.size() >= 1) {
            int a = arguments.top();
            arguments.pop();
            return exp(a);
        } else {
            throw runtime_error("Synthax error - exp");
        }
    } else if(functionName == "log") {
        if(arguments.size() >= 1) {
            int a = arguments.top();
            arguments.pop();
            return log(a);
        } else {
            throw runtime_error("Synthax error - log");
        }
    } else if(functionName == "max") {
        if(arguments.size() >= 2) {
            int a = arguments.top();
            arguments.pop();
            int b = arguments.top();
            arguments.pop();
            return max(a,b);
        } else {
            throw runtime_error("Synthax error - max");
        }
    } else if(functionName == "min") {
        if(arguments.size() >= 2) {
            int a = arguments.top();
            arguments.pop();
            int b = arguments.top();
            arguments.pop();
            return min(a,b);
        } else {
            throw runtime_error("Synthax error - min");
        }
    } else {
        // Fibo
        if(arguments.size() >= 1) {
            int a = arguments.top();
            arguments.pop();
            return fibo(a);
        } else {
            throw runtime_error("Synthax error - fibo");
        }
    }
}

void setVar(string var, int val, map<string, int>& variables) {
    variables[var] = val;
}

int getVarRes(string var, map<string, int>& variables) {
    return variables[var];
}

int processExpression(stack<string> expression) {
    int res;
    vector<int> tab;
    stack<int> exp;
    map<string, int> variables;
    int lastVar;
    int stateVar = 0;
    string varToInit;
    while(!expression.empty()) {
        string e = expression.top();
        expression.pop();
        if(isdigit(e[0])) {
            tab.push_back(stoi(e));
        } else if(isalpha(e[0])) {
            if(isFunction(e)) {
                // Get the corresponding result of the function
                int res = evaluateFunction(e, exp);
                exp.push(res);
            } else {
                // Value used in an assignement
                string var = e;
                if(!expression.empty()) {
                    e = expression.top();
                    if(e[0] == '=') {
                        if(stateVar) {
                            throw runtime_error("Synthax error - variables assignement");
                        }
                        varToInit = var;
                        stateVar = 1;
                    } else {
                        tab.push_back(variables[var]);
                    }
                } else {
                    // Value used for assignement
                    // Check if the key exists
                    if(variables.count(e) == 0) {
                        throw runtime_error("Synthax error - variables already assigned in the box");
                    } else {
                        tab.push_back(variables[var]);
                    }
                }
            }
        } else if(e[0] == ';') {
            // Get variables
            if(stateVar) {
                int op = exp.top();
                exp.pop();
                lastVar = op;
                setVar(varToInit, op, variables);
                stateVar = 0;
            }
        } if(!tab.empty()) {
            while(!tab.empty()) {
                exp.push(tab.back());
                tab.pop_back();
            }
        } else if(exp.size() >= 2 && !isFunction(e)){
            int resu;
            int log;
            int op2 = exp.top();
            exp.pop();
            int op1;
            switch(e[0]) {
                 case '+':
                    op1 = exp.top();
                    exp.pop();
                    exp.push(op1 + op2);
                    break;
                case '-':
                    op1 = exp.top();
                    exp.pop();
                    exp.push(op1 - op2);
                    break;
                case '*':
                    op1 = exp.top();
                    exp.pop();
                    exp.push(op1 * op2);
                    break;
                case '^':
                    op1 = exp.top();
                    exp.pop();
                    resu = power(op1, op2);
                    exp.push(resu);
                    break;
                case '/':
                    op1 = exp.top();
                    exp.pop();
                    if(op2 == 0) {
                        throw invalid_argument("Logical error - division by 0.");
                    }
                    exp.push(op1 / op2);
                    break;
                case '?':
                    op1 = exp.top();
                    exp.pop();
                    if(op1 < 0 || op1 > 1) {
                        cout << op1 << endl;
                        throw invalid_argument("Syntax Error - ternary error (not a logical operation).");
                    } else {
                        if(op1) {
                            while(!expression.empty() && expression.top()[0] != ':') {
                                expression.pop();
                            }
                            if(expression.empty()) {
                                throw invalid_argument("Syntax Error - ternary error (not the correct syntax -> ?val1:val2).");
                            } else {
                                expression.pop();
                            }
                            exp.push(op2);
                        }
                    }
                    break;
                case ':':
                    // We are considering that here the statement is correct for ternary operations
                    // And the logical operation is false so we have to take the statement for the ':'
                    exp.push(op2);
                    break;
                case '%':
                    op1 = exp.top();
                    exp.pop();
                    if(op2 == 0) {
                        throw invalid_argument("Logical error - division by 0.");
                    }
                    exp.push(op1 % op2);
                    break;
                case '<':
                    op1 = exp.top();
                    exp.pop();
                    if(e == "<=") {
                        exp.push(op1 <= op2);
                    } else {
                        exp.push(op1 < op2);
                    }
                    break;
                case '>':
                    op1 = exp.top();
                    exp.pop();
                    if(e == ">=") {
                        exp.push(op1 >= op2);
                    } else {
                        exp.push(op1 > op2);
                    }
                    break;
                default:
                    op1 = exp.top();
                    exp.pop();
                    if(e == "!=") {
                        exp.push(op1 != op2);
                    } else if(e == "==") {
                        exp.push(op1 == op2);
                    } else {
                        cout << "-> " << e << " <-" << endl;
                        throw invalid_argument("Syntax Error - invalid operator");
                    }
            }
        }
    }
    if(!exp.empty()) {
        res = exp.top();
        exp.pop();
    } else {
        if(variables.size() > 0) {
            res = lastVar;
        } else {
            throw invalid_argument("Error");
        }
    }
    return res;
}
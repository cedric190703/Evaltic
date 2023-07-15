#pragma once
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <string.h>
#include "../Utils/utils.h"

using namespace std;

int priorite(char op);
void getFunExp(char& expresion, size_t idx, size_t size);
const char* convertExpressionRecursive(const string& expression, size_t size,
    stack<char>& operators, stringstream& postfix, size_t* i, int isFun);
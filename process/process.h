#pragma once
#include <map>
#include <stack>
#include <vector>
#include "../functions/functions.h"
#include "../preprocess/preprocess.h"

using namespace std;

int evaluateFunction(string functionName, stack<int>& arguments);
int isFunction(string e);
void setVar(string var, int val, map<string, int>& variables);
int getVarRes(string var, map<string, int>& variables);
int processExpression(stack<string> expression);
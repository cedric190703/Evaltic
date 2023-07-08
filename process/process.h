#pragma once
#include <map>
#include "../functions/functions.h"
#include "../preprocess/preprocess.h"

using namespace std;

int getFunctionResult(char* stc, size_t idx, size_t size);
int isFunction(char* stc, size_t idx, size_t size);
int getVarRes(char* var, map<string, int>);
int getTernary(char* stc, size_t idx, size_t size);
int getLogicalOp(char* stc, size_t idx, size_t size);
int processExpression(char* expression);

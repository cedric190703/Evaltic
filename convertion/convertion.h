#pragma once
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <string.h>
#include "../Utils/utils.h"
#include "../functions/functions.h"
#include "../LinkedList/LinkedList.h"

using namespace std;

int priorite(string op);
stack<string> reverseStack(stack<string> original);
int* resizeArrayFun(int* arr, int currentSize, int newSize);
void convertExpressionRecursive(
const string& expression,
size_t size,
stack<string>& operators,
stack<string>& res,
size_t* i, 
LinkedList list);
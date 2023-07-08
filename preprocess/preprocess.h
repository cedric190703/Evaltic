#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <cctype>
#include <iostream>

using namespace std;

size_t getSize(char* expression);
int getSign(char* expression, size_t* idx, size_t size);
int checkName(char* name);
int isOperator(char e);
char* getDigit(char* expression, size_t size);
int islogicalOperator(char e);

// Remove whitespace ->         3 + 4 => 3+4;
// Get sign -> +++-++-4 => 4 | ++---++-+---2 => -2;
// ---++++-++++--+-3 ---+++--++- 5 => -3-(-5);
// Check var -> a + 3 = Error
// Check funct -> minn(3,2) + max(2,6) => Error but MiN(3,2)       + MAx(2,6) => min(3,2)+max(3,2);
// Check ternary -> a = 2 > 3 : 3 : 5 => Error
// Sentence => a      =42;b = ---4 ++++4; a ++ b => a=42;b=-4+4;a+b;
// Error like this -> -aaa * min(3, ----2) => Error
// Logical operator -> 6===3 -> Error but -> --++-6== ---++--3 -> -6==-3;
// Add a ; at the end for the process part
// If mutliple ;; -> 3++--+4 ;;; => Error
// Correct -> -a = 42; => in the next part -> a = -42
char* preprocessExpression(char* expression);
# Abacus
This project is about to reproduce Abacus for operations.

<pre>
*operation :
-Operator : + - * / %
-Logical : (&& || == !=) -> 1 if true 0 otherwize
-Ternary : condition ? a : b

*Parentheses : ()

*functions:
-div(a, b)
-add(a, b)
-mul(a, b)
-sous(a ,b)
-modulo(a ,b)
-abs(a)
-pow(a ,b)
-exp(a)
-log(a)
-log10(a)
-max(a, b)
-min(a, b)
-fibo(a)

*variables : a = 5

*Errors :
0 -> No error 
1 -> Syntax Error
2 -> Logical error (undefined variables/symbols and invalid function calls/parentheses error)
3 -> Math error (division by 0)

Evaluate expressions with ; to tell the end of a 'line of code' like :
=>a = 4; b = a +42; c = a * min(a,b) =>184
</pre>

<pre>
Structure of the project :

.
├── functions
│   ├── functions.cpp
│   └── functions.h
├── main.cpp
├── Makefile
├── preprocess
│   ├── preprocess.cpp
│   └── preprocess.h
├── process
│   ├── process.cpp
│   └── process.h
└── README.md

3 directories, 9 files
</pre>
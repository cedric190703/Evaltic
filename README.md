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
</pre>

Example of expression :
<pre>
a = 4; b = a +42; c = a * max(a,b);
OUTPUT :
Preprocessing part :

a=4b=a+42c=a*max(a,b)

----------------------

Convert into a postix expression :

a | = | 4 | = | ; | b | = | a | 42 | + | = | ; | c | = | a | a | b | max | * | = | ; | ; | 

----------------------

process part :

result -> 184
</pre>

Structure of the project :
<pre>
.
├── convertion
│   ├── convertion.cpp
│   └── convertion.h
├── functions
│   ├── functions.cpp
│   └── functions.h
├── LinkedList
│   ├── LinkedList.cpp
│   └── LinkedList.h
├── main.cpp
├── Makefile
├── preprocess
│   ├── preprocess.cpp
│   └── preprocess.h
├── process
│   ├── process.cpp
│   └── process.h
├── README.md
└── Utils
    ├── utils.cpp
    └── utils.h

6 directories, 15 files
</pre>

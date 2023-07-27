# Evaltic
<pre>
This project has 3 parts :
1 => Preprocessing on the expression to cleanup the expression or detect a potential error.

2 => Shunting yard for converting the arrays of expression from the preprocessing part into a postfix expression.

3 => Evaluate the postfix expression to give the result.

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

<pre>
This project also got a test suite for multiple examples for testing the code :

example of it :
Tests for Evaluation : 
-----------------------------

Test (0/10) :
Expression : 7+9+1
-----------------------------
Expected result : 17
-----------------------------
                  17
-----------------------------

Test (1/10) :
Expression : a = 53; b = 98; c = max(a,max(a,b))
-----------------------------
Expected result : 98
-----------------------------
                  98
-----------------------------

Test (2/10) :
Expression : a = fibo(7); b = a + 14; c = max(b, (2>1 ? 42 : 2))
-----------------------------
Expected result : 42
-----------------------------
                  42
-----------------------------

Test (3/10) :
Expression : a = (42 >= 42 ? 42 : 16);b = a + 5^2; c = max(a, b);
-----------------------------
Expected result : 67
-----------------------------
                  67
-----------------------------

Test (4/10) :
Expression : a = (9/3)*4+5*(3+4)
-----------------------------
Expected result : 47
-----------------------------
                  47
-----------------------------

Test (5/10) :
Expression : 35+add(9+5,6)
-----------------------------
Expected result : 55
-----------------------------
                  55
-----------------------------

Test (6/10) :
Expression : 42+mul(5,5)+ sub(25,0)+add(42,0)+sub(83,0)
-----------------------------
Expected result : 1
-----------------------------
                  1
-----------------------------

Test (7/10) :
Expression : (42+mul(5,5)+ sub(25,0)+add(42,0)+sub(83,0))*(42+mul(5,5)+ sub(25,0)+add(42,0)+sub(83,0)+1)+40
-----------------------------
Expected result : 42
-----------------------------
                  42
-----------------------------

Test (8/10) :
Expression : (42+mul(5,5)+ sub(25,0)+add(42,0)+sub(83,0))*(42+mul(5,5)+ sub(25,0)+add(42,0)+sub(83,0)+1)+max(38+min(42,2),5)
-----------------------------
Expected result : 42
-----------------------------
                  42
-----------------------------

Test (9/10) :
Expression : (42+mul(5,5)+ sub(25,0)+add(42,0)+sub(83,0))*(42+mul(5,5)+ sub(25,0)+add(42,0)+sub(83,0)+1)+40 - 42
-----------------------------
Expected result : 0
-----------------------------
                  0
-----------------------------

Number of correct outputs : 10/10
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

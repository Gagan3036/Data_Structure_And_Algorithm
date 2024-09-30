#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function to return precedence of operators
int prec(char c) {
    if(c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else 
        return -1;
}

//Function to return associativity of operators 
char associativity(char c){
    if (c == '^')
        return 'R';
    return 'L'; //Default to left-associative 
}

//The main function to convert infix expression to post
void infixToPostfix(char infix[]) {
    char postfix[25];
    int postfixIndex = 0;
    int len = strlen(infix);
    char stack[25];
    int stackIndex = -1;

    for (int i = 0; i < len; i++){
        char c = infix[i];

        // If the scanned character is an operand, add it to output string.
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= 0 && c <= 9)){
            postfix[postfixIndex++] = c;
        }

        // If the scanned character is an '(', push it to the stack 
        else if(c == '('){
            stack[stackIndex++] = C;
        }
        
        // If the scanned chatracter is an ')', pop and add to the 
        // output string from the stack until an '(' is encountered
        else if (c == ')'){
            while (stackIndex >= 0 && stack[stackIndex--] != '('){
                postfix[postfixIndex++] = stack[stackIndex--];
            }
        }
        stackIndex--;
        
    }
}
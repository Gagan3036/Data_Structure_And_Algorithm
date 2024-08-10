/*Complilation code:

gcc PostfixEvaluation.c -o PostfixEvaluation -lm

./PostfixEvaluation
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define max 100

float st[max];
int top = -1;

void push(float st[], float val);
float pop(float st[]);
float EvaluatePostfix(char exp[]);

int main() {
    float val;
    char exp[100];

    printf("\nEnter any postfix expression: ");
    fgets(exp, sizeof(exp), stdin);
    // Remove the newline character if present
    exp[strcspn(exp, "\n")] = 0;

    val = EvaluatePostfix(exp);
    printf("\nResult: %f\n", val);

    return 0;
}

float EvaluatePostfix(char exp[]) {
    int i = 0;
    float op1, op2, value;

    while (exp[i] != '\0') {
        if (isdigit(exp[i])) {
            push(st, (float)(exp[i] - '0'));
        } else if (exp[i] == ' ') {
            // Skip spaces if the input is space-separated
            i++;
            continue;
        } else {
            op1 = pop(st);
            op2 = pop(st);

            switch (exp[i]) {
                case '+':
                    value = op1 + op2;
                    break;
                case '-':
                    value = op2 - op1; // Corrected the order
                    break;
                case '*':
                    value = op1 * op2;
                    break;
                case '/':
                    value = op2 / op1; // Corrected the order
                    break;
                case '%':
                    value = fmod(op2, op1); // Corrected the order
                    break;
                default:
                    printf("Unexpected character: %c\n", exp[i]);
                    return -1;
            }
            push(st, value);
        }
        i++;
    }
    return pop(st);
}

void push(float st[], float val) {
    if (top == max - 1) {
        printf("\nOverflow");
    } else {
        top++;
        st[top] = val;
    }
}

float pop(float st[]) {
    if (top == -1) {
        printf("\nUnderflow");
        return -1;
    } else {
        float val = st[top];
        top--;
        return val;
    }
}

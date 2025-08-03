#include <stdio.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

void infixToPostfix(char* exp, char* postfix) {
    int i, j = 0;
    for (i = 0; exp[i]; i++) {
        if (exp[i] >= 'a' && exp[i] <= 'z') {
            postfix[j++] = exp[i];
        } else if (exp[i] == '(') {
            push(exp[i]);
        } else if (exp[i] == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop();
        } else if (isOperator(exp[i])) {
            while (top >= 0 && precedence(stack[top]) >= precedence(exp[i])) {
                postfix[j++] = pop();
            }
            push(exp[i]);
        }
    }
    while (top >= 0) postfix[j++] = pop();
    postfix[j] = '\0';
}

int main() {
    char exp[] = "a+b*(c-d)";
    char postfix[100];
    infixToPostfix(exp, postfix);
    printf("Postfix: %s\n", postfix);
    return 0;
}

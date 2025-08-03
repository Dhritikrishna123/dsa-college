#include <stdio.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }

int isBalanced(char* exp) {
    for (int i = 0; exp[i]; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (top == -1) return 0;
            char open = pop();
            if ((exp[i] == ')' && open != '(') ||
                (exp[i] == '}' && open != '{') ||
                (exp[i] == ']' && open != '[')) {
                return 0;
            }
        }
    }
    return top == -1;
}

int main() {
    char exp[] = "({[]})";
    printf("%s\n", isBalanced(exp) ? "Balanced" : "Not Balanced");
    return 0;
}

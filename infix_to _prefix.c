//infix to prefix conversion
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char s[50]; 
int t = -1;

void push(char x) { if (t < 49) s[++t] = x; }
char pop() { return (t > -1) ? s[t--] : '\0'; }
char seek() { return (t > -1) ? s[t] : '#'; }

int input_prec(char ch) {
    switch(ch) {
        case '+': case '-': return 1;
        case '*': case '/': return 3;
        case '^': return 6;
        case ')': return 9; case '(': return 0; 
        default: return 7; 
    }
}
int stack_prec(char ch) {
    switch(ch) {
        case '+': case '-': return 2;
        case '*': case '/': return 4;
        case '^': return 5;
        case ')': return 0; case '#': return -1;
        default: return 8;
    }
}

void reverse_str(char str[]) {
    int n = strlen(str);
    for(int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - 1 - i];
        str[n - 1 - i] = temp;
    }
}
void swap_parenthesis(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') str[i] = ')';
        else if (str[i] == ')') str[i] = '(';
    }
}

void infix_to_postfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    t = -1; push('#');
    
    while(infix[i] != '\0') {
        char ch = infix[i];
        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else {
            while(stack_prec(seek()) > input_prec(ch))
                postfix[j++] = pop();
            if(stack_prec(seek()) != input_prec(ch))
                push(ch);
            else pop();
        }
        i++;
    }
    while(seek() != '#')
        postfix[j++] = pop();
    postfix[j] = '\0';
}

int main() {
    char infix[50], temp[50], prefix[50];
    
    printf("Enter infix expression (max 49 chars): ");
    scanf("%s", infix);
    
    strcpy(temp, infix);
    reverse_str(temp);
    
    swap_parenthesis(temp); 
    
    infix_to_postfix(temp, prefix);
    
    reverse_str(prefix);
    
    printf("Prefix expression: %s\n", prefix);
    
    return 0;
}

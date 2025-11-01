//evaluates a postfix expression 
#include <stdio.h>
#include <stdlib.h>

int eval(char[]);
void push(int);
int pop();
int isoperator(char);

int s[10];
int t = -1;

int main()
{
    char postfix[10];
    int x;
    
    printf("\nEnter a valid postfix expression: ");
    scanf("%s", postfix);
    x = eval(postfix);
    printf("The result is...%d", x);
    return 0;
}

int eval(char postfix[])
{
    int i = 0;
    char ch;
    int x, y, z;
    
    while((ch = postfix[i++]) != '\0')
    {
        if (isoperator(ch))
        {
            x = pop();
            y = pop();
            
            switch(ch)
            {
                case '+': z = y + x; break;
                case '-': z = y - x; break;
                case '*': z = y * x; break;
                case '/': z = y / x; break;
                case '^': 
                    z = 1;
                    for(int i = 0; i < x; i++) 
                        z *= y;
                    break;
            }
            push(z);
        }
        else 
        {
            push(ch - '0');
        }
    }
    return pop();
}

int isoperator(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^': return 1;
        default: return 0;
    }
}

void push(int x)
{
    s[++t] = x;
}

int pop()
{
    return s[t--];
}
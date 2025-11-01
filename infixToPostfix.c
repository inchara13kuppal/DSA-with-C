#include <stdio.h>
#include <stdlib.h>


int input_prec(char );
int stack_prec(char);
void convert_infix_to_postfix(char [],char []);
void push(char);
char pop();
char seek();
int is_operand(char); 

char s[20]; 
int t = -1; // Global stack top initialized to -1

void main()
{
    char infix[20], postfix[20];
    
    push('#'); // Initialize stack with '#' sentinel
    
    printf("\nEnter a valid infix expression");
    scanf("%s", infix);
    
    convert_infix_to_postfix(infix, postfix);
    
    printf("The postfix form of the infix expression is...%s", postfix);
}

void convert_infix_to_postfix(char infix[], char postfix[])
{ 
    int i = 0, j = 0;
    char next;

    while((next = infix[i]) != '\0')
    {
        if (is_operand(next)) // Case 1: Operands (go directly to postfix)
        {
            postfix[j++] = next;
        }
        else if (next == '(') // Case 2: Opening Parenthesis (pushed)
        {
            push(next);
        }
        else if (next == ')') // Case 3: Closing Parenthesis (pops until '(')
        {
            while(seek() != '(')
                postfix[j++] = pop();
            pop(); // Discard the '('
        }
        else // Case 4: Operator (+, -, *, /, ^)
        {
            // Pop stack operators with HIGHER or EQUAL precedence
            while(stack_prec(seek()) >= input_prec(next)) 
            {
                postfix[j++] = pop();
            }
            push(next); // Push the current operator
        }
        i++;
    }

    // Empty the remaining stack to the postfix string
    while(seek() != '#')
        postfix[j++] = pop();
        
    postfix[j] = '\0'; // Null-terminate the postfix string
}

int is_operand(char ch) {
    // Defines what an operand is (letters or digits)
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9');
}

int input_prec(char ch)
{
    // Input precedence (used when the operator is in the INFIX expression)
    switch(ch)
    { 
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 3;
        case '^': return 6;
        case '(': return 9; // High value ensures it's pushed
        case ')': return 0;
        default : return 7;
    } 
}
   
int stack_prec(char ch)
{
    // Stack precedence (used when the operator is on the STACK)
    switch(ch)
    {
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 4;
        case '^': return 5; // Lower than input (6) for right-associativity
        case '(': return 0; // Low value ensures operators pop over it
        case '#': return -1;
        default : return 8;
    }
} 
 
void push(char x)
{
    s[++t] = x;
}

char pop()
{
    return (s[t--]);
}

char seek()
{
    if (t < 0) return '#'; 
    return (s[t]);
}
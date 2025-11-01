#include <stdio.h>
#include <stdlib.h>

int check_parenthesis(char []);
char pop(char[],int*);
void push(char [],int *,char );
int isempty(int);

void main()
{ 
  int res;
  char exp[10];
  
 printf("Enter a valid expression ( only with parenthesis)..");
 scanf("%s",exp);
 res=check_parenthesis(exp);
 
 if(res)printf("Valid Expression");
 else printf("Invalid Expression");
 
}

int check_parenthesis(char exp[])
{ int i=0,t=-1; 
  char stk[10];
  char ch,x;
  while(exp[i]!='\0')
  {   ch=exp[i];
      switch(ch)
	  {
		case '(':
		case '[':
        case '{': push(stk,&t,ch);break;
		
		case ')': if(!isempty(t))
                     {
                      x =pop(stk,&t);
                      if(x != '(') return 0;
                      }
					 else {return 0;}break;	
		case ']': if(!isempty(t))
                     {
                      x =pop(stk,&t);
                      if(x != '[') return 0;
                     }
					 else {return 0;}break;	
		case '}': if(!isempty(t))
                     {
                      x =pop(stk,&t);
                      if(x != '{') return 0;
                     }	
                     else {return 0;}break;			
        default: return 0;			 
	  }
	  i++; 
   } return isempty(t);
}

void push(char s[],int *t,char ch)
{
   (*t)++;
  s[*t]=ch;
}

char pop(char s[],int *t)
{
  char x=s[*t];
       (*t)--;
  return x;
}

int isempty(int t)
{
	if(t==-1)
		return 1;
	return 0;
}

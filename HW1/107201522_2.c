#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>

#define BLANK ' '
#define TAB '\t'
#define MAX 100

void push(float symbol);
float pop();
void infix_to_postfix();
float eval_post(float result);
int priority(char symbol);
int isEmpty();
int white_space(char );

char infix[MAX], postfix[MAX];
float stack[MAX];
int top;

int main()
{
        top=-1;
        float value,result;
        gets(infix);
        infix_to_postfix();
        printf(">");
        for(int i=0;i<strlen(postfix);i++)
        {
            printf(" %c",postfix[i]);
        }
        printf("\n");
        value = eval_post(result);
        float fvalue=roundf(value);
        int ac = (int)fvalue;
        printf("> %d",ac);

        return 0;
}/*End of main()*/

void infix_to_postfix()
{
        unsigned int i,p=0;
        char next;
        char symbol;
        for(i=0;i<strlen(infix);i++)
        {
                symbol=infix[i];
                if(!white_space(symbol))
                {
                        switch(symbol)
                        {
                        case '(':
                                push(symbol);
                                break;
                        case ')':
                                while((next=pop())!='(')
                                        postfix[p++] = next;
                                break;
                        case '+':
                        case '-':
                        case '*':
                        case '/':
                                while( !isEmpty( ) &&  priority(stack[top])>= priority(symbol) )
                                        postfix[p++]=pop();
                                push(symbol);
                                break;
                        default: /*if an operand comes*/
                             postfix[p++]=symbol;
                        }
                }
        }
        while(!isEmpty( ))
                postfix[p++]=pop();
         /*End postfix with'\0' to make it a string*/
}/*End of infix_to_postfix()*/

/*This function returns the priority of the operator*/
int priority(char symbol)
{
        switch(symbol)
        {
        case '(':
                return 0;
        case '+':
        case '-':
                return 1;
        case '*':
        case '/':
                return 2;
        default :
                return 0;
        }
}/*End of priority()*/

void push(float symbol)
{
        if(top>MAX)
        {
                printf("Stack overflow\n");
                exit(1);
        }
        stack[++top]=symbol;
}/*End of push()*/

float pop()
{
        if( isEmpty() )
        {
                printf("Stack underflow\n");
                exit(1);
        }
        return (stack[top--]);
}/*End of pop()*/
int isEmpty()
{
        if(top==-1)
                return 1;
        else
                return 0;
}/*End of isEmpty()*/

int white_space(char symbol)
{
        if( symbol == BLANK || symbol == TAB )
                return 1;
        else
                return 0;
}/*End of white_space()*/

float eval_post(float result)
{
        float a,b;
        float temp;
        unsigned int i;

        for(i=0;i<strlen(postfix);i++)
        {
                if(postfix[i]<='9' && postfix[i]>='0')
                        push(postfix[i]-'0');
                else
                {
                        a=pop();
                        b=pop();
                        switch(postfix[i])
                        {
                        case '+':
                                temp=b+a;break;
                        case '-':
                                temp=b-a;break;
                        case '*':
                                temp=b*a;break;
                        case '/':
                                temp=b/a;break;
                        }
                        push(temp);
                }
        }
        result=pop();
        return result;
}/*End of eval_post */

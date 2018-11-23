#include <stdio.h>
#include <string.h>
#define max_length 100

struct stack
{
    char array[max_length];
    int top;
};

int is_full(struct stack);
int empty(struct stack);
void push(struct stack *, char);
void pop(struct stack *);
char know_top(struct stack );
int is_number(char );
int priority(char);


int main()
{
    char input[max_length];
    gets(input);
    int lastone=strlen(input)-1;

    struct stack s;
    s.top = -1; 


    char temp[max_length];   
    int i = 0;
    char ch;
    while(lastone != -1)
    {
        ch = input[lastone--];
        if(is_number(ch))  
            temp[i++] = ch;
        else if(ch == ')')  
        {
        	push(&s, ch);
        }
        else if(ch == '(')
        {
            while(know_top(s) != ')')
            {
                temp[i++] = know_top(s); 
                pop(&s);
            }
            pop(&s);    //pop the ')'
        }
        else if(ch == ' ')
        {
        	temp[i++] = ' ';
        	continue;
		}
        else
        {
            if(s.top == -1) //first letter directly output
                push(&s, ch);
            else if(priority(know_top(s)) <= priority(ch)) 
			{   // ISP <= ICP
				//temp[i++] = know_top(s);
				//pop(&s);
                push(&s, ch);
            }
            else
            {
                while(priority(know_top(s)) > priority(ch))   // ISP <ICP
                {
                    temp[i++] = know_top(s);
                    //push(&s, ch);
					pop(&s);
                    
                }
                push(&s, ch);
            }
        }
    }
    
	while(s.top != -1)  
    {
        temp[i++] = know_top(s);
        pop(&s);
    }

    for(i--; i>=0; i--) 
        printf("%c", temp[i]);


    return 0;
}


int is_full(struct stack s)
{
    if(s.top == max_length-1)
        return 1;
    else
        return 0;
}
int empty(struct stack s)
{
    if(s.top == -1)
        return 1;
    else
        return 0;
}

void push(struct stack *s, char element)
{
    if(!is_full(*s))
    {
        s->top++;
        s->array[s->top] = element;
    }
}
void pop(struct stack *s)
{
    if(!empty(*s))
        s->top--;
}

char know_top(struct stack s)
{
    return s.array[s.top];
}

int is_number(char c)
{
    if('0'<=c && c<='9')
        return 1;
    else
        return 0;
}


int priority(char ch)
{
    if(ch=='+' || ch =='-')
        return 1;
    else if(ch=='*' || ch=='/' || ch=='%')
        return 2;
    else if(ch=='!' || ch=='&' || ch=='~')
        return 3;        
    else if(ch=='(' || ch=='.' )
        return 4;
    else
        return 0;
}


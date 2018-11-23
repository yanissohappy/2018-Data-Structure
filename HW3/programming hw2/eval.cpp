#include <stdlib.h>
#include <string>
#include <string.h>
#define max_size 100
 
struct stack
{
  int top;
  int array[max_size];
};
void push(stack *,int);
int pop(stack *);
int top(stack *);
bool empty(stack *);
bool eval(stack *,char);

int main()
{
  	char input[max_size];
  	int weight;
  	
    while(gets(input))
    {
        stack s;
        s.top=-1; //initialize s
        int temp_num =0;
        int flag=0;
        int lastone=strlen(input)-1; //the last number in an array.

        for(;lastone>=0;lastone--)
        {
            if(flag)
			break;
            
            if((input[lastone]=='+')||(input[lastone]=='-')||(input[lastone]=='*')||(input[lastone]=='/')){
			    if(!eval(&s,input[lastone]))
                {
                    printf("Wrong input.\n");
                    flag = 1;
                    continue;
                }
            }                
            else if(input[lastone]==' '){			
            	continue;
            }            	
            else{          
            	weight=1;//If the number is 10000, I will parse it until I encounter ªÅ¥ÕÁä. 
                while(input[lastone]>='0' && input[lastone]<='9')
                {
                    temp_num = temp_num + (input[lastone]-'0')*weight;
                    weight*=10;
                    lastone--;
                }
                push(&s,temp_num);
                temp_num=0;  
				continue; 
			}
        }
        
        
        if(!flag)
        {
            printf("%d\n",top(&s));
        }
    }
    return 0;
}

void push(stack *s,int num)
{
    s->top++;
    s->array[s->top]=num;
}

int pop(stack *s)
{
    int num;
    
    num=s->array[s->top];
    s->top--;
    return num;
}

int top(stack *s)
{
	return s->array[s->top];
}

bool empty(stack *s)
{
    if(s->top==-1)return true;
    return false;
}

bool eval(stack *s,char op)
{
    int result;
    if(empty(s))return false;
    int num1 = pop(s);
    if(empty(s))return false;
    int num2 = pop(s);
	switch(op)
	{
		case '+': result=num1+num2;
		break;
		case '-': result=num1-num2;
		break;
		case '*': result=num1*num2;
		break;
		case '/': 
		if(num2!=0){
			result=num1/num2;
		}
		else{
			printf("Please don't use zero as Denominator!\n");
			return false;
		}
		break;
	}
    push(s,result);
    return true;
}

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>

#define size 100

struct deque
{
    int arr[size];
    int front;
    int rear;
};

void shift(struct deque *);
void push(struct deque *, int, int);
void pop(struct deque *, int);
int push_front_number(char str[size]);
int push_back_number(char str[size]);

int main()
{
    struct deque q;
    int mode = 0;
    int direction;
    int i;
    int number;
    char str[size]={};

    q.front = -1;   //initialization
    q.rear = -1;
    
	do{
	gets(str); //read line.
	
	if((str[0]=='p')&&(str[1]=='u')&&(str[2]=='s')&&(str[3]=='h')&&(str[4]=='_')&&(str[5]=='f')&&(str[6]=='r')&&(str[7]=='o')&&(str[8]=='n')&&(str[9]=='t'))
	{//push_front
		mode=1;
		direction=1; //from left
		number=push_front_number(str);
	}
	
	if((str[0]=='p')&&(str[1]=='u')&&(str[2]=='s')&&(str[3]=='h')&&(str[4]=='_')&&(str[5]=='b')&&(str[6]=='a')&&(str[7]=='c')&&(str[8]=='k'))
	{//push_back
		mode=1;
		direction=2; //from right
		number=push_back_number(str);
	}	
	
	if((str[0]=='p')&&(str[1]=='o')&&(str[2]=='p')&&(str[3]=='_')&&(str[4]=='f')&&(str[5]=='r')&&(str[6]=='o')&&(str[7]=='n')&&(str[8]=='t'))
	{//pop_front 
		mode=2;
		direction=1; //from left
	}		
	
	if((str[0]=='p')&&(str[1]=='o')&&(str[2]=='p')&&(str[3]=='_')&&(str[4]=='b')&&(str[5]=='a')&&(str[6]=='c')&&(str[7]=='k'))
	{//pop_back 
		mode=2;
		direction=2; //from right
	}	
		
	if((str[0]=='s')&&(str[1]=='h')&&(str[2]=='o')&&(str[3]=='w'))
	{//pop_back 
	    while(q.front < q.rear)
	        printf("%d ", q.arr[++q.front]);
	}				
	
    if(q.front == -1 && q.rear == size-1 && mode == 1)   //check full
    {
        puts("Array is full.");
    }
    
    if(q.front == -1 && q.rear == -1 && mode == 2)   //check no item
    {
        puts("Array has no items.");
    }

    if(mode == 1)   //push
    {
        push(&q, number, direction);
    }
    else if(mode == 2)    //pop
    {
        pop(&q, direction);
    }
	
	}while(!((str[0]=='s')&&(str[1]=='h')&&(str[2]=='o')&&(str[3]=='w')));	

    return 0;
}

void shift(struct deque *q)
{
    int i;  
    for(i=q->rear; i>q->front; i--)
        q->arr[i+1] = q->arr[i];
    q->front=q->front+1;
    q->rear=q->rear+1;
}

void push(struct deque *q, int number, int dir)
{
	if(!(q->front == -1 && q->rear == size-1))
	{
	    if(dir == 1)    //left
	    {
	        if(q->front == -1)
	            shift(q);
	        q->arr[q->front--] = number;
	    }
	    else    //right
	    {
	        q->arr[++q->rear] = number;
	    }
	}
}

void pop(struct deque *q, int dir)
{
    if(q->front != q->rear) //check no item
    {
        if(dir == 1)
        	q->front=q->front+1;
        else
            q->rear=q->rear-1;
    }
}

int push_front_number(char str[size])
{
	int lastone=strlen(str)-1;
	int weight=1;
	int temp_num =0;
	for(;lastone>=11;lastone--){
	    while(str[lastone]>='0' && str[lastone]<='9' && str[lastone]!=' ')
	    {
	        temp_num = temp_num + (str[lastone]-'0')*weight;
	        weight*=10;
	        lastone--;
	    }
	}
	return temp_num;
}

int push_back_number(char str[size])
{
	int lastone=strlen(str)-1;
	int weight=1;
	int temp_num =0;
	for(;lastone>=10;lastone--){
	    while(str[lastone]>='0' && str[lastone]<='9' && str[lastone]!=' ')
	    {
	        temp_num = temp_num + (str[lastone]-'0')*weight;
	        weight*=10;
	        lastone--;
	    }
	}
	return temp_num;
}

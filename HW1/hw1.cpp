#include <stdio.h>
#include <stdlib.h>

int fibonacci_recursion(int);
int fibonacci_iteration(int);

int main(){

	int num;
	int index;
	scanf("%d", &num); // counting number of the loops
	for(int i=0; i<num; i++)
	{
	scanf("%d", &index);	
	printf("%d ",fibonacci_recursion(index));
	printf("%d\n",fibonacci_iteration(index));
	}
	return 0;
}

int fibonacci_recursion(int n) 
{ 
   if (n <= 1) 
      return n; 
   return fibonacci_recursion(n-1) + fibonacci_recursion(n-2); 
} 

int fibonacci_iteration(int n)
{
    int first = 0;
    int second = 1;
    int final;
 
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
 
    for(int i=0; i<=(n-2); i++)
    {
        final = first + second;
        first = second;
        second = final;
    }
    return final;
}

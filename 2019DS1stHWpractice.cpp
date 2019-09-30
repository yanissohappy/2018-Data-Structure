#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int used[10]; 
int total_size = 0;
char *array[10];
int split(char **arr, char *str, const char *del);
void print_set();
void recursion(int index);

int main(){
	char str[1000]={};
	int i = 0;
	
	for(i=0; i < 10; ++i) used[i] = 0;
	
	gets(str);
	
	total_size = split(array, str, " ");
	recursion(0);
	return 0;
}

int split(char **arr, char *str, const char *sign) {
   int counter = 0;
   char *s = strtok(str, sign);
  
   while(s != NULL) {
     *arr++ = s;
     s = strtok(NULL, sign);
     counter++;
   }
   return counter;
}


void print_set(){
    int i;
    printf("{ ");
    
    for(i = 0; i < total_size; ++i){
    	if(used[i]) printf("%s ", array[i]);
	}
    printf("} ");
}

void recursion(int index)
{
    int i;
    if(index == total_size) {       
        print_set();         
    } else {
        used[index]=0;   
        recursion(index + 1); 
        used[index]=1;   
        recursion(index + 1); 
    }
}


#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>

void search_change_array(int arr[100],int modified,int new_key);
void swap(int &p1, int &p2);
void MaxHeapify(int array[100], int root, int length);
int HowManyInArray(int arr[100]);
void print_arr(int arr[100],int count);


int main()
{
	
	char str[10000]={};
	int arr[100]={0};
	int t,i=0;
	int index = 0;
	int be_modified;
	int new_key;
	
	for(int i=0;i<100;i++)
	{
		arr[i]=-9999999;
	}	
	
	gets(str);//get first line	
	char *p = strtok(str, " ");	
	
	while (p != NULL && index < 100) {
	  arr[index++] = atoi(p);
	  p = strtok(NULL, " ");
	}
	
	gets(str);//get secone line	
	p = strtok(str, " ");
	be_modified=atoi(p);//get the number will be modified
	p = strtok(NULL, " ");
	new_key=atoi(p);

	search_change_array(arr,be_modified,new_key);
	print_arr(arr,HowManyInArray(arr));	

    return 0;
}

void search_change_array(int arr[100],int modified,int new_key)
{
	int i=0;
	for(i=0;i<100;i++)
	{
		if(arr[i]==modified){
		arr[i]=new_key;
		break;
		}
	}
	
	MaxHeapify(arr,i, HowManyInArray(arr));
	
	while(arr[i]>arr[(i-1)/2] && i>=0)
	{
		MaxHeapify(arr,(i-1)/2, HowManyInArray(arr));
		i=(i-1)/2;
	}
}

int HowManyInArray(int arr[100])
{
	int count=0;
	for(int i=0;i<100;i++)
	{
		if(arr[i]!=-9999999)
		count++;
			
		if(arr[i]<=-9999999)
		break;
	}
	return count;	
}

void swap(int &p1, int &p2)
{
    int temp = p1;
    p1 = p2;
    p2 = temp;
}

void MaxHeapify(int array[100], int root, int length)
{

    int left = 2*root+1;      
    int right = 2*root + 2;     
    int largest;                

    if (left <= length && array[left] > array[root])
        largest = left;
    else
        largest = root;

    if (right <= length && array[right] > array[largest])
        largest = right;

    if (largest != root) {                         
        swap(array[largest], array[root]);         
        MaxHeapify(array, largest, length);        
    }
}

void print_arr(int arr[100],int count)
{
	for(int i=0;i<count;i++)
	{
		printf("%d ",arr[i]);
	}
}


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

bool all_is_ok1(int count1[15][15]);
bool all_is_ok2(int count2[39][19]);
bool isroomavail1(int, int);
bool isroomavail2(int, int);
bool ismoveavail1(int, int*, int*); 
bool ismoveavail2(int, int*, int*); 
int counter1=0;
int counter2=0;
int imove[8]={-1,0,1,1,1,0,-1,-1};
int jmove[8]={1,1,1,0,-1,-1,-1,0};

int main()
{
	srand ((unsigned) time (NULL));
	int count1[15][15]={0};
	int count2[39][19]={0};
	int spbugi1=10, spbugj1=10, spbugi2=1, spbugj2=1;
	int randnum=0;
	int step_count1=0, step_count2=0;
	int* ibug1=&spbugi1;
	int* jbug1=&spbugj1;
	int* ibug2=&spbugi2;
	int* jbug2=&spbugj2;
	int i, j;
	

	/* I found imove and jmove mean
		6	7	0
		5	ij	1
		4	3	2	
	*/
	
	while( (all_is_ok1(count1)==false) && (counter1 < 50000) )
	{
		do
		{
			randnum = rand()%8;
		} while( ismoveavail1(randnum, ibug1, jbug1)==0 ); // To choose a right postion
		count1[*ibug1][*jbug1]++;
		counter1++;
		step_count1++;
	}
	
	while( (all_is_ok2(count2)==false) && (counter2 < 50000) )
	{
		do
		{
			randnum = rand()%8;
		} while( ismoveavail2(randnum, ibug2, jbug2)==0 );
		count2[*ibug2][*jbug2]++;
		counter2++;
		step_count2++;
	}	
	
	printf("Experiment 1:\n");
	printf("Total moves: %d\n",step_count1);
	for(i=0; i<15; i++)
	{
		for(j=0; j<15; j++)
		{
		printf("%6d",count1[i][j]);
		}
		printf("\n");
	}
	
	printf("Experiment 2:\n");
	printf("Total moves: %d\n",step_count2);
	for(i=0; i<39; i++)
	{
		for(j=0; j<19; j++)
		{
		printf("%6d",count2[i][j]);
		}
		printf("\n");
	}

	return 0;
}

bool all_is_ok1(int count1[15][15])
{
	int i, j;
	for(i=0; i<15; i++)
	{
		for(j=0; j<15; j++)
		{
			if(count1[i][j]==0)
			return false;	
		}
	}
	return true;
}

bool all_is_ok2(int count2[39][19])
{
	int i, j;
	for(i=0; i<39; i++)
	{
		for(j=0; j<19; j++)
		{
			if(count2[i][j]==0)
			return false;	
		}
	}
	return true;	
}

bool isroomavail1(int ibug, int jbug)
{
	if( ibug >= 15 || ibug < 0 || jbug >= 15 || jbug < 0 )
		return false;
	else
		return true;
}

bool isroomavail2(int ibug, int jbug)
{
	if( ibug >= 39 || ibug < 0 || jbug >= 19 || jbug < 0 )
		return false;
	else
		return true;
}

bool ismoveavail1(int k, int* imov, int* jmov) 
{
	int tmpi = *imov + imove[k],
		tmpj = *jmov + jmove[k];
	if( isroomavail1(tmpi, tmpj) ) {
		*imov = tmpi;
		*jmov = tmpj;
		return true;
	}
	return false;
}

bool ismoveavail2(int k, int* imov, int* jmov) 
{
	int tmpi = *imov + imove[k],
		tmpj = *jmov + jmove[k];
	if( isroomavail2(tmpi, tmpj) ) {
		*imov = tmpi;
		*jmov = tmpj;
		return true;
	}
	return false;
}

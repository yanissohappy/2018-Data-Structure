#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int activity;
	int max=0;
	scanf("%d",&activity);
	int num, start[10000], end[10000], duration[10000];
	int ee[10000], le[10000], e[10000], l[10000];
	int critical[10000];
	int corresponding[10000]={0};
	for(int i=0;i<activity;i++)
	{
		scanf("%d",&num);
		scanf("%d %d %d", &start[num-1], &end[num-1], &duration[num-1]);
		corresponding[start[num-1]]++;
		if(end[num-1]>max)
			max=end[num-1];
	}
	 
	for(int i=0;i<=max;i++)
		ee[i]=0;
		
	int i=0;
	
	while(corresponding[i]!=0)
	{
		for(int j=0;j<activity;j++){
			if(start[j]==i && ee[end[j]]<=ee[start[j]]+duration[j])
			{
				ee[end[j]]=ee[start[j]]+duration[j];
				corresponding[i]--;
			}else if(start[j]==i && ee[end[j]]>ee[start[j]]+duration[j]){
				corresponding[i]--;
			}
		}
		
		if(corresponding[i]==0)
		i++;		
	}
		
	for(int i=0;i<=max;i++)
		le[i]=ee[max];
		
	for(int i=activity-1;i>=0;i--){
		if(le[start[i]]>le[end[i]]-duration[i])
			le[start[i]]=le[end[i]]-duration[i];
	}
	
	for(int i=0;i<activity;i++)
	{
		e[i]=ee[start[i]];
		l[i]=le[end[i]]-duration[i];
		
		if(l[i]-e[i]!=0)
			critical[i]=0;
		else
			critical[i]=1;
	}
	printf("\nOutput:\n");
	printf("act.	e	l	slack	critical\n");
    for(int i=0;i<activity;i++){
		if(critical[i]==0)
		printf("%d	%d	%d	%d	%s\n",i+1,e[i],l[i],l[i]-e[i],"No");
		else if(critical[i]==1)
		printf("%d	%d	%d	%d	%s\n",i+1,e[i],l[i],l[i]-e[i],"Yes");
	}
	return 0;
}

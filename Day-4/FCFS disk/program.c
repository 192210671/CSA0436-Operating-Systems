#include<stdio.h>
#include<stdlib.h>
int main()
{
//	First Come First Served
int ReadyQueue[100],i,n,TotalHeadMov=0,initial;
printf("Enter the No of Processes:");
scanf("%d",&n);
for(i=0;i<n;i++)
{   
    printf("Enter the Value of Process[%d]:",i+1);
	scanf("%d",&ReadyQueue[i]);
}
printf("Enter the Initial Start Point:");
scanf("%d",&initial);

for(i=0;i<n;i++)
{
	TotalHeadMov=TotalHeadMov+abs(ReadyQueue[i]-initial);
	initial=ReadyQueue[i];
}

printf("Total Head Movement=%d",TotalHeadMov);


return 0;

}

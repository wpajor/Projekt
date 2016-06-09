#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>


int main()
{
    int size=1000;
    int mtxt[size];
    int mID;
    int guard;
    key_t key;
    time_t start,stop;
    if((key=ftok("send.c",'S'))== -1)
    {
	perror("ftok");
	exit(1);
    }
    
    if((msqid=msgget(key, 0666))== -1)
    {
	perror("msgget");
	exit(1);
    }
	if(msgrcv(mID,&mtxt,sizeof(mtxt),0,0)==-1)
	    {
		perror("msgrcv");
		exit(1);
	    }
	time(&start);
	for(int n=0;n<size-4;n++)
	{
	    guard=1;
	    for(int m=i+1;m<5+n;m++)
		if(mtxt[n]!=mtxt[m])
		    guard=0;
		if(guard==1)
		{
		    time(&stop);
		    printf("czas : %d ",difftime(koniec,stop));
		    break;
		}
	}

      if((msgctl(mID,IPC_RMID,NULL))!=0)
	{
	    perror("msgctl");
	    exit(1);
	}
return 0;
}

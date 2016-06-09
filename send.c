#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>


int main()
{
    int size=1000;
    char mtxt[size];
    int mID;
    key_t key;
    if((key=ftok("send.c",'S'))==-1)
	{
	    perror("ftok");
	    exit(1);
	}

    if((mID=msgget(key, 0666 | IPC_CREAT))==-1)
	{
	    perror("msgget");
	    exit(1);
	}
    
    
    for(int n=1;i<size;n++)
	mtext[i]=mtxt[i-1]*4;

    if(msgsnd(mID,&mtxt,sizeof(mtxt),0)== -1)
    	{
		perror("msgsnd");
		exit(1);
    	}
return 0;
}	

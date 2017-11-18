#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	if( argc<2 )
	{
		perror("a.out filename");
		exit(1);
	}


	char buf[512]={0};

	int ret = readlink(argv[1],buf,sizeof(buf));
	if( ret == -1 )
	{
		perror("readlink");
		exit(1);
	}

	buf[ret]=0;
	printf("%s\n",buf);

	return 0;
}

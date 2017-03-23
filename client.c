#include <stdio.h>
#include "prog.h"

int search(CLIENT *client, char* line, char c)
{
	operands ops;
	ops.line = line;
	ops.c = c;

	int *result;

	result = search_1(&ops,client);
	if (result == NULL)	{
    	fprintf(stderr,"Error calling remote procedure\n");
    	exit(0);
  	}
  	return(*result);
}

int main(int argc, char *argv[])
{
	CLIENT *client;
	char* line;
	char* c;

	if (argc != 4){
    	fprintf(stderr,"Usage: %s hostname line char\n",argv[0]);
    	exit(0);
  	}

  	client = clnt_create(argv[1], PROG1, VERSION, "udp");

  	if (client == (CLIENT *) NULL) {
		clnt_pcreateerror(argv[1]);
		exit(1);
	}

	line = argv[2];
	c = argv[3];

	printf("Number of '%c's in '%s' ---> %d\n", *c, line, search(client,line,*c));

	return(0);
}
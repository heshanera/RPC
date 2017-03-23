#include <stdio.h>
#include "prog.h"

int * search_1_svc(operands *argp, struct svc_req *rqstp)
{
	static int  similar = 0;
	printf("Got request: searching '%c' in '%s'\n", argp->c, argp->line);
	while(*(argp->line) != '\0')
	{
		//printf("%c\n",*line);
		if ( *(argp->line) == argp->c ) similar++;
		(argp->line)++;
	}	
	return (&similar);
}
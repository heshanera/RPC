#include <stdio.h>
#include <stdlib.h>
#include "prog.h"

int * search_1_svc(operands *argp, struct svc_req *rqstp)
{
	static int similar = 0;
	similar -= similar;
	printf("Got request: searching '%c' in '%s'\n", argp->c, argp->line);
	int len = strlen(argp->line);
	//printf("%d\n", len);
	int i = 0;
	while(i < len)
	{
		//printf("%c\n",(argp->line)[i]);
		if ( (argp->line)[i] == argp->c ) similar++;
		i++;
	}
		
	return (&similar);
}
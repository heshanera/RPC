#include <stdio.h>
#include <stdlib.h>

struct operands {
	char* line;
	char c;
};

int search(struct operands *argp)
{
	
	static int  similar = 0;

	//printf("Got request: searching '%c' in '%s'\n", argp->c, argp->line);

	while(*(argp->line) != '\0')
	{
		//printf("%c\n",*line);
		if ( *(argp->line) == argp->c ) similar++;
		(argp->line)++;
	}	
	return(similar);
}

int main(int argc, char *argv[])
{

	if (argc != 3){
		fprintf(stderr,"Usage: prog string char\n");
		exit(0);
	}

	char *tmp;
	tmp  = argv[1];
	char *c = argv[2];

	struct operands ops;
	ops.line = tmp;
	ops.c = *c;

	int similar = search(&ops);
	printf("Number of '%c's in '%s' ---> %d\n", *c, tmp, similar);
	return(0);
}
/*------------------------------------------------------------------------
 *   Write note to stdout                          
 *
 *   O. Hellwig
 *  ----------------------------------------------------------------------*/

#include "fd.h"

void note(FILE *fp){

	/* extern variables */
	extern char	LOG_FILE[STRING_SIZE];
	extern int	MYID, LOG;
	extern int	FFID;
	extern FILE	*FP;

	/* local variables */
	char	ext[10];


	/* open log-file (each PE is using different file) */
	sprintf(ext,".%.4i.%i",FFID,MYID);  
	strcat(LOG_FILE,ext);

	if (!(MYID)){
		fprintf(fp," Please note: \n");
		fprintf(fp," Each processing element (PE) will write log information during the execution \n");
		fprintf(fp," of the program to %s.PE .\n",LOG_FILE);
		fprintf(fp," See corresponding log-files for further information on the status of each PE.\n");
		fprintf(fp," Information about the overall program execution, e.g. \n");
		fprintf(fp," numerical stability, accuracy, computing times for each time step etc., \n");
		fprintf(fp," will be written by PE 0 to ");
		if (LOG)
			fprintf(fp," standard output, i.e. on the screen. \n\n");
		else
			fprintf(fp," %s .\n\n",LOG_FILE);
	}

	if ((!(MYID)) && (LOG))
		FP=stdout;
	else
		FP=fopen(LOG_FILE,"w");

	fprintf(FP," This is the log-file generated by PE %d \n\n",MYID);

}
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "main.h"
#include "vector.h"
#include "timer.h"


void initRand(){
	srand(time(NULL));
}

int main(int argc, char const ** argv){
	long i;
	double paraTime,seqTime;
	double v1[TAB_MAX],v2[TAB_MAX],v3[TAB_MAX];
	initRand();

	fillRandom(v1,TAB_MAX);
	fillRandom(v2,TAB_MAX);

/*	for(i=0;i<4;i++){
		v1[i] = i;
		v2[i] = 3-i;
	}

	printf("#n\tseqTime\tparaTime\n");
	for(i=0 ; i<10000 ; i++){
		fillRandom(v1,TAB_MAX);
		fillRandom(v2,TAB_MAX);

		seqTime = get_time();
		add(v1,v2,v3,TAB_MAX);
		seqTime = get_time() - seqTime;

		fillRandom(v1,TAB_MAX);
		fillRandom(v2,TAB_MAX);

		paraTime = get_time();
		addPara(v1,v2,v3,TAB_MAX);
		paraTime = get_time()-paraTime;
		printf("%d\t%lf\t%lf\n",i,seqTime,paraTime);
	}
	*/
	sscanf(argv[1],"%ld",&i);
	testPI(i);
	return EXIT_SUCCESS;
}

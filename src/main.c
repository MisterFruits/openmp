#include "main.h"


void initRand(){
	srand(time(NULL));
}	

int main(int argc, char const ** argv){
	int i;
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
	sscanf(argv[1],"%d",&i);
	testPi(i);
	return EXIT_SUCCESS;
}	


void testPI(int nbIt){
	int comptPara=0,comptSeq=0,i;
	double x,y,paraTime,seqTime;
	paraTime = get_time();
	#pragma omp parallel for shared(comptPara)
	for(i=0 ; i<nbIt ; i++){
		x=rand();
		y=rand();
		if(!(x*x+y*y > 1)){
			comptPara++;
		}
	}
	paraTime = get_time()-paraTime;

	seqTime = get_time();
	for(i=0 ; i<nbIt ; i++){
		x=rand();
		y=rand();
		if(!(x*x+y*y > 1)){
			comptPara++;
		}
	}
	seqTime = get_time()-seqTime;
	printf("%lf\t%lf\n",seqTime,paraTime);
}	

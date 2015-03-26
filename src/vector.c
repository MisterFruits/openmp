#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

#define MAX 100000

void add(double const * v1, double const * v2, double * res, int n){
	int i;
	for(i=0 ; i<n ; i++){
		res[i] = v1[i] + v2[i];
	}
}


void addPara(double const * v1 , double const * v2, double * res, int n){
	int i;
	#pragma omp parallel for
	for(i=0 ; i<n ; i++){
		res[i] = v1[i] + v2[i];
	}
}

double scalar(double const * v1, double const * v2, int n){
	int i;
	double res=0;
	for(i=0 ; i<n ; i++){
		res = res + v1[i]*v2[i];
	}
	return res;
}
double scalarPara(double const * v1 , double const * v2, int n){
	return scalar(v1,v2,n);
}


void println(double const* v, int n){
	int i;
	if(n>0){
		printf("[%lf",v[0]);
		for(i=1 ; i<n ; i++){
			printf(",%lf",v[i]);
		}
		printf("]\n");
	}
	else{
		printf("[]\n");
	}
}

void fillRandom(double * v, int n){
	int i;

	for(i=0; i<n ; i++){
		v[i] = rand() * MAX;
	}
}


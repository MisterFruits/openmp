#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

void add(double const * , double const *, double *, int);
void addPara(double const * , double const *, double *, int);
double scalar(double const * , double const *, int);
double scalarPara(double const * , double const *, int);
void println(double const*, int);
void fillRandom(double *, int);

#endif /* _VECTOR_H_ */

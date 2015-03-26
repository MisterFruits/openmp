#import "pi.h"

bool inCircle(){
    x=rand();
    y=rand();
    return !(x*x+y*y > 1);
}

double getPi(int nbIt){
    double count = 0;
    for (int i = 0; i < nbIt; ++i){
        count += inCircle();
    }
}

double getPiPara(int nbIt){

}

void testPI(int nbIt){
    int comptPara=0,comptSeq=0,i;
    double x,y,paraTime,seqTime;
    paraTime = get_time();
    #pragma omp parallel for
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
        if(){
            comptSeq++;
        }
    }
    seqTime = get_time()-seqTime;
    printf("%lf\t%lf\n",seqTime,paraTime);
}

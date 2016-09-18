#include <stdio.h>
#include <math.h>

long double logPow(int a,int b);
void printList(long double vec[],int length);
void bubbleSort(long double vec[],int length);
long double taylorLog(long double x);


int main(){
    int aMin = 2;
    int aMax = 100;
    int bMin = 2;
    int bMax = aMax;

    int nmbrOfnmbrs = (aMax-aMin+1)*(bMax-bMin+1);;
    long double nmbrs[nmbrOfnmbrs];

    nmbrs[nmbrOfnmbrs];

    int a;
    int b;
    double nmbr;
    unsigned int it=0;
    for(a=aMin; a<=aMax; a++){
        for(b=bMin; b<=bMax; b++){
            //printf("%d\n",it);
            nmbr = logPow(a,b);
            nmbrs[it]=nmbr;
            it++;
            //printf("log(%d^%d)=%ff\n",a,b,nmbr);
        }
    }
    bubbleSort(nmbrs, nmbrOfnmbrs);
    int nDistinctNum = countDistinctNum(nmbrs,nmbrOfnmbrs);

    //double tst[] = {1.0,1.0,1.0,1.0,1.0,1.0};
    //nDistinctNum = countDistinctNum(tst,5);
    //printList(nmbrs, nmbrOfnmbrs);
    printf("Number of distinct numbers:%d\n",nDistinctNum);
    //printf("%u, %d\n",it, n);
    return 0;
}

long double logPow(int a,int b){
    return (long double)log(log(b*log(a))/(10000*log(2)))/(10000*log(2))/(100000*log(2));
    return (long double)(b*taylorLog((long double)a));
}

long double taylorLog(long double x){
    int nTerms = 1000;
    long double taylorSum = 0;
    long double powerSum;
    int i;
    int j;
    //printf("%d",(x-1)/x);
    //return pow((x-1)/x,nTerms)/nTerms;
    for(i=1; i<=nTerms; i++){
        powerSum=1;
        for(j=0; j<i; j++){
            powerSum+=log((x-1)/x);
        }
        powerSum/=i;
        taylorSum+=powerSum;
    }
   
    return taylorSum;
}

int countDistinctNum(long double vec[], int length){
    int i;
    int nDistinctNum = 0;
    double lastNum = -1;
    for(i=0; i<length; i++){
        //printf("%f=%f:%d\n",vec[i],lastNum
        if(vec[i]-lastNum!=0){
            nDistinctNum++;
            lastNum=vec[i];
        }
    }
    return nDistinctNum;
}
void bubbleSort(long double vec[], int length){
    int isSorted=1;
    int i=0;
    double tmp;
    while(i<length-1){
        if(vec[i]>vec[i+1]){//Switch place
            tmp=vec[i];
            vec[i]=vec[i+1];
            vec[i+1]=tmp;

            if(i>0){
                i--;
            }
        }else{
            i++;
        }
    }
}

void printList(long double vec[],int length){
    int i;
    for(i=0; i<length; i++){
        printf("%Lf\n",vec[i]);
    }
}

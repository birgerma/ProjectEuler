#include<stdio.h>
#include<math.h>

int function(int a,int b, int n);
int isPrime(int n);
int countPrimes(int a, int b);

int main(){
    int maxA=1000;
    int maxB=1000;

    int maxPrimes=0;
    int bestA=0;
    int bestB=0;

    int a=-999;
    int b=61;
    int n;
    if(1){
    for(a=-maxA+1; a<maxA; a++){ 
         for(b=-maxB; b<=maxB; b++){

             n = countPrimes(a,b);
             if(n> maxPrimes){  
                 printf("a=%d, b=%d, n=%d\n",a,b,n);
                 maxPrimes=n;
                 bestA=a; 
                 bestB=b; 
             } 
         } 
    }
    }
    n=countPrimes(a,b);
    //printf("a=%d, b=%d, n=%d\n",a,b,n);
    printf("Best a=%d, best b=%d, number of primes:%d.\n a*b=%d\n",bestA,bestB,maxPrimes,bestA*bestB);
}

int countPrimes(int a, int b){
    int n=0;
    int prime = function(a,b,n);
    while(isPrime(prime)){
        //printf("%d\n",prime);
        n++;
        prime=function(a,b,n);
    }
    return n;
}

int function(int a,int b,int n){
    return n*n+a*n+b;
}

int isPrime(int n){
    if(n==2){
        return 1;
    }else if(n%2==0 || n<2){
        return 0;
    }

    int i;
    for(i=3; i<=(int)sqrt(n); i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

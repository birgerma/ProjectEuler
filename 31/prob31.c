#include<stdio.h>


int combIndex=0;
//int combinations[8][10000];
int success[10000];

int onePenny = 1;
int twoPenny = 2;
int fivePenny = 5;
int tenPenny = 10;
int twentyPenny = 20;
int fiftyPenny = 50;
int onePound = 100;
int twoPound = 200;

int coinValues[8] = {1,2,5,10,20,50,100,200};
//int coinValues[8] = {onePenny, twoPenny, fivePenny, tenPenny, twentyPenny, fiftyPenny, onePound, twoPound};
int goal = 200;

int computeCoinSum(int comb[]);
void printCombination(int comb[]);
unsigned long computeCoinCombinations();

int main(){

    unsigned long nmbrOfComb = computeCoinCombinations();
    printf("Number of combinations:%lu\n",nmbrOfComb);
}



unsigned long computeCoinCombinations(){
    //sum+=coinValues[nextCoinIndex];
    int combination[8] = {};
    int sum;
    unsigned long nmbrOfCorrectComb = 0;
    //int it;
    int target=200;
    int a;
    int b,c,d,e,f,g;
    int ways=0;
    for (a = target; a >= 0; a -= 200) {
        for (b = a; b >= 0; b -= 100) {
            for (c = b; c >= 0; c -= 50) {
                for (d = c; d >= 0; d -= 20) {
                    for (e = d; e >= 0; e -= 10) {
                        for (f = e; f >= 0; f -= 5) {
                            for (g = f; g >= 0; g -= 2) {
                                ways++;
                            }
                        }
                    }
                }
            }
        }
    }

    return ways;;
}

void printCombination(int comb[]){
    int sum = computeCoinSum(comb);

    printf("%d*1p + %d*2p +  %d*5p +  %d*10p + %d*20p +  %d*50p +  %d*1Pound +  %d*2Pound = %f Pound\n",
           comb[0],comb[1],comb[2],comb[3],
           comb[4],comb[5],comb[6],comb[7],
           ((double)sum)/100);

}

int computeCoinSum(int comb[]){
    int sum=0;
    int i;
    for(i=0; i<8; i++){
        //printf("i=%d, %d\n",i,combinations[i][index]);
        sum+=(coinValues[i]*comb[i]);
    }
    return sum;
}

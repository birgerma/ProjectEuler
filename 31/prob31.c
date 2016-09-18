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
    while(combination[7]<2){
        
        sum = computeCoinSum(combination);
        if(sum<goal){//Increase one step
            int i;
            for(i=0; i<7; i++){
                if(combination[i]*coinValues[i]>=goal){
                    combination[i]=0;
                }else{
                    combination[i]++;
                    break;
                }
            }
        }else if(sum>=goal){
            if(sum==goal){
                nmbrOfCorrectComb++;
                if(nmbrOfCorrectComb>73682){
                    printf("ERROR\n");
                    //printf("%lu\n",nmbrOfCorrectComb);
                    //printCombination(combination);
                }
            }
            int i;
            int j;
            for(i=6; i>=0; i--){
                if(combination[i]>0){
                    j=i+1;
                    combination[j]++;
                    break;
                }
            }
            for(i=0; i<j; i++){
                combination[i]=0;
            }
        }else{
            printf("Something went wrong...");
        }
    }
    return nmbrOfCorrectComb;
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

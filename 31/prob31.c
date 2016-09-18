#include<stdio.h>


int combIndex=0;
int combinations[8][10000];
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

int computeCoinSum(int index);
void printCombination(int index);

int main(){

    computeCoinCombinations(2,combIndex);
    /* int i; */
    /* for(i=7; i>=0; i--){ */
    /*     printf("%d\n",i); */
    /*     computeCoinCombinations(i,combIndex); */
    /*     combIndex++; */
    /* } */
    printf("Number of combinations tested:%d\n",combIndex);
}



int computeCoinCombinations(int nextCoinIndex, int index){
    //sum+=coinValues[nextCoinIndex];
    combinations[nextCoinIndex][index]++;
    int sum = computeCoinSum(index);
    
    if(sum==goal){
        //printf("Goal(index=%d)! Sum is %d: ",index,sum);
        success[index]=1;
        //printCombination(index);
    }else if(sum<goal){
        int i;
        computeCoinCombinations(0, index);
        //printf("Index: %d\n",combIndex);
        for(i=1; i<8; i++){
            combIndex++;
            //printf("Index: %d\n",combIndex);
            computeCoinCombinations(i, combIndex);
            //printf("Index: %d\n",combIndex);
        }
    }
}

void printCombination(int index){
    int sum = computeCoinSum(index);

    printf("%d*1p + %d*2p +  %d*5p +  %d*10p + %d*20p +  %d*50p +  %d*1Pound +  %d*2Pound = %f Pound\n",
           combinations[0][index],combinations[1][index],combinations[2][index],combinations[3][index],
           combinations[4][index],combinations[5][index],combinations[6][index],combinations[7][index],
           ((double)sum)/100);

}

int computeCoinSum(int index){
    int sum=0;
    int i;
    for(i=0; i<8; i++){
        //printf("i=%d, %d\n",i,combinations[i][index]);
        sum+=(coinValues[i]*combinations[i][index]);
    }
    return sum;
}

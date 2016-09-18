#include <stdio.h>


int main(){

    int presentNumber=1;
    int stepLength=2;
    int nmbrOfCorners=0;
    int diagonalSum=1;

    printf("Present number:%d, number of corners:%d ",presentNumber,nmbrOfCorners);
    printf("Sum:%d\n",diagonalSum);
    while(stepLength<1001){
        presentNumber+=stepLength;
        diagonalSum+=presentNumber;
        nmbrOfCorners++;
        //printf("Present number:%d, number of corners:%d ",presentNumber,nmbrOfCorners);
        //printf("Sum:%d\n",diagonalSum);
        if(nmbrOfCorners==4){
            stepLength+=2;
            nmbrOfCorners=0;
        }
    }
    printf("Diagonal sum:%d\n",diagonalSum);
}

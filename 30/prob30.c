#include<stdio.h>
#include<math.h>

void printPowerSum(int num,int sum);

int power=5;

int main(){

    int sum =0;
    int totalSum = 0;

    int i;
    for(i=10; i<1000000; i++){
        sum=recursiveDigitSum(i,0);
        if(sum==i){
            totalSum+=sum;
            printPowerSum(i,sum);
        }
    }

    printf("Total sum:%d\n",totalSum);
    //printf("%d\n",recursiveDigitSum(n1,0));
}


int recursiveDigitSum(int number, int sum){
    int n = number%10;

    number/=10;

    sum+=pow(n,power);

    if(number!=0){
        return recursiveDigitSum(number,sum);
    }else{
        return sum;
    }
}

void printPowerSum(int num,int sum){
    int printZero=0;
    if(num>99999){
        printf("%d^%d+",num/100000,power);
        num%=100000;
        printZero=1;
    }
    if(num>9999){
        printf("%d^%d+",num/10000,power);
        num%=10000;
        printZero=1;
    }
    if(num>999 || printZero){
        printf("%d^%d+",num/1000,power);
        num%=1000;
        printZero=1;
    }
    if(num>99 || printZero){
        printf("%d^%d+",num/100,power);
        num%=100;
        printZero=1;
    }
    if(num>9 || printZero){
        printf("%d^%d+",num/10,power);
        num%=10;
        printZero=1;
    }
    printf("%d^%d=%d \n",num,power,sum);
}

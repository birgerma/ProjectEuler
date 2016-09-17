#include<stdio.h>

int fib1[1000]={0};
int fib2[1000]={0};

void addNum2Vec(int vec[], int num);
void printIntVec(int vec[]);
void computeNextFib();

int main(int argc,char *argv[]){

    // Initialize fib1 and fib2 to 1:
    addNum2Vec(fib1,1);
    addNum2Vec(fib2,1);

    int fibIndex=2;
    while(fib2[0]==0){
        computeNextFib();
        fibIndex++;
    
    }
    printf("Index:%d Fib number:",fibIndex);
    printIntVec(fib2);
    return 0;

}

void computeNextFib(){
    int tmpNum;
    int num;
    int tmpFib[1000];

    // Copy fib2 to temporary place:
    int k;
    for(k=0; k<1000; k++){
        tmpFib[k]=fib2[k];
    }
    int i=999;
    int j;
//    printf("---------------\n");
    for(;i>=0; i--){
        j=i;
        num = fib1[i];
        while(j>=0){
            tmpNum = fib2[j]+num;
            if(tmpNum>9){
                //printf("Whole tmpNum:%d\n",tmpNum);
                //              printf("First digit:%d\n",tmpNum/10);
                //printf("Second digit:%d\n",tmpNum%10);
                
                fib2[j]=tmpNum%10;
                //printf("fib2[%d]=%d\n",j,fib2[j]);
                //printf("tmpNum: %d\n",tmpNum);
                num=tmpNum/10;
                //printf("%d\n",tmpNum);
                j--;
            }else{
                //printf("Else tmpNum %d\n",tmpNum);
                fib2[j]=tmpNum;
                break;
            }
            // printf("j=%d",j);
        }
    }
    //printf("---------------\n");
    for(k=0; k<1000;k++){
        fib1[k]=tmpFib[k];
    }
}



void addNum2Vec(int vec[], int num){
    int i=999;
    int newNum;
    int leastSigDig;
    while(i>=0){
        newNum=vec[i]+num;
        if(newNum>9){
            leastSigDig = newNum%10;
            num = newNum/10;
            vec[i]=leastSigDig;
            i--;
        }else{
            vec[i]=newNum;
            break;
        }
    }
}

void printIntVec(int vec[]){
    int i=0;

    //Find forst significant digit:
    while(vec[i]==0){
        i++;
    }
    for(; i<1000; i++){
        printf("%d",vec[i]);
    }
    printf("\n");
}

#include <stdio.h>
#include<stdlib.h>

int main(){
    int row,col; 
    int steps=0;
    int r[5][5];
    int a;
    int b;
 
    for (a=0; a<5; a++){
        for (b=0; b<5; b++){
    scanf("%d",&r[a][b]);
    if(r[a][b]==1){
        row=a;
        col=b;
    }
    
        }
    }
    steps=abs(2-row)+abs(2-col);
    printf("%d",steps);
}
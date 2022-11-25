#include <stdio.h>
#include "my_mat.h"

int main(){

    char c = '0';
    int a,b;

    while(char != 'D'){
        scanf("%c",&c);
        if(c == 'A') fill();
        else if(c == 'B'){
            scanf("%d%d",&a,&b);
            if(isPathExist(a,b)) printf("True\n");
            else printf("False\n");
        }else if(c == 'C'){
            scanf("%d%d",&a,&b);
            printf("%d\n",findShortestPath(a,b));
        } 
    }

    //fill();
   // printf("filled \n");
    // printMat();

    // i = findShortestPath(0,3);
    
    // printf("----------RESULT-------------\n %d \n -----------------------------\n",i);
    

    return 0;
};


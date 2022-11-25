#include <stdio.h>
#include "my_mat.h"

int main(){

    char c = '0';
    int a,b;


    while(c != 'D'){
        scanf("%c",&c);
        if(c == 'A') {
            fill();
        }
        else if(c == 'B'){
            scanf("%d",&a);
            scanf("%d",&b);
            if(isPathExist(a,b)) printf("True\n");
            else printf("False\n");
        }else if(c == 'C'){
            scanf("%d",&a);
            scanf("%d",&b);
            printf("%d\n",findShortestPath(a,b));
        } 
    }
    return 0;
};


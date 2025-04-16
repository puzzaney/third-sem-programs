#include<stdio.h>

void TOH(int n, char from, char to, char aux)
{
    if(n==1){
        printf("\nMove Disk %d from peg %c to peg %c",n,from,to);
        return;
    }
    TOH(n-1,from,aux,to);
    printf("\nMove Disk %d from peg %c to peg %c",n,from,to);
    TOH(n-1,aux,to,from);
}

int main(){
    TOH(3,'A','C','B');
    return 0;
}

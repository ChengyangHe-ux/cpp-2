#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
int main()
{
    int a;
    srand (time(NULL));
    while(1)
    {   a=rand()%100+1;
        printf("\r%3d", a);
        if (kbhit()) break;
    }
    getchar();
    return 0;
}
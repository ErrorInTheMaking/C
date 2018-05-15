#include<stdio.h>

int first = 0;
int second = 1;

int fibonacci_rec(int n)
{
    if(n == 0)
        return first;
    if(n == 1)
        return second;
    else
        return fibonacci_rec(n-1) + fibonacci_rec(n-2);
}

int main(int argc, char const **argv)
{
    int i;

    for(i = 0; i < 20; ++i)
        printf("%d->%d\n" ,i+1, fibonacci_rec(i));  

    return 0;
}

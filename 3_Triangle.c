#include<stdio.h>
int main()
{
    int a,b,c,c1,c2,c3;
    char istriangle;
    do
    {
        printf("Enter 3 sides of Triangle = ");
        scanf("%d %d %d",&a, &b, &c);
        c1 = a>=1 && a<=10;
        c2 = b>=1 && b<=10;
        c3 = c>=1 && c<=10;
        if(!c1)
            printf("Value of a not in range");
        if(!c2)
            printf("Value of b not in range");
        if(!c3)
            printf("Value of c not in range");
    }while(!(c1 && c2 && c3));

    //To check if it is a triangle or not
    if( a<b+c && b<a+c && c<a+b )
        istriangle = 'y';
    else
        istriangle = 'n';

    //Check for type of triangle
    if(istriangle == 'y')
    {
        if((a==b) && (b==c))
            printf("Equilateral Triangle \n");
        else if((a!=b) && (a!=c) && (b!=c))
            printf("Scalene Triangle \n");
        else
            printf("Isocesles Triangle \n");
    }
    else
        printf("Not a triangle \n");
    return 0;
}

// rajumang@Thunder:~/projects$ ./a.out
// Enter 3 sides of Triangle = 1 5 5
// Isocesles Triangle 

// rajumang@Thunder:~/projects$ ./a.out
// Enter 3 sides of Triangle = 5 7 6
// Scalene Triangle 
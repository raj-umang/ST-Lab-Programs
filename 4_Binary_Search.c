#include<stdio.h>
int binsrc(int x[], int low, int high, int key)
{
    int mid;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(key == x[mid])
            return mid;
        if(key < x[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main()
{
    int x[20], key, i, n, success;
    printf("Enter the n value = ");
    scanf("%d", &n);
    if(n>0)
    {
        printf("Enter elements in ascending order = ");
        for(i=0; i<n; i++)
            scanf("%d",&x[i]);
        printf("Enter the key element to be searched = ");
        scanf("%d",&key);
        success = binsrc(x, 0, n-1, key);
        if(success>=0)
            printf("Element found in position = %d \n", success+1);
        else
            printf("Element not found \n");
    }
    else   
        printf("No. of element should be greater than 0 \n");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int main()
{
    // 2- C Program to take an array elements from user,
    //  then print them out "using 2 for loops". (Print Array)
    int arr[SIZE];
    printf("\n take an array elements from user, then print them out:\n");
    printf("Enter 10 elements in the array :\n");
    for(int i=0; i<SIZE; i++)
    {
        printf("Enter element %d : ",i+1);
        scanf("%d", &arr[i]);
    }
    printf("\nElements in array are: ");
    for(int i=0; i<SIZE; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");

    // 3- C Program to find the minimum & maximum value of array elements. (Min_Max Array)
    int arr1[SIZE];
    int max, min, n;
    printf("\n\nfind the minimum & maximum value of array elements :\n");
    printf("Enter 10 elements in the array :\n");
    for(int i=0; i<SIZE; i++)
    {
        printf("element %d : ",i);
        scanf("%d",&arr1[i]);
    }
    max = arr1[0];
    min = arr1[0];
    for(int i=1; i<SIZE; i++)
    {
        if(arr1[i]>max)
        {
            max = arr1[i];
        }
        if(arr1[i]<min)
        {
            min = arr1[i];
        }
    }
    printf("\n Maximum is : %d\n", max);
    printf("\n Minimum is : %d\n", min);

    return 0;
}

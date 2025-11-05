#include <stdio.h>
void bubbleSort(int arr[],int n)
{
    int temp;
    int isSorted;
    for(int i=0;i<n-1;i++)
    {
        isSorted=1;
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j+1]<arr[j])
            {
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
                isSorted=0;
            }
        }
        if(isSorted)
        return;
    }
}
void main()
{
    int size;
    printf("Enter the size of the array : ");
    scanf("%d",&size);

    int arr[size];
    printf("Enter the elements of the array :\n");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }

    bubbleSort(arr,size);

    printf("Sorted Array :\n");
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}
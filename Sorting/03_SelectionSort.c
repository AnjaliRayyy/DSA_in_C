#include <stdio.h>
void selectionSort(int arr[],int n)
{
    int min,temp;
    for(int i=0;i<n-1;i++)
    {
        min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min])
            min=j;
        }
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
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

    selectionSort(arr,size);
    
    printf("Sorted Array :\n");
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}
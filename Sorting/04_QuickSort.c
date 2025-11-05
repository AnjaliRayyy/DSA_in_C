#include <stdio.h>
int partition(int arr[],int low,int high)
{
    int pivot=arr[low];
   int i=low+1;
   int j=high;
   int temp;
   do{
        while(arr[i]<=pivot)
        i++;
        while(arr[j]>pivot)
        j--;

        if(i<j){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
   }while(i<j);
   
   temp=arr[low];
   arr[low]=arr[j];
   arr[j]=temp;
   return j;
}
void quickSort(int arr[],int low,int high)
{
    int partitionIndex;
    if(low<high)
    {
        partitionIndex=partition(arr,low,high);
        quickSort(arr,low,partitionIndex-1);
        quickSort(arr,partitionIndex+1,high);
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

    quickSort(arr,0,size-1);

    printf("Sorted Array :\n");
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}
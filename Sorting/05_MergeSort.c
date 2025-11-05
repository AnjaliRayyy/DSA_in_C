#include <stdio.h>
void merge(int arr[],int start,int mid,int end)
{
    int temp[end-start+1];
    int k=0;
    int i=start;
    int j=mid+1;
    while(i<=mid && j<=end)
    {
        if(arr[i]<arr[j])
        {
            temp[k++]=arr[i];
            i++;
        }
        else
        {
            temp[k++]=arr[j];
            j++;
        }
    }
    while(i<=mid)
    {
        temp[k++]=arr[i++];
    }
    while(j<=end)
    {
        temp[k++]=arr[j++];
    }
    for(int idx=0;idx<k;idx++)
    {
        arr[start+idx]=temp[idx];
    }
}
void mergeSort(int arr[],int start,int end)
{
    if(start<end)
    {
        int mid=start+(end-start)/2;
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,start,mid,end);
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

    mergeSort(arr,0,size-1);

    printf("Sorted Array :\n");
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}
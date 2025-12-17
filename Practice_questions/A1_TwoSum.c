/*Given an array of integers and a target value, return the indices of the two numbers such that they add up to the target. You may assume each input will have exactly one solution, and the same element cannot be used twice.*/
#include <stdio.h>
#include <stdlib.h>
int* twoSum(int arr[],int n,int target){
    int* ans=malloc(2* sizeof(int));
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==target)
            {
                ans[0]=i;
                ans[1]=j;
                break;
            }
        }
    }
    return ans;
}
void main()
{
    int n;
    printf("Enter the length of the input array : ");
    scanf("%d",&n);

    //Taking array as user input
    int* arr=(int *)malloc(n*sizeof(int));
    printf("Enter the elements :\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    //Taking the target as user input
    int target;
    printf("Enter the target : ");
    scanf("%d",&target);

    int *ans=twoSum(arr,n,target);
    printf("%d %d\n",ans[0],ans[1]);
    free(ans);
}
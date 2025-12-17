/*Given a matrix, if any cell contains a zero, set its entire row and column to zero. Do this in-place.*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 10
void replaceWithZero(int arr[MAX][MAX],int m,int n){
    for(int i=0;i<m;i++){
        int containsZero=0;
        for(int j=0;j<n;j++){
            //Checking if the row contains zero
            if(arr[i][j]==0){
                containsZero=1;
                break;
            }
        }
        //If the row contanins zero replace all row elements with 0
        if(containsZero){
            for(int k=0;k<n;k++){
                arr[i][k]=0;
            }
        }
    }
}
void main()
{
    int m,n;
    printf("Enter the no. of rows and col : ");
    scanf("%d %d",&m,&n);
    int arr[MAX][MAX];

    printf("Enter the elements of the array :\n");
    for(int i=0;i<m;i++){
        printf("Row %d elements :\n",i);
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    printf("Before transforming : \n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    
    replaceWithZero(arr,m,n);

    printf("After transforming : \n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
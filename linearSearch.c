#include<stdio.h>

int main(){
    int size,a[100],i,val;
    printf("Enter the size of array:");
    scanf("%d",&size);
    for(i=0;i<=size-1;i++){
        printf("Enter the elements:");
        scanf("%d",&a[i]);
    }
    printf("Enter the element to be searched:");
    scanf("%d",&val);

    for(i=0;i<=size;i++){
        if(a[i]==val){
            printf("Element is found at index %d",i);
            return 0;
        }
    }
            printf("Element not found");
            return 0;
};
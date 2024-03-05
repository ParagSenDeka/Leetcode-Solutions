#include<stdio.h>

int main(){
    int size,val;
    printf("Enter the size of array:");
    scanf("%d",&size);
    int a[100];
    for(int i=0;i<=size-1;i++){
        printf("Enter the elements:");
        scanf("%d",&a[i]);
    }
    printf("Enter the element to be searched:");
    scanf("%d",&val);

    int start=0;
    int end=size-1;
    while(start<end){
        int mid=(start+end)/2;
        if(val==a[mid]){
            printf("Element is found");
            return 0;
        }
        else if(val>a[mid]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        }
        printf("Search unsuccessful");
        return 0;
}
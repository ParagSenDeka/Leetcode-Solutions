#include<stdio.h>
#define MAX 10



int main(){
int queue[MAX];
int front=-1;
int rear=-1;

void display(int front,int rear){
    if(front<0){
        printf("Queue underflow");
    }
    else{
    while(rear>=front)
    {
        printf("%d",queue[rear]);
        rear--;
    }
    }
}

void enqueue(){
    int item;
    printf("Enter the data to insert:");
    scanf("%d",&item);
    if(rear==(MAX-1)){
        printf("Queue overflow");
    }
    else{
        if(front==-1){
            front=0;
        }
        rear++;
        queue[rear]=item;
    }
    display(front,rear);
    }

void dequeue(){
    int item;
    if(front=-1 || front>rear){
        printf("Queue is underflow");
    }
    else{
        item=queue[front];
        front++;
    }
}

    enqueue();
    // dequeue();
    // display();
}
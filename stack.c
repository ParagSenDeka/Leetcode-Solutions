#include <stdio.h>
#define n 10

int stack[n];
int top = -1;

void display(int top)
{
    if (top == -1)
    {
        printf("\nStack is empty");
    }
    else
    {
        while (top >= 0)
        {
            printf("%d", stack[top]);
            top--;
        }
    }
}

void push()
{
    int data;
    printf("Enter the data to be inserted:");
    scanf("%d", &data);
    if (top == (n - 1))
    {
        printf("Stack overflow");
    }
    else
    {
        top++;
        stack[top] = data;
        display(top);
    }
}

void pop(){
    int data;
    if(top==-1){
        printf("Stack underflow");
    }
    else{
        data=stack[top];
        top--;
        display(top);
    }
}

int main()
{
    push();
    pop();
    return 0;
}
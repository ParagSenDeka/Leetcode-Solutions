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

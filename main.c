#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
}*top=NULL;
void push(int);
void pop();
void display();

int main()
{
    int choice,data;
    char opt;
    printf("\n:: Stack using Linked List ::\n");
    do{
      printf("\n****** MENU ******\n");
      printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d",&choice);
      switch(choice){
	 case 1: printf("Enter the value to be insert: ");
		 scanf("%d",&data);
		 push(data);
		 break;
	 case 2: pop(); break;
	 case 3: display(); break;
	 case 4: exit(0);
	 default: printf("\nWrong selection!!! Please try again!!!\n");
      }
      printf("do you wanna continue\n");
      opt=getch();
   }while(opt=='Y'||opt=='y');
    return 0;
}
void push(int value){
struct node *newnode;
newnode=(struct node *)malloc(sizeof(struct node));
newnode->data=value;
if(top==NULL)
    newnode->next=NULL;
else
    newnode->next=top;
top=newnode;
}
void pop(){
if(top==NULL)
    printf("\nthe stack is empty\n underflow!!!!\n");
else
{
    struct node *temp;
    temp=top;
    top=temp->next;
    printf("popped out element %d",temp->data);
    free(temp);

}
}
void display(){
if(top==NULL)
   {
       printf("stack is empty\nunderflow");
   }
else{
    struct node *temp = top;
    while(temp->next!= NULL){
    printf("%d--->",temp->data);
    temp = temp->next;}
    printf("%d--->NULL\n",temp->data);
}
}

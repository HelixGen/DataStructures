#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node *next;


}*header=NULL;


void CreateCircularLinkedList(int array[], int n){
     header=(struct Node *)malloc(sizeof(struct Node));
     header->data=array[0];
     header->next=header;
     struct Node* Current=header;
     for(int i=1;i<n;i++){
        struct Node * NewNode=(struct Node *)malloc(sizeof(struct Node));
        NewNode->data=array[i];
        Current->next=NewNode;
        Current=NewNode;
        Current->next=header;

     }

}


void Display(){
 struct Node * p=header;
 do{
  printf("%d\n",p->data);
  p=p->next;


 }
 while(p!=header);

 

}

void Insert(int pos,int x){
  struct Node *t=header;
  struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
  newNode->data=x;
  
  if(pos==0){
    newNode->next=header;
    while(t->next!=header){
      t=t->next;
    }
   t->next=newNode;
   header=newNode;

  }

  else if(pos>0){
    for(int i=1;i<pos;i++){
      t=t->next;

    }
   struct Node *q=t->next;
   t->next=newNode;
   newNode->next=q;



}
  



}


void Delete(int pos){
 struct Node *t=header;
  if(pos==0){
   while(t->next!=header){
       t=t->next;

   }
   t->next=header->next;
   free(header);
   header=t->next;



  }

 else if(pos>0){
    for(int i=0;i<pos-1 && t;i++){
       t=t->next;

    }
        struct Node *q=t->next;
        t->next=q->next;
        free(q);


 }

 // naev grvuma valid positiony



}




int main(){
int array[5]={1,2,3,4,5};
CreateCircularLinkedList(array,5);
//Delete(4);
Display();


    return 0;
}

#include <stdio.h>
#include <stdlib.h>


struct Node{
 struct Node *prev;
 int data;
 struct Node *next;


}*first=NULL;


void Create(int array[], int n){
   
  first=(struct Node *)malloc(sizeof(struct Node));
     struct Node * current;
     first->data=array[0];
     first->next=first;
     first->prev=first;
     current=first;
     for(int i=1;i<n;i++){
       struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
       newNode->data=array[i];
       newNode->next=NULL;
       newNode->prev=current;
       current->next=newNode;
       current=newNode;
}
     
first->prev=NULL;

}


void Display(){
   struct Node *p=first;
   while(p!=NULL){
     printf("%d\n",p->data);
     p=p->next;
   }



}

void Insert( int x, int pos){
struct Node * node= (struct Node *)malloc(sizeof(struct Node));
   node->data=x;
  if(pos==0){
   
   node->next=first;
   node->prev=NULL;
   first->prev=node;
   first=node;

  }

else if(pos >0){
  struct Node *p=first; 
  for(int i=0;i<pos-1;i++){
    p=p->next;


   }

   if(p->next!=NULL){
       node->next=p->next;
       p->next->prev=node;
       node->prev=p;
       p->next=node;

   }

   else{
      node->next=NULL;
      node->prev=p;
      p->next=node;

   }




}




}

void Delete(int pos){
  if(pos==0){
   struct Node *p=first->next;
   free(first);
   first=p;
   first->prev=NULL;


  }

  else if(pos>0){
   struct Node *p=first;
    for(int i=0;i<=pos-1;i++){
      p=p->next;

   }
    if(p->next!=NULL){
       p->prev->next=p->next;
       p->next->prev=p->prev;
       free(p);

    }

else {
      p->prev->next=NULL;
      free(p);

}



  }




}




int main(){
int array[5]={1,2,3,4,5};
Create(array,5);
Delete(4);
Display();


    return 0;
}
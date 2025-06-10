#include <stdio.h>
#include <stdlib.h>



struct Stack{
int size;
int Top;
int *s;



};


//linked list way 
struct Node {
  int data;
  struct Node * next;


}*top=NULL;

void push(int x){
  struct Node *t=(struct Node *)malloc(sizeof(struct Node));
  if(t==NULL){
     printf("stack overflow");  //pti stugenq ete heap lcvuma chenq kara taza node insert anenq vortev nodery unlimited qanakov karanq stexcenq


  }

  else{
      t->data=x;
      t->next=top;
      top=t;
     

  }



};


int pop(){
    int x=-1;
    struct Node *t;

    
    if(top==NULL){
         printf("stack underflow");
    }

    else{
          t = top;
      x = t->data;
top = top->next;
free(t);
          


    }

return x;

}


int peek(int pos){
  struct Node *p=top;
  for(int i=0;i<pos-1 && p!=NULL;i++){
     p=p->next;


  }

  if(p!=NULL){
     return p->data;

  }


  else
    return -1;

}


int stackTop(){
  if(top)
     return top->data;
   else
     return -1;


}

int isEmpty(){
  if(top)
     return 0;
   else
      return 1;

}



int isFull(){
   struct Node *p=(struct Node *)malloc(sizeof(struct Node));
   if(p==NULL){
       free(p);
       return 1;
   }
  else{
    return 0;
  }



}


void display(){
     struct Node *p=top;
     while(p!=NULL){
        printf("%d\n",p->data);
        p=p->next;

     }


}





void push(struct Stack *st,int x){
  if(st->Top==st->size-1)
     printf("Stack Overflow \n");
else{
   st->Top++;
   st->s[st->Top]=x;

}

}

void Display(struct Stack st){
  for(int i=0;i<st.size;i++){
      printf("%d\n", st.s[i]);

  }



}


int pop(struct Stack *st){
   int x=-1;
   if(st->Top==-1){
      printf("stack underflow");

   }
   else{
      x=st->s[st->Top];
      st->Top--;
     st->size=st->size-1;       

    
   }

return x;

}


int peek(struct Stack st, int pos){
   int x=-1;
   if(st.Top-pos+1<0){
      return x;

   }
   else{
    x= st.s[st.Top-pos+1];
   return x;

   }


}


int stackTop(struct Stack st){
  if(st.Top==-1){
     return -1;

  }

  else{
    return st.s[st.Top];
  }

}


int isEmpty(struct Stack st){
   if(st.Top==-1){
     return 1;

   }

   return 0;

}




int main(){
/*
struct Stack st;

st.size=5;
st.s=(int *)malloc(st.size*sizeof(int));
st.Top=-1;
*/
/* functions work 
push(&st,10);
push(&st,11);
push(&st,12);
push(&st,13);
push(&st,14);
Display(st);
printf("poped value %d\n",pop(&st));
Display(st);
printf("the value of 1 position is %d\n", peek(st,1));
printf("the top element of stack is %d\n",stackTop(st));
if(isEmpty(st)){
  printf("stack is empty\n");
  


}

else {
  printf("stack is not empty\n");

}
*/

push(4);
push(5);
push(6);
//printf("%d",peek(3));
pop();
display();

if(isEmpty()){
    printf("empty \n");
}

else{
    printf("not empty \n");
}


if(isFull()){
   printf("full \n");

}

else{
   printf("not full \n");

}

    return 0;
}
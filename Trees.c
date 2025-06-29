#include <stdio.h>
#include <stdlib.h>



struct Stack {
    int size;
    int Top;
    struct Node **s;
};





void push(struct Stack *st, struct Node* x) {
    if (st->Top == st->size - 1) {
        printf("Stack Overflow\n");
    } else {
        st->Top++;
        st->s[st->Top] = x;
    }
}


struct Node* pop(struct Stack *st) {
    struct Node* x = NULL;

    if (st->Top == -1) {
        printf("Stack Underflow\n");
    } else {
        x = st->s[st->Top];
        st->Top--;
    }

    return x;
}


struct Node* stackTop(struct Stack st) {
    if (st.Top == -1) {
        return NULL;
    } else {
        return st.s[st.Top];
    }
}



int isEmpty(struct Stack st){
   if(st.Top==-1){
     return 1;

   }

   return 0;

}


struct Queue {
    int size;
    int front;
    int Rear;
    struct Node **Q;
};

void Create(struct Queue *q, int size) {
    q->size = size;
    q->front = q->Rear = -1;
    q->Q = (struct Node **)malloc(q->size * sizeof(struct Node *));
}

void Enqueue(struct Queue *q, struct Node *x) {
    if (q->Rear == q->size - 1) {
        printf("Queue Overflow\n");
    } else {
        q->Rear++;
        q->Q[q->Rear] = x;
    }
}

struct Node* Dequeue(struct Queue *q) {
    struct Node *x = NULL;
    if (q->front == q->Rear) {
        printf("Queue is Empty\n");
    } else {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

int isEmptyQueue(struct Queue q) {
    return q.front == q.Rear;
}








struct Node{
  struct Node *leftchild;
  int data;
  struct Node *rightchild;


}*root=NULL;




void CreateBinaryTree(int array[], int n){
  
   root=(struct Node*)malloc(sizeof(struct Node));
   root->leftchild=NULL;
   root->rightchild=NULL;
   root->data=array[0];
   struct Node **Nodearray=(struct Node**)malloc(n*sizeof(struct Node));
  Nodearray[0] = root;
   int i=0;
   while(i<n){
          if( 2 * i + 1 < n && Nodearray[i]->leftchild==NULL){
            struct Node *p=(struct Node*)malloc(sizeof(struct Node));
            p->leftchild=NULL;
            p->data=array[2*i+1];
            p->rightchild=NULL;
            Nodearray[2*i+1 ]=p;
            Nodearray[i]->leftchild=p;  
        
        }

         else if (2* i+2 < n && Nodearray[i]->rightchild == NULL) {
        struct Node *p = (struct Node*)malloc(sizeof(struct Node));
        p->leftchild = NULL;
        p->data = array[2 * i + 2];
        p->rightchild = NULL;
        Nodearray[2 * i + 2] = p;
        Nodearray[i]->rightchild = p;
    }


       else {
          i++;

       }




   }
     





}

void Preorder( struct Node *t ){
if(t!=NULL){
  printf("%d ",t->data);
  Preorder(t->leftchild);
  Preorder(t->rightchild);

}


}

void Inorder( struct Node *t ){
if(t!=NULL){
  
  Inorder(t->leftchild);
  printf("%d ",t->data);
  Inorder(t->rightchild);

}


}


void Postorder(struct Node *t){
   if(t!=NULL){
      Postorder(t->leftchild);
      Postorder(t->rightchild);
      printf("%d " ,t->data);


   }



}

void PreorderIterative(struct Node *t ,int n){
   struct Stack st;

st.size=n;
st.s=(struct Node **)malloc(st.size*sizeof(struct Node *));
st.Top=-1;
while(!isEmpty(st) || t!=NULL){
    if(t!=NULL){
        printf("%d ",t->data);
        push(&st,t);
        t=t->leftchild;
    }


    else{
        struct Node *p=pop(&st);
        t=p->rightchild;


    }


}


}

void InorderIterative(struct Node *t ,int n){
   struct Stack st;

st.size=n;
st.s=(struct Node **)malloc(st.size*sizeof(struct Node *));
st.Top=-1;
while(!isEmpty(st) || t!=NULL){
    if(t!=NULL){
        
        push(&st,t);
        t=t->leftchild;
    }


    else{
        struct Node *p=pop(&st);
        printf("%d ",p->data);
        t=p->rightchild;


    }


}


}

void LevelorderTraversal(struct Node *t, int n){
  struct Queue qt;
  qt.size=n;
  qt.front=qt.Rear=-1;
  qt.Q=(struct Node **)malloc(n*sizeof(struct Node *));
  Enqueue(&qt,t);
  while(!isEmptyQueue(qt)){
      struct Node *p=Dequeue(&qt);
      printf("%d ",p->data);
      if(p->leftchild!=NULL){
        Enqueue(&qt,p->leftchild);
      
    }
       if(p->rightchild!=NULL){
        Enqueue(&qt,p->rightchild);
       }
       
  



}



}







int main(){

int array[] = {10, 20, 30, 40, 50, 60, 70};
CreateBinaryTree(array,7);
printf("preorder");
Preorder(root);
printf("\n");

printf("inorder");
Inorder(root);
printf("\n");


printf("postorder");
Postorder(root);
printf("\n");


printf("preorder Iterative");
PreorderIterative(root,7);
printf("\n");

printf("Inorder Iterative");
InorderIterative(root,7);
printf("\n");

printf("Levelorder Iterative");
LevelorderTraversal(root,7);
printf("\n");


return 0;
}
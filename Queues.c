#include <stdio.h>
#include <stdlib.h>


struct Queue{
int  size;
int front;
int Rear;
int *Q;


};


void Create(struct Queue *q, int size){
q->size=size;
q->front= q->Rear=-1;
q->Q=(int *)malloc(q->size*sizeof(int));

};


void Enqueue(struct Queue *q, int x){
  if(q->Rear==q->size-1){
     printf("error in inserting\n");

  }
  else {
  q->Rear++;
  q->Q[q->Rear]=x;
  }

}

int Dequeue(struct Queue *q){
    int x=-1;
    if(q->front==q->Rear){
          printf("Queue is Empty");

    }
    
    else{
       q->front++;
       x=q->Q[q->front];


    }
     
return x;


}

int isEmpty(struct Queue q){
   if(q.front==q.Rear){
      return 1;

   }

   return 0;



}


int isFull(struct Queue q){
if(q.Rear==q.size-1){
    return 1;
}

return 0;


}

void Display(struct Queue q){
  for(int i=q.front+1;i<=q.Rear;i++){
       printf("%d\n", q.Q[i]); 

  }


}





int main(){
struct Queue q;
Create(&q,7);
//Enqueue(&q,0);
//Enqueue(&q,1);
//Enqueue(&q,2);
//Enqueue(&q,3);
//Enqueue(&q,4);
//Enqueue(&q,5);
//Enqueue(&q,6);
Display(q);


if(isFull(q)){
  printf("is full\n");

}
else{
    printf("no is not full\n");
}


if(isEmpty(q)){
 printf("is empty\n");

}

else{
  printf("is not empty\n");

}










    return 0;
}
#include <stdio.h>
#include <stdlib.h>




struct Dequeue{
int  size;
int front;
int Rear;
int *Q;


};



void Create(struct Dequeue *q, int size){
q->size=size;
q->front= q->Rear=-1;
q->Q=(int *)malloc(q->size*sizeof(int));

};

void EnqueueByFront(struct Dequeue *q, int x){
   if(q->front>0){
      q->Q[q->front]=x;
      q->front--;
     


   }
 else{
     printf("cant insert anything\n");

 }



}


int DequeueByRear(struct Dequeue *q){
     int x=-1;
    if(q->Rear>q->front){
     x =q->Q[q->Rear];
      q->Rear--;
     


   }
 else{
     printf("cant delete anything \n");
     
 } 

return x;


}


void EnqueueByRear(struct Dequeue *q, int x){
  if(q->Rear==q->size-1){
     printf("error in inserting \n");

  }
  else {
  q->Rear++;
  q->Q[q->Rear]=x;
  }

}

int DequeueByFront(struct Dequeue *q){
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

void Display(struct Dequeue q){
  for(int i=q.front+1;i<=q.Rear;i++){
       printf("%d\n", q.Q[i]); 

  }


}


int main(){

struct Dequeue q;
Create(&q,7);

EnqueueByRear(&q,0);
EnqueueByRear(&q,1);
EnqueueByRear(&q,2);
EnqueueByRear(&q,3);
EnqueueByRear(&q,4);
EnqueueByRear(&q,5);
EnqueueByRear(&q,6);
DequeueByFront(&q);
DequeueByFront(&q);
DequeueByFront(&q);
EnqueueByFront(&q,0);
EnqueueByFront(&q,1);
EnqueueByFront(&q,2);

Display(q);


    return 0;
}







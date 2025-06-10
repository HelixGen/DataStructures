#include <stdio.h>
#include <stdlib.h>




struct CircularQueue{
int  size;
int front;
int Rear;
int *Q;


};


void Create(struct CircularQueue *q, int size){
q->size=size;
q->front= q->Rear=0;
q->Q=(int *)malloc(q->size*sizeof(int));

};




void Enqueue(struct CircularQueue *q , int x){
   if(((q->Rear)+1)%q->size==q->front){
    printf("queue is full \n");
   }

else {
     q->Rear=(q->Rear+1)%q->size;
     q->Q[q->Rear]=x;


}


}


int dequeue(struct CircularQueue *q){
int x=-1;
if(q->front==q->Rear){
    printf("queue is empty");

}
else{
q->front=(q->front+1)%q->size;
x=q->Q[q->front];

}

return x;

}







int isEmpty(struct CircularQueue q){
   if(q.front==q.Rear){
      return 1;

   }

   return 0;



}


int isFull(struct CircularQueue q){
if(((q.Rear)+1)%q.size==q.front){
    return 1;
   }

return 0;


}


void Display(struct CircularQueue q){
int i=q.front+1;
do{
  printf("%d\n",q.Q[i]);
  i=(i+1)%q.size;

}while(i!=(q.Rear+1)%q.size);




}









int main(){






struct CircularQueue q;
Create(&q,7);
Enqueue(&q,0);
Enqueue(&q,1);
Enqueue(&q,2);
Enqueue(&q,3);
Enqueue(&q,4);
Enqueue(&q,5);
Enqueue(&q,6);
Enqueue(&q,7);
Display(q);


    return 0;
};
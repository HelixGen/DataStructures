#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
   int data;
   struct Node *next;

}*first=NULL;


void Create(int array[], int n){
  first=(struct Node *)malloc(sizeof(struct Node));
   struct Node *t;
   struct Node *last;
   first->data=array[0];
   first->next=NULL;
   last=first;
   for(int i=1;i<n;i++){
      t=(struct Node*)malloc(sizeof(struct Node));
      t->data=array[i];
      t->next=NULL;
      last->next=t;
      last=t;
}

}

void DisplayIterative( struct Node *p){
   while(p!=NULL){
     printf("%d\n",p->data);
     p=p->next;
   }

}

void DisplayRecursive(struct Node *p){
   if(p!=NULL){
     printf("%d\n",p->data);
     DisplayRecursive(p->next);


   }
    


}

void DisplayRecursiveReverse(struct Node *p){
      if(p!=NULL){
        DisplayRecursiveReverse(p->next);
        printf("%d\n",p->data);

      }

}


int Count(struct Node *p){
   int c=0;
   while(p!=NULL){
   c++;
   p=p->next;

   }

   return c;

}

int CountRecursive(struct Node *p){
   if(p!=NULL){
       return CountRecursive(p->next)+1;

   }
   else 
      return 0;


}



int SumIterative(struct Node *p){
    int sum=0;
    while(p!=NULL){
    sum+=p->data;
    p=p->next;

   }

   return sum;
}


int SumRecursive(struct Node *p){
     if(p!=NULL){
      return SumRecursive(p->next)+p->data;

     } 
return 0;
}


int MaxElem(struct Node *p){
   int max=-32768;
   while(p!=NULL){
     if(p->data > max){
        max=p->data;
     }
     p=p->next;
   
    }
return max;


}

struct Node * Search(struct Node *p,int key){
  while(p!=NULL){
     if(key==p->data){
        return p;
     }

     p=p->next;
  
    }

return NULL;

}


struct Node *SearchRecursive(struct Node *p,int key){
    if(p==NULL){
        return NULL;
    }
    if(key==p->data){
        return p;
    }

    return Search(p->next,key);

}


void Insert(int pos,int elem){
  struct Node *t =(struct Node *)malloc(sizeof(struct Node));

  t->data=elem;
  t->next=NULL;

  if(pos==0){
    t->next=first;
    first=t;

}

  else if(pos>0){
    struct Node *p=first;
    for(int i=0;i<pos-1 && p!=NULL;i++){
          p=p->next;


    }
    t->next=p->next;
    p->next=t;





  }





}


void InsertLast( struct Node *first,int x){
struct  Node* p=first;
struct Node * t=(struct Node *)malloc(sizeof(struct Node));
t->data=x;

if(first==NULL){
first=t;
t->next=NULL;

}

else{
 while(p->next!=NULL){
  p=p->next;


}

p->next=t;
t->next=NULL;



}







}


struct Node* InsertInSorted(struct Node *first, int x) {
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->next = NULL;
    t->data = x;

    
    if (first == NULL || first->data > x) {
        t->next = first;
        first = t;
    }
    else {
        struct Node *q = NULL;
        struct Node *p = first;

        while (p != NULL && p->data < x) {
            q = p;
            p = p->next;
        }

        q->next = t;
        t->next = p;
    }

    return first;  
}




void Delete(int pos){
  struct Node *p=first;
   if(pos==0){
      p=p->next;
      free(first);
      first=p;


  }

  else if(pos>0){
        struct Node *q=NULL;
        for(int i=0;i<pos && p;i++){
            q=p;
            p=p->next;

        }
     
        q->next=p->next;
        free(p);



  }





}


int IsSorted(){
 int min=INT_MIN;
 struct Node *p=first;
 while(p!=NULL){
   if(p->data<min){
      return 0;
   }

min=p->data;
p=p->next;


 }

return 1;

}


void ReverseLinkedList(){
  struct Node *p=first;
  struct Node *q=NULL;
  struct Node * r=NULL;
  
  while(p!=NULL){
   r=q;
   q=p;
   p=p->next;
   q->next=r;
   

  }

first=q;  //esel nra hamara petq vor verjum first beri verji node i vra u vor tpeluc dranic sksac gna


}


void CreateLoopedList() {
    struct Node *t1, *t2, *t3, *t4, *t5;

    t1 = (struct Node *)malloc(sizeof(struct Node));
    t2 = (struct Node *)malloc(sizeof(struct Node));
    t3 = (struct Node *)malloc(sizeof(struct Node));
    t4 = (struct Node *)malloc(sizeof(struct Node));
    t5 = (struct Node *)malloc(sizeof(struct Node));

    t1->data = 1; t1->next = t2;
    t2->data = 2; t2->next = t3;
    t3->data = 3; t3->next = t4;
    t4->data = 4; t4->next = t5;
    t5->data = 5; t5->next = t2; // Creates a loop: 5 → 2

    first = t1;
}

void CreateNormalList() {
    struct Node *t1, *t2, *t3, *t4, *t5;

    t1 = (struct Node *)malloc(sizeof(struct Node));
    t2 = (struct Node *)malloc(sizeof(struct Node));
    t3 = (struct Node *)malloc(sizeof(struct Node));
    t4 = (struct Node *)malloc(sizeof(struct Node));
    t5 = (struct Node *)malloc(sizeof(struct Node));

    t1->data = 1; t1->next = t2;
    t2->data = 2; t2->next = t3;
    t3->data = 3; t3->next = t4;
    t4->data = 4; t4->next = t5;
    t5->data = 5; t5->next = NULL;  // No loop

    first = t1;
}




int CheckLoop(){
  struct Node *p=first->next;
  struct Node *q=first;
  while(p && q){
     if(p==q){
      return 1;
     }

  p=p->next->next;
  q=q->next;


  }

return 0;


}






int main(){
//int array[5]={0,1,2,3,4};
//Create(array,5);
//DisplayIterative(first);
//DisplayRecursive(first);
//DisplayRecursiveReverse(first);
//printf("the count of nodes is %d\n",Count(first));
//printf("the count of node in recursive is %d\n",CountRecursive(first));
//printf("the sum is iterative %d\n",SumIterative(first));
//printf("the sum is recursive %d\n",SumRecursive(first));
//printf("the max element is %d\n",MaxElem(first));

/*struct Node * temp=Search(first,3);
if(temp!=NULL){
   printf("the value is found %d",temp->data);

}


else{
    printf("the value is not found");
}
*/
/*
struct Node * temp=SearchRecursive(first,3);
if(temp!=NULL){
   printf("the value is found %d",temp->data);

}


else{
    printf("the value is not found");
}
*/


/*int A[] = {10, 20, 30, 40,50,60,70,80,90};
Create(A, 9);
*/     
//Insert(0,15);
//InsertLast(first,55);
//InsertInSorted(first,1);
//Delete(0);
/*if(IsSorted()){
   printf("sorted\n");

}

else{
  printf("not sorted\n");


}
*/
//ReverseLinkedList();



//DisplayIterative(first);

//CreateLoopedList();
CreateNormalList();

if(CheckLoop()){
  printf("contains loop");



}

else{
  printf("doesnt contain loop");


}





    return 0;
}


#include <stdio.h>
#include <stdlib.h>


struct Node {
   struct Node *lchild;
   int data;
   struct Node *rchild;



};

struct Node* SearchIterative(struct Node *t , int key){
     while(t!=NULL){

   if(t->data==key){
    return t;
   }

   else if(t->data<key){
       t=t->lchild;

   }

   else{
      t=t->rchild;

   }
     }

    return NULL;

    }


struct Node *SearchRecursive(struct Node *t , int key){
      if(t!=NULL){
         if(t->data==key){
           return t;
         } 
        else if(t->data<key){
            return SearchRecursive(t->lchild,key);
        }
       else{
            return SearchRecursive(t->rchild,key);

       }

      }

return NULL;



}

struct Node* InsertIterative(struct Node *v, int value) {
    struct Node *p = v;
    struct Node *t = NULL;

    while (p != NULL) {
        if (p->data == value) {
            return NULL; 
        }

        t = p; 

        if (value < p->data) {
            p = p->lchild;
        } else {
            p = p->rchild;
        }
    }

  
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->lchild = newNode->rchild = NULL;

    if (t == NULL) {
        return newNode;
    }

    if (value < t->data) {
        t->lchild = newNode;
    } else {
        t->rchild = newNode;
    }

    return newNode;
}



struct Node *t=NULL;
struct Node *InsertRecursive(struct Node *v, int value){
       if(v!=NULL){
           if(v->data==value)
               return NULL;
           else if(value<v->data){
               t=v;
               return InsertRecursive(v->lchild,value);

           }
           
           else {
               t=v;
               return InsertRecursive(v->rchild,value);

           }


       }

      else{
            v=(struct Node *)malloc(sizeof(struct Node ));
          v->lchild=NULL;
          v->data=value;
          v->rchild=NULL;

         if (t != NULL) {
            if (value < t->data)
                t->lchild = v;
            else
                t->rchild = v;
        }

        return v;
    }







}



struct Node* CreateIterative(int arr[], int n){
      struct Node *root = (struct Node *)malloc(sizeof(struct Node));
      root->data = arr[0];
      root->lchild = root->rchild = NULL;
      if (n>1)
      for(int i=1;i<n;i++){
           if(SearchIterative(root,arr[i])==NULL){
               InsertIterative(root,arr[i]);
           }   


      }


return root;


}

void InorderTraversal(struct Node* t){
 if(t!=NULL){
        InorderTraversal(t->lchild);
        printf("%d  ",t->data);
        InorderTraversal(t->rchild);

 }

}






struct Node* findInorderPredecessorParent(struct Node *v) {
    struct Node *t;
    if (v == NULL || v->lchild == NULL)
        return NULL;

    t = v;
    v = v->lchild;

    if (v->rchild == NULL)
        return NULL; 

    while (v->rchild != NULL) {
        t = v;
        v = v->rchild;
    }

    return t;  
}




void DeleteNode(struct Node *v,int value){
    struct Node *p = v;
    struct Node *t = NULL;

    while (p != NULL) {
        if (p->data == value) {
            if(p->lchild==NULL && p->rchild==NULL){
                if(t->lchild==p) t->lchild=NULL;
                else if(t->rchild==p) t->rchild=NULL;
                free(p);
                return; 
            }
             
            else if(p->lchild!=NULL && p->rchild!=NULL){
                struct Node *InorderPredecessorParent=findInorderPredecessorParent(p);
                struct Node *InorderPredecessor=InorderPredecessorParent->rchild;
                InorderPredecessorParent->rchild=InorderPredecessor->lchild;
                InorderPredecessor->lchild=p->lchild;
                InorderPredecessor->rchild=p->rchild;
                if(t->lchild==p) t->lchild=InorderPredecessor;
                else if(t->rchild==p) t->rchild=InorderPredecessor;
                p->lchild=NULL;
                p->rchild=NULL;
                free(p);
                return; 
            }

            else if (t != NULL && t->lchild == p) {
                if (p->lchild != NULL) {
                    t->lchild = p->lchild;
                } else if (p->rchild != NULL) {
                    t->lchild = p->rchild;
                }
                free(p); 
                return; 
            }

            else if (t != NULL && t->rchild == p) {
                if (p->lchild != NULL) {
                    t->rchild = p->lchild;
                } else if (p->rchild != NULL) {
                    t->rchild = p->rchild;
                }
                free(p);
                return; 
            }
        }

        t = p; 
        if (value < p->data) {
            p = p->lchild;
        } else {
            p = p->rchild;
        }  
    }
}

        //one issues is  that it cant delete root node petqa dzvi
        
    
    















int main(){
int arr[] = { 50,30, 70, 20, 40, 60, 80,10, 25, 35, 45, 55, 65, 75, 85};


struct Node *root=CreateIterative(arr,15);
DeleteNode(root,70);

InorderTraversal(root);




    return 0;
}

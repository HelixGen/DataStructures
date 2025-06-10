#include <stdio.h>
#include <stdlib.h>

struct Matrix{
   int A[10];
   int n;

};



void setDiagonalElement(struct Matrix *m, int i,int j,int x){
   if(i==j){
     m->A[i-1]=x;

   }


}


int getDiagonalElement(struct Matrix m, int i, int j){
   if(i==j){
    return m.A[i-1];
   }

else{

    return 0;
}


}



void setLowerDiagonalElement(struct Matrix *m, int i, int j,int x){
     if(i>=j){
        int index=((i*(i-1))/2)+(j-1);
        m->A[index]=x;

     }

    else{
     int index=((i*(i-1))/2)+(j-1);
        m->A[index]=0;

    }


}



    int getLowerDiagonalElement(struct Matrix m, int i,int j){
    if(i>=j){
    int index=((i*(i-1))/2)+(j-1);
     return  m.A[index];

}

return 0;

}


void setUpperDiagonalElement(struct Matrix *m, int i, int j,int x){
     if(i<=j){
        int index = ((i - 1) * m->n - ((i - 2) * (i - 1)) / 2) + (j - i);
        m->A[index]=x;

     }

    else{
     int index = ((i - 1) * m->n - ((i - 2) * (i - 1)) / 2) + (j - i);;
        m->A[index]=0;

    }


    }

   int getUpperDiagonalElement(struct Matrix m, int i,int j){
    if(i<=j){
    int index = ((i - 1) * m.n - ((i - 2) * (i - 1)) / 2) + (j - i);
     return  m.A[index];

}

return 0;

} 


void setTriDiagonalElement(struct Matrix *m, int i, int j,int x){
     if(i-j==1){
        int index = i-1;
        m->A[index]=x;

     }

    else if(i-j==0){
          int index =m->n-1+i-1;
          m->A[index]=x;

    }
   
    else if(i-j==-1){
           int index = (2*m->n)-1+i-1;
           m->A[index]=x;
    }


    }


 int getTriDiagonalElement(struct Matrix m, int i,int j){
     if(i-j==1){
        int index = i-1;
       return m.A[index];

     }

    else if(i-j==0){
          int index =m.n-1+i-1;
       return   m.A[index];

    }
   
    else if(i-j==-1){
           int index = (2*m.n)-1+i-1;
         return  m.A[index];
    }

return 0;

} 


void setToeplitzElement(struct Matrix *m, int i, int j,int x){
     if(i<=j){
        int index = j-i;
        m->A[index]=x;

     }

    else if(i>=j){
          int index =m->n+i-j-1;
          m->A[index]=x;

    }
   
    }


int getToeplitzElement(struct Matrix m, int i,int j){
    if(i<=j){
        int index = j-i;
       return m.A[index];

     }

    else if(i>=j){
          int index =m.n+i-j-1;
         return  m.A[index];

    }
    



return 0;

} 







void displayMatrix(struct Matrix m) {
    for (int i = 1; i <= m.n; i++) {
        for (int j = 1; j <= m.n; j++) {
            if (i == j)
                printf("%d ", m.A[i - 1]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

void displayLowerMatrix(struct Matrix m) {
    for (int i = 1; i <= m.n; i++) {
        for (int j = 1; j <= m.n; j++) {
            printf("%d ", getLowerDiagonalElement(m, i, j));
        }
        printf("\n");
    }
}


void displayUpperMatrix(struct Matrix m) {
    for (int i = 1; i <= m.n; i++) {
        for (int j = 1; j <= m.n; j++) {
            printf("%d ", getUpperDiagonalElement(m, i, j));
        }
        printf("\n");
    }
}

void displayTriMatrix(struct Matrix m){
for (int i = 1; i <= m.n; i++) {
        for (int j = 1; j <= m.n; j++) {
            printf("%d ", getTriDiagonalElement(m, i, j));
        }
        printf("\n");
    }

}


void displayToeplitzMatrix(struct Matrix m) {
    for (int i = 1; i <= m.n; i++) {
        for (int j = 1; j <= m.n; j++) {
            printf("%d ", getToeplitzElement(m, i, j));
        }
        printf("\n");
    }
}


 

int main(){
struct Matrix DiagonalMatrice;
DiagonalMatrice.n=4;

    setDiagonalElement(&DiagonalMatrice, 1, 1, 5);
    setDiagonalElement(&DiagonalMatrice, 2, 2, 8);
    setDiagonalElement(&DiagonalMatrice, 3, 3, 9);
    setDiagonalElement(&DiagonalMatrice, 4, 4, 12);

    displayMatrix(DiagonalMatrice);
    printf("\n");

    struct Matrix LowerDiagonalMatrice;
    LowerDiagonalMatrice.n = 4;
    
    setLowerDiagonalElement(&LowerDiagonalMatrice, 1, 1, 1);
    setLowerDiagonalElement(&LowerDiagonalMatrice, 2, 1, 2);
    setLowerDiagonalElement(&LowerDiagonalMatrice, 2, 2, 3);
    setLowerDiagonalElement(&LowerDiagonalMatrice, 3, 1, 4);
    setLowerDiagonalElement(&LowerDiagonalMatrice, 3, 2, 5);
    setLowerDiagonalElement(&LowerDiagonalMatrice, 3, 3, 6);
    setLowerDiagonalElement(&LowerDiagonalMatrice, 4, 1, 7);
    setLowerDiagonalElement(&LowerDiagonalMatrice, 4, 2, 8);
    setLowerDiagonalElement(&LowerDiagonalMatrice, 4, 3, 9);
    setLowerDiagonalElement(&LowerDiagonalMatrice, 4, 4, 10);
   displayLowerMatrix(LowerDiagonalMatrice);
   printf("\n");



struct Matrix UpperDiagonalmatrice;
    UpperDiagonalmatrice.n = 4;

    setUpperDiagonalElement(&UpperDiagonalmatrice, 1, 1, 1);
    setUpperDiagonalElement(&UpperDiagonalmatrice, 1, 2, 2);
    setUpperDiagonalElement(&UpperDiagonalmatrice, 1, 3, 3);
    setUpperDiagonalElement(&UpperDiagonalmatrice, 1, 4, 4);

    setUpperDiagonalElement(&UpperDiagonalmatrice, 2, 2, 5);
    setUpperDiagonalElement(&UpperDiagonalmatrice, 2, 3, 6);
    setUpperDiagonalElement(&UpperDiagonalmatrice, 2, 4, 7);

    setUpperDiagonalElement(&UpperDiagonalmatrice, 3, 3, 8);
    setUpperDiagonalElement(&UpperDiagonalmatrice, 3, 4, 9);

    setUpperDiagonalElement(&UpperDiagonalmatrice, 4, 4, 10);

    displayUpperMatrix(UpperDiagonalmatrice);
     printf("\n");

// symmetricy heriqa uppery u lowery store anes menak


struct Matrix TriDiagonalMatrice;
    TriDiagonalMatrice.n = 4;

    // Set values for the tridiagonal matrix
    setTriDiagonalElement(&TriDiagonalMatrice, 1, 1, 1);
    setTriDiagonalElement(&TriDiagonalMatrice, 1, 2, 2);
    setTriDiagonalElement(&TriDiagonalMatrice, 2, 1, 3);
    setTriDiagonalElement(&TriDiagonalMatrice, 2, 2, 4);
    setTriDiagonalElement(&TriDiagonalMatrice, 2, 3, 5);
    setTriDiagonalElement(&TriDiagonalMatrice, 3, 2, 6);
    setTriDiagonalElement(&TriDiagonalMatrice, 3, 3, 7);
    setTriDiagonalElement(&TriDiagonalMatrice, 3, 4, 8);
    setTriDiagonalElement(&TriDiagonalMatrice, 4, 3, 9);
    setTriDiagonalElement(&TriDiagonalMatrice, 4, 4, 10);

    displayTriMatrix(TriDiagonalMatrice);
    printf("\n");


 struct Matrix m;
    m.n = 4;

    // First row
    setToeplitzElement(&m, 1, 1, 1);
    setToeplitzElement(&m, 1, 2, 2);
    setToeplitzElement(&m, 1, 3, 3);
    setToeplitzElement(&m, 1, 4, 4);

    // First column (excluding m[1][1])
    setToeplitzElement(&m, 2, 1, 5);
    setToeplitzElement(&m, 3, 1, 6);
    setToeplitzElement(&m, 4, 1, 7);

    displayToeplitzMatrix(m); 




    return 0;
}
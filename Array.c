#include <stdio.h>
#include <stdlib.h>



struct Array{
   int *A;
   int size;
   int length;


};

void Append(struct Array *arr,int x){
      if(arr->length<arr->size)
         arr->A[arr->length++]=x;
}


void Insert(struct Array *arr, int index, int x){
         int i;
         if(index>=0 && index<=arr->length){
              for(i=arr->length;i>index;i--)
                arr->A[i]=arr->A[i-1];
                arr->A[index]=x;
                arr->length++;

         }


}


int Delete(struct Array *arr, int index){
     int x=0;
     if(index>=0 && index <=arr->length){
     x=arr->A[index];
     for(int i=index; i<arr->length-1;i++)
       arr->A[i]=arr->A[i+1];
       arr->length--;
       return x;

     }
return 0;

}



void Display(struct Array arr){
    int i;
    printf("Elements are\n");
    for(i=0;i<arr.length;i++)
        printf("%d\n", arr.A[i]);
        
}


int LinearSearch(struct Array arr,int elem){
  int i=0;
  for(i;i<arr.length;i++)
      if(arr.A[i]==elem)
        return i;
      
  return -1;
  


}

int LinearSearchImprovedTransposition(struct Array *arr, int elem){
    for (int i = 0; i < arr->length; i++) {
        if (arr->A[i] == elem) {
            if (i > 0) {
            
                int temp = arr->A[i];
                arr->A[i] = arr->A[i - 1];
                arr->A[i - 1] = temp;
              
            }
            return i; 
        }
    }
    return -1;
    

// move to head nel henc qtnuma tanuma skizb


}

int BinarySearchIterative(struct Array arr, int elem) {
    int l = 0;
    int h = arr.length - 1;

    while (l <= h) {
        int mid = (l + h) / 2; 
        if (elem == arr.A[mid])
            return mid;
        else if (elem < arr.A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }

    return -1; 
}



int BinarySearchRecursive(struct Array arr, int l, int elem, int h){
  
if(l<=h){
    int mid = (l + h) / 2; 
        if (elem == arr.A[mid]){
            return mid;

        }
            
        else if (elem < arr.A[mid]){
            h = mid - 1;
          return  BinarySearchRecursive(arr,l,elem,h);

        }
            
        else{
            l = mid + 1; 
          return  BinarySearchRecursive(arr,l,elem,h);
        }




}

return -1;


}


int Get(struct Array arr,int index){
  if(index >=0 && index <arr.length)
      return arr.A[index];

 return -1;

}

void Set(struct Array arr,int index,int elem){
    if(index >=0 && index <arr.length)
        arr.A[index]=elem;
  
  }


int min(struct Array arr){
  int min=arr.A[0];
  for(int i=1;i<arr.length;i++){
    if(arr.A[i]<min){
        min=arr.A[i];
    }
  }

 return min; 

}

int max(struct Array *arr) {
    int max = arr->A[0];
    for (int i = 1; i < arr->length; i++) {
        if (arr->A[i] > max) {
            max = arr->A[i];
        }
    }
    return max;
}





int Sum(struct Array arr, int n){
   if(arr.length<0)
           return 0;
   

   else
     return Sum(arr, arr.length-1)+arr.A[n];



}


void ReverseArray(struct Array arr){
  int i=0;
  int j=arr.length-1;
  while(i<j){
     int temp=arr.A[i];
     arr.A[i]=arr.A[j];
     arr.A[j]=temp;
     i++;
     j--;


  }



}

int IsArraySorted(struct Array arr){
    for(int i=0;i<arr.length-1;i++){
         if(arr.A[i]>arr.A[i+1]){
            return 0;
         }


    }
 
return 1;


}


void NegPosChange(struct Array *arr) {
    int i = 0;
    int j = arr->length - 1;

    while (i < j) {
        while (arr->A[i] < 0) i++;
        while (arr->A[j] >= 0) j--;

        if (i < j) {
            int temp = arr->A[i];
            arr->A[i] = arr->A[j];
            arr->A[j] = temp;
        }
    }
}







int main(int argc, char *argv[]){
    /*
    int n,i;
    struct Array arr;
    printf("Enter the size of array\n");
    scanf("%d", &arr.size);
    arr.A=(int *)malloc(arr.size*sizeof(int));
    arr.length=0;    
    printf("enter the number of elements\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
       scanf("%d",&arr.A[i]);
    arr.length=n;

  Insert(&arr,4,7);
  Delete(&arr,4);

      Display(arr);
*/

 /*struct Array arr;
    arr.size = 7;
    arr.length = 7;  // IMPORTANT!
    arr.A = (int *)malloc(arr.size * sizeof(int));

    arr.A[0] = 0;
    arr.A[1] = 7;
    arr.A[2] = 10;
    arr.A[3] = 11;
    arr.A[4] = 14;
    arr.A[5] = 15;
    arr.A[6] = 17;

    */
/*
printf("the result of linear search Improved Transposition is %d \n", LinearSearchImprovedTransposition(&arr,17));
printf("the result of linear search Improved Transposition is %d \n", LinearSearchImprovedTransposition(&arr,17));
printf("the result of binary  search Iterative %d \n", BinarySearchIterative(arr,11));
printf("the result of binary  search Recursive %d \n", BinarySearchRecursive(arr,0,11,arr.length-1));
*/
//printf("the element of index %d is %d\n",4,Get(arr,4));
//printf("the min is %d\n",min(arr));
//printf("the max is %d\n",max(arr));
//printf("is sorted %d",IsArraySorted(arr));


/*
struct Array arr;
    arr.size = 7;
    arr.length = 7;  // IMPORTANT!
    arr.A = (int *)malloc(arr.size * sizeof(int));

    arr.A[0] = -6;
    arr.A[1] = 3;
    arr.A[2] = -8;
    arr.A[3] = 10;
    arr.A[4] = 5;
    arr.A[5] = -7;
    arr.A[6] = -9;

NegPosChange(&arr);

for(int i=0;i<arr.length;i++){
    printf("the numbers are %d\n",arr.A[i]);
}


*/

 struct Array arr;
arr.size = 10;
arr.length = 10;
arr.A = (int *)malloc(arr.size * sizeof(int));

arr.A[0] = 6;
arr.A[1] = 7;
arr.A[2] = 8;
arr.A[3] = 9;
arr.A[4] = 11;
arr.A[5] = 12;
arr.A[6] = 15;
arr.A[7] = 16;
arr.A[8] = 17;
arr.A[9] = 18;

// Create a bitset array
int maxVal = max(&arr);  // assume max() is already defined
struct Array bitset;
bitset.size = maxVal + 1;
bitset.length = maxVal + 1;
bitset.A = (int *)malloc(bitset.size * sizeof(int));

// Initialize all elements to 0
for (int i = 0; i < bitset.length; i++) {
    bitset.A[i] = 0;
}

// Mark presence of elements from arr
for (int i = 0; i < arr.length; i++) {
    bitset.A[arr.A[i]]++;
}

// Print missing elements
for (int i = 1; i < bitset.length; i++) {
    if (bitset.A[i] == 0) {
        printf("%d element is missing \n", i);  // FIX: print i, not bitset.A[i]
    }
}


    return 0;

}


// duplicate qtnely mekel sumnel nuyn dzev heshta
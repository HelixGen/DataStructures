#include <stdio.h>


int SumNnaturalNumbers(int n){
   if(n==0){
      return 0;

   }

   else 
    return SumNnaturalNumbers(n-1)+n;


}


int factorial(int n){
   if(n==0 || n==1)
      return 1;
    else
      return factorial(n-1)*n;


}


int Power(int m,int n){
  if(n==0)
      return 1;
  else if(n>0)
     return Power(m,n-1)*m;


}


double TailorSeries(int x, int n){
    if(n==0)
       return 1;

    else {
       int r= TailorSeries(x,n-1);
       int p=Power(x,n);
       int f=factorial(n);
       return r+(p/f);
        
 

    }


}


int fibonacci(int n){
  if(n==0)
    return 0;
  else if(n==1)
   return 1;
  
   else{
    return fibonacci(n-2)+fibonacci(n-1);

   }


}


int C(int n, int r){
   if(r==0|| r==n){
    return 1;
   }
   
    else
    return C(n-1,r-1)+C(n-1,r);
}


int main(){
  printf(" The sum of 10 natural numbers is %d\n" ,SumNnaturalNumbers(10));
  printf("the factorial of 6 natural numbers is %d\n ",factorial(6));
  //printf("the power of 2^5 is %d\n", Power(2,5));
  //printf("tailor series of number e^2 is %d",TailorSeries(2,10));
  
  printf("the fibonacci %d",fibonacci(5));
  printf("the combination of C(4,3) is %d",C(4,3)); 
  return 0;
}
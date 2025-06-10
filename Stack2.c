#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int size;
    int Top;
    char *s;
};

void push(struct Stack *st, char x) {
    if (st->Top == st->size - 1) {
        printf("Stack Overflow\n");
    } else {
        st->Top++;
        st->s[st->Top] = x;
    }
}


char pop(struct Stack *st) {
    char x = '\0';  

    if (st->Top == -1) {
        printf("Stack Underflow\n");
    } else {
        x = st->s[st->Top];
        st->Top--;
    }

    return x;
}


char stackTop(struct Stack st){
  if(st.Top==-1){
     return '\0';

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




int isOpeniningBracket(char s){
  return s=='(' ? 1:0;


}

int isClosingBracket(char s){
  return s==')' ? 1:0;


}


int isOpeningBracketExtended(char s){
      if(s=='(' || s=='{'||s=='['){
        return 1;

      }
      else 
      return 0;


}

int isclosingBracketExtended(char s){
      if(s==')' || s=='}'||s==']'){
        return 1;

      }
      else 
      return 0;


}





int ValidParanthesisExtended(char *str){
 struct Stack st;
 st.size=strlen(str);
 st.Top=-1;
 st.s=(char *)malloc(st.size*sizeof(char));
    for(int i=0;str[i]!='\0';i++){
    if(isOpeningBracketExtended(str[i])){
       push(&st,str[i]);
       
    }

    else if(isclosingBracketExtended(str[i])){
        int difference=str[i]-stackTop(st);
        if(difference==1||difference==2||difference ==3){
          if(isEmpty(st)) return 0;
         else 
           pop(&st);
             

    }
    else{
         return 0;

    } 
   

}


}
   if(isEmpty(st)){
       return 1;

   }

   else 
   return 0;

}



int ValidParanthesis(char *str){
 struct Stack st;
 st.size=strlen(str);
 st.Top=-1;
 st.s=(char *)malloc(st.size*sizeof(char));
    for(int i=0;str[i]!='\0';i++){
    if(isOpeniningBracket(str[i])){
       push(&st,str[i]);
       
    }

    else if(isClosingBracket(str[i])){
         if(isEmpty(st)) return 0;
         else 
           pop(&st);
             

    }



}
   if(isEmpty(st)){
       return 1;

   }

   else 
   return 0;

}










int main(){

    char str[]="[{()}([])]";
    if(ValidParanthesisExtended(str)){
        printf("is valid");
    }

    else{

        printf("invalid");
    }



    return 0;
}
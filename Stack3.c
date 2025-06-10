#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

struct Stack {
    int size;
    int Top;
    char *s;
};


struct StackInt{
   int size;
   int Top;
   int *s;

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
   

    if (st->Top == -1) {
        return '\0';
    } else {
        return st->s[st->Top--];
        
    }

    
}


char stackTop(struct Stack st){
  if(st.Top==-1){
     return '\0';

  }

  else{
    return st.s[st.Top];
  }

}



void pushInt(struct StackInt *st, int x) {
    if (st->Top == st->size - 1) {
        printf("Stack Overflow\n");
    } else {
        st->Top++;
        st->s[st->Top] = x;
    }
}

int popInt(struct StackInt *st) {
    if (st->Top == -1) {
        printf("Stack Underflow\n");
        return 0;
    } else {
        return st->s[st->Top--];
    }
}


int stackTopInt(struct StackInt st){
  if(st.Top==-1){
     return 0;

  }

  else{
    return st.s[st.Top];
  }

}






int isEmpty(struct Stack st){
   return st.Top == -1;
}






int isOperator(char s){
    if(s=='*' || s=='+' || s=='-' || s=='/' || s=='^')
        return 1;
    return 0;
}


int isParanthesis(char s){
   if(s=='(')
   return 1;

   return 0;

}





int precedence(char s){
  if(s=='*'||s=='/')
     return 2;
   else if(s=='+'||s=='-')
      return 1;

      return 0;

    }



int outStackPrecedence(char s) {
    switch(s) {
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 4;
        case '^': return 7;
        case '(': return 8;
        case ')': return 1;
        default: return 0;
    }
}

int inStackPrecedence(char s) {
    switch(s) {
        case '+':
        case '-': return 3;
        case '*':
        case '/': return 5;
        case '^': return 6;
        case '(': return 1;
        default: return 0;
    }
}









char* infixToPostifx(char *str){
   struct Stack st;
   st.size=strlen(str);
   st.Top=-1;
   st.s=(char *)malloc(st.size*sizeof(char));
   char *postfix = (char *)malloc((strlen(str) + 1) * sizeof(char)); 
   int i=0;
    int j=0;
    
    while(str[i]!='\0'){
         if(isOperator(str[i])){
              if(precedence(str[i])>precedence(stackTop(st))){
                 push(&st,str[i]);
                 i++;
              }
             else{
                 postfix[j]=pop(&st);
                 j++;

             }
         
         }  
         else {
               postfix[j]=str[i];
               i++;
               j++;

         }
         
}

while(!isEmpty(st)){
  postfix[j]=pop(&st);
  j++;

}

postfix[j]='\0';
free(st.s);
return postfix;

}




char* infixToPostifxExtended(char *str){
   struct Stack st;
   st.size=strlen(str);
   st.Top=-1;
   st.s=(char *)malloc(st.size*sizeof(char));
   char *postfix = (char *)malloc((strlen(str) + 1) * sizeof(char)); 
   int i=0;
   int j=0;
    
    while(str[i]!='\0'){
         if(isOperator(str[i]) || isParanthesis(str[i])){
              if(outStackPrecedence(str[i])>inStackPrecedence(stackTop(st))){
                 push(&st,str[i]);
                 i++;
              }
             else{
                 if(!isParanthesis(stackTop(st))){
                      postfix[j]=pop(&st);
                      j++;

                 }
               
                 else {
                    pop(&st);
                    i++;
                 }

            
            }
         
         }  
        
        
        else if(str[i]==')'){
                   if(!isParanthesis(stackTop(st))){
                      postfix[j]=pop(&st);
                      j++;

                   }


                  else{
                     pop(&st);
                     i++;

                  }


        }
        
        
        
         else {
               postfix[j]=str[i];
               i++;
               j++;

         }
         
}

while(!isEmpty(st)){
  postfix[j]=pop(&st);
  j++;

}

postfix[j]='\0';
free(st.s);
return postfix;

}

int performOperation(char op, int s1, int s2) {
    switch(op) {
        case '+': return s1 + s2;
        case '-': return s1 - s2;
        case '*': return s1 * s2;
        case '/': return s1 / s2;
        case '^': return (int)pow(s1, s2);
    }
    return 0;
}






int calculation(char *str) {
    struct StackInt st;
    st.size = strlen(str);
    st.Top = -1;
    st.s = (int *)malloc(st.size * sizeof(int));
    int i = 0;

    while(str[i] != '\0') {
        if (isdigit(str[i])) {
            pushInt(&st, str[i] - '0');
            i++;
        }
        else if (isOperator(str[i])) {
            int s1 = popInt(&st);
            int s2 = popInt(&st);
            int result = performOperation(str[i], s2, s1);
            pushInt(&st, result);
            i++;
        }
        else {
            i++;
        }
    }

    int finalResult = popInt(&st);
    free(st.s);
    return finalResult;
}









int main(){
 /* char str[] = "A+B*C-D/E";
char *str2 = infixToPostifx(str);  // pointer, not array

int j = 0;
while (str2[j] != '\0') {
    printf("%c", str2[j]);  // fixed quotes
    j++;
}
*/

 char expr[] = "23+5*";
    char *postfix = infixToPostifxExtended(expr);
    printf("Infix   : %s\n", expr);
    printf("Postfix : %s\n", postfix);
    printf("result is: %d\n",calculation(postfix));
     
    free(postfix);











    return 0;
}
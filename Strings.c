#include <stdio.h>
#include <stdlib.h>


int LengthOfString(char string[]){
   int i;
   for(i=0;string[i]!='\0';i++){}
   return i;

};

char* ChangeUpperToLower (char string[]){
   int i;
   for(i=0;string[i]!='\0';i++){
    string[i]=string[i]+32;


   }

   return string;


}

char *ToggledString(char string[]){
   int i;
   for(i=0;string[i]!='\0';i++){
      if(string[i]>=65 && string[i]<=90){
        string[i]=string[i]+32;
      }

      else if(string[i]>=97 && string[i]<=122){
        string[i]=string[i]-32;
      }


   }

   return string;


}


int CountOfWord(char string[]){
   int vcount=0;
   int i=0;
   while(string[i]!='\0'){
    if(string[i]==' ' && string[i-1]!=' '){
       vcount++;
       
    }
   
    i++;

   }
 return vcount+1;  //loopov hashvum enq space eri qanaky +1 enq anum vor word count ta


}


int CountOfWovels(char string[]){
     int count=0;
     int i=0;
     while(string[i]!='\0'){
       if(string[i]=='a'||string[i]=='e'||string[i]=='o'||string[i]=='i'||string[i]=='A'||string[i]=='E'||string[i]=='O'||string[i]=='I')
         count++;
      i++; 

     }

return count;
}


int IsValid(char string[]){
  int valid=1;
  int i=0;
  while(string[i]!='\0'){
    if(!((string[i]>=48 && string[i]<=57)||(string[i]>=65 && string[i]<=90)||(string[i]>=97 && string[i]<=122)))
      valid=0; 


    i++;
  }

  return valid;

}


char *ReverseOfWord(char string[]){
int i=0;
int j=LengthOfString(string)-1;
while(i<j){
char temp=string[i];
string[i]=string[j];
string[j]=temp;
i++;
j--;


}

return string;

}


int EqualStrings(char str1[],char str2[]){
   int valid=0;
   int i=0;
   if(LengthOfString(str1)!=LengthOfString(str2)){
      return valid;

   }

   while(str1[i]!='\0'&& str2[i]!='\0'){
       if(str1[i]!=str2[i]){
        return valid;
       }
     i++;
   
      }
    
   valid=1;
   return valid;


}


int CheckPalidrome(char str1[]){
  int i=0;
  int j=LengthOfString(str1)-1;
   int IsPalidrome=0;
  while(i<j){
    if(str1[i]!=str1[j])
    return IsPalidrome;

    i++;
    j--;
     
  

  }

  IsPalidrome=1;
  return IsPalidrome;

}


char *DuplicateLetters(char str1[]){
 int H[52]={0}; // 0–25: a–z, 26–51: A–Z
 int i;
 static char Dubstr[53];
 int k = 0;
 for(i=0;str1[i]!='\0';i++){
   if(str1[i]>=65 && str1[i]<=90){
      H[str1[i]-39]+=1;

   }
    else if(str1[i]>=97 && str1[i]<=122){
        H[str1[i]-97]+=1;
    }
}



for(int j=0;j<52;j++){
   if (H[j] == 2) {
            if (j < 26)
                Dubstr[k++] = j + 97;
            else
                Dubstr[k++] =j+39;
        }

}

Dubstr[k] = '\0';  
return Dubstr;


}


int CheckValidAnagram(char str1[],char str2[]){
      int valid=0;
      int H[26]={0};
      int i;
      for(i=0;str1[i]!='\0';i++){
            H[str1[i]-97]++;

      }
    for(i=0;str2[i]!='\0';i++){
            H[str2[i]-97]--;
           if(H[str2[i]-97]<0){
            return valid;
           }
      
      
      
          }
      
      valid=1;
      return valid;

    }





int main(int argc , char *argv[]){
  char string[]="Anasun";
  printf("the length of string %s is %d \n",string,LengthOfString(string));
 
  char Word[]="WELCOME";
  printf("the lowercase of string is %s \n",ChangeUpperToLower(Word));

  char ToToggleWord[]="weLCoME";
  printf("the toggled string is %s \n", ToggledString(ToToggleWord));


  char expression[]="HOW ARE YOU";
  printf("the count of the words in string is %d \n" ,CountOfWord(expression));
  
  printf("the count of the vovels in string is %d \n" ,CountOfWovels(expression));
  

  char validString[]="HWAREYOU";
  if(IsValid(validString)){
   printf("valid\n");
  }
     else{
   printf("invalid\n");
     }


 printf("the reverse of the string is %s \n",ReverseOfWord(validString));

char w1[]="essa";
char w2[]="esva";

if(EqualStrings(w1,w2)){
  printf("equal\n");
}

else{
   printf("non equal\n");

}

char Palidromestr[]="bobob";
if(CheckPalidrome(Palidromestr)){
    printf("palidrome\n");

}

else{
   printf("non palidrome string \n");

}


char strdub[] = "aaassssppllee";

printf("the dublicates are %s \n",DuplicateLetters(strdub));


char astr1[]="evil";
char astr2[]="vile";

if(CheckValidAnagram(astr1,astr2)){
    printf("valid anagram\n");

}
else {
  printf("not valid anagram\n");


}




    return 0;
}

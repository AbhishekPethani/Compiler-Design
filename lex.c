#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
 
int isKeyword(char buffer[]){
    char keywords[23][10] = {"break","case","char","do","double","else","enum","float","for","goto",
                            "if","int","long","return","short","signed","sizeof","struct","switch","union",
                            "unsigned","void","while"};
    int i, flag = 0;
    for(i = 0; i < 32; ++i){
        if(strcmp(keywords[i], buffer) == 0){
            flag = 1;
            break;
        }
    }
    return flag;
}

void operator(char ch)
{
     FILE *ope; 
     ope = fopen("operator.txt","a+");
     fprintf(ope,"%c\n",ch);
     fclose(ope);
} 

void keyword(char *ch)
{
     FILE *key; 
     key = fopen("keyword.txt","a+");
     fprintf(key,"%s\n",ch);
     fclose(key);
}

void identifier(char *ch)
{
     FILE *iden; 
     iden = fopen("identifier.txt","a+");
     fprintf(iden,"%s\n",ch);
     fclose(iden);
}

int main(){
    char ch, buffer[15], operators[] = "&+-*/%=;,'\"";
    FILE *fp;
    int i,j=0;
    
    fp = fopen("1.txt","r");
    while((ch = fgetc(fp)) != EOF){
           for(i = 0; i < 11; ++i){
               if(ch == operators[i])
               {
                   printf("%c is operator\n", ch);
                   operator(ch);
               }
           }
           if(isalnum(ch)){
               buffer[j++] = ch;
           }
           else if((ch == ' ' || ch == '\n') && (j != 0)){
                   buffer[j] = '\0';
                   j = 0;
                   if(isKeyword(buffer) == 1)
                   {
                       printf("%s is keyword\n", buffer);
                       keyword(buffer);
                       //fprintf(key,"%s",buffer);
                   }
                   else
                   {
                       printf("%s is indentifier\n", buffer);
                       identifier(buffer);
                       //fprintf(iden,"%s",buffer);
                   }
           }
           
    }
    fclose(fp);
    getch();
}          

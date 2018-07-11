#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void main(){
    char ch,ch1;
    FILE *fp, *out;
    int flag =0;
    fp = fopen("input.txt","r");
    out = fopen("output.txt","a+");
	while((ch = fgetc(fp)) != EOF){
		ch1 = ch;
		ch = fgetc(fp);
    	if(ch1 == '/' && ch == '/') 
		{
			ch = fgetc(fp);
				while(ch != '\n')
				{
					fprintf(out,"%c",ch);
					ch = fgetc(fp);
				}
				fprintf(out,"\n");
		}	
		else if(ch1 == '/' && ch == '*')	
		{
			ch = fgetc(fp);
			while(ch != '*')
			{
				fprintf(out,"%c",ch);
				ch = fgetc(fp);
			}
			fprintf(out,"\n");
		}
	}
    fclose(fp);
    fclose(out);
    getch();
}          

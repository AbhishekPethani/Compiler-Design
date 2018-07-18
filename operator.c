#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
	char str[100];
	scanf("%s",str);
	//printf("%s",str);
	char operator1[] = {'+','-','*','/'};
	//printf("%s",operator1);
	char ch;
	int i,j;
	for(j=0;j<strlen(str);j++)
	{
		ch = str[j];
		for(i=0;i<4;i++)
		{
			if(ch == operator1[i])
				printf("%c is a valid operator.\n",ch);
		}
	}
	getch();
}

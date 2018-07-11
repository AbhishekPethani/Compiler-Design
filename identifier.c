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

void main()
{
	char identifier[100];
	//scanf("%s", identifier);
	gets(identifier);
	int j,ch = (int)identifier[0];
	if(isKeyword(identifier) == 1)
    {
        printf("Keyword are not valid identifier.");
    }
	else if((identifier[0] >= 'A' && identifier[0] <= 'Z') || (identifier[0] >= 'a' && identifier[0] <= 'z') || identifier[0] == '_' || !(identifier[0] >= 48 && identifier[0] <= 57) )	
	{
		printf("This is a valid Identifier.");
	}	
	else
	{
		printf("This is a not valid Identifier.");
	}	
	getch();		
}

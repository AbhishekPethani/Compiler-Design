%{
	#include<string.h>
	int word=0,line=0,character=0;
%}

character [a-zA-Z]

%%
[a-zA-Z]+ {word++; 	character += strlen(yytext);}
[\n] {line++;}
. {character++;}
%%

int main()
{
     yyin = fopen("input.txt", "r");
     yylex();
     printf("Number of Lines are: %d\n", line);
     printf("Number of Characters are: %d\n", character);
     printf("Number of Words are: %d\n", word);
	 return 0;
}

int yywrap()
{
    return 1;
}



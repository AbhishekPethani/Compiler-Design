%{
	int vowel=0,consonants=0;
%}

%%
[aeiou] {vowel++;}
[^aeiou^" "\n^] {consonants++;}
%%

int main()
{
     yyin = fopen("input.txt", "r");
     yylex();
     printf("Number of vowel are: %d\n", vowel);
     printf("Number of Characters are: %d\n", consonants);
	 return 0;
}

int yywrap()
{
    return 1;
}



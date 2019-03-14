#include<stdio.h>
#include<string.h>

int palindrome(char *string);

int main()
{
	char str[40];

	scanf("%s",str);
	printf("%d\n",palindrome(str));

	return 0;
}

int palindrome(char *string)
{
	char *rev=string;
	int flag=1;

	while(*string!='\0')
		string++;
	string--;
	while(*rev!='\0' && *string!='\0')
	{
		if(*rev!=*string)
			return 0;
		rev++;
		string--;
	}

	return flag;
}
//Problema 2 - Laboratorul 4

#include"Biblioteca.h";

InternationalStandardBookNumber::InternationalStandardBookNumber(char valueofidenttara[], char valueofidenteditura[], char valueofidenttitlu[])
{
	int i, j, x;
	char c[14];
	for (i = 0, j = 0;i < strlen(valueofidenttara);i++, j++)
		value[j] = valueofidenttara[i];
	value[j++] = '-';
	for (i = 0;i < strlen(valueofidenteditura);i++, j++)
		value[j] = valueofidenteditura[i];
	value[j++] = '-';
	for (i = 0;i < strlen(valueofidenttitlu);i++, j++)
		value[j] = valueofidenttitlu[i];
	value[j++] = '-';
	for (i = 0;i < j;i++)
		c[i] = value[i];
	c[i] = NULL;
	x = concatenarecifre(c);
	if (x % 11 < 10)
		value[j++] = (char)x % 11 + 48;
	else
		value[j++] = 'X';
	value[j] = NULL;
}

InternationalStandardBookNumber::InternationalStandardBookNumber(char valueofisbn[])
{
	int i;
	for (i = 0;i <= strlen(valueofisbn);i++)
		value[i] = valueofisbn[i];
}

InternationalStandardBookNumber::InternationalStandardBookNumber(const InternationalStandardBookNumber &ISBN)
{
	strcpy(this->value, ISBN.value);
}

InternationalStandardBookNumber::~InternationalStandardBookNumber()
{
	//delete[] isbn;
}

int InternationalStandardBookNumber::concatenarecifre(char s1[])
{
	int num = 0, i;
	for (i = 0;i<strlen(s1);i++)
		if (s1[i] >= 48 && s1[i] <= 57)
			num = num * 10 + s1[i] - 48;
	return num;
}

int InternationalStandardBookNumber::validarecifracontrol()
{
	int i, cifcont;
	char c[14];
	if (value[strlen(value) - 1] >= 48 && value[strlen(value) - 1] <= 57)
		cifcont = value[strlen(value) - 1] - 48;
	else
		cifcont = 10;
	for (i = 0;i < strlen(value) - 1;i++)
		c[i] = value[i];
	c[i] = NULL;
	if (cifcont == concatenarecifre(c) % 11)
		return 1;
	else
		return 0;
}

char *InternationalStandardBookNumber::Get_isbn()
{
	return value;
}
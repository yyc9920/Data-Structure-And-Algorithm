#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode
{
    char data[40];
    int year;
} movies;


void main()
{
	int i=0;
	int k=0;
	movies *movie[10];
	while(i<10){
		movie[i] = (movies *)malloc(sizeof(movies));
		i++;
	}
	strcpy(movie[0]->data, "Harry Porter");
	strcpy(movie[1]->data, "Lord of the Ring");
	strcpy(movie[2]->data, "Darknight");
	strcpy(movie[3]->data, "Avengers");
	strcpy(movie[4]->data, "Interstellar");
	strcpy(movie[5]->data, "Conjuring");
	strcpy(movie[6]->data, "Star Wars");
	strcpy(movie[7]->data, "X-Men");
	strcpy(movie[8]->data, "Avatar");
	strcpy(movie[9]->data, "Terminator");

	movie[0]->year = 2001;
	movie[1]->year = 2002;
	movie[2]->year = 2008;
	movie[3]->year = 2012;
	movie[4]->year = 2014;
	movie[5]->year = 2013;
	movie[6]->year = 1977;
	movie[7]->year = 2000;
	movie[8]->year = 2009;
	movie[9]->year = 1984;

	while(k<5){
		printf("%d:%-16s(%d)\t", (k+1), movie[k]->data, movie[k]->year);
		k++;
	}
	printf("\n\n");
	while(k<10){
		printf("%d:%-16s(%d)\t", (k+1) ,movie[k]->data, movie[k]->year);
		k++;
	}
	printf("\n");
}

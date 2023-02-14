#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person
{
	char name[20];
	int age;
};

int search(struct person[], int, struct person);
void insert(struct person[], int, struct person);
void show(struct person[], int);

int main()
{
	struct person sortedVector[10] = { {"John", 20}, {"Mark", 60}, {"Mary", 60}, {"Paul", 40}, {"Paul", 50} }, inputPerson;
	int size = 5, maxSize = 10;
#ifdef DEBUG
	show(sortedVector, size);
#endif
	do
	{
		printf("Enter a name : ");
		scanf("%s", inputPerson.name);
		fflush(stdin);
		printf("Enter an age : ");
		scanf("%d", &inputPerson.age);
		fflush(stdin);
		if (search(sortedVector, size, inputPerson) == 0)
		{
			insert(sortedVector, size, inputPerson);
			size++;
		}
		show(sortedVector, size);
	}
	while (size < maxSize);
	return 0;
}

int search(struct person vector[], int size, struct person inputPerson)
{
	int i = size - 1;
	while (i > 0 && vector[i].age > inputPerson.age || (vector[i].age == inputPerson.age && strcmp(vector[i].name, inputPerson.name) > 0))
	{
		i--;
	}
	return vector[i].age == inputPerson.age && strcmp(vector[i].name, inputPerson.name) == 0;
}

void insert(struct person vector[], int size, struct person inputPerson)
{
	int i = size;
	while (i > 0 && (strcmp(vector[i - 1].name, inputPerson.name) > 0 || (strcmp(vector[i - 1].name, inputPerson.name) == 0 && vector[i - 1].age > inputPerson.age)))
	{
		vector[i] = vector[i - 1];
		i--;
	}
	vector[i] = inputPerson;
}

void show(struct person vector[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%s\t%d\n", vector[i].name, vector[i].age);
	}
	printf("\n");
}
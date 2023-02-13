#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct table
{
	char name[20];
	int age;
};

int return1st65(struct table*, int);

int main()
{
	struct table* ptrTable = NULL;
#ifdef DEBUG
	struct table table[10] = { {"John", 20}, {"Mary", 30}, {"Bob", 40}, {"Sue", 50}, {"Joe", 60}, {"Bill", 70}, {"Sally", 80}, {"Fred", 90}, {"Sam", 100}, {"Sue", 110} };
	int size = 10;
#else
	struct table table[5];
	int size = 5;
	//ask user to enter name and age
	for (int i = 0; i < 5; i++)
	{
		printf("Enter name: ");
		scanf("%s", table[i].name);
		printf("Enter age: ");
		scanf("%d", &table[i].age);
	}
#endif
	//print table
	for (int i = 0; i < 5; i++)
	{
		printf("%s\t%d\n", table[i].name, table[i].age);
	}
	//find first person over 65
	ptrTable = return1st65(table, size);
	if (ptrTable != NULL)
	{
		printf("First person over 65 is %s at %d years old\n", ptrTable->name, ptrTable->age);
	}
	else
	{
		printf("No one is over 65\n");
	}
}

int return1st65(struct table* ptrTable, int size)
{
	//find first person over 65 with a while and return a pointer to that person, otherwise return NULL
	//do it in least lines
	while (ptrTable->age < 65 && size > 0)
	{
		ptrTable++;
		size--;
	}
	return (size > 0) ? ptrTable : NULL;
}
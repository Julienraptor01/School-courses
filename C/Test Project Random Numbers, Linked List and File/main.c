//generate a random number between 1 and 20
//insert it in a sorted linked list (from highest to lowest) (the list is only linked in one direction, so you can't go backwards)
//repeat the above 10 times
//print the list
//generate a random number between 1 and 20
//print the number
//if the number is in the list, delete all instances of it
//write it to a file if it was deleted
//repeat the above 8 times
//print the list

//make functions to insert, delete, and print the list
//also make one to generate a random number
//make a function to write to a file
//all of this above was the original assignment, but got changed a bit later on, so don't mind it

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//full safe gets
#define saferGETS(var) fgets(var, sizeof(var), stdin); var[strcspn(var, "\n")] = '\0'

struct node
{
	int data;
	struct node* next;
};

// QoL functions
int generateRandomNumber(int, int);

// list functions
void insertNodeInList(struct node**, int);
int deleteNodeInList(struct node**, int);
void printNodeInList(struct node*);
void printList(struct node*);

// queue functions
void addNodeToQueue(struct node**, struct node**, int);
int removeNodeFromQueue(struct node**, struct node**);
void printNodeFromQueue(struct node**, struct node**);
void printQueue(struct node**, struct node**);

// file functions
void writeToFile(int, char*);
void printFile(char*);

int main()
{
	char* fileName = "deleted numbers.dat";
	//make sure the file exists
	FILE* file = fopen(fileName, "rb");
	file != NULL ? fclose(file) : (file = fopen(fileName, "wb"), fclose(file));
	struct node* headOfList = NULL,* headOfQueue = NULL, * tailOfQueue = NULL;
	int i, randomNumber;
	srand(time(NULL));
	for (i = 0; i < 10; i++)
	{
		insertNodeInList(&headOfList, generateRandomNumber(1, 20));
	}
	printf("The list is : ");
	printList(headOfList);
	for (i = 0; i < 8; i++)
	{
		switch (i)
		{
		case 0:
			printf("The %dst number is : ", i + 1);
			break;
		case 1:
			printf("The %dnd number is : ", i + 1);
			break;
		case 2:
			printf("The %drd number is : ", i + 1);
			break;
		default:
			printf("The %dth number is : ", i + 1);
			break;
		}
		printf("%d", randomNumber = generateRandomNumber(1, 20));
		//if the random number was deleted, write it to the file
		if (deleteNodeInList(&headOfList, randomNumber))
		{
#ifdef DEBUG
			printf(" (deleted)\n");
#endif
			writeToFile(randomNumber, fileName);
			//also add it to the queue
			addNodeToQueue(&headOfQueue, &tailOfQueue, randomNumber);
			//delete all instances of the random number while it exists
			while (deleteNodeInList(&headOfList, randomNumber));
		}
#ifdef DEBUG
		else
		{
			printf(" (not deleted)\n");
		}
#else
		printf("\n");
#endif
	}
	printf("The list of remaining numbers is : ");
	printList(headOfList);
	printf("The queue of deleted numbers is : ");
	printQueue(&headOfQueue, &tailOfQueue);
	printf("The numbers that are in the \"%s\" file are : ", fileName);
	printFile(fileName);
	//ask the user if they want to delete the file with yes/no in a do while loop
	char answer[4];
	do
	{
		printf("Do you want to delete the file with the deleted numbers ? (yes/no) : ");
		fflush(stdin);
		saferGETS(answer);
	}
	while (strcmp(answer, "yes") != 0 && strcmp(answer, "no") != 0);
	if (strcmp(answer, "yes") == 0)
	{
		remove(fileName);
		printf("The file is deleted.\n");
	}
	else
	{
		printf("The file isn't deleted.\n");
	}
	return 0;
}

int generateRandomNumber(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

void insertNodeInList(struct node** headOfList, int data)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	if (*headOfList == NULL)
	{
		newNode->next = NULL;
		*headOfList = newNode;
	}
	else
	{
		struct node* current = *headOfList;
		struct node* previous = NULL;
		while (current != NULL && current->data > data)
		{
			previous = current;
			current = current->next;
		}
		newNode->next = current;
		previous == NULL ? (*headOfList = newNode) : (previous->next = newNode);
	}
}

int deleteNodeInList(struct node** headOfList, int data)
{
	struct node* current = *headOfList;
	struct node* previous = NULL;
	while (current != NULL && current->data > data)
	{
		previous = current;
		current = current->next;
	}
	/*
	if (current != NULL && current->data == data) {
		previous == NULL ? (*headOfList = current->next) : (previous->next = current->next);
		free(current);
		return 1;
	} else {
		return 0;
	}
	*/
	return current != NULL && current->data == data ? (previous == NULL ? (*headOfList = current->next) : (previous->next = current->next), free(current), 1) : 0;
}

void printNodeInList(struct node* headOfList)
{
	printf("%d", headOfList->data);
}

void printList(struct node* headOfList)
{
	//if the list is empty, print that
	if (headOfList == NULL)
	{
		printf("empty\n");
		return;
	}
	struct node* current = headOfList;
	while (current != NULL)
	{
		printNodeInList(current);
		//print a space if it's not the last node otherwise print a new line
		current->next != NULL ? printf(" ") : printf("\n");
		current = current->next;
	}
}

void addNodeToQueue(struct node** headOfQueue, struct node** tailOfQueue, int data)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;
	*headOfQueue == NULL ? (*headOfQueue = newNode) : ((*tailOfQueue)->next = newNode);
	*tailOfQueue = newNode;
}

int removeNodeFromQueue(struct node** headOfQueue, struct node** tailOfQueue)
{
	struct node* current = *headOfQueue;
	*headOfQueue = current->next;
	if (*headOfQueue == NULL)
	{
		*tailOfQueue = NULL;
	}
	int data = current->data;
	free(current);
	return data;
}

void printNodeInQueue(struct node** headOfQueue, struct node** tailOfQueue)
{
	printf("%d", removeNodeFromQueue(headOfQueue, tailOfQueue));
}

void printQueue(struct node** headOfQueue, struct node** tailOfQueue)
{
	if (*headOfQueue == NULL)
	{
		printf("empty\n");
		return;
	}
	while (*headOfQueue != NULL)
	{
		printNodeInQueue(headOfQueue, tailOfQueue);
		//print a space if it's not the last node otherwise print a new line
		*headOfQueue != NULL ? printf(" ") : printf("\n");
	}
}

void writeToFile(int data, char* fileName)
{
	FILE* file = fopen(fileName, "ab");
	//the file cannot not exist, we'll make sure at the start of the program so no need to check for it
	fwrite(&data, sizeof(data), 1, file);
	fclose(file);
}

void printFile(char* fileName)
{
	//if the file is empty, print that
	FILE* file = fopen(fileName, "rb");
	fseek(file, 0, SEEK_END);
	if (ftell(file) == 0)
	{
		printf("empty\n");
		return;
	}
	fseek(file, 0, SEEK_SET);
	//the file cannot not exist, we'll make sure at the start of the program so no need to check for it
	int data;
	while (fread(&data, sizeof(data), 1, file))
	{
		printf("%d ", data);
	}
	printf("\n");
	fclose(file);
}

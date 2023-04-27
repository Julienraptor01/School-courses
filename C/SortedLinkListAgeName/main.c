//this program will be a sorted linked list
//each element data will contain a name and an age
//the list will be sorted both by name and by age
//we are gonna do that by having 2 pointers inside each node which will point to the next node in their respective lists

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//implement bool type
typedef enum bool { false, true } bool;

//full safe gets
#define saferGETS(var) fgets(var, sizeof(var), stdin); var[strcspn(var, "\n")] = '\0'

struct node
{
	char name[20];
	int age;
	struct node *nextName;
	struct node *nextAge;
};

//this menu will be the base of the program to choose to insert, delete and view the list
bool menu(struct node**, struct node**);

//functions to do tasks
//creating a new person
void createPerson(struct node**, struct node**);
//deleting a person
void deletePerson(struct node**, struct node**);
//searching a person
void searchPerson(struct node*, struct node*);
//viewing all the people
void viewPeople(struct node*, struct node*);

//functions to manage the list
//insert a node in the list
void insertNodeInList(struct node**, struct node**, char*, int);
//search a node with given age and name
struct node* searchNodeByNameAndAge(struct node*, char*, int);
//search a node with given name
struct node* searchNodeByName(struct node*, char*);
//search a node with given age
struct node* searchNodeByAge(struct node*, int);
//delete a node with given address
void deleteNode(struct node**, struct node**, struct node*);
//view a node
void viewNode(struct node*);

int main()
{
	struct node *headByAge = NULL, *headByName = NULL;
	while (menu(&headByName, &headByAge));
}

bool menu(struct node **headByName, struct node **headByAge)
{
	int choice = -1;
	printf("\n1) Register a person\n2) Delete a person\n3) Search a person\n4) View all people\n5) Exit\nWhat do you want to do ? ");
	fflush(stdin);
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		createPerson(headByName, headByAge);
		break;
	case 2:
		deletePerson(headByName, headByAge);
		break;
	case 3:
		searchPerson(*headByName, *headByAge);
		break;
	case 4:
		viewPeople(*headByName, *headByAge);
		break;
	case 5:
		printf("You chose to exit the program\n");
		break;
	default:
		printf("Choose a valid option (1-4)\n");
	}
	return (choice != 4);
}

void createPerson(struct node **headByName, struct node **headByAge)
{
	bool empty, isNegative;
	char name[20];
	int age;
	do
	{
		printf("Enter the name of the person : ");
		fflush(stdin);
		saferGETS(name);
		//make sure the name is not empty
		if ((empty = (strlen(name) == 0)))
			printf("The name can't be empty\n");
	} while (empty);
	do
	{
		printf("Enter the age of the person : ");
		fflush(stdin);
		scanf("%d", &age);
		//make sure the age isn't negative
		if ((isNegative = (age < 0)))
			printf("The age can't be negative\n");
	} while (isNegative);
	insertNodeInList(headByName, headByAge, name, age);
}

void deletePerson(struct node **headByName, struct node **headByAge)
{
	if (*headByName == NULL)
	{
		printf("The list is empty\n");
		return;
	}
	bool empty, isNegative;
	char name[20];
	int age;
	struct node *toDelete;
	do
	{
		printf("Enter the name of the person : ");
		fflush(stdin);
		saferGETS(name);
		//make sure the name is not empty
		if ((empty = (strlen(name) == 0)))
			printf("The name can't be empty\n");
	} while (empty);
	do
	{
		printf("Enter the age of the person : ");
		fflush(stdin);
		scanf("%d", &age);
		//make sure the age isn't negative
		if ((isNegative = (age < 0)))
			printf("The age can't be negative\n");
	} while (isNegative);
	//search if the person doesn't exist in the list and print an error message or delete the person
	/*
	if ((toDelete = searchNodeByNameAndAge(*headByName, name, age)) == NULL)
		printf("The person you want to delete doesn't exist\n");
	else
		deleteNode(headByName, headByAge, toDelete);
	*/
	//use ternary operator to make the code cleaner
	((toDelete = searchNodeByNameAndAge(*headByName, name, age)) == NULL) ? printf("The person you want to delete doesn't exist\n") : deleteNode(headByName, headByAge, toDelete);
}

void searchPerson(struct node *headByName, struct node *headByAge)
{
	if (headByName == NULL)
	{
		printf("The list is empty\n");
		return;
	}
	//do you want to search by both name and age or just one of them
	int choice = -1;
	bool empty, isNegative;
	char name[20];
	int age;
	struct node *toView = NULL;
	do
	{
		printf("Search by name and age (1) or by name (2) or by age (3) ? ");
		fflush(stdin);
		scanf("%d", &choice);
	} while (choice < 1 || choice > 3);
	switch (choice)
	{
	case 1:
		do
		{
			printf("Enter the name of the person : ");
			fflush(stdin);
			saferGETS(name);
			//make sure the name is not empty
			if ((empty = (strlen(name) == 0)))
				printf("The name can't be empty\n");
		} while (empty);
		do
		{
			printf("Enter the age of the person : ");
			fflush(stdin);
			scanf("%d", &age);
			//make sure the age isn't negative
			if ((isNegative = (age < 0)))
				printf("The age can't be negative\n");
		} while (isNegative);
		toView = searchNodeByNameAndAge(headByName, name, age);
		break;
	case 2:
		do
		{
			printf("Enter the name of the person : ");
			fflush(stdin);
			saferGETS(name);
			//make sure the name is not empty
			if ((empty = (strlen(name) == 0)))
				printf("The name can't be empty\n");
		} while (empty);
		toView = searchNodeByName(headByName, name);
		break;
	case 3:
		do
		{
			printf("Enter the age of the person : ");
			fflush(stdin);
			scanf("%d", &age);
			//make sure the age isn't negative
			if ((isNegative = (age < 0)))
				printf("The age can't be negative\n");
		} while (isNegative);
		toView = searchNodeByAge(headByAge, age);
		break;
	}
	//if the person doesn't exist print an error message or print the person
	/*
	if (toView == NULL)
		printf("The person you want to view doesn't exist\n");
	else
		printNode(toView);
	*/
	//use ternary operator to make the code cleaner
	toView == NULL ? printf("The person you searched doesn't exist\n") : viewNode(toView);
}

void viewPeople(struct node *headByName, struct node *headByAge)
{
	if (headByName == NULL)
	{
		printf("The list is empty\n");
		return;
	}
	//ask if they want to view the list sorted by name or by age
	int choice = -1;
	do
	{
		printf("View the list sorted by name (1) or by age (2) ? ");
		fflush(stdin);
		scanf("%d", &choice);
	} while (choice != 1 && choice != 2);
	//view the list
	//printf and put name or age depending on the choice with a ternary operator
	printf("The list sorted by %s is :\n", (choice == 1) ? "name" : "age");
	//use a ternary operator to choose the head of the list
	struct node *current = (choice == 1) ? headByName : headByAge;
	while (current != NULL)
	{
		viewNode(current);
		current = (choice == 1) ? current->nextName : current->nextAge;
	}
}

void insertNodeInList(struct node **headByName, struct node **headByAge, char *name, int age)
{
	//create the new node
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	strcpy(newNode->name, name);
	newNode->age = age;
	//if the list is empty
	if (*headByName == NULL)
	{
		*headByName = newNode;
		*headByAge = newNode;
		newNode->nextName = NULL;
		newNode->nextAge = NULL;
	}
	else
	{
		//if the list is not empty
		//search the node before the new node in the list sorted by name
		struct node *current = *headByName, *previous = NULL;
		while (current != NULL && strcmp(current->name, name) < 0)
		{
			previous = current;
			current = current->nextName;
		}
		//if the name corresponds to a name already in the list, also verify the age
		while (current != NULL && strcmp(current->name, name) == 0 && current->age < age)
		{
			previous = current;
			current = current->nextName;
		}
		//if the new node is the first node in the list
		if (previous == NULL)
		{
			newNode->nextName = *headByName;
			*headByName = newNode;
		}
		else
		{
			//if the new node is not the first node in the list
			newNode->nextName = previous->nextName;
			previous->nextName = newNode;
		}
		//search the node before the new node in the list sorted by age
		current = *headByAge;
		previous = NULL;
		while (current != NULL && current->age < age)
		{
			previous = current;
			current = current->nextAge;
		}
		//if the age corresponds to an age already in the list, also verify the name
		while (current != NULL && current->age == age && strcmp(current->name, name) < 0)
		{
			previous = current;
			current = current->nextAge;
		}
		//if the new node is the first node in the list
		if (previous == NULL)
		{
			newNode->nextAge = *headByAge;
			*headByAge = newNode;
		}
		else
		{
			//if the new node is not the first node in the list
			newNode->nextAge = previous->nextAge;
			previous->nextAge = newNode;
		}
	}
}

struct node *searchNodeByNameAndAge(struct node *head, char *name, int age)
{
	struct node *current = head;
	while (current != NULL && (current->age != age || strcmp(current->name, name) != 0))
		current = current->nextName;
	return current;
}

struct node *searchNodeByName(struct node *head, char *name)
{
	struct node *current = head;
	while (current != NULL && strcmp(current->name, name) != 0)
		current = current->nextName;
	return current;
}

struct node *searchNodeByAge(struct node *head, int age)
{
	struct node *current = head;
	while (current != NULL && current->age != age)
		current = current->nextAge;
	return current;
}

void deleteNode(struct node **headByName, struct node **headByAge, struct node *toDelete)
{
	struct node *currentByName = *headByName, *currentByAge = *headByAge, *previousByName = NULL, *previousByAge = NULL;
	//no need to null check, we will NEVER pass a null pointer to this function
	//search the node before the node to delete in the list sorted by name
	while (currentByName != toDelete)
	{
		previousByName = currentByName;
		currentByName = currentByName->nextName;
	}
	previousByName == NULL ? (*headByName = toDelete->nextName) : (previousByName->nextName = toDelete->nextName);
	//search the node before the node to delete in the list sorted by age
	while (currentByAge != toDelete)
	{
		previousByAge = currentByAge;
		currentByAge = currentByAge->nextAge;
	}
	previousByAge == NULL ? (*headByAge = toDelete->nextAge) : (previousByAge->nextAge = toDelete->nextAge);
	//free the memory
	free(toDelete);
}

void viewNode(struct node *toView)
{
	printf("Name : %s\tAge : %d\n", toView->name, toView->age);
}
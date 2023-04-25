#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//implement bool type
typedef enum bool { false, true } bool;

//full safe gets
#define saferGETS(var) fgets(var, sizeof(var), stdin); var[strcspn(var, "\n")] = '\0'

struct nodePatient
{
	char name[20];
	bool isPriority;
	struct nodePatient* next;
};

// menu
int menu(struct nodePatient**, struct nodePatient**, char*);

// register a patient with name and priority
void registerPatient(struct nodePatient**, struct nodePatient**);
// take care of a patient
void takeCarePatient(struct nodePatient**, struct nodePatient**, char*);
//show all patients from file
void showRoomOccupancy(char*);

// function for the file handling
void writeToFile(int, char*, char*, char*);
void printFile(char*);

// function for my hybrid stack / queue handling
void addNodeToStack(struct nodePatient**, struct nodePatient**, char[20], bool);
void addNodeToQueue(struct nodePatient**, struct nodePatient**, char[20], bool);
void addNode(struct nodePatient**, struct nodePatient**, char[20], bool);
struct nodePatient removeNode(struct nodePatient**, struct nodePatient**);

// debug function for the stack / queue handling
void printNode(struct nodePatient*);
void printAllNodes(struct nodePatient*);

int main()
{
	//make sure file exists
	char* fileName = "patients.dat";
	FILE* file = fopen(fileName, "rb");
	file != NULL ? fclose(file) : (file = fopen(fileName, "wb"), fclose(file));
	//init the hybrid stack / queue
	struct nodePatient* head = NULL;
	struct nodePatient* tail = NULL;
	//start the menu
	while(menu(&head, &tail, fileName));
}

int menu(struct nodePatient** head, struct nodePatient** tail, char* fileName)
{
	int choice = -1;
#ifndef DEBUG
	printf("\n1) Register a patient\n2) Take care of a patient\n3) Show room occupancy\n4) Exit\nWhat do you want to do ? ");
#else
	printf("\n1) Register a patient\n2) Take care of a patient\n3) Show room occupancy\n4) Exit\n5) Print all nodes\nWhat do you want to do ? ");
#endif
	fflush(stdin);
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		registerPatient(head, tail);
		break;
	case 2:
		takeCarePatient(head, tail, fileName);
		break;
	case 3:
		showRoomOccupancy(fileName);
		break;
	case 4:
		printf("You choosed to exit the program\n");
		break;
#ifndef DEBUG
	default:
		printf("Choose a valid option (1-4)\n");
#else
	case 5:
		printAllNodes(*head);
		break;
	default:
		printf("Choose a valid option (1-5)\n");
#endif
	}
	return (choice != 4);
}

void registerPatient(struct nodePatient** head, struct nodePatient** tail)
{
	char name[20];
	char priority;
	bool isPriority;
	printf("Enter the name of the patient : ");
	fflush(stdin);
	saferGETS(name);
	//make sure the user enters a valid input (y/n)
	do
	{
		printf("Is the patient priority ? (y/n) : ");
		fflush(stdin);
		isPriority = ((priority = getchar()) == 'y') ? true : (priority == 'n') ? false : -1;
		addNode(head, tail, name, isPriority);
	}
	while (isPriority == -1);
}

void takeCarePatient(struct nodePatient** head, struct nodePatient** tail, char* fileName)
{
	//verify if there are patients
	if (*head == NULL)
	{
		printf("There are no patients to take care of\n");
		return;
	}
	//take care of the patient
	struct nodePatient patient = removeNode(head, tail);
	printf("Patient %s is taken care of\n", patient.name);
	//if the patient isn't priority, stop here
	if (!patient.isPriority)
	{
		printf("Patient %s was taken care of\n", patient.name);
		return;
	}
	//if the patient is priority, ask more info to write to file
	char problem[100];
	int roomNumber;
	printf("Enter the problem of the patient : ");
	fflush(stdin);
	saferGETS(problem);
	printf("Enter the room number of the patient : ");
	fflush(stdin);
	scanf("%d", &roomNumber);
	//write to file
	writeToFile(roomNumber, patient.name, problem, fileName);
	printf("Patient %s was taken care of and assigned to room %d\n", patient.name, roomNumber);
}

void showRoomOccupancy(char* fileName)
{
	//open the file
	FILE* file = fopen(fileName, "rb");
	//verify if there are patients in the file
	fseek(file, 0, SEEK_END);
	if (ftell(file) == 0)
	{
		printf("There are no patients in the file\n");
		return;
	}
	fclose(file);
	//print the file
	printFile(fileName);
}

void writeToFile(int roomNumber, char* name, char* problem, char* fileName)
{
	//open the file
	FILE* file = fopen(fileName, "ab");
	//write to file
	//remember to write the string length as long before the string
	//this is needed to read the string from the file
	fwrite(&roomNumber, sizeof(roomNumber), 1, file);
	long size = strlen(name);
	fwrite(&size, sizeof(size), 1, file);
	fwrite(name, size, 1, file);
	size = strlen(problem);
	fwrite(&size, sizeof(size), 1, file);
	fwrite(problem, size, 1, file);
	//close the file
	fclose(file);
}

void printFile(char* fileName)
{
	//open the file
	FILE* file = fopen(fileName, "rb");
	//read the file
	int roomNumber;
	long size;
	char name[20] = "";
	char problem[100] = "";
	bool notFEOF = true;
	while ((notFEOF = (fread(&roomNumber, sizeof(roomNumber), 1, file) != 0)))
	{
		//fread(&roomNumber, sizeof(roomNumber), 1, file);
		//i did this in the while in the FEOF check already
		fread(&size, sizeof(size), 1, file);
		fread(&name, size, 1, file);
		fread(&size, sizeof(size), 1, file);
		fread(&problem, size, 1, file);
		printf("Room number : %d\nPatient name : %s\nProblem : %s\n", roomNumber, name, problem);
	}
	//close the file
	fclose(file);
}

void addNodeToStack(struct nodePatient** head, struct nodePatient** tail, char name[20], bool isPriority)
{
	//create the new node
	struct nodePatient* newNode = (struct nodePatient*)malloc(sizeof(struct nodePatient));
	strcpy(newNode->name, name);
	newNode->isPriority = isPriority;
	if (*head == NULL)
	{
		//assign null to the next node if the stack is empty and make the new node the tail
		newNode->next = NULL;
		*tail = newNode;
	}
	else
	{
		//assign the old head to the next node if the stack isn't empty
		newNode->next = *head;
	}
	//make the new node the head in any case
	*head = newNode;
}

void addNodeToQueue(struct nodePatient** head, struct nodePatient** tail, char name[20], bool isPriority)
{
	//create the new node
	struct nodePatient* newNode = (struct nodePatient*)malloc(sizeof(struct nodePatient));
	strcpy(newNode->name, name);
	newNode->isPriority = isPriority;
	newNode->next = NULL;
	*tail == NULL ? (*head = newNode) : ((*tail)->next = newNode);
	*tail = newNode;
}

void addNode(struct nodePatient** head, struct nodePatient** tail, char name[20], bool isPriority)
{
	//if the patient is priority, add it to the stack
	if (isPriority)
	{
		addNodeToStack(head, tail, name, isPriority);
	}
	//if the patient isn't priority, add it to the queue
	else
	{
		addNodeToQueue(head, tail, name, isPriority);
	}
}

struct nodePatient removeNode(struct nodePatient** head, struct nodePatient** tail)
{
	//the struct to return will be the head that we are gonna unstack
	struct nodePatient patient = **head;
	//the head cannot be null, we took care of that in the takeCarePatient function
	struct nodePatient* current = *head;
	*head = (*head)->next;
	if (*head == NULL)
	{
		*tail = NULL;
	}
	free(current);
	return patient;
}

void printNode(struct nodePatient* node)
{
	printf("Name : %s\nisPriority : %s\n\n", node->name, node->isPriority ? "true" : "false");
}

void printAllNodes(struct nodePatient* head)
{
	struct nodePatient* current = head;
	while (current != NULL)
	{
		printNode(current);
		current = current->next;
	}
}

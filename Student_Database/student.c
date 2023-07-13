#include "header.h"
#include <stdlib.h>


STUDENT* createStudentList(void)
{
	STUDENT* headNode = NULL;

	printf("Creating database...\n");

	allocateStudent(&headNode);
	enterData(headNode);

	printf("First student succesfully created!\n");
	return headNode;
}


void allocateStudent(STUDENT** s)
{
	*s = (STUDENT*)calloc(1, sizeof(STUDENT));
	if (*s == NULL)
	{
		perror("Cannot allocate memory for a new student entry...");
		exit(-1);
	}
}

void enterData(STUDENT* s)
{
	system("cls");
	getchar();
	printf("Enter students name: ");
	scanf("%19[^\n]", s->name);
	getchar();
	printf("Enter students surname: ");
	scanf("%19[^\n]", s->surname);
	printf("Enter students ID (integer number): ");
	scanf("%i", &(s->ID));
	printf("Enter students GPA: ");
	scanf("%f", &(s->GPA));
	printf("Enter students major: (with a number)\n1 - Computer Engineering\n2 - Electrical Engineering\n3 - Automation\n");
	do
	{
		printf("Enter your choice: ");
		scanf("%i", &(s->major));
	} while (s->major < 1 || s->major > 3);
	
	getchar();
	printf("Student succesfully created. Press ENTER to continue.");
	getchar();
}

STUDENT* addNewStudent(STUDENT* headNode)
{
	STUDENT* newHeadNode = NULL;

	printf("Adding new student...\n");

	allocateStudent(&newHeadNode);
	enterData(newHeadNode);

	newHeadNode->nextNode = headNode;

	printf("Student succesfully added!\n");
	return newHeadNode;
}

STUDENT* findStudentByID(STUDENT* headNode, int ID)
{
	while (headNode)
	{
		if (headNode->ID == ID) return headNode;
		headNode = headNode->nextNode;
	}
	printf("Student not found");
	return NULL;
}

void printStudentNode(STUDENT* s)
{
	printf("Name: %s\nSurname: %s\n", s->name, s->surname);
	printf("ID: %i\nGPA: %.2f\n", s->ID, s->GPA);

	switch (s->major)
	{
		case computer_engineering:
			printf("Major: Computer Engineering\n");
			break;
		case electrical_engineering:
			printf("Major: Electrical Engineering\n");
			break;
		case automation:
			printf("Major: Automation\n");
			break;
	}
}

void printStudentList(STUDENT* headNode)
{
	system("cls");

	printf("Student database:\n");

	while (headNode)
	{
		printStudentNode(headNode);
		headNode = headNode->nextNode;
	}

	getchar();
	printf("Press ENTER to continue.");
	getchar();
}

int countStudents(STUDENT* headNode)
{
	int i = 0;

	while (headNode)
	{
		i++;
		headNode = headNode->nextNode;
	}

	return i;
}

void deleteStudent(STUDENT** headNode, STUDENT* s)
{
	STUDENT* traverseNode;

	if (*headNode == s)
	{
		*headNode = (*headNode)->nextNode;
		free(s);
		printf("Student succesfully deleted\n");
		return;
	}

	traverseNode = *headNode;
	while (traverseNode->nextNode)
	{
		if (traverseNode->nextNode == s)
		{
			traverseNode->nextNode = s->nextNode;
			free(s);
			printf("Student succesfully deleted\n");
			return;
		}
		traverseNode = traverseNode->nextNode;
	}
	printf("Cannot delete the student. The student was not found!");
}

STUDENT* deleteAllStudents(STUDENT* s)
{
	STUDENT* deleteNode = NULL;

	while (s)
	{
		deleteNode = s;
		s = s->nextNode;
		free(deleteNode);
	}
	return NULL;
}
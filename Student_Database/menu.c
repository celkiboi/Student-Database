#include "header.h"

int mainMenu(STUDENT** headNode)
{
	int choice;
	

	system("cls");

	printf("Welcome to \"Student database\".\nMade by: Tomislav Celic\n");
	printf("Choose what do you want to do:\n1 - Create a database\n2 - Load data\n3 - Save data\n4 - Exit\n");
	do
	{
		printf("Enter your choice: ");
		scanf("%i", &choice);
	} while (choice < 1 || choice > 4);


	switch (choice)
	{
	case 1:
		printf("WARNING: Creating a new database will delete all your previously saved data\nInsert 1 if you are sure and 0 if you want to return\n");
		do
		{
			printf("Enter your choice ");
			scanf("%i", &choice);
		} while (choice < 0 || choice > 1);

		if (choice == 1) newFile(headNode);
		return 1;
	case 2:
		printf("Do you want to load saved data\nInsert 1 if you are sure and 0 if you want to return\n");
		do
		{
			printf("Enter your choice ");
			scanf("%i", &choice);
		} while (choice < 0 || choice > 1);

		if (choice == 1) openFile(headNode);
		return 2;
	case 3:
		printf("WARNING: Previously saved data will be replaced\nInsert 1 if you are sure and 0 if you want to return\n");
		do
		{
			printf("Enter your choice ");
			scanf("%i", &choice);
		} while (choice < 0 || choice > 1);

		if (choice == 1) saveFile(headNode);
		return 3;
	case 4:
		printf("WARNING: Unsaved data will be lost. Are you sure you want to exit?\nInsert 1 if you are sure and 0 if you want to return\n");
		do
		{
			printf("Enter your choice ");
			scanf("%i", &choice);
		} while (choice < 0 || choice > 1);

		if (choice == 1)
		{
			headNode = deleteAllStudents(*headNode);
			return 0;
		}
		else return 4;
	}
}

int subMenu(STUDENT** headNode)
{
	int choice, id;

	system("cls");

	printf("Database manager\n1 - print data\n2 - add student\n3 - delete data\n4 - return to main menu\n");

	do
	{
		printf("Enter your choice: ");
		scanf("%i", &choice);
	} while (choice < 1 || choice > 4);

	switch (choice)
	{
		case 1:
			printStudentList(*headNode);
			break;
		case 2:
			*headNode = addNewStudent(*headNode);
			break;
		case 3:
			printf("Enter the ID of the student you wish to delete: ");
			scanf("%i", &id);
			do
			{
				printf("Are you sure you want to delete the student by the id %i? 1 - Yes, 0 - No\nEnter your choice: ", id);
				scanf("%i", &choice);
			} while (choice < 0 || choice > 1);

			deleteStudent(headNode, findStudentByID(*headNode, id));
			getchar();
			printf("Press enter to continue");
			getchar();
			break;
		case 4:
			return 1;
	}
	return 0;
}

void subMenuRuntime(STUDENT** headNode)
{
	int choice;

	do
	{
		choice = subMenu(headNode);
	} while (choice == 0);
}
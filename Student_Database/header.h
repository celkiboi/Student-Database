#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>

typedef enum major {computer_engineering = 1, electrical_engineering, automation}MAJOR;

typedef struct student
{
	char name[20];
	char surname[20];
	int ID;
	float GPA;
	MAJOR major;
	struct student *nextNode;
}STUDENT;

STUDENT* createStudentList(void);

void allocateStudent(STUDENT** s);

void enterData(STUDENT* s);

STUDENT* addNewStudent(STUDENT* headNode);

STUDENT* findStudentByID(STUDENT* headNode, int ID);

void deleteStudent(STUDENT** headNode, STUDENT* s);

STUDENT* deleteAllStudents(STUDENT* s);

void printStudentNode(STUDENT* s);

void printStudentList(STUDENT* headNode);

int countStudents(STUDENT* headNode);

STUDENT* loadStudentNode(FILE* fp, STUDENT* headNode, int numberOfNode);

void loadStudentList(FILE* fp, STUDENT** headNode);

void writeStudentNode(FILE* fp, STUDENT* s, int numberOfNode);

void writeStudentList(FILE* fp, STUDENT* s);

void openFile(STUDENT** headNode);

int mainMenu(STUDENT** headNode);

void newFile(STUDENT** headNode);

int subMenu(STUDENT** headNode);

void subMenuRuntime(STUDENT** headNode);
#endif
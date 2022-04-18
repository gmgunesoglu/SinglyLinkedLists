/* Gokhan Gunesoglu   gokhangunesoglu@gmail.com */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string>

struct Staff {
	char name[30];
	char surname[20];
	int selary;
	int ID;
	Staff* next;
};

bool isThisCircleList = true;								//false=lineer list // true=circle list
Staff* head, head2;
Staff* foot, foot2;
int staffID = 1000;
int nodeCount = 0;

void loadDemo();
void writeString(char ptr[], std::string str);
bool compareLetter(char str1[], char str2[]);
void clearData(char* ptr);
Staff* createNewNode();
void addNodeToHead();
void addNodeToFoot();
void addNodeToIndex();
void printList();
Staff* findNodeByName(Staff* start, char name[]);
Staff* findNodeBySurname(Staff* start, char name[]);
Staff* findNodeByID(Staff* start, int code);
void findNodeAndWrite(int key);
void deleteNode(Staff* willBeDelete);
void findNodeAndRemove(int key);
void addNodeToNextOfStaffID();
void printActions();
bool userScreen();

int main() {												////main is here////	////main is here////	////main is here////


	loadDemo();									//if u dont need to demo nodes, command it.
	printf("Wellcome, Enter a number:\n");
	printf("0 = Exit   1-11 = Actions   Higer numbers print actions...\n");
	while (userScreen()) {
	}
	if (isThisCircleList) {
		printf("list was circle\n");
	}
	else {
		printf("list was lineer\n");
	}
	printf("Okey than, See you later...");

	return 0;
}														////////////////////	////////////////////	////////////////////

void loadDemo() {
	head = (Staff*)malloc(sizeof(Staff));
	Staff* iter = head;
	nodeCount++;
	clearData(iter->name);
	iter->ID = ++staffID;
	iter->selary = 9000;
	writeString(iter->name, "Gokhan Muzaffer");
	writeString(iter->surname, "Gunesoglu");

	iter->next = (Staff*)malloc(sizeof(Staff));
	clearData(iter->next->name);
	iter = iter->next;
	nodeCount++;
	iter->ID = ++staffID;
	iter->selary = 8000;
	writeString(iter->name, "Gokhan");
	writeString(iter->surname, "Gunesoglu");

	iter->next = (Staff*)malloc(sizeof(Staff));
	clearData(iter->next->name);
	iter = iter->next;
	nodeCount++;
	iter->ID = ++staffID;
	iter->selary = 10;
	writeString(iter->name, "Serkan");
	writeString(iter->surname, "Gunesoglu");

	iter->next = (Staff*)malloc(sizeof(Staff));
	clearData(iter->next->name);
	iter = iter->next;
	nodeCount++;
	iter->ID = ++staffID;
	iter->selary = 7900;
	writeString(iter->name, "Muhammed");
	writeString(iter->surname, "Karakas");

	iter->next = (Staff*)malloc(sizeof(Staff));
	clearData(iter->next->name);
	iter = iter->next;
	nodeCount++;
	iter->ID = ++staffID;
	iter->selary = 7800;
	writeString(iter->name, "Zekiye");
	writeString(iter->surname, "Tekin");

	iter->next = (Staff*)malloc(sizeof(Staff));
	clearData(iter->next->name);
	iter = iter->next;
	nodeCount++;
	iter->ID = ++staffID;
	iter->selary = 7700;
	writeString(iter->name, "Eli Esref");
	writeString(iter->surname, "Atasoy");

	iter->next = (Staff*)malloc(sizeof(Staff));
	clearData(iter->next->name);
	iter = iter->next;
	nodeCount++;
	iter->ID = ++staffID;
	iter->selary = 7600;
	writeString(iter->name, "Damla Nur");
	writeString(iter->surname, "Emlik");

	iter->next = (Staff*)malloc(sizeof(Staff));
	clearData(iter->next->name);
	iter = iter->next;
	nodeCount++;
	iter->ID = ++staffID;
	iter->selary = 7500;
	writeString(iter->name, "Emre");
	writeString(iter->surname, "Tantu");

	iter->next = (Staff*)malloc(sizeof(Staff));
	clearData(iter->next->name);
	iter = iter->next;
	nodeCount++;
	iter->ID = ++staffID;
	iter->selary = 7400;
	writeString(iter->name, "Emre");
	writeString(iter->surname, "Tantu");

	iter->next = (Staff*)malloc(sizeof(Staff));
	clearData(iter->next->name);
	iter = iter->next;
	nodeCount++;
	iter->ID = ++staffID;
	iter->selary = 7300;
	writeString(iter->name, "Soner");
	writeString(iter->surname, "Celik");

	iter->next = (Staff*)malloc(sizeof(Staff));
	clearData(iter->next->name);
	iter = iter->next;
	nodeCount++;
	iter->ID = ++staffID;
	iter->selary = 8100;
	writeString(iter->name, "Toner");
	writeString(iter->surname, "Celik");
	foot = iter;
	if (isThisCircleList) {
		foot->next = head;
	}
}

void writeString(char ptr[], std::string str) {
	int i = 0;
	while (str[i] != NULL) {
		ptr[i] = str[i];
		i++;
	}
}

bool compareLetter(char str1[], char str2[]) {
	int i = 0;
	while (str1[i] != '\0' || str2[i] != '\0') {
		if (str1[i] != str2[i])
			return false;
		i++;
	}
	return true;
}

void clearData(char* ptr) {
	for (int i = 0; i < sizeof(Staff); i++) {
		ptr[i] = NULL;
	}
}

Staff* createNewNode() {
	Staff* newNode = (Staff*)malloc(sizeof(Staff));
	clearData(newNode->name);
	printf("Name of staff:\n");
	gets_s(newNode->name);
	printf("Surname of staff:\n");
	gets_s(newNode->surname);
	printf("Selary of staff:\n");
	scanf("%i", &newNode->selary);
	newNode->ID = ++staffID;
	nodeCount++;
	return newNode;
}

void addNodeToHead() {
	Staff* newNode = createNewNode();
	if (head == NULL) {						//0 node
		head = foot = newNode;
		if (isThisCircleList) {				//if is it circle
			foot->next = head;
		}
	}
	else {									//1 and more node
		newNode->next = head;
		head = newNode;
		if (isThisCircleList) {				//if is it circle
			foot->next = head;
		}
	}
	printList();
}

void addNodeToFoot() {
	Staff* newNode = createNewNode();
	if (head == NULL) {
		head = foot = newNode;
		if (isThisCircleList) {
			foot->next = head;
		}
	}
	else {
		foot->next = newNode;
		foot = newNode;
		if (isThisCircleList) {
			foot->next = head;
		}
	}
	printList();
}

void addNodeToIndex() {
	Staff* iter = head;
	int key;
	printf("List has %i node, enter a number range(0 to %i)\n", nodeCount, nodeCount);
	do {
		printf("Wich index do you want to add:");
		scanf("%i", &key);
		if (key > nodeCount || key < 0) {
			printf("Please enter a key range 0 to %i\n", nodeCount);
		}
	} while (key > nodeCount || key < 0);
	if (key == 0) {
		addNodeToHead();
		return;
	}
	if (key == nodeCount) {
		addNodeToFoot();
		return;
	}
	for (int i = 0; i < key - 1; i++) {
		iter = iter->next;
	}
	Staff* newNode = createNewNode();
	newNode->next = iter->next;
	iter->next = newNode;
	printList();
}

void printList() {
	if (head == NULL) {
		printf("List is empty\n");
		return;
	}
	Staff* iter = head;
	printf("============================================================Current List============================================================\n");
	while (iter != foot) {
		printf("[Staff ID: %i]   [Staff Selary: %i]   [Staff Name: %s]   [Staff Surname: %s]\n", iter->ID, iter->selary, iter->name, iter->surname);
		iter = iter->next;
	}
	printf("[Staff ID: %i]   [Staff Selary: %i]   [Staff Name: %s]   [Staff Surname: %s]\n\n", iter->ID, iter->selary, iter->name, iter->surname);
}

Staff* findNodeByName(Staff* start, char name[]) {
	while (start != foot) {
		if (compareLetter(start->name, name))
			return start;
		start = start->next;
	}
	if (compareLetter(start->name, name))
		return start;
	return NULL;
}

Staff* findNodeBySurname(Staff* start, char name[]) {
	while (start != foot) {
		if (compareLetter(start->surname, name)) {
			return start;
		}
		start = start->next;
	}
	if (compareLetter(start->surname, name)) {
		return start;
	}
	return NULL;
}

Staff* findNodeByID(Staff* start, int code) {
	while (start != foot) {
		if (start->ID == code)
			return start;
		start = start->next;
	}
	if (start->ID == code)
		return start;
	return NULL;
}

void findNodeAndWrite(int key) {
	Staff* iter = head;
	if (key == 1) {
		char name[30];
		printf("Enter the name of the staff:\n");
		scanf("%i"); //bugs
		gets_s(name);
		int i = 0;
		while (true) {
			iter = findNodeByName(iter, name);
			if (iter != NULL) {
				if (i == 0)
					printf("===========================================================Staff Found===========================================================\n");
				printf("[Staff ID: %i]   [Staff Selary: %i]   [Staff Name: %s]  [Staff Surname: %s]\n", iter->ID, iter->selary, iter->name, iter->surname);
				i++;
				iter = iter->next;
			}if (iter == head || iter == NULL) {
				if (i == 0)
					printf("Staff coudnot find...\n");
				printf("\n");
				return;
			}
		}
	}
	if (key == 2) {
		char name[20];
		printf("Enter the surname of the the staff:\n");
		scanf("%i"); //bugs
		gets_s(name);
		int i = 0;
		while (true) {
			iter = findNodeBySurname(iter, name);
			if (iter != NULL) {
				if (i == 0)
					printf("===========================================================Staff Found===========================================================\n");
				printf("[Staff ID: %i]   [Staff Selary: %i]   [Staff Name: %s]  [Staff Surname: %s]\n", iter->ID, iter->selary, iter->name, iter->surname);
				i++;
				iter = iter->next;
			}if (iter == head || iter == NULL) {
				if (i == 0)
					printf("Staff coudnot find...\n");
				printf("\n");
				return;
			}
		}
	}
	int code;
	printf("Enter the ID of the staff:");
	scanf("%i", &code);
	iter = findNodeByID(iter, code);
	if (iter != NULL) {
		printf("===========================================================Staff Found===========================================================\n");
		printf("[Staff ID: %i]   [Staff Selary: %i]   [Staff Name: %s]  [Staff Surname: %s]\n", iter->ID, iter->selary, iter->name, iter->surname);
	}
	else
		printf("Staff ID coudnot find...\n");
	return;
}

void deleteNode(Staff* willBeDelete) {
	Staff* temp = willBeDelete;
	if (temp == head) {
		if (head == foot) { 		//if this is the last one node
			free(head);
			head = NULL;
			nodeCount--;
			return;
		}
		head = head->next;
		if (isThisCircleList) {
			foot->next = head;
		}
		free(willBeDelete);
		nodeCount--;
		return;
	}
	else {
		temp = head;
		while (temp->next != willBeDelete) {
			temp = temp->next;
		}
		temp->next = temp->next->next;
		free(willBeDelete);
		foot = temp;
		nodeCount--;
		return;
	}
}

void findNodeAndRemove(int key) {
	Staff* iter = head;
	if (key == 1) {
		char name[30];
		printf("Enter the name of the staff:\n");
		scanf("%i"); //bugs
		gets_s(name);
		int i = 0;
		while (true) {
			iter = findNodeByName(iter, name);
			if (iter != NULL) {
				if (i == 0)
					printf("============================================================Removed Staff============================================================\n");
				printf("[Staff ID: %i]   [Staff Selary: %i]   [Staff Name: %s]  [Staff Surname: %s]\n", iter->ID, iter->selary, iter->name, iter->surname);
				deleteNode(iter);
				iter = iter->next;
				i++;
			}
			else {
				if (i == 0)
					printf("Staff coudnot find...\n");
				printf("\n");
				printList();
				return;
			}
		}
	}
	if (key == 2) {
		char name[30];
		printf("Enter the surname of the staff:\n");
		scanf("%i"); //bugs
		gets_s(name);
		int i = 0;
		while (true) {
			iter = findNodeBySurname(iter, name);
			if (iter != NULL) {
				if (i == 0)
					printf("============================================================Removed Staff============================================================\n");
				printf("[Staff ID: %i]   [Staff Selary: %i]   [Staff Name: %s]  [Staff Surname: %s]\n", iter->ID, iter->selary, iter->name, iter->surname);
				deleteNode(iter);
				iter = iter->next;
				i++;
			}
			else {
				if (i == 0)
					printf("Staff coudnot find...\n");
				printf("\n");
				printList();
				return;
			}
		}
	}
	int code;
	printf("Enter the ID of the staff:");
	scanf("%i", &code);
	iter = findNodeByID(iter, code);
	if (iter != NULL) {
		printf("============================================================Removed Staff============================================================\n");
		printf("[Staff ID: %i]   [Staff Selary: %i]   [Staff Name: %s]  [Staff Surname: %s]\n", iter->ID, iter->selary, iter->name, iter->surname);
		deleteNode(iter);
		printList();
	}
	else {
		printf("Staff ID coudnot find...\n");
	}
	return;
}

void addNodeToNextOfStaffID() {
	int staffID;
	printf("Enter an staff ID:");
	scanf("%i", &staffID);
	Staff* iter = findNodeByID(head, staffID);
	if (iter == foot) {
		addNodeToFoot();
		return;
	}
	Staff* newNode = createNewNode();
	newNode->next = iter->next;
	iter->next = newNode;
	printList();
}

void printActions() {
	printf("1  => Print List\n");
	printf("2  => Add staff to head of list\n");
	printf("3  => Add staff to foot of list\n");
	printf("4  => Add staff to index wich you want\n");
	printf("5  => Find staff by name\n");
	printf("6  => Find staff by surname\n");
	printf("7  => Find staff by staff ID\n");
	printf("8  => Remove staff by name\n");
	printf("9  => Remove staff by surname\n");
	printf("10 => Remove staff by staff ID\n");
	printf("11 => Add staff to next of the staff ID\n");
	printf("0  => Exit\n");
}

bool userScreen() {
	int number;
	printf("Enter a number:");
	scanf("%i", &number);
	switch (number) {
	case 0:
		return false;
	case 1:
		printList();
		return true;
	case 2:
		addNodeToHead();
		return true;
	case 3:
		addNodeToFoot();
		return true;
	case 4:
		addNodeToIndex();
		return true;
	case 5:
		findNodeAndWrite(1);
		return true;
	case 6:
		findNodeAndWrite(2);
		return true;
	case 7:
		findNodeAndWrite(3);
		return true;
	case 8:
		findNodeAndRemove(1);
		return true;
	case 9:
		findNodeAndRemove(2);
		return true;
	case 10:
		findNodeAndRemove(3);
		return true;
	case 11:
		addNodeToNextOfStaffID();
		return true;
	default:
		printActions();
		return true;
	}
}
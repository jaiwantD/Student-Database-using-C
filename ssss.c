#include <stdio.h>
#include <string.h>
#define MAX_STUDENTS 100
struct Student {
 int id;
 char name[50];
 int age;
 float gpa;
 int isDeleted;
};
struct StudentDatabase {
 struct Student students[MAX_STUDENTS];
 int numStudents;
};
void addStudent(struct StudentDatabase *db) {
 if (db->numStudents < MAX_STUDENTS) {
 struct Student newStudent;
 printf("Enter student details:\n");

printf("ID: ");
 scanf("%d", &newStudent.id);
 printf("Name: ");
 scanf(" %[^\n]", newStudent.name);
 printf("Age: ");
 scanf("%d", &newStudent.age);
 printf("GPA: ");
 scanf("%f", &newStudent.gpa);
 newStudent.isDeleted = 0;
 db->students[db->numStudents] = newStudent;
 db->numStudents++;
 printf("Student added to the database.\n");
 } else {
 printf("Database is full. Cannot add more students.\n");
 }
}
void deleteStudent(struct StudentDatabase *db, int id) {
 int found = 0;
 for (int i = 0; i < db->numStudents; i++) {
 if (db->students[i].id == id) {
 db->students[i].isDeleted = 1;
 printf("Student with ID %d deleted from the database.\n", id);
 found = 1;
 break;
 }
 }
 if (!found) {
 printf("Student with ID %d not found in the database.\n", id);
 }
}
void displayStudents(const struct StudentDatabase *db) {
 if (db->numStudents == 0) {
 printf("Database is empty.\n");
 } else {
 printf("Students in the database:\n");
 for (int i = 0; i < db->numStudents; i++) {
 if (!db->students[i].isDeleted) {
 printf("------------------------------------------------------\n");
 printf("ID: %d\t| Name: %s\t| Age: %d\t| GPA: %.2f\t|\n",
 db->students[i].id, db->students[i].name,
 db->students[i].age, db->students[i].gpa);
 printf("------------------------------------------------------\n");
 }
 }
 }
}
void updateStudent(struct StudentDatabase *db, int id) {
 int found = 0;
 for (int i = 0; i < db->numStudents; i++) {
 if (db->students[i].id == id && !db->students[i].isDeleted) {
 printf("Enter new details for student with ID %d:\n", id);
printf("Age: ");
 scanf("%d", &db->students[i].age);
 printf("GPA: ");
 scanf("%f", &db->students[i].gpa);
 printf("Student with ID %d updated successfully.\n", id);
 found = 1;
 break;
 }
 }
 if (!found) {
 printf("Student with ID %d not found in the database.\n", id);
 }
}
int main() {
 struct StudentDatabase myDatabase;
 myDatabase.numStudents = 0;
 int choice, id;
 do {
 printf("\nStudent Database Management\n");
 printf("1. Add a student\n");
 printf("2. Delete a student by ID\n");
 printf("3. Update student data by ID\n");
 printf("4. Display all students\n");
 printf("5. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 printf("**********************************\n");
 switch (choice) {
 case 1:
 addStudent(&myDatabase);
 break;
 case 2:
 printf("Enter ID of the student to delete: ");
 scanf("%d", &id);
 deleteStudent(&myDatabase, id);
 break;
 case 3:
 printf("Enter ID of the student to update: ");
 scanf("%d", &id);
 updateStudent(&myDatabase, id);
 break;
 case 4:
 displayStudents(&myDatabase);
 break;
 case 5:
 printf("Exiting the program.\n");
 break;
 default:
 printf("Invalid choice. Please enter a valid option.\n");
 }
 } while (choice != 5);
 return 0;
}

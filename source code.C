#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 100

struct Book
{
int id;
char title[50];
char author[50];
char isbn[20];
int issued;
int issuedTo;
};

struct User
{
int uid;
char name[50];
};

struct Book books[MAX];
struct User users[MAX];

int book_count = 0;
int user_count = 0;

void addBook();
void deleteBook();
void searchBook();
void registerUser();
void issueBook();
void returnBook();
void displayBooks();

void main()
{
int ch;
clrscr();
printf("After registration only Book is issued");
do
{
printf("\n\nLibrary Management System Menu :)\n");
printf("1. Add Book\n");
printf("2. Delete Book\n");
printf("3. Search Book\n");
printf("4. Register User\n");
printf("5. Issue Book\n");
printf("6. Return Book\n");
printf("7. Display Books\n");
printf("8. Exit\n");
printf("Enter your choice: ");
scanf("%d", &ch);
switch(ch)
{
case 1: addBook(); break;
case 2: deleteBook(); break;
case 3: searchBook(); break;
case 4: registerUser(); break;
case 5: issueBook(); break;
case 6: returnBook(); break;
case 7: displayBooks(); break;
case 8: exit(0);
default: printf("Enter valid choice :(\n");
}
}while(ch != 8);
getch();
}

void addBook()
{
if(book_count >= MAX)
{
printf("Book list is full!!...\n");
return;
}
printf("Enter Book ID: ");
scanf("%d", &books[book_count].id);
printf("Enter Title: ");
scanf(" %[^\n]", books[book_count].title);
printf("Enter Author: ");
scanf(" %[^\n]", books[book_count].author);
printf("Enter ISBN: ");
scanf(" %[^\n]", books[book_count].isbn);
books[book_count].issued = 0;
books[book_count].issuedTo = 0;
book_count++;
printf("Book added successfully :)\n");
}

void deleteBook()
{
int id,j, i, found = 0;
printf("Enter Book ID to delete: ");
scanf("%d", &id);
for(i = 0; i < book_count; i++)
{
if(books[i].id == id)
{
found = 1;
for(j = i; j < book_count - 1; j++)
{
books[j] = books[j + 1];
}
book_count--;
printf("Book deleted successfully :)\n");
break;
}
}
if(!found)
printf("Book ID not found :(\n");
}

void searchBook()
{
int id,i, found = 0;
printf("Enter Book ID to search: ");
scanf("%d", &id);
for(i = 0; i < book_count; i++) {
if(books[i].id == id) {
printf("Book Found !!..\n");
printf("ID: %d\nTitle: %s\nAuthor: %s\nISBN: %s\nStatus: %s",books[i].id, books[i].title, books[i].author,books[i].isbn, books[i].issued ? "Issued" : "Available");
if(books[i].issued)
printf(", Issued To: User ID %d", books[i].issuedTo);
printf("\n");
found = 1;
break;
}
}
if(!found)
printf("Book not found :(\n");
}

void registerUser()
{
if(user_count >= MAX)
{
printf("User list is full :(\n");
return;
}
printf("Enter User ID: ");
scanf("%d", &users[user_count].uid);
printf("Enter Name: ");
scanf(" %[^\n]", users[user_count].name);
user_count++;
printf("User registered successfully :)\n");
}

void issueBook()
{
int id,i, uid,u, found = 0, userFound = 0;
printf("Enter Book ID to issue: ");
scanf("%d", &id);
printf("Enter User ID: ");
scanf("%d", &uid);
for (u = 0; u < user_count; u++)
{
if (users[u].uid == uid)
{
userFound = 1;
break;
}
}
if (!userFound) {
printf("User not registered :(\n");
return;
}
for (i = 0; i < book_count; i++)
{
if (books[i].id == id && books[i].issued == 0)
{
books[i].issued = 1;
books[i].issuedTo = uid;
printf("Book issued successfully to User ID %d :)\n", uid);
found = 1;
break;
}
}
if (!found)
printf("Book not available or already issued :(\n");
}

void returnBook()
{
int id,i, found = 0;
printf("Enter Book ID to return: ");
scanf("%d", &id);
for (i = 0; i < book_count; i++)
{
if (books[i].id == id && books[i].issued == 1)
{
books[i].issued = 0;
books[i].issuedTo = 0;
printf("Book returned successfully :)\n");
found = 1;
break;
}
}
if (!found)
printf("Book ID not found or not issued :(\n");
}

void displayBooks()
{
int i;
if(book_count == 0)
{
printf("No books available or added !!..\n");
return;
}
printf("\nList of Books:\n");
for(i = 0; i < book_count; i++) {
printf("ID: %d, Title: %s, Author: %s, ISBN: %s, Status: %s",
books[i].id, books[i].title, books[i].author,
books[i].isbn, books[i].issued ? "Issued" : "Available");
if (books[i].issued)
printf("\nIssued To: User ID %d", books[i].issuedTo);
printf("\n");
}
}
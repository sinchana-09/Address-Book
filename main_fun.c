#include <stdio.h>
#include <string.h>
    struct Contact
    {
        char name[50];
        char phone[20];
        char email[50];
    };
    struct Addressbook
    {
        struct Contact c1[100];
        int Contactcount;
    };
    void createContact(struct Addressbook *book);
    void listContact(struct Addressbook *book);
    void searchContact(struct Addressbook *book);
    void editContact(struct Addressbook *book);
    void deleteContact(struct Addressbook *book);
    void saveContact(struct Addressbook *book);
    void loadContact(struct Addressbook *book);
    struct Addressbook *book;
int main()
{
    struct Addressbook book;
    book.Contactcount=0;
    loadContact(&book);
    int option;
     do {
        printf("\nAddress Book Menu:\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
    	printf("6. Save and load contacts\n");		
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
    switch (option)
    {
        case 1:
            createContact(&book);
            break;
        case 2:
            searchContact(&book);
            break;
        case 3:
            editContact(&book);
           break;
        case 4:
            deleteContact(&book);
            break;
        case 5:
            listContact(&book);
            break;
        case 6:
           saveContact(&book);
            break;
        case 7:
            printf("Exiting");
            break;
        default:
            printf("Invalid option");
    }
}
    while(option != 7);
    return 0;

}

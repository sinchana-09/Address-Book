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
    void searchContact(struct Addressbook *book)
{
    if (book->Contactcount == 0) {
        printf("No contacts found!");
        return;
    }

    int choice, found = 0;
    char search[50];

    printf("\n1. Search by Name\n2. Search by Phone\n3. Search by Email\nEnter choice: ");
    scanf("%d", &choice);

    printf("Enter detail to search: ");
    scanf("%s", search);

    for (int i = 0; i < book->Contactcount; i++)
    {
        switch (choice)
        {
            case 1:
                if (strstr(book->c1[i].name, search) != NULL)
                {
                    printf("%-20s %-15s %-25s\n", book->c1[i].name, book->c1[i].phone, book->c1[i].email);
                    found = 1;
                }
                break;

            case 2:
                if (strcmp(search, book->c1[i].phone) == 0)
                {
                    printf("%-20s %-15s %-25s\n", book->c1[i].name, book->c1[i].phone, book->c1[i].email);
                    found = 1;
                }
                break;

            case 3:
                if (strcmp(search, book->c1[i].email) == 0)
                {
                    printf("%-20s %-15s %-25s\n", book->c1[i].name, book->c1[i].phone, book->c1[i].email);
                    found = 1;
                }
                break;
        }
    }

    if (found == 0)
    {
        printf("Contact not found!\n");
    }
    printf("\n");
}
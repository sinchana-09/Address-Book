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
    void listContact(struct Addressbook *book)
    {
          if (book->Contactcount == 0) {
        printf("\nNo contacts found in address book!\n\n");
        return;
    }

    printf("\n%-20s %-15s %-25s\n", "Name", "Phone", "Email");
    for (int i = 0; i < book->Contactcount; i++) {
        printf("%-20s %-15s %-25s\n", 
               book->c1[i].name, 
               book->c1[i].phone, 
               book->c1[i].email);
    }
    printf("\n");
    }
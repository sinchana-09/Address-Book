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
    void loadContact(struct Addressbook *book)
    {
       FILE *fptr = fopen("contact.txt", "r");

    if (fptr == NULL)
    {
        book->Contactcount = 0;
        return;
    }

    //Read total count from first line
    if (fscanf(fptr, "%d\n", &book->Contactcount) != 1)
    {
        book->Contactcount = 0;
        fclose(fptr);
        return;
    }

    // Read contacts line by line
    for (int i = 0; i < book->Contactcount; i++)
    {
        fscanf(fptr, " %[^,],%[^,],%[^\n]\n", 
               book->c1[i].name, 
               book->c1[i].phone, 
               book->c1[i].email);
    }

    fclose(fptr);
}

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
    void saveContact(struct Addressbook *book)
    { 
     FILE *fptr = fopen("contact.txt", "w");

    if (fptr == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    // Write total contact count first
    fprintf(fptr, "%d\n", book->Contactcount);

    // Run a loop Contactcount times to save each contact
    for (int i = 0; i < book->Contactcount; i++)
    {
        fprintf(fptr, "%s,%s,%s\n", book->c1[i].name, book->c1[i].phone, book->c1[i].email);
    }

    // 4. Close the file
    fclose(fptr);

    printf("Contacts saved successfully to contact.txt!\n\n");
}
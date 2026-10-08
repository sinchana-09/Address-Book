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

void deleteContact(struct Addressbook *book) 
{
    if (book->Contactcount == 0)
    {
        printf("\nNo contacts to delete!\n\n");
        return;
    }
    //Search method to find array index
    int search_choice;
    printf("\nSearch contact to delete by:\n1. Name\n2. Phone\n3. Email\nEnter choice: ");
    scanf("%d", &search_choice);

    char search[50];
    printf("Enter detail to search: ");
    scanf("%s", search);

    int delete_idx = -1;
    for (int i = 0; i < book->Contactcount; i++)
    {
        if (search_choice == 1 && strstr(book->c1[i].name, search) != NULL)
        {
            delete_idx = i;
            break;
        } else if (search_choice == 2 && strcmp(search, book->c1[i].phone) == 0)
        {
            delete_idx = i;
            break;
        } else if (search_choice == 3 && strcmp(search, book->c1[i].email) == 0)
        {
            delete_idx = i;
            break;
        }
    }

    if (delete_idx == -1) 
    {
        printf("Contact not found!\n\n");
        return;
    }
    //Display contact and ask for confirmation
    printf("\nFound Contact: %-20s %-15s %-25s\n", 
           book->c1[delete_idx].name, 
           book->c1[delete_idx].phone, 
           book->c1[delete_idx].email);

    char confirm;
    printf("Are you sure you want to delete this contact? (y/n): ");
    scanf(" %c", &confirm); // Note the space before %c to handle newline characters

    if (confirm != 'y' && confirm != 'Y') {
        printf("Deletion cancelled.\n\n");
        return;
    }

    // Shift array elements left from delete_idx
    for (int i = delete_idx; i < book->Contactcount - 1; i++) {
        book->c1[i] = book->c1[i + 1];
    }

    //Step 4: Decrement contact count
    book->Contactcount--;

    printf("\nContact deleted successfully!\n\n");

    // Display updated list
  void listContact(struct Addressbook *book);
}
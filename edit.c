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
    void editContact(struct Addressbook *book) {
    if (book->Contactcount == 0) {
        printf("\nNo contacts to edit!\n\n");
        return;
    }

    int search_choice;
    printf("\nSearch by:\n1. Name\n2. Phone\n3. Email\nEnter choice: ");
    scanf("%d", &search_choice);

    char search[50];
    printf("Enter detail to search: ");
    scanf("%s", search);

    int index = -1;
    for (int i = 0; i < book->Contactcount; i++)
    {
        if (search_choice == 1 && strstr(book->c1[i].name, search) != NULL)
        {
            index = i;
            break;
        } 
        else if (search_choice == 2 && strcmp(search, book->c1[i].phone) == 0)
        {
            index = i;
            break;
        } 
        else if (search_choice == 3 && strcmp(search, book->c1[i].email) == 0)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        printf("Contact not found!\n\n");
        return;
    }

    int edit_choice;
    printf("\nWhat do you want to edit?\n1. Name\n2. Phone\n3. Email\nEnter choice: ");
    scanf("%d", &edit_choice);

    switch (edit_choice)
    {
        case 1:
        { 
            char new_name[50];
            printf("Enter new name: ");
            scanf(" %[^\n]", new_name);
            for (int j = 0; new_name[j] != '\0'; j++)
            {
                char ch = new_name[j];
                if (!((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || ch == ' '))
                {
                    printf("Invalid input\n");
                    return;
                }
            }
            strcpy(book->c1[index].name, new_name);
            break;
        }

        case 2:
        {
            char new_phone[20];
            printf("Enter new phone: ");
            scanf("%s", new_phone);
            if (strlen(new_phone) != 10) 
            {
                printf("Invalid input\n");
                return;
            }
            for (int j = 0; j < 10; j++)
            {
                if (new_phone[j] < '0' || new_phone[j] > '9')
                {
                    printf("Invalid input\n");
                    return;
                }
            }
            strcpy(book->c1[index].phone, new_phone);
            break;
        }

        case 3:
        { 
            char new_email[50];
            printf("Enter new email: ");
            scanf("%s", new_email);
            if (strchr(new_email, '@') == NULL || strstr(new_email, ".com") == NULL)
            {
                printf("Invalid input\n");
                return;
            }
            for (int j = 0; new_email[j] != '\0'; j++)
            {
                if (new_email[j] >= 'A' && new_email[j] <= 'Z')
                {
                    printf("Invalid input\n");
                    return;
                }
            }
            strcpy(book->c1[index].email, new_email);
            break;
        }

        default:
            printf("Invalid choice!\n");
            return;
    }

    printf("Contact updated successfully!\n\n");
    void listContact(struct Addressbook *book);
}
   
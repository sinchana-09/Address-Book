
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
   void createContact(struct Addressbook *book)
   {  
  if(book ->Contactcount >=100)
  {
    printf("Address book is full");
    return;
  }
  int i=book->Contactcount;
  char name[50],phone[20];
printf("Enter the name :");
scanf(" %[^\n]" ,name);
int isnamevalid=1;
int j;
  for (j=0 ; name[j] != '\0';j++)
  {
    char ch = name[j];
    if(!((ch >= 'A' && ch <='Z')||(ch >='a' && ch <= 'z')|| ch == ' '|| ch =='.'))
    {
      isnamevalid=0;
      break;
    }
  }
  if(isnamevalid==0)
  {
    printf("Invalid input");
    return;
  }
  int isnumvalid=1;
  printf("Enter the number:");
  scanf("%s" , phone);
  if (strlen(phone) !=10)
  {
    isnumvalid=0;
  }
  else
  {
    for(j=0;j<10 ;j++)
    {
      if(phone[j]<'0'||phone[j] >'9')
      {
        isnumvalid=0;
        break;
      }
    }
  }
  if(isnumvalid==0)
  {
    printf("Invalid input");
    return;
  }
  char new_email[50];
printf("Enter email: ");
scanf("%s", new_email);

int len = strlen(new_email);
int valid = 1;

// 1. Check if it ends with "@gmail.com" (10 characters long)
if (len < 10 || strcmp(new_email + (len - 10), "@gmail.com") != 0) {
    valid = 0;
} else {
    // 2. Check characters BEFORE "@gmail.com" for capital letters
    for (int j = 0; j < len - 10; j++) {
        if (new_email[j] >= 'A' && new_email[j] <= 'Z') {
            valid = 0;
            break;
        }
    }
}

if (valid == 0) {
    printf("Invalid input!\n");
    return;
}
  strcpy(book->c1[i].name , name);
  strcpy(book ->c1[i].phone,phone);
  strcpy(book->c1[i].email,new_email);
  book->Contactcount++;
}
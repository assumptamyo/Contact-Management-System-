#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_CONTACTS 100
struct Contact{
    char name[50];
    char email[50];
    char phono[15];
    char address[50];
};

void addContact(struct Contact contacts[],int *contactNo){
    if(*contactNo < MAX_CONTACTS){
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        printf("\nEnter Name : ");
        fgets(contacts[*contactNo].name,sizeof(contacts[*contactNo].name),stdin);
        contacts[*contactNo].name[strcspn(contacts[*contactNo].name, "\n")] = '\0';
        printf("Enter Email : ");
        scanf("%s",contacts[*contactNo].email);
        printf("Enter Phono : ");
        scanf("%s",contacts[*contactNo].phono);
        while ((c = getchar()) != '\n' && c != EOF);
        printf("Enter Address : ");
        fgets(contacts[*contactNo].address,sizeof(contacts[*contactNo].address),stdin);
        printf("Contact added Successfully ! \n\n");
        (*contactNo)++;
    }else{
        printf("Cannot Add More Contacts.Contact list is full.\n\n");
    }
}

void searchContact(struct Contact contacts[],int contactNo){
    int i,found=0;
    char searchName[50];
    int c;
    while((c = getchar()) !='\n' && c != EOF);
    printf("Enter searchName : ");
    fgets(searchName,sizeof(searchName),stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    for(i=0; i<contactNo; i++){
        if(strcmp(searchName, contacts[i].name) == 0){
            printf("**Contact Found : \n");
            puts(contacts[i].name);
            printf("Email : %s\n",contacts[i].email);
            printf("Phono : %s\n", contacts[i].phono);
            puts(contacts[i].address);
            found=1;
            break;
        }
    }
    if(!found){
        printf("Contact not found!\n");
    }
}

void displayContact(struct Contact contacts[],int contactNo){
    int i;
    if(contactNo == 0) {
        printf("No contacts avaliable.\n\n");
        return;
    }
        printf("\t Contact Lists \n");
        for(i=0; i<contactNo; i++){
            printf("%d. Name : %s , Email : %s , Phono : %s , Address : %s \n",i+1,contacts[i].name,contacts[i].email,contacts[i].phono,contacts[i].address);
    }
}
    void main(){
    int choice,contactNo=0;
    system("cls");
    struct Contact contacts[MAX_CONTACTS];
    do{
        printf("Contact Management System\n");
        printf("1: Add Contatct \n");
        printf("2: Search Contact \n");
        printf("3: Display Contact \n");
        printf("4: Exist \n");
        printf("Enter any choice : ");

    if (scanf("%d", &choice) != 1){
        printf("%d",scanf("%d",&choice));
        int c;
        c = getchar();
        while((c=getchar()) != '\n' && c != EOF);
    }
        switch (choice)
        {
            case 1 :
                addContact(contacts,&contactNo);
                break;
            
            case 2 :
                searchContact(contacts,contactNo);
                break;

            case 3 :
                displayContact(contacts,contactNo);
                break;

            case 4 :
                printf("Existing System! \n");
                break;
        
            default:
                printf("Invalid Input!Please type a digit between 1 and 4. \n");
                break;
        }
    }while(choice!=4);
}
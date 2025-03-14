#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student 
{
    int roll_no;
    char name[20];
    struct student *next;
};

struct student* add_last(struct student *ptr)
{
    struct student *nu = (struct student*)calloc(1,sizeof(struct student));
    printf("Enter roll number: ");
    scanf("%d", &nu->roll_no);
    printf("Enter name: ");
    scanf("%s", nu->name);
    nu->next = NULL;

    if (ptr == NULL) 
    {
        ptr=nu;
        nu->next = nu;
        //return newNode;
        
        return ptr;
    }
    else
    {
        struct student *temp = ptr;
        while (temp->next != ptr) 
        {
            temp = temp->next;
        }
        temp->next = nu;
        nu->next = ptr;
    }
    return ptr;
}

struct student *add_first(struct student *ptr)
{
    struct student *temp=NULL;
    struct student *nu = (struct student*)calloc(1,sizeof(struct student));
    printf("Enter roll number: ");
    scanf("%d", &nu->roll_no);
    printf("Enter name: ");
    scanf("%s", nu->name);
    
    if(ptr==NULL)
    {
        ptr=nu;
        nu->next=ptr;
        return ptr;
    }
    
    nu->next=ptr;
    temp=ptr;
    
    while(temp->next != ptr)
    {
        temp=temp->next;
    }
    
    ptr=nu;
    temp->next=nu;
    
    return ptr;
}

struct student *delete_first(struct student *ptr)
{
    struct student *temp=NULL,*last=NULL;
    
    if(ptr==NULL)
    {
        printf("circular sll is empty\n");
        return NULL;
    }
    
    //only single node is present and that node to be delete from the list
    if(ptr->next==ptr)
    {
        free(ptr);
        ptr=NULL;
        return NULL;
    }
    temp=ptr;
    last=ptr;
    while(last->next != ptr)
    {
        last=last->next;
    }
    ptr=ptr->next;
    last->next=ptr;
    
    free(temp);
    temp=NULL;
    return ptr;
}

void display(struct student *ptr)
{
    if (ptr == NULL) {
        printf("List is empty\n");
        return;
    }
    struct student *temp = ptr;
    do {
        printf("Address: %p, Roll No: %d, Name: %s next_addr:%p\n", (void*)temp, temp->roll_no, temp->name,temp->next);
        temp = temp->next;
    } while (temp != ptr);
}

struct student *delete_last(struct student *ptr)
{
    struct student *temp=NULL,*current=NULL;
    
    if(ptr==NULL)
    {
        printf("circular sll is empty\n");
        return NULL;
    }
    
    if(ptr->next==ptr)
    {
        free(ptr);
        ptr=NULL;
        return NULL;
    }
    
    temp=ptr;
    while(temp->next != ptr)
    {
        current=temp;
        temp=temp->next;
    }
    current->next=ptr;
    
    return ptr;
}

int main()
{
    struct student *head=NULL;
    int choice;
    while(1)
    {
        printf("1.add_last 2.add_first 3.delete_first 4.delete_last 8.display\n");
        printf("enter your choice:");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1: head=add_last(head);
                        break;
            case 2: head=add_first(head);
                        break;
            case 3: head=delete_first(head);
                        break;
            case 4: head=delete_last(head);
                        break;
            case 8: display(head);
                        break;
            
        }
    }
    return 0;
}

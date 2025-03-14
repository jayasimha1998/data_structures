 

/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student 
{
    int roll_no;
    char name[20];
    struct student *next;
};

struct student *add_last(struct student *ptr)
{
    struct student *nu=NULL,*tmp=NULL;
    
    nu=calloc(1,sizeof(struct student));
    if(nu==NULL)
    {
        printf(" node not created\n");
        return ptr;
    }
    
    printf("enter stu roll_no:\n");
    scanf("%d",&nu->roll_no);
    printf("enter stu name:\n");
    scanf("%s",nu->name);
    
    if(ptr==NULL)
    {
        ptr=nu;
    }
    else
    {
        tmp=ptr;
        while(tmp->next)
        {
            tmp=tmp->next;
        }
        tmp->next=nu;
    }
    return ptr;
}

void display(struct student *ptr)
{
  while(ptr !=NULL)
  {
      printf("stu->roll_no:%d stu->name:%s\n",ptr->roll_no,ptr->name);
      ptr=ptr->next;
  }
  
}

struct student *add_first(struct student *ptr)
{
    struct student *nu=NULL;
    
    nu=calloc(1,sizeof(struct student));
    
    if(nu==NULL)
    {
        printf(" node not created\n");
        return ptr;
    }
    
    printf("enter stu roll_no:\n");
    scanf("%d",&nu->roll_no);
    printf("enter stu name:\n");
    scanf("%s",nu->name);
    
    
    nu->next=ptr;
    ptr=nu;
    
    return ptr;
    
}

struct student *add_middle(struct student *ptr)
{
    struct student *nu=NULL,*tmp=NULL,*current=NULL;
    
    nu=calloc(1,sizeof(struct student));
    
    if(nu==NULL)
    {
        printf("node not created\n");
        return ptr;
    }
    
    printf("enter stu roll_no:\n");
    scanf("%d",&nu->roll_no);
    printf("enter stu name:\n");
    scanf("%s",nu->name);
    
    int size=0;
    if(ptr==NULL)
    {
        ptr=nu;
    }
    else
    {
        tmp=ptr;
        while(tmp)
        {
            size++;
            tmp=tmp->next;
        }
        
        int cnt=(size%2==0)?(size/2):((size+1)/2);
        
        tmp=NULL;
        
        tmp=ptr;
        current=ptr->next;
        for(int i=0;i<cnt;i++)
        {
            current=tmp;
            tmp=tmp->next;
        }
        
        current->next=nu;
        nu->next=tmp;
    }
    
    return ptr;
}

struct student *delete_last(struct student *ptr)
{
    struct student *tmp=NULL,*current=NULL;
    
    if(ptr==NULL)
    {
        printf("sll is empty\n");
        return ptr;
    }
    else
    {
        tmp=ptr;
        while(tmp->next)
        {
            current=tmp;
            tmp=tmp->next;
        }
        if(ptr==tmp)
        {
            ptr=NULL;
        }
        else
        {
            current->next=NULL;
        }
        free(tmp);
        tmp=NULL;
    }
    return ptr;
}

struct student *delete_first(struct student *ptr)
{
    struct student *tmp=NULL;
    
    if(ptr==NULL)
    {
        printf("sll is empty\n");
        return ptr;
    }
    tmp=ptr;
    ptr=ptr->next;
    
    free(tmp);
    tmp=NULL;
    
    return ptr;
}

struct student *delete_data(struct student *ptr,int data)
{
    struct student *tmp=NULL,*prev=NULL;
    
    if(ptr==NULL)
    {
        printf("sll is empty\n");
        return ptr;
    }
    else if(ptr->roll_no == data)
    {
        tmp=ptr;
        ptr=ptr->next;
        free(tmp);
        tmp=NULL;
    }
    else
    {
        prev=ptr;
        tmp=ptr->next;
        while(tmp && tmp->roll_no != data)
        {
            prev=tmp;
            tmp=tmp->next;
        }
        
        if(tmp==NULL)
        {
            printf("data:%d is not found in a list\n",data);
        }
        else
        {
            prev->next=tmp->next;
            
            free(tmp);
            tmp=NULL;
        }
        return ptr;
    }
}

struct student *delete_middle(struct student *ptr)
{
    struct student *temp=NULL,*current=NULL;
    int cnt=0;

    temp=ptr;
    while(temp)
    {
        cnt++;
        temp=temp->next;
    }
    printf("cnt:%d\n",cnt);

    int size=(cnt%2==0)?(cnt/2):((cnt+1)/2);
    temp=NULL;
    current=ptr;
    temp=ptr->next;
    for(int i=0;i<size-1;i++)
    {
        current=temp;
        temp=temp->next;
    }
    current->next=temp->next;
    free(temp);
    temp=NULL;
    return ptr;
}

struct student *add_node_at_position(struct student *ptr,int postion)
{
  struct student *nu=NULL,*tmp=NULL,*current=NULL;
  
  nu=calloc(1,sizeof(struct student));
  if(nu==NULL)
  {
      printf("no new node created\n");
      return ptr;
  }
  
    printf("enter stu roll_no:\n");
    scanf("%d",&nu->roll_no);
    printf("enter stu name:\n");
    scanf("%s",nu->name);
    
    //add_at_first
    if(postion==0)
    {
        nu->next=ptr;
        ptr=nu;
    }
    else
    {
        tmp=ptr;
        for(int i=0;i<postion && tmp != NULL;i++)
        {
            tmp=tmp->next;
        }
        
        if(tmp==NULL)
        {
            printf("given postion:%d out of the list\n",postion);
        }
        else
        {
            nu->next=tmp->next;
            tmp->next=nu;
        }
    }
    return ptr;
}

struct student *delete_node_at_position(struct student *ptr,int postion)
{
    struct student *tmp=NULL,*current=NULL;

    if(postion==0)
    {
        tmp=ptr;
        ptr=ptr->next;
        free(tmp);
        tmp=NULL;
        return ptr;
    }
    else
    {
        //current=ptr;
        tmp=ptr; //->next;
        for(int i=1;i<postion;i++)
        {
            current=tmp;
            tmp=tmp->next;
        }
        current->next=tmp->next;
        free(tmp);
        tmp=NULL;
    }
    return ptr;
}

struct student *reverse_list(struct student *ptr)
{
    struct student *prev=NULL,*current=NULL,*next=NULL;

    current=ptr;
    while(current != NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    ptr=prev;
    return ptr;
}

int main()
{
    struct student *head=NULL;
    int choice,data,postion;
    while(1)
    {
        printf("1.add_last 2.add_first 3.add_middle 4.delete_last 5.delete_first 6.delete_middle 7.delete_data 8.display 9.add_node_at_position 10.delete_node_at_position 11.reverse_list 12.exit\n");
        printf("enter your choice:");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1: head=add_last(head);
                        break;
            case 2: head=add_first(head);
                        break;
            case 3: head=add_middle(head);
                        break;
            case 4: head=delete_last(head);
                        break;
            case 5: head=delete_first(head);
                        break;
            case 6: head=delete_middle(head);
                        break;
            case 7: printf("enter delete data:");
                    scanf("%d",&data);
                    head=delete_data(head,data);
                    break;
            case 8: display(head);
                    break;
            case 9: printf("enter new node postion:");
                    scanf("%d",&postion);
                    head=add_node_at_position(head,postion);
                    break;
            case 10: printf("enter delete node postion:");
                     scanf("%d",&postion); 
                     head=delete_node_at_position(head,postion);
                     break;
            case 11: head=reverse_list(head);
                     break;
            case 12: exit(0);

            default: printf("invalid option\n");   
        }
    }

    return 0;
}



/* pending functions

    1. duplicate node is found then delete the node

    2.

*/

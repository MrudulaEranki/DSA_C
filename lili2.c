#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node* next;
};
struct node *head , *tail = NULL;


void add_into_LL(int data)
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));

    ptr->data = data;
    ptr->next = NULL;

    if(head == NULL)
    {
        head = ptr;
        tail = ptr;
    }

    else 
    {
        tail->next = ptr;
        tail = ptr;
    }
}

int count_LL()
{
    int count  = 0;

    struct node* current = head;

    while(current != NULL)
    {
        count ++;
        current = current->next;
    }
    return count;
}

void display_LL()
{
    struct node* now = head;

    if (head == NULL){
      printf("empty list!!\n");
      return;
    }

    printf("the items are:\n");

    while (now != NULL)
    {
        /* code */
        printf("%d\n",now->data);
        now = now->next;
    }
   // printf("\n");
    
}

void insert()
{
    struct node *new ;
    new = malloc(sizeof(struct node));


    printf("enter the position where you'd like to insert your item\n");
    int pos;
  

    scanf("%d",&pos);
     int  elements = count_LL();
    int a;
        printf("enter the number\n");
        scanf("%d",&a);


        if(pos == 1)
        {
        new->data = a;
        new->next = head;
        head = new;
       }

       if(pos > elements)
       {
        new->data = a;
        new->next = NULL;

        struct node *temp = head;
        while(temp->next != NULL){
        temp = temp->next;
         }

       temp->next = new;
       }

       if(pos > 1 && pos < elements)
       {
        struct node *temp = head;

          for(int i=2; i < pos; i++) {
            if(temp->next != NULL) {
               temp = temp->next;
          }
           }
         new->next = temp->next;
            temp->next = new;
       }
       system("cls"); 
	  
    

}

void delete()
{
     printf("enter the position where you'd like to delete your item\n");
    int pos;
  

    scanf("%d",&pos);

    struct node* temp = head; 

    int i;
    if (pos == 1) {
        printf("\nElement deleted is : %d\n", temp->data);
        head = head->next;
        temp->next = NULL;
        free(temp); 
    }
    else {
        for (i = 1; i < pos ; i++) {
            temp = temp->next;
        }
        
        struct node* del = temp->next; 
        temp->next = temp->next->next;
        printf("\nElement deleted is : %d\n", del->data);
        del->next = NULL;
        free(del); 
    }
    system("cls"); 
			//mainscreen();
    
}



int main()
{
    int n;
    system("cls"); 
	//mainscreen();
	label1:


	printf("\n\t\t\t\t\t\t\t\t\t\tEnter the corresponding no\n");
	printf("\n\t\t\t\t\t\t\t\t\t\t1.DISPLAY\n");
	printf("\n\t\t\t\t\t\t\t\t\t\t2.INSERT\n");
	printf("\n\t\t\t\t\t\t\t\t\t\t3.DELETE\n");
       	
	fflush(stdin);
    char d;
    scanf("%c",d);
	
	switch(d)
	{
		case '1':
		      {
			display_LL();
		       
			break;
		      }
		case '2':
		      {
			insert();
			break;

			}
		case '3':
		      {
			delete();
			break;
			}

		default:
		       {
			system("cls"); 
			//mainscreen();
			printf("\n\t\t\t\tWrong choice");
			 printf("\n\t\t\t\tRetype choice");
			goto label1;
			}

	}
	system("cls"); 
	//mainscreen();
	goto label1;

    return 0;
}
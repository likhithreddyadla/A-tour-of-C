#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Creating a Struct function to generate a linked list
struct Node
{
  char* word;
  struct Node* link;
}Node;

// function for creating a node with string before hand
struct Node* createNode(char* word)
{
  struct Node* start=(struct Node*)malloc(sizeof(struct Node));
  if(start==NULL)
    {
      return start;
    }
  //copies the string from the argv and store it in the linked list
  start->word=strdup(word);
  start->link=NULL;
    return start;
}
// Need an insert method of linked lists
struct Node* insert(struct Node* start,char* word)
{
  //if linked list is null
  if(start==NULL)
    {
      //adding a linked list to the front of the linked list bc it was empty list
      start= createNode(word);
      return start;
    }
  //adding in the front of the linked list
  if(CompStrings(start->word,word)<0)
    {
      struct Node* temp=start;
      struct Node* new =createNode(word);
      start=new;
      start->link=temp;
      return start;
    }
  else
    {
      struct Node* ptr= NULL;
      //adding in the between the linked list
      for(ptr=start;ptr->link!=NULL;ptr=ptr->link)
	{
	  if(CompStrings(ptr->word,word)>0 && CompStrings(ptr->link->word,word)<=0)
	    {
	      struct Node* temp=ptr->link;
	      ptr->link=createNode(word);
	      ptr->link->link=temp;
	      return start;
	     }
	}
      // adding in the back of the linked list
      ptr->link=createNode(word);
      return start;
    }
}
// printing the linked list method
void print(struct Node* start)
{
  struct Node* ptr=start;
  //traversing through the linked list 
  while(ptr!=NULL)
    {
      printf("%s\n",ptr->word);
      ptr=ptr->link;
    }
}


//This is a compare method to compare two strings and sort them in descending aplhabetical order
int CompStrings(char* str1, char* str2)
{
  char *ptr1=str1;
  char* ptr2=str2;

  while(*ptr1 !='\0')
    {
      
      if(*ptr2=='\0')
	{
	return 1;
	}
          if(*ptr2>*ptr1)
	    {
	      if(*ptr2>='a' && *ptr2<='z' && *ptr1>='A' && *ptr1<='Z')
		{
		  return 1;
		}
	  
	      return -1;
	    }
	  
	  if(*ptr1>*ptr2)
	    {
	      if(*ptr1>='a' && *ptr1<='z' && *ptr2>='A' && *ptr2<='Z')
		{
		  return -1;
		}
	         return 1;
	    }

	  ptr1++;
	  ptr2++;
           }
              if(ptr2!='\0')
		    return -1;

	      return 0;
}
int main(int argc, char*argv[])
{

  if(argc<2)
    {
      printf("Need to have two arguments to tokenize\n");
      return(1);
    }
  if(argc>2)
    {
       printf("Need to have two arguments to tokenize\n");
      return(1);
    }
  struct Node* start=NULL;
  
  int i;
  //reading the string through argv[1]
  for(i=0;i<strlen(argv[1]);i++)
    {
      //checks if it is not a alphabetical character
      if(!isalpha(argv[1][i]))
	argv[1][i]=' ';
    }
  //gets the words and inserts into the linked list
  char* string=strtok(argv[1]," ");
  while(string!=NULL)
    {
      start=insert(start,string);
      string=strtok(NULL," ");
    }
  
  print(start);
  // Freeing the memory of the linked list
  struct Node* ptr3=start;
  //freeing up the linked lists that i have dynamically created
  while(ptr3!=NULL)
    {
      struct Node* temp=ptr3->link;
      free(ptr3->word);
      free(ptr3);
      ptr3=temp;
    }
  return 0;
}

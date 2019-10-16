--------------------------------------------------------------------Documentation------------------------------------------------------------------
A) what my program does?

->This program pointersorter sorts the strings in descending order of the alphabetical tokens.Printing format of the program is Z-A first then z-a.Capital letters have higher precedence than the lowercase letter.It takes in words from argv[1] string and sort them according to the order.

Example:-
	INPUT:- ./pointersorter "rooney ROOneya ROOney"
	OUTPUT:-
		ROOneya
		ROOney	
		rooney
------------------------------------------xxxxxxxxxxxxxx---------------------------------------------
Example 2:-
	INPUT:- ./pointersorter cat23catmaran569()APPLE
	OUTPUT:- 
		 APPLE
		 catmaran
		 cat

->It also ignores any non alphabetical characters.I have used Linked List Data Structure to insert the string into the Node. Then it sorts string node according to the string comparsion in the linked list.
-------------------------------------------xxxxxxxxxxxxx--------------------------------------------------
B) How is the tokenizer works?

->The string is passed through argv[1]. It checks for the letter in argv[1] and then I used the function strtok() which tokenizes the string, if it sees a non alphabet character it replaces with a space character. it takes the space character as a delimeter.
-------------------------------------------xxxxxxxxxxxxx-----------------------------------------------------
C) Struct Node

-> This is a struct node which consists of a Node string(which holds a word) and a "link" to link to another node. 
-------------------------------------------xxxxxxxxxxxxx--------------------------------------------------------------
D) Struct Node* createNode
-> This function creates a single Node(Linked List) whenever it is called. I have copied the letters by using the function from the "string.h" library which contains strdup().This function allocates memory dynamically.This function returns a pointer to a null-terminated byte string, which is the duplicate of the string pointed to the word. 
------------------------------------------xxxxxxxxxxxx------------------------------------------------------------
E) FUNCTION'S BREAKDOWN

-> CreateNode(char*word)
	-What it does?
	This function creates a single node containing characters and links to null. Once this function is called it can readily be added to the linked 	list. It allocates the memory of the dynamically.

   I have created this fucntion so I break down the lines of code :) 
-------------------------------------------------------------------------------------------------------------------------------

-> struct Node* insert(struct Node* start,char* word)
	-What it does?
	This function adds Node to the linked list in order according to the string compare method. It first checks to see if the linked list is NULL, if 		it is it will add to the front of the linked list.Then checks if it needs to be added in between the linked list and then at the end of the 	   	linked list.It returns the front linked list in the ending after it is done.
------------------------------------------------------------------------------------------------------------------------------------

-> void print(struct Node* start)
	-What it does?
	This function just prints out each node in a new line, it starts with the first node in the linked list and ends at the ending of the linked list.It prints the linked list by traversing through the linked list from the starting.It doesnt return anything.
--------------------------------------------------------------------------------------------------------------------------------

-> int CompStrings(char* str1,char* str2)
	-What it does?
	This function determines which string comes first alphabetically, and in the case of the capital letters it has special cases. It returns 1 if str1> str2, 0 if both strings are equal and -1 if str1<str2.
---------------------------------------------------------------------------------------------------------------------------------
-> in the main function
	- What my main function does?
	In this main I check if it passes in more than two arguments or less than arguements.Also goes through the argv[1] and check for non alphabetical characters,if there are any non alphabetical characters it replaces it with a space character. Then I used the strtok() function where it takes the argv[1] and treats all the space characters as delimeter.Then it calls the function print(start). After it is done printing the linked list, since I have dynamically created a memory by using malloc function. I have to free them all. I have freed all the linked list by traversing through the linked list and calling the function free();
-------------------------------------------------------THE END-------------------------------------------------------------------

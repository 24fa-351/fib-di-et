#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
   char *number_command_line = argv[1];
   char *iterative = argv[2];
   char *filename = argv[3];

   if (argc < 4){
      printf("You dont have enough arguments");
      exit(1);
   }

   int aNumber;
   aNumber = strtol(number_command_line, NULL, 10);

   int intgerReadFromFile;

   // creation of file pointer
   FILE *fptr;
   // Open a file in read mode
   fptr = fopen(filename,"r");
   // Check if nothing is in file
   if(fptr == NULL){
      printf("No file found");
      exit(1);
   }

   // declare a string buffer
   char myString[100];
   // Read the content and store it inside myString
   fgets(myString, 100, fptr);
   // Convert the first characters in the buffer into a interger
   intgerReadFromFile = strtol(myString, NULL, 10);

   // Syntax for printf ( "formatted_string", arguments_list);
   printf("The number in the file %s, the number in the commandline %d, the Iterative is %s, The filename is %s\n",
      intgerReadFromFile, aNumber, iterative, filename);
   printf("file contents: %s\n", myString);

   return 0;
}

// TODO: Find out why you cant read from the test1.txt file

#include <stdio.h>
#include <stdlib.h>

int fib_recursive(int N) 
{
   if (N <= 0)
   {
      return 0;
   }
   if (N == 1)
   {
      return 1;
   }
   return fib_recursive(N - 1) + fib_recursive(N - 2); // recursively summing the two previous numbers in the sequence.
}

int fib_iterative(int N)
{
   int ix = 0;
   int iy = 1;
   int next_int;
   if (N <= 0)
   {
      return 0;
   }
   if (N == 1)
   {
      return 1;
   }
   for (int fi = 2; fi <= N; fi++)
   {
      next_int = ix + iy;                            // 'next_int' is assigned to the sum of ix + iy.
      ix = iy;                                       // 'ix' value is assigned the 'y' value.
      iy = next_int;                                 // 'iy' value is assigned the 'next_int' value.
   }
   return iy;
}

int main(int argc, char *argv[])
{
   char *number_from_terminal = argv[1];
   char *method = argv[2];
   char *filename = argv[3];

   if (argc < 4)
   {
      printf("You dont have enough arguments\n");
      exit(1);
   }

   int number_from_term = strtol(number_from_terminal, NULL, 10);
   int number_from_file;
   int N;

   FILE *fptr;                                     // creation of file pointer called fptr.
   fptr = fopen(filename, "r");                    // Open a file in read mode.
   if (fptr == NULL)                               // Check if nothing is in file.
   {
      printf("No file found\n");
      exit(1);
   }

   char my_string[100];                            // declare a string buffer.
   fgets(my_string, 100, fptr);                    // Read the content and store it inside myString.
   number_from_file = strtol(my_string, NULL, 10); // Convert the first characters in the buffer into a interger.

   N = number_from_term + number_from_file;

   if (method[0] == 'r')                           // Method 'r' fib_recursive is call.
   {
      int fib_value = fib_recursive(N - 1);
      printf("%d", fib_value);
   }
   else if (method[0] == 'i')                      // Method 'i' fib_iterative is call.
   {
      int fib_value = fib_iterative(N - 1);
      printf("%d", fib_value);
   }
   return 0;
}
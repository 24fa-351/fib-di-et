#include <stdio.h>
#include <stdlib.h>

int fib_recursive ( int N ) {
   if (N <= 0){ return 0; }                                    // Check if N is '0'
   if (N == 1){ return 1; }                                    // Check if N is '1'
   return fib_recursive ( N - 1 ) + fib_recursive ( N - 2 );   
}

int fib_iterative( int N ) {
   int x = 0;
   int y = 1;
   int next_int;
   if ( N <= 0 ) { return 0; }            // check if N is '0'
   if ( N == 1 ) { return 1; }            // check if N is '1'
   for ( int i = 2 ; i <= N ; i++ ) {
      next_int = x + y;                   // 'next_int' is assigned to the sum of x + y.
      x = y;                              // 'x' value is assigned the 'y' value.
      y = next_int;                       // 'y' value is assigned the 'next_int' value.
   }
   return y;
}

int main ( int argc, char *argv[] ) {
   char *number_command_line = argv[1];
   char *method = argv[2];
   char *filename = argv[3];

   if (argc < 4){
      printf("You dont have enough arguments");
      exit(1);
   }

   int number = strtol(number_command_line, NULL, 10);
   int number_from_file;
   int N; 

   FILE *fptr;                                        // creation of file pointer called fptr
   fptr = fopen(filename,"r");                        // Open a file in read mode
   if ( fptr == NULL ) {                              // Check if nothing is in file
      printf("No file found");
      exit(1);
   }

   char my_string[100];                                // declare a string buffer
   fgets(my_string, 100, fptr);                        // Read the content and store it inside myString
   number_from_file = strtol(my_string, NULL, 10);     // Convert the first characters in the buffer into a interger
   
   N = number + number_from_file;

   if ( method[0] == 'r' ) {
      int fib_value = fib_recursive( N - 1 );
      printf( "%d" , fib_value );
   } 
   else if ( method [0] == 'i' ) {
      int fib_value = fib_iterative( N - 1 );
      printf( "%d" , fib_value );
   }
   return 0;
}
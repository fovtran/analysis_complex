#include <stdio.h>
int main() 
{
int i;
int j;
int size = 1;
int array [size][size];

printf ("Enter the size you would like for the nxn matrix: ");
scanf ("%d", &size);

printf ("Now enter elements into the matrix. \n");

for (i = 0; i < size; i++)
{
   for (j = 0; j < size; j++)
   {
      printf ("[%d][%d] = ", i, j);
      scanf ("%d", &array [i][j]);
   }
}
printf ("------------------------\n\n");

printf ("the matrix is: \n\n");

for (i = 0; i < size; i++)
{
   for (j = 0; j < size; j++)
   {
      printf ("  %d  ", array [i][j]);
   }
   printf ("\n");
}
return (0);
}
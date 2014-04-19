

/*****************************************************************
 * Brennan Wallace                                               *
 * Box:  4775                                                    *
 * Supplemental Problem 3 for CSC 161                            *
 * Assignment for Friday, March 15                            *
 *****************************************************************/

/*****************************************************************
 * Academic honesty certification:                               *
 *   Written/online sources used:                                *
 *							      	 *
 *    Website 1 Professor Walker's  Grinnell Website	         *
 *		www.cs.grinnell.edu/~walker/                     *
 *		courses/161.sp13/modules/getting-                *
 *		started/getting-started.shtml			 *
 *								 *
 *	  Website 2 The sizeof Operator                          *
 *		msdn.microsoft.com/en-us/library/0w557f          *
 *               h7(v=vs.80).aspx                                *
 *			      					 *
 *    Textbook 1 The C programming Language			 *
 *      By Brian W. Kernighan and Dennis M. Ritchie              *
 *								 *
 *   Help obtained:                                              *
 *					      			 *
 *     Professor Walker					 *
 *						      		 *
 *   My signature below confirms that the above list of sources  *
 *   is complete AND that I have not talked to anyone else       *
 *   [e.g., CSC 161 students] about the solution to this problem *
 *                                                               *
 *   Signature:							 *
 *	       							 *
 *					         Brennan Wallace *
 *****************************************************************/

#include <stdio.h>


#define num_of_letters 26

void print_histogram(int char_totals[], int num_of_lines);
int highest_pos_int_in_an_int_array (int int_array[], int array_len);
void zeroed_out_array(int array[], int array_len);
void count_frequency (int char_totals []);

int main ()
{
  //declaring variables
  int char_totals[num_of_letters];
  int num_of_lines = 0;
	
  //set all array values to zero 
  zeroed_out_array(char_totals, num_of_letters);

  //input data and alter array accordingly
  count_frequency (char_totals);
	
  //find the nuber of lines by finding the highest total
  num_of_lines = highest_pos_int_in_an_int_array (char_totals, num_of_letters);
	
  print_histogram(char_totals, num_of_lines);

  return 0; //to indicate no errors
}

//zeroed_out_array documentation:
/*
  Pre-Conditions:
	
  size of array >= Amount_cleared > -1.
	
  Post-Conditions:
 
  Set array elements starting with element 0 and up to 1 less than amount_cleared, to 0.
 
*/

void zeroed_out_array(int array[], int amount_cleared)
{
  int i;
  //turn all elements in the array up to amount_cleared to 0
  for (i = 0; i < amount_cleared; i++)
    {
      array[i] = 0;
    }
}

//print_histogram documentation:
/*
  Pre-Conditions:
 
  num_of_lines > -1.
 
  num_of_lines = max value of the elements of  char_totals
 
  Post-Conditions:
 
  Prints a histogram that shows the size of each element with a corresponding letter
 
*/

void print_histogram(int char_totals[], int num_of_lines)
{
	
  int outer_count, inner_count;
  int i;
	

	
  printf("Histogram follows:\n");
  //if the element's size is at least the same value as the current line nember oa * is printed for that letter
	
  //the outer loop goes through the lines
  //the inner loop goes through the indivdual letters/array for each line
	
	
  for (outer_count = num_of_lines; outer_count > 0; outer_count--) 		{
    for (inner_count = 0; inner_count < num_of_letters; inner_count++)
      {
        if (char_totals[inner_count] >= outer_count)
          {
            printf("* ");
          }
        else
          {
            printf("  ");
          }
      }
    printf("\n");
  }
	
  //print axis
  for (i = 'a'; i <= 'z'; i++)
    {
      printf("%c ", i);
    }
	
  printf("\n");
}

//highest_pos_int_in_an_int_array documentation:
/*
  Pre-Conditions:
 
  array_len = the length of int_array
 
  Post-Conditions:
 
  returns highest_int
	
  highest_int = the largest element in the array
 
*/

int highest_pos_int_in_an_int_array (int int_array[], int array_len)
{
  int highest_int = 0;
  int i;
  for (i = 0; i < array_len; i++)
    {
      if (int_array[i] > highest_int)
        {
          highest_int = int_array[i];
        }
    }
  return highest_int;
}

//count_frequency documentation:
/*
  Pre-Conditions:
 
  char_totals[] must be 26 elements long or longer
  the first 26 elements must all = 0
 
 
  Post-Conditions:
 
  char_totals[]'s elements will be changed to represnt the number of temes each letter is inputed 
  where 'a''s frequency is represented by char_totals[0], 'b' 's frequency by char_totals[1] and so on
 
*/

void count_frequency (int char_totals[])
{
  int i, h;
  int char_num;
  char ch;
  //ask for input
  printf("Enter Text:");
	
	
  //add values to the array
  ch = getchar();
  while (!(ch == '#')) //letter counting stop at the first # sign
    {
      if (isalpha(ch))
        {
          //convert to lower case if upper
          if (isupper(ch)) 
            {
              ch = tolower(ch);
            }
			
          //add values to the array
          char_num = ch - 'a'; 
          char_totals[char_num]++;
        }
      ch = getchar();
    }
}



/*

  Set of Reasonable Circumstances:
 
  1. letters are not used but the output does not reflect this or has some other error 
  2. multiple lines are used but the output does not reflect this or has some other error 
  3. upper-case letters are used but the output does not reflect this or has some other error
  4. lowercase letters are used but the output does not reflect this or has some other error
  5. not all the letters work
  6. non-letters are not ignored
  7. # does not end input
  8. there is a tie for the most common letter but the output does not reflect this or has some other error

 
 
  Test Plan:
 
  To test these circumstances and their effects several tests will be done that each cover one or more of these circumstances. 
  If one of these cases produces a non-desired output we can conclude that an error occurred. 
  Desired output would be where the output looks like the sample provided and follows the problems specifications.
 
  A more detailed list qualities that describe successful output include:
  For each letter of a certain type a star is placed.
  Each star should be on top of others for that letter (if there are any).
  Capital letters are treated as lowercase.
  The height of the histogram is no more then the title line and the number of stars for the most common letter(s)
  non-letter charters should be ignored
  input is looked at until the # is used
 
  Tests:
 
  Test A:
  Circumstances Tested: 1,7
 
  Input:#abcedfg
 
  Expected Output:
 
  Histogram follows:
  a b c d e f g h i j k l m n o p q r s t u v w x y z
 
 
  Test B:
  Circumstances Tested: 2-6
 
  Input:AAAaaabc23defghijklmnopqrstuvwxyz#
 
  Expected Output:
 
  Histogram follows:
  *
  *
  *
  *
  *
  * * * * * * * * * * * * * * * * * * * * * * * * * *
  a b c d e f g h i j k l m n o p q r s t u v w x y z
 

 
 
  Test C:
  Circumstances Tested: 2, 3, 6, 8
 
  Input:aaAbbBccC!!!#
 
  Expected Output:
 
  Histogram follows:
 
  * * *
  * * *
  * * *
  a b c d e f g h i j k l m n o p q r s t u v w x y z
 

 Output:

  Test 1:


  blanch$ gcc -lMyroC -o gogo /home/wallaceb/Desktop/SP3CSC161.c
  blanch$ ./gogo
  Enter Text:#abcedfg
  Histogram follows:
  a b c d e f g h i j k l m n o p q r s t u v w x y z 

  Output Correct

  Test 2:

  blanch$ ./gogo
  Enter Text:AAAaaabc23defghijklmnopqrstuvwxyz#
  Histogram follows:
  *                                                   
  *                                                   
  *                                                   
  *                                                   
  *                                                   
  * * * * * * * * * * * * * * * * * * * * * * * * * * 
  a b c d e f g h i j k l m n o p q r s t u v w x y z 
  
  Output Correct 

  Test 3:


  blanch$ ./gogo
  Enter Text:aaAbbBccC!!!#
  Histogram follows:
  * * *                                               
  * * *                                               
  * * *                                               
  a b c d e f g h i j k l m n o p q r s t u v w x y z 
 
  Output Correct

 
  Analysis:
 
  All the tests produce the expected output. As the test outputs were based on the 
  problems not occurring we can conclude that the program, with identical output to
  the prediction.  Because of this the code can be considered successful.
 
*/

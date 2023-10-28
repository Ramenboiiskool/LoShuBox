#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int size = 3;

int checkLoShuMagicSquare(const int[][size]);
void printSquare(const int[][size]);

int main() 
{
    	time_t t;
    	srand((unsigned)time(&t));

   	int array[size][size];
    	int numbers[9];
    	int count = 0;

	//Using example working Loshu Box
    	int array1[][3] = {{4, 9, 2}, 
        	      	 {3, 5, 7}, 
                    	 {8, 1, 6}};

    	printSquare(array1);
    	if(checkLoShuMagicSquare(array1))
        	printf("Is a loshu square \n");
    	else   
        	printf("Is not a loshu square \n");

    	//Using example of not working Loshu Box
    	int array2[][3] = {{1, 2, 3}, 
                    	 {4, 5, 6}, 
                    	 {7, 8, 9}};
    	printSquare(array2);
	if(checkLoShuMagicSquare(array2))
        	printf("Is a loshu square \n");
    	else   
        	printf("Is not a loshu square \n");

    	do 
	{
        	// Populate the array with random unique numbers from 1 to 9
        	for (int i = 0; i < 9; i++) 
		{
            	numbers[i] = i + 1;
        	}

        	for (int i = 0; i < size; i++) 
		{
            	for (int j = 0; j < size; j++) 
			{
                		int index = rand() % 9;
                		array[i][j] = numbers[index];
                		numbers[index] = numbers[8]; // Remove used number
            	}
        	}

        	count++;

    	} 
    	while (!checkLoShuMagicSquare(array));

    	printf("Lo Shu Magic Square found after %d attempts:\n", count);
    	printSquare(array);

    	return EXIT_SUCCESS;
}

	int checkLoShuMagicSquare(const int square[][size]) 
	{
    		// Check rows, columns, and diagonals
    		int sum1 = 0, sum2 = 0;
    		for (int i = 0; i < size; i++) 
		{
      	  	int rowSum = 0;
      	  	int colSum = 0;
      	  	for (int j = 0; j < size; j++) 
			{
            		rowSum += square[i][j];
            		colSum += square[j][i];
        		}
        		if (rowSum != 15 || colSum != 15) 
			{
            		return 0;
        		}
        		sum1 += square[i][i];
        		sum2 += square[i][size - 1 - i];
    		}
    		return sum1 == 15 && sum2 == 15;
	}

	void printSquare(const int square[][size]) 
	{
    		for (int i = 0; i < size; i++) {
        		for (int j = 0; j < size; j++) 
			{
            		printf("%d ", square[i][j]);
        		}
        		printf("\n");
    	}
	}
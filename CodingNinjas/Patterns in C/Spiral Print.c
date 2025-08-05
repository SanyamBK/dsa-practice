#include <stdio.h>

void spiralPrint(int nRows, int mCols, int input[][mCols])


int main ()
{  
	int nRows = 4, mCols = 4;

   int input[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

     int e = 0, els = nRows * mCols;
	 int i = 0, j = 0, colstr= 0, colend = mCols - 1, rowstr = 0, rowend = nRows - 1 ;
    while (e < els) {
      
      while (j <= colend) {
        printf("%d ", input[i][j]);
		j ++; e++;
		
      }
	  rowstr ++;
	  i = rowstr; j --;
	  while (i <= rowend) {
		printf("%d ", input[i][j]);
		i ++; e++;
		}
		colend --;

	i-- ; j--;


	  while (j >= colstr) {
		printf("%d ", input[i][j]);
		j--; e++;
	  }
	  	rowend --;
	  j++; i--;

	while (i >= rowstr) {
		printf("%d ", input[i][j]);
		i--; e++;
	}
	i++;
	colstr++;

    }
}




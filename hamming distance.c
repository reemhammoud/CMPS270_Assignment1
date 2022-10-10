#include <stdio.h>


int x, y,z;

int main()
{
    //test cases
    // positive integers 0 and 3 gives 2
    //negative value terminates 
    //powers of 2 returns 0 4 and 4 gives 0 8 and 8 gives zero
    
    printf("Enter two positive integers or negative number to terminate: ");      
    scanf("%d%d", &x, &y); 

  
    while (x>=0 && y>=0) {
        printf("%d\n", hamming_distance(x, y));

        printf("Enter two integers: ");
        scanf("%d%d", &x, &y);
    }
    return 0;
} 


// Function to calculate hamming distance
//requires: two positive integers or negative value to stop
//effect: returns the number of different bits between these two integers
int hamming_distance(int x, int y)
{
    int a = x ^ y; //Adding two bits and eliminating the carry, returns zero when two bits are the same and 1 when different
    int diffBits = 0;

    while (a > 0) {
        diffBits += a & 1;//adding the least significant bit of a 
        a >>= 1; // shifting "a" one bit to the right 
    }

    return diffBits;
}


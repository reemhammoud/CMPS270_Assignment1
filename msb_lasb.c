#include <stdio.h>
#include <math.h>
unsigned int msb(unsigned int x);
unsigned int lsb(unsigned int x);
unsigned int x;

int main()
{
	printf("please enter a positive int to find distance between first and last bit: ");
	scanf("%d", &x);
	printf("%d", msb(x) - lsb(x));
	

	// Test Cases
	// 320 = (0101000000)
	//         ↑
	//msb_position=8,  lsb position=6,  msb-lsb=2
	msb(320);
	lsb(320);//=6

	// 13 = (1101) 
	//       ↑
	msb(13);

	// (1000) = (01111101000)
	//            ↑
	msb(1000);

	// (17) = (10001)  
	//         ↑
	msb(17);

	// (6) = (00110) 
	//          ↑
	msb(6);

	msb(9);
	lsb(9);

	//if powers of 2 msb-lsb=0
	msb(4);//2
	lsb(4);//2

	msb(8);//3
	lsb(8);//3
}


//requires: an unsigned integer
//effect: finds the most segificant bit set to 1
unsigned int msb(unsigned int x)
{
	if (x <= 0)
	{
		return;
	}
	int r = x;
	// Active all bits after leftmost bit
	r = r | (r >> 1);
	r = r | (r >> 2);
	r = r | (r >> 4);
	r = r | (r >> 8);
	r = r | (r >> 16);
	// Get the value of leftmost bit
	r = r ^ (r >> 1);
	// r contain one set bit.
	int msb_pos = (int)(log(r & -r) / log(2) );
	return msb_pos;
}

//requires: unsigned int
//effect: returns least significant bit set to 1
unsigned int lsb(int x) {
	int lsb_pos= log2(x & -x) ; 
	return lsb_pos;
	
}


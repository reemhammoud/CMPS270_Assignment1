#include <stdio.h>
#define SIZE    10


int main() {
	int values[SIZE] = { 1,1,1,1,1,2,2,2,3,3 };
	printArray(values);
    arrayHistogram(values);
    swap(values, 2, 7);
    printArray(values);// to test swap

    //bubbleSort(values, SIZE);
    float Median = median(values,SIZE);
    printf("median : %.2f\n", Median);

    int Mode = mode(values,SIZE);
    printf("mode : %d\n", Mode);

    int sorted = isSorted(values, SIZE);
    if (sorted) {
        printf("sorted\n");
        printArray(values);
    }
    else
        printf("not sorted\n");
	return 0;
}

//requres: array
//effect: prints array in specific formate
int printArray(int values[10]) {
	printf("%s   %s\n", "index",     "value");
	for (int i = 0; i < SIZE; ++i) {
		printf("    %d       %d\n",i, values[i]);
	}
}

//requires: frequencies of each element
//effects: prints stars according to the nujmber of frequency
int arrayHistogram(int array[]) {
    int frequencies[SIZE];
    int visited = -1;

    for (int i = 0; i < SIZE; i++) {
        int count = 1;
        for (int j = i + 1; j < SIZE; j++) {
            if (array[i] == array[j]) {
                count++;
                //To avoid counting same element again    
                frequencies[j] = visited;
            }
        }
        if (frequencies[i] != visited)
            frequencies[i] = count;
    }

    //Displays the frequency of each element present in array    
    printf("----------------------------------\n");
    printf(" Value | Frequency | Histogram\n");
    printf("----------------------------------\n");
    for (int i = 0; i < SIZE; i++) {
        if (frequencies[i] != visited) {
            printf("    %d", array[i]);
            printf("    |  ");
            printf("  %d", frequencies[i]);
            printf("%s","    | ");
            
            printf("\n");
            
        }
    }
   
}

void stars(int x) {
    for (int i = 0; i < x; i++) {
        printf("*");
    }
}

//requires: two indices to swap them
//effect: swap the values found in each index
int swap(int values[], int i, int j) {
    int temp = values[i];
    values[i] = values[j];
    values[j] = temp;
}
//requires: length of array
//effect: sort the array in ascending order using bubble sort method
void bubbleSort(int values[], int arraylength) {
    for (int i = 0; i < arraylength - 1; i++) {
        for (int j = 0; j < arraylength - i - 1; j++) {
            if (values[j] > values[j + 1])
                swap(values, j, j + 1);
        }
    }
}


// requires: an array and its size
//effect: returns the median of the array 
int median(int values[], int arraylength) {
    bubbleSort(values, arraylength);
    int median;
    if (arraylength % 2 == 0) {
        median = (values[arraylength / 2 - 1] + values[arraylength / 2]) / 2.0;
    }
    else {
        median = values[arraylength / 2];
    }
    return median;

}

// requires: an array and its size
//effect: returns the mode (molst frequent element) of the array 
int mode(int values[], int arraylength) {
    int mode = 0;
    int maxFreq = 0;
    for (int i = 0; i < arraylength; i++) {
        int counter = 0;
        for (int j = 0; j < arraylength; j++) {
            if (values[i] = values[j]) {
                counter += 1;
            }
        }
        if (counter > maxFreq) {
            maxFreq = counter;
            mode = values[i];
        }
    }
    return mode;
}

//requires: the array and its size
//effect: return if the array is sorted or not
int isSorted(int values[], int arraysize) {
    for (int i = 0; i < arraysize; i++) {
        for (int j = arraysize - 1; j > 0; j--) {
            if (values[j] < values[j - 1]) {
                return 0;
            }
        }
    }
    return 1;
}



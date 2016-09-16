//bubble.c
//Bubble Sort
//Black Belt Challenge
//Randomized values
//Selection Sort
//I'm copying down this not doing shortcut keys

#include <stdio.h>
#include <time.h>
#define MAX 9

//function prototypes
void printValues();
void sort();
void swap(int*,int*);
void randomize();

int values[] = {7,3,9,4,6,1,2,8,5};


//length of values stored for usage in later loops
//Shamelessly stolen from StackOverflow
int leng = sizeof(values)/sizeof(values[0]);

int main(){
	randomize();
	printf("Before: \n");
	printValues();
	sort();
	printf("After: \n");
	printValues();
	printf("FIN\n");
	return(0);
}//end of main


//Start of printValues()
void printValues(){
	//Prints values of each number in list
	//Loop through each value printing individually
	//Problems with for loop so doing a while loop
	printf("[");
	int funkybunch = 0;
	while(funkybunch < leng){
		printf("%d",values[funkybunch]);
		//Seperate each of the numbers by commas
		if(funkybunch < leng - 1){
			printf(",");
		}
		funkybunch++;
	}
	printf("]\n");
}

void sort(){
	//creating count variables and setting them to 0
	int a = 0;
	int b = 0;
	//temp is minimum val- set to max + 1 value of array so we do
	//not run into any errors in computing
	//temploc is location of min value in array
	int temp = 51;
	int temploc = 0;
	//Create loop
	while(a < leng){
        //run through each value finding the minimum each time
        while(b < leng){
            //will look through all of the values to find min from a to leng
            if(values[b] < temp){
                temp = values[b];
                temploc = b;
            }
            b++;
        }
        //create pointers for passing
        int* pa = &values[a];
        int* pb = &values[temploc];
        //swap positions of the min and value[a]
        swap(pa,pb);
        a++;
        b = a;
        //reset the temps for appropriate run next time
        temploc = b;
        temp = 51;
    }
}

//swaps the values like the last 10 times you've seen this comment
//tag code
void swap(int* a,int* b){
	//printf("a: %d\n",*a);
	//printf("b: %d\n",*b);
	//Storing the values of the objects in temp variables
	int temp1 = *a;
	int temp2 = *b;
	//switch the two values
	*a = temp2;
	*b = temp1;
	printValues();
}

//randomizes values
void randomize(){
	//creating count variable
	int lol = 0;
	//loop through length of values and change them to random
	//numbers between 0 and 50
	while(lol < leng){
		//gets rand int between 0 and 50
		//Shamelessly stolen from StackOverflow
		values[lol] = rand() % 51;
		lol++;
	}
}

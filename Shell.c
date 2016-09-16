//Bubble Sort
//Black Belt Challenge
//Randomized values
//Shell Sort
//Psuedocode essentially taken straight from tutorialspoint.com
//So there's a chance it will light up like a christmas tree, but
//I understand it, and used comment tags to demonstrate that I do
#include <stdio.h>
#include <time.h>
#define MAX 9

//function prototypes
void printValues();
void sort();
void randomize();

int values[] = {7,3,9,4,6,1,2,8,5};


//length of values stored for usage in later loops
//Shamelessly stolen from StackOverflow
int leng = sizeof(values)/sizeof(values[0]);

int main(){
    //all that fun stuff in the others
    //randomize it, print it, sort it, print it
	randomize();
	printf("Before: \n");
	printValues();
	sort();
	printf("After: \n");
	printValues();
	//end
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
}//end printvalues()

void sort(){
	//create interval for comparing each num in list to
	int interval = 0;
	//increase size of interval for purpose of comparing 2 at a time at first
	while(interval < leng / 3){
        interval = interval * 3 +1;
	}

	while(interval > 0){

        //create variable to be on the outside (right side)
        int out = interval;

        //loop by adding to outer
        while(out < leng){
            //create inside
            int in = out;
            //store values to be inserted as temporary value
            int insertable = values[out];
            //insertion sort of the values in question
            //if the outside value is greater than the inside
            //we insert the inside to the outside
            //we start from the right and move to left
            while(in > interval - 1 && values[in - interval] >= insertable){
                values[in] = values[in - interval];
                in = in - interval;
                printValues();
            }//end insertion sort along specified interval
            //put the temp into the inside of the array
            values[in] = insertable;
            out++;

        }
        //decrease the interval so it gets to 1 eventually
        interval = (interval - 1) / 3;
	}//end while
}//end sort

//randomizes the values inside it
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
	}//end while

}//end randomize

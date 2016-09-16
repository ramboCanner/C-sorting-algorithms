//bubble.c
//Bubble Sort
//Black Belt Challenge
//Randomized values
//Insertion Sort
//I'm copying down this not doing shortcut keys

#include <stdio.h>
#include <time.h>
#define MAX 9

//function prototypes
void printValues();
void sort();
void insert(int*,int*);
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
	//Create loop
	while(a < leng - 1){
        //create "bubble" of values length a + 1 and insert compare the values
        int tempa = a + 1;
        while(values[tempa] <= values[b] && b >=0){
            int* pos1 = &values[tempa];
            int* pos2 = &values[b];
            insert(pos1,pos2);
            b--;
            tempa--;
        }
        a++;
        b = a;
    }
}

void insert(int* a,int* b){
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

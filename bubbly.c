//bubble.c
//Bubble Sort
//I'm copying down this not doing shortcut keys

#include <stdio.h>
#include <time.h>
#define MAX 9

//function prototypes
void printValues();
void sort();
void swap(int*,int*);

int values[] = {7,3,9,4,6,1,2,8,5};


//length of values stored for usage in later loops
//Shamelessly stolen from StackOverflow
int leng = sizeof(values)/sizeof(values[0]);

int main(){
    //print unsorted array
	printf("Before: \n");
	printValues();
	//sort the array
	sort();
	//print sorted array
	printf("After: \n");
	printValues();
	//END OF MAIN as designated by latin 'FIN'
	printf("FIN\n");
	return(0);
}//end of main


//prints array
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

//sorts function
void sort(){
	//creating count variables and setting them to 0
	int a = 0;
	int b = 0;
	int* p1;
	int* p2;
	p1 = &values[0];
	p2 = p1;
	//Create loop 1
	while(a < leng - 1){
        //create nested loop to run through it all
		while(p2 < values + leng - 1){
			//obtain pointers of the values
			//if the the earlier value is greater than the one to
			//the right, then I will switch them
			if(*p2 > *(p2 + 1)){
                //swap the two disagreeing values
				swap(p2,(p2 + 1));
			}

			//add to the inner loop's count
			p2 = p2 + 1;
			//printf("%d: %d\n",p2, *p2);
		}
	//reset the nested loop's count
	p2 = values;
	//adding one to count of loop's count
	a++;
	}
}//end sort

//swaps values at pointers
void swap(int* a,int* b){
    //printf("Swapping %d with %d\n",*a,*b);
	//printf("a: %d\n",a);
	//printf("b: %d\n",b);
	//Storing the values of the objects in temp variables
	int temp1 = *a;
	int temp2 = *b;
	//switch the two values
	*a = temp2;
	*b = temp1;
	printValues();
}//end swap

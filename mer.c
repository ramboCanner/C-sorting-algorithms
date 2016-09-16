//Merge Sort
//I have tried recursion 3 different friggin times
//and am not getting it to work. Let's thus do it this
//way, a simple but easy way that makes sense
//I'm copying down this not doing shortcut keys

#include <stdio.h>
#include <time.h>
#define MAX 9

//function prototypes
void printValues();
void sort();
void randomize();

int val[] = {7,3,9,11,4,6,1,2,5};

//length of values stored for usage in later loops
//Shamelessly stolen from StackOverflow
int lengt = sizeof(val)/sizeof(val[0]);

int ttyl = sizeof(val)/sizeof(val[0]);

int main(){
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
	while(funkybunch < ttyl){
		printf("%d",val[funkybunch]);
		//Seperate each of the numbers by commas
		if(funkybunch < ttyl - 1){
			printf(",");
		}
		funkybunch++;
	}
	printf("]\n");
}

//Start of printValues()
void printVal(int* values){
	//Prints values of each number in list
	//Loop through each value printing individually
	//Problems with for loop so doing a while loop
	printf("[");
	int funkybunch = 0;
	while(funkybunch < 16){
		printf("%d",values[funkybunch]);
		//Seperate each of the numbers by commas
		if(funkybunch < 15){
			printf(",");
		}
		funkybunch++;
	}
	printf("]\n");
}

void sort(){
    //make the algorithm into a perfect base 2
    int ln = 0;
    float junky = lengt;
    //determine if it is indeed base 2
    while(junky > 1.0){
        junky = junky / 2.0;
        ln++;
    }
    int p;
    int dude = 1;
    //determine the closest value to base 2 the length is
    for(p = 0; p < ln; p++){
        dude = dude * 2;
    }
    int leng = dude;
    //create a new temp array with the length determined above
    int values[leng];

    //fill excess slots with number -47 as filler so can be easily removed
    //after all is sorted properly
    for(p = 0; p < leng; p++){
        if(p > lengt){
            values[p] = -47;
        }
        else{
            values[p] = val[p];
        }
    }


    //go by one by one, then increase * 2 each iteration
	int a = 1;
	//the times needed to increment each iteration
	int itots = leng / (a * 2);
	//iteration we are currently on
	int iter = 0;
	while(a < leng){
        printVal(values);
	    //temp arrays to be merged
	    int L[a];
        int R[a];
        int adj = 0;
        //loop until we get to the final increment
        while(iter < itots){
            //printf("a: %d\titer: %d\titots: %d\n",a,iter,itots);
            //temp equals parts of the actual
            int i;
            int j;

            //fill the temporary with actual array values
            for(i = 0; i < a; i++){
                //printf("Lvalues[%d]: %d\n",i + iter * a * 2,values[i + iter * a * 2 + a]);
                L[i] = values[i + iter * a * 2];
            }
            for(j = 0; j < a + adj; j++){
                //printf("Rvalues[%d]: %d\n",j + iter * a * 2 + a,values[j + iter * a * 2 + a]);
                R[j] = values[j + iter * a * 2 + a];
            }

            i = 0;
            j = 0;
            //k is the values[] position, therefore it makes sense
            //with the value below; if you dont understand, do the
            //math and you will
            int k = iter * a * 2;

            //go through each of the values
            while(i < a && j < a){
                printVal(values);
                //printf("L[%d]: %d\tR[%d]: %d\n",i,L[i],j,R[j]);
                //if left is less than right, the values[k]
                //should be the left
                //and vice versa
                if(L[i] < R[j]){
                    values[k] = L[i];
                    i++;
                }
                else{
                    values[k] = R[j];
                    j++;
                }
                k++;
            }
            //printValues();
            //if we have left over values because one side was substantially
            //smaller than the other, put those values on the end
            //of our array
            while(i < a){
                values[k] = L[i];
                i++;
                k++;
                //printValues();
            }
            while(j < a){
                values[k] = R[j];
                j++;
                k++;
                //printValues();
            }

            //iteration increases
            iter++;
        }
        //we now increase the size of a and adjust total iterations available
        a = a * 2;
        itots = leng / (a * 2);
        iter = 0;
	}

	//put the sorted values back into the original array
	//by not including the -47 filler
	int u;
	int gg = 0;
	for(u = 0; u < leng; u++){
        if(values[u] != -47){
            val[gg] = values[u];
            gg++;
        }
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


//A3 Q1
//Nelson Elliott

int c = 0;

//Global vars
float ave;
int max;
int min;

//Get average of numbers
void *getAve(void *arg){

  //Use the int array passed into the thread
  int *intArray = (int *) arg;
  int sum = 0;

  //Calculate the sum of the values within the int array
  for(int i = 0; i < c; i++){
    sum = sum + intArray[i];
  }

  //Calculate average with the sum / count of ints
  ave = (float)sum / c;

  //Exit the thread when done
  pthread_exit(0);
}

//Get max of numbers
void *getMax(void *arg){

  //Use the int array passed into the thread
  int *intArray = (int *) arg;

  max = 0;

  //Iterate through the int array to find the max
  for(int i = 0; i < c; i++){
    if(intArray[i] > max){
      max = intArray[i]; //New max found
    }
  }

  //Exit the thread when done
  pthread_exit(0);
}

//Get min of numbers
void *getMin(void *arg){

  //Use the int array passed into the thread
  int *intArray = (int *) arg;

  min = intArray[0];

  //Iterate through the int array to find the min
  for(int i = 0; i < c; i++){
    if(intArray[i] < min){
      min = intArray[i]; //New min found
    }
  }

  //Exit the thread when done
  pthread_exit(0);
}


//Main
int main(int* argc, char *argv[]){

  //Check number of args
  if (argc < 1) {
    printf("Usage: stats int int int...");
  } else {

    //Get an int array from the args
    int *numbers = (int*)malloc((argc - 1) * sizeof(int));

    for(int i = 1; i < argc; i++){
      numbers[i - 1] = strtol(argv[i], NULL, 0);
      c++;
    }

    //Create threads
    pthread_t Thread_1;
    pthread_t Thread_2;
    pthread_t Thread_3;

    //Init threads and pass int array and functions
    pthread_create(&Thread_1, NULL, getAve, (void*)numbers);
    pthread_create(&Thread_2, NULL, getMax, (void*)numbers);
    pthread_create(&Thread_3, NULL, getMin, (void*)numbers);

    //Join each thread to wait until they finish
    pthread_join(Thread_1, NULL);
    pthread_join(Thread_2, NULL);
    pthread_join(Thread_3, NULL);

    //Give output
    printf("The average value is: %.2f\n",ave);
    printf("The maximum value is: %d\n",max);
    printf("The minimum value is: %d\n",min);

    //Deallocation memory storing the int array
    free(numbers);
  }

}

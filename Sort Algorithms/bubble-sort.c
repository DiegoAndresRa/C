#include<stdio.h>
#include<stdlib.h>

#define max_input

void bubbleSort(int,int*);
void swap(int*,int*);
void printArray(int,int*);

int main(int argc, char** argv){
    // intput
    int size = atoi(argv[1]);
    int* array = (int*)calloc(size,sizeof(int));
    for(int i=2;i<argc;i++){array[i-2]=atoi(argv[i]);}

    // Bubble sort
    bubbleSort(size,array);
    printArray(size,array);

    free(array);
}

void printArray(int array_count,int* array){
    if(array_count == 0)
        return;
    printf("%d ",*array);
    printArray(array_count-1,array+1);
}

void bubbleSort(int array_count,int* array){
    int limit = array_count-1;
    // To all bubble
    for(int iterations=0;iterations<array_count;iterations++){
        // One bubble (bigger than, lower than)
        for(int index=0;index<limit;index++){
            if(array[index]>array[index+1])
                swap(&array[index],&array[index+1]);
        }
        limit--;
    }
}

void swap(int* item1, int* item2){
    int tmp_item = *item2;
    *item2 = *item1;
    *item1 = tmp_item;
}


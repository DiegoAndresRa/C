#include<stdio.h>
#include<stdlib.h>

void swap(int*, int*);
void printArray(int,int*);
void selectionSort(int,int*);

int main(int argc, char** argv){
    // input
    int size = atoi(argv[1]);
    int* array = (int*)calloc(size,sizeof(int));

    for(int i=0;i<size;i++){array[i]=atoi(argv[i+2]);}

    // sort
    selectionSort(size,array);
    printArray(size,array);
}

void printArray(int array_count,int* array){
    if(array_count == 0)
        return;
    printf("%d ",*array);
    printArray(array_count-1,array+1);
}

void selectionSort(int array_count, int* array){
    
    for(int iteration=0;iteration<array_count;iteration++){
        int min = iteration;
        for(int forward=iteration;forward<array_count;forward++)
            if(array[min]>=array[forward]){min = forward;}
        swap(&array[min],&array[iteration]);
    }
}

void swap(int* item1, int* item2){
    int tmp_item = *item2;
    *item2 = *item1;
    *item1 = tmp_item;
}
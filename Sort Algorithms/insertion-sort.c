#include<stdio.h>
#include<stdlib.h>
void printArray(int,int*);
void swap(int*,int*);
void insertionSort(int,int*);

int main(int argc,char** argv){
    // input
    int size = atoi(argv[1]);
    int* array = (int*)calloc(size,sizeof(int));
    for(int i=0;i<size;i++){array[i]=atoi(argv[i+2]);}

    // sort
    insertionSort(size,array);
    printArray(size,array);
}

void insertionSort(int array_count,int* array){
    // General Sort
    for(int items=0;items<array_count-1;items++){
        if(array[items+1] < array[items]){
            swap(&array[items],&array[items+1]);
            // Inside sort
            for(int within_items=items;within_items>=1;within_items--)
                if(array[within_items] < array[within_items-1]){swap(&array[within_items],&array[within_items-1]);}
        }
    }
}

void swap(int* item1,int* item2){
    int temp = *item1;
    *item1 = *item2;
    *item2 = temp;
}

void printArray(int array_count,int* array){
    if(array_count == 0)
        return;
    printf("%d ",*array);
    printArray(array_count-1,array+1);
}
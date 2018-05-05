#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int i;

void print_array(int size, int*);
void swap(int*, int*);
void heapify(int size, int*, int index);
void heap_sort(int size, int*);

int main(int argc, char** argv)
{
    int *T, size;

    srand(time(NULL));

    printf("Size: ");
    scanf("%d", &size);

    T = (int*)malloc(size*sizeof(int));

    for(i = 0; i < size; ++i)
        *(T + i) = rand() % 100;
    
    printf("Before sorting: ");
    print_array(size, T); 
    
    heap_sort(size, T);

    printf("After sorting: "); 
    print_array(size, T);

    return 0;
}

void print_array(int size, int *my_array)
{
    for(i = 0; i < size; ++i)
        printf("%d ", *(my_array + i));
    puts("");
}

void swap(int *x, int *v)
{
    int temp = *x;
    *x = *v;
    *v = temp;
}

void heapify(int size, int *my_array, int index)
{
    int largest_node = index;
    int left_node = 2*index;
    int right_node = 2*index + 1;

    if(left_node < size && *(my_array + left_node) > *(my_array + largest_node))
        largest_node = left_node;
    
    if(right_node < size && *(my_array + right_node) > *(my_array + largest_node))
        largest_node = right_node;
    
    if(largest_node != index)
    {
        swap(my_array + index, my_array + largest_node);
        heapify(size, my_array, largest_node);
    }
}

void heap_sort(int size, int *my_array)
{
    for(i = size/2; i >= 0; --i)
        heapify(size, my_array, i);

    for(i = size -1; i >= 0; --i)
    {
        swap(my_array, my_array + i);
        heapify(i, my_array, 0);
    }
}


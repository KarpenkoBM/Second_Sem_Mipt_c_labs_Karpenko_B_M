#include <iostream>
#include <stdlib.h>
#include <cstring>

void swap(void* i, void* j, size_t type_size) {
  void* tmp = malloc(type_size);
  std::memcpy(tmp, j, type_size);
  std::memcpy(j, i, type_size);
  std::memcpy(i, tmp, type_size);
  free(tmp);
}
void* move(void* arr, int move_to)
{
    char* ptr_current = reinterpret_cast <char*>(arr);
        ptr_current += move_to;
        return arr = reinterpret_cast <void*>(ptr_current);
}
int compareInt(void *lhs, void *rhs)
{
    if(*reinterpret_cast <int*>(lhs) > *reinterpret_cast <int*>(rhs))
    {
        return 1;
    }
    return 0;
}
int part(void* A, int lo, int hi, void* (*next)(void*, int), int type_size,int (*compare)(void *, void *)) {
    void* pivot = next(A, (hi + lo) / 2);
    int i = lo;
    int j = hi;
    while (true) {
        while (compare(next(A, i), pivot)== 0) {
            i++;
        }
        while (compare(next(A, j), pivot)== 1) {
            j--;
        }
        if (i >= j) {
            return j;
        }
        swap(next(A, i), next(A, j), type_size);
        i++;
        j--;
    }
}

void quicksort(void* A, int lo, int hi, void* (*next)(void*, int), int type_size)
{
    if (lo < hi) {
        int p = part(A, lo, hi, next, type_size,compareInt);
        quicksort(A, lo, p, next, type_size);
        quicksort(A, p + 1, hi, next, type_size);
    }
}


int main()
{
    int arr_size = 0;
    std::cin>> arr_size;
    int* arr = new int[arr_size];
    for (int i = 0; i < arr_size; i++)
    {
        std::cin>>arr[i];
    }
    quicksort(arr,0, (arr_size-1), sizeof(int) );
    for(int i = 0; i < arr_size; i++)
    {
       std:: cout <<arr[i]<<std::endl;
    }

return 0;
}

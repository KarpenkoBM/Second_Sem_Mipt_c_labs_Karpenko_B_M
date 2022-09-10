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
void* move(void* arr, int move_to, int type_size)
{
    char* ptr_current = reinterpret_cast <char*>(arr);
        ptr_current += move_to * type_size;
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
int part(void* arr, int left, int right, int type_size,int (*compare)(void *, void *)) {
    void* pivot = move(arr, (left + right) / 2, type_size);
    int i = left;
    int j =  right;
    while (true) {
        while (compare(pivot, move(arr, i, type_size))== 1) {
            i++;
        }
        while (compare(move(arr, j, type_size), pivot)== 1) {
            j--;
        }
        if (i >= j) {
            return j;
        }
        swap(move(arr, i, type_size), move(arr, j, type_size), type_size);
        i++;
        j--;
    }
}

void quicksort(void* arr, int left, int right, int type_size, int (*compare)(void *, void *))
{
    if (left < right) {
        int p = part(arr, left, right,type_size,compare);
        quicksort(arr, left, p, type_size, compare );
        quicksort(arr, p + 1, right, type_size, compare);
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
    quicksort(arr,0, (arr_size-1), sizeof(int), compareInt);
    for(int i = 0; i < arr_size; i++)
    {
       std:: cout <<arr[i]<<" ";
    }

return 0;
}

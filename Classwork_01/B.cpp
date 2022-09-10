#include <iostream>
#include <stdlib.h>
#include <cstring>


int compareInt(void *l, void *r)
{
    if(*reinterpret_cast <int*>(l) > *reinterpret_cast <int*>(r))
    {
        return 1;
    }
    return 0;
}

int minimal(void* arr, int arr_size, int type_size, int (*compare)(void *, void *))
{
     void* minimal_value = arr;
     int minimal_index = 0;
    for ( int i = 0; i < arr_size; i++ )
    {
        if (compare (minimal_value, arr) ==  1)
            {
                minimal_index = i;
                minimal_value = arr;
            }
        char* ptr_current = reinterpret_cast <char*>(arr);
        ptr_current += type_size;
        arr = reinterpret_cast <void*>(ptr_current) ;;
    }
    return minimal_index;
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
    std::cout <<  minimal(arr, arr_size, sizeof(int), compareInt) << std::endl;
return 0;
}

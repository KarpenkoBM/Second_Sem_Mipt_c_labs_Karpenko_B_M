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

int main()
{
    int i, j;
    std::cin >> i>>j;
    swap(&i, &j, 32);
    std::cout << i<<" "<<j;
    return(0);
}

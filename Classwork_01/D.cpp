#include<iostream>
#include<limits>

using namespace std;

int main()
{
    cout << "char" << ' ' <<  sizeof(char) * 8<< ' ' << int(numeric_limits<char>::min()) << ' ' << int(numeric_limits<char>::max()) << '\n';
    cout << "short int" << ' '<<  sizeof(short int) * 8 <<' ' << numeric_limits<short int>::min() << ' ' << numeric_limits<short int>::max() << '\n';
    cout << "int" << ' ' << sizeof(int) * 8<<' '<<  numeric_limits<int>::min() << ' ' << numeric_limits<int>::max() << '\n';
    cout << "long int" << ' ' << sizeof(long int) * 8 <<' '<< numeric_limits<long int>::min() << ' ' << numeric_limits<long int>::max() << '\n';
    cout << "float" << ' ' <<  sizeof(float) * 8 <<' '<< numeric_limits<float>::min() << ' ' << numeric_limits<float>::max() << '\n';
    cout << "double" << ' ' <<  sizeof(double) * 8 <<' '<< numeric_limits<double>::min() << ' ' << numeric_limits<double>::max() << '\n';
    return 0;
}

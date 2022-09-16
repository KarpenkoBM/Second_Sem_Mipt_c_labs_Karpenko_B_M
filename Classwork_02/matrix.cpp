#include <iostream>
#include <math.h>

class Matrix {
    public:
        Matrix(int arr[], std::size_t n_elements) // ���������� ������� �� �������
        {
            for(int m = 0; m < n_elements; m++)
            {
                for(int k =0; k < n_elements; k++)
                {
                    for(int i = 0; i < n_elements* n_elements; i++)
                    {
                        *mat[k,m] = arr[i];
                    }
                }
            }

        }

        Matrix(int element=1, std::size_t n_elements=1)  // ���������� ������� ��������� element; n_elements -- ���������� ���������
        {
            for(int j = 0; j < n_elements; j++)
            {
                for(int i = 0; i < n_elements; i++)
                {
                    *mat[i,j] = element;
                }
            }
        }

        //Matrix() // ���������� ����������� �� ���������, ��� ������� ������� 1 � ��������� ������ 1
        //{
        //}

        Matrix(const Matrix& other) // ���������� ���������� �����������
        {
            for(int j = 0; j < other.size; j++)
            {
                for(int i = 0; i < other.size; i++)
                {
                    mat[i,j] = other.mat[i,j];
                }
            }

        }

        void printMatrix()// ������� �������: ������ �������� � ������ ��������� ��������, ������ �������� \n
        {
            for(int j = 0; j < size; j++)
            {
                for(int i = 0; i < size; i++)
                {
                    if (i == size - 1)
                    {
                        std::cout<<mat[i,j]<<std::endl;
                    }
                    std::cout<<*mat[i,j]<<' ';

                }
            }
        }
        void operator=(Matrix &other)
        {

            for (int j =0; j < size; j++)
            {
                for (int i = 0; i< size; i++)
                {
                    *mat[i, j]= *other.mat[i,j];
                }
            }
        }

        int calcDeterminant() // ��������� �����������
        {
            int Determinant = 0;
            Matrix copy_matrix(1, size);
            for (int j =0; j < size; j++)
            {
                for (int i = 0; i< size; i++)
                {
                    *copy_matrix.mat[i, j]= *mat[i,j];
                }
            }
            int* det = new int[size];
            for(int j = 0; j < size - 3; j++)
            {
                det[j] = 1;
            }
            while (copy_matrix.size > 2)
            {
                for(int j = 0; j < copy_matrix.size ; j++)
                {
                    det[j]= *copy_matrix.mat[j,1];
                    copy_matrix.simplify(j);
                }

            }
            for (int i = 0; i < size; i++)
            {
                det[i] *= copy_matrix.calcDeterminant_2();
                Determinant += (pow((-1),i))*det[i];
            }
            delete[] det;
            return Determinant;

        }

        void calcSquare() // ��������� ������� �������, ��������� �������� � ��� �� ���������� ������
        {
             for(int j = 0; j < size; j++)
            {
                for(int i = 0; i < size; i++)
                {
                    *mat[i,j] *= *mat[i,j];
                }
            }

        }

        void matTranspose()// ������������ ���������������� �������, ��������� ����������� ��� ��
        {
             for(int j = 0; j < size; j++)
            {
                for(int i = 0; i < size; i++)
                {
                    *mat[i,j] = *mat[j, i];
                }
            }

        }

        ~Matrix() // ���������� ����������
        {
            delete[] mat;
        }

    private:
        int** mat;  // ������ ��� �������� �������� �������
        int size;  // ������ ������� �������
        Matrix simplify(int str)
        {
            Matrix new_matrix(1, size);
             for(int j = 0; j < size; j++ )
            {
                for(int i = 0; i < size; i++ )
                {
                     for (int m = 1; m < size; m++)
                    {
                        for(int k = 0; k < size and k != str; k++ )
                        {
                                *new_matrix.mat[i,j]= *mat[k,m];

                        }
                    }


                }
            }
        return new_matrix;
        }
        int calcDeterminant_2()
        {
            if (size != 2)
            {
                std::cout<<"Error calculating determinant"<<std::endl;
                return 0;
            }
            else return ((*mat[1,1])*(*mat[2,2])-(*mat[1,2])*(*mat[2,1]));
        }
};

int main()
{
    int* arr = new int[100];
   for(int j =0; j < 100; j++)
   {
        arr[j]= j;
   }
   Matrix matr(arr,10);
   std::cout << matr.calcDeterminant()<<std::endl;
   delete[] arr;
   return 0;

}

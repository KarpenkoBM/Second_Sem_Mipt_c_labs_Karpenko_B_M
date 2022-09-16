#include <iostream>


class Fraction {
    public:
        Fraction(int numerator = 0, int denominator = 1)
        {
            if (denominator == 0)
            {
                std::cout<<"incorrect input:"<<
                std::endl<<"denominator was changed from 0 to 1"<<std::endl;
                denominator = 1;
            }
            if (denominator < 0)
            {
                numerator *= -1;
                denominator *= -1;
            }
            this->numerator = numerator;
            this->denominator = denominator;
        }

        //Fraction(int numerator = 0)
       // {
        //    this->numerator = numerator;
        //    denominator = 1;
        //}
       // Fraction() = delete;

        Fraction(const Fraction& other):
            numerator(other.numerator),
            denominator(other.denominator) { } // ����������� ����������� deep

        void printFraction()// ������� ����� � ������� 'numerator / denominator'
        {
            std::cout<<numerator<<" / "<<denominator<<std::endl;
        }

        void fracReverse()
        {
            int tmp = 0;
            tmp = numerator;
            numerator = denominator;
            denominator = tmp;

        }

        void fracSimplify() // ��������� ����� �� �����������
        {
            if (numerator == 0 or denominator == 0 or
                numerator == 1 or denominator == 1 )
            {
                return;
            }
            int bik = 0, smal=0;
            if(abs(numerator)>denominator)
            {
                bik = numerator;
                smal = denominator;
            }
            else
            {
                smal = numerator;
                bik = denominator;
            }
            int r = bik % smal;
            while (r != 0)
            {
                bik = smal;
                smal = r;
                r = bik % smal;
            }
            numerator /= smal;
            denominator /= smal;
        }

        void multByNumber(int value) // �������� ����� �� �����
        {
            numerator*= value;
            fracSimplify();
        }

        void multByFrac(const Fraction& other)// �������� ����� �� ������ �����, ��������� �������� � ���������� (� this)
        {
            numerator*= other.numerator;
            denominator*= other.denominator;
            fracSimplify();
        }

        Fraction multByFracReturn(const Fraction& other) const// �������� ����� � ���������� ��������� � ������
        {
            Fraction mult_result(numerator*other.numerator,
                                 denominator*other.denominator);
            mult_result.fracSimplify();
            return mult_result;
        }

        void sumFrac(const Fraction& other)// �������������� ����� �� ������ �����, ��������� �������� � ���������� (� this)
        {
              numerator = other.numerator*denominator +
                            numerator*other.denominator;
              denominator = denominator*other.denominator;
              fracSimplify();
        }

        Fraction sumFracReturn(const Fraction& other) const
        {
           Fraction sum_result(other.numerator*denominator +
                               numerator*other.denominator,
                               denominator*other.denominator);
           sum_result.fracSimplify();
           return sum_result;
        }

        void diffFrac(const Fraction& other)// ����� �������� ������, ��������� �������� � ���������� (� this)
        {
              numerator = numerator*other.denominator -
                          other.numerator*denominator;
              denominator = denominator*other.denominator;
              fracSimplify();
        }

        Fraction diffFracReturn(const Fraction& other) const// ����� �������� ������, ��������� � ������

        {
            Fraction dif_result(numerator*other.denominator -
                                 other.numerator*denominator,denominator*other.denominator);
            dif_result.fracSimplify();
            return dif_result;
        }

        double calc()// ���������� �������� ����� � ���������� ����
        {
            return double(numerator) / double(denominator);
        }

        int getNumerator()// ���������� �������� ���������
        {
            return numerator;
        }

        int getDenominator() // ���������� ���������� �����������
        {
            return denominator;
        }

    private:
        int numerator;
        int denominator;
};

int main ()
{
    Fraction frac(5,3);
    frac.printFraction();
    frac.multByNumber(5);
    frac.printFraction();
    Fraction frac_2(2,3);
    frac.sumFrac(frac_2);
    frac.printFraction();
    frac.multByFrac(frac_2);
    frac.printFraction();
    frac.diffFrac(frac_2);
    frac.printFraction();
    Fraction frac_3(1,3);
    frac.diffFracReturn(frac_3).printFraction();
    std::cout<<frac.calc()<<std::endl;
    return 0;
}

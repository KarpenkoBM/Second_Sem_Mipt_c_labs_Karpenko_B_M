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
            denominator(other.denominator) { } // Конструктор копирования deep

        void printFraction()// Выводит дробь в формате 'numerator / denominator'
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

        void fracSimplify() // Сокращает дробь по возможности
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

        void multByNumber(int value) // Умножить дробь на число
        {
            numerator*= value;
            fracSimplify();
        }

        void multByFrac(const Fraction& other)// Умножить дробь на другую дробь, результат оставить в вызывающей (в this)
        {
            numerator*= other.numerator;
            denominator*= other.denominator;
            fracSimplify();
        }

        Fraction multByFracReturn(const Fraction& other) const// умножает дроби и возвращает результат в третью
        {
            Fraction mult_result(numerator*other.numerator,
                                 denominator*other.denominator);
            mult_result.fracSimplify();
            return mult_result;
        }

        void sumFrac(const Fraction& other)// Просуммировать дробь на другую дробь, результат оставить в вызывающей (в this)
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

        void diffFrac(const Fraction& other)// Взять разность дробей, результат оставить в вызывающей (в this)
        {
              numerator = numerator*other.denominator -
                          other.numerator*denominator;
              denominator = denominator*other.denominator;
              fracSimplify();
        }

        Fraction diffFracReturn(const Fraction& other) const// Взять разность дробей, результат в третью

        {
            Fraction dif_result(numerator*other.denominator -
                                 other.numerator*denominator,denominator*other.denominator);
            dif_result.fracSimplify();
            return dif_result;
        }

        double calc()// Возвращает значение дроби в десятичном виде
        {
            return double(numerator) / double(denominator);
        }

        int getNumerator()// Возвращает значение числителя
        {
            return numerator;
        }

        int getDenominator() // Возвращает знамечение знаменателя
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

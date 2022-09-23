#include <iostream>
#include <string>


struct Point
{
unsigned long long x, y;
Point ( unsigned long long x , unsigned long long y ): x(x), y(y)
{

}
Point minx(Point const &rha) const
{
return Point(rha.x < x ? rha.x : x, y);
}
Point miny(Point const &rha) const
{
return Point(x, rha.y < y ? rha.y : y);
}
Point maxx(Point const &rha) const
{
return Point(rha.x > x ? rha.x : x, y);
}
Point maxy(Point const &rha) const
{
return Point(x, rha.y > y ? rha.y : y);
}
void print() const
{
std::cout << "(" << x << ", " <<y << ")";
}
};

class Rectangle
{
public:
    Rectangle(const Point &point): point(point) {}
    Rectangle() : Rectangle (Point(0, 0)) {}
    Rectangle operator+(Rectangle const &rha) const
    {
        Rectangle new_rec = Rectangle (point.maxx(rha.point));
        Rectangle final_rec = Rectangle (new_rec.point.maxy(rha.point));

        return final_rec;
    }

    Rectangle operator*(Rectangle const &rha) const
    {
        Rectangle new_rec = Rectangle (point.minx(rha.point));
        Rectangle final_rec = Rectangle (point.miny(rha.point));
        return final_rec;
    }
    Rectangle &operator+=(Rectangle const &rha)
    {
        Rectangle new_rec = Rectangle(point.maxx(rha.point));
        Rectangle final_rec = Rectangle((new_rec.point.maxy(rha.point)));
        point = final_rec.point;
        return *this;
    }
    Rectangle &operator*=(Rectangle const &rha)
    {
        Rectangle new_rec = Rectangle(point.minx(rha.point));
        Rectangle final_rec = Rectangle((new_rec.point.miny(rha.point)));
        point = final_rec.point;
        return *this;
    }
    void print() const
    {
        point.print();
    }

private: Point point;
};
Rectangle make_rec(std::string str, int &i )
{
    int x = 0;
    i++;
    while(str[i] != ',')
    {
        x = 10 * x + (str[i] - '0');
        i++;
        //std::cout << 1 << std::endl;
    }
    i++;
    int y = 0;
    while (str[i] != ')')
    {
        y = 10 * y + (str[i] - '0');
        i++;
        //std::cout << 2 << std::endl;
    }
    Rectangle res (Point(x,y));
    //res.print();
    return res;
}
Rectangle result(std::string str)
{
    int num_of_mult = 0;
    int num_of_brack = 0;
    int k = 0;
    int i = 0;
    for (char el : str)
    {
        if (el == '*')
        {
            num_of_mult++;
        }
        if (el == '(')
        {
            num_of_brack++;
        }
    }
    Rectangle* mass_for_sum = new Rectangle[num_of_brack - num_of_mult];
    while(i < str.length())
    {
        while(str[i]==' ' || str[i] == '+')
        {
            i++;
        }
        //std::cout << 3 << std::endl;
        Rectangle result = Rectangle(Point(0,0));
        if(str[i] == '(')
        {
            result += make_rec(str, i);
            result.print();
            std::cout << 3 << std::endl;
        }
        if (not(++i == str.length()))
        {
            while (str[i] == '*')
            {
                i++;
                Rectangle temp = make_rec(str, i);
                i++;
                result *= temp;
                //std::cout << 4 << std::endl;
            }
        }
        std::cout<<"k ="<<k<<std::endl;
         std::cout<<"str"<<i<<' '<<str[i]<<std::endl;
        mass_for_sum[k] = result;
        mass_for_sum[k].print();
        k++;
        i++;
    }
    Rectangle answer = Rectangle();
    for(int i = 0; i < num_of_brack - num_of_mult; i++)
    {
        mass_for_sum[i].print();
        answer += mass_for_sum[i];
    }
    return answer;
}

int main()
{
    std :: string expression;
    std :: getline(std :: cin, expression);
    Rectangle temp = result(expression);
    temp.print();
    return 0;
}

#include <iostream>
#include <random>
#include <set>
#include<fstream>
using State = int ;
const State MaxState = 1000;


class set_State
{
public:

    std::set<State> state;

    set_State( std::set<State> const &state): state(state) {}
    set_State()
       {
            state.clear();
       }
       presence(const State &st) const
       {
           state.count(st)>0;
       }
       set_State(State N, State min, State max, unsigned seed)
       {
           std:: set<State> steat;
           state.clear();
           std:: default_random_engine reng(seed) ;
           std:: uniform_int_distribution<State> dstr (min, max ) ;
           State n = 0;
           while (n != N)
           {
               if (steat.count(dstr(reng)) == 0)
               {
                   steat.emplace(dstr(reng));
                   n++;
               }

           }
           state = steat;

       }
       set_State operator+(set_State const &other) const
       {
           set_State Sum = *this;
           for (std::set<State>::iterator i = other.state.begin(); i != other.state.end(); i++)
           {
               Sum.state.emplace(*i);
           }
       }
       set_State operator*(set_State const &other) const
       {
           set_State Sum;
           for (std::set<State>::iterator i = state.begin(); i != state.end(); i++)
           {
               for (std::set<State>::iterator j = other.state.begin(); j != other.state.end(); i++)
               {
                   if(*i == *j)
                   {
                       Sum.state.emplace(*i);
                   }
               }
           }
       }
       set_State operator!() const
       {
             set_State Res;

            for (State i = - MaxState; i <= MaxState; i++)
            {
                if (this->state.count(i) == 0){
                    Res.state.emplace(i);
                }
            }

            return Res;
        }
 void write_in_file(std :: ofstream &fout){
            fout.open("Random_State.txt");
            for (std::set<State>::iterator i = state.begin(); i !=  state.end(); ++i){
                fout << *i << '\n';
            };
            fout.close();
        }

};
 class DiscreteState : public set_State
 {
    public:
    DiscreteState(State s0)
    {
            state.clear();
            state.emplace(s0);
    }
        DiscreteState() : DiscreteState(0) {}
 };

 class SegmentState : public set_State
 {
  public:
        SegmentState(State begin_s0, State end_s0) {
            state.clear();
            for(State i = begin_s0; i < end_s0 + 1; i++){
                state.emplace(i);
            }
        }
        SegmentState() : SegmentState(0, 0) {};
};

 class Probability_Test
{
    private :
    State const E_min, E_max;

    public :
    Probability_Test ( State E_min, State E_max ) : E_min(E_min ) , E_max(E_max) { }

    float test (
    const set_State& system ,
    unsigned test_count ,
    unsigned seed ) const
    {
    std:: default_random_engine reng(seed) ;
    std:: uniform_int_distribution<State> dstr (E_min, E_max ) ;

    unsigned good = 0 ;
    for ( unsigned cnt = 0 ; cnt != test_count ; ++cnt )
    {
         if ( system.presence(dstr( reng ) ) )
         {
            ++good;
         }
    }
    //std::cout<<' '<<good<<std::endl;

    return static_cast<float>(good )
            /static_cast <float>( test_count ) ;
    }
  float more_random_test(const set_State &system, const unsigned test_count, const State seed_for_seed)
  {
            std :: default_random_engine reng(seed_for_seed);
            std :: uniform_int_distribution<int> dstr (-100, 100);
            float sum = 0;

            for (int i = 0; i < 10; i++)
            {
                sum += test(system, test_count, dstr(reng))/10;
            }
            //std::cout<<' '<<sum<<std::endl;
            return sum;
    }

};

int main()
{
    set_State thiss(100, -1000, 1000, 228);
    SegmentState nuts(0 ,100) ;
    Probability_Test protest(-1000, 1000);
    std::ofstream fout;
    fout.open("res.txt");
    int test_amount = 1;

    for(int i = 0; i <= 50000; i += 5)
    {

        fout << i << ' ' << protest.more_random_test(thiss, i, 132) << ' '
                                << protest.more_random_test(nuts, i, 132) << std::endl;

    }

    fout.close();

    return 0;
}

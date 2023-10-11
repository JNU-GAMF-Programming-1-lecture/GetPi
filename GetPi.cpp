#include <iostream>
#include <iomanip>
#include <numbers> // std::numbers



using namespace std;
using namespace std::numbers;

// It has to be compiled with x86 configuration!
double get_PI_asm()
{
  double pi;
  __asm
  {
    fldpi
    fstp pi
  }
  return pi;
}

/*
  Explanation of the assembly commands:

  fldpi:   loads the value of pi from the CPU's floating-point constant 
           memory onto the floating-point stack.
  fstp pi: pops the value from the top of the floating-point stack and stores 
           it in the C++ variable pi. 
  */


int main()
{
  cout << fixed << setprecision(17);
  cout << "PIasm=  " << get_PI_asm() << endl;
  // Taditional way of calculation std::atan
  cout << "PIatan= " << atan(1.0) * 4 << endl; 
  cout << "PI20=   " << pi << endl;  // C++ 20! std::numbers::pi
  return 0;
}
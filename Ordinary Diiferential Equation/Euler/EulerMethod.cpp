#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

//Given differential function

double f(float x)
{
return -2*pow(x,3)+12*x*x-20*x+8.5;
}

// Analytical function after integrating the differential equation

double analytical(float x)
{
return -0.5*pow(x,4)+4*pow(x,3)-10*x*x+8.5*x+1;
}

// Function for Euler Method

double Euler(float h)
{
   float x=0,y,y0=1;
   ofstream solution("EULER_output(0.1).txt");          // Creating file to save the output
   cout<<endl<<"For h="<<h<<endl<<endl<<"x      Analytical     Euler"<<endl;
   while(x<=4)
   {
   cout<<x<<"\t"<<analytical(x)<<"\t\t"<<y0<<endl;
   solution<<x<<"\t"<<analytical(x)<<"\t\t"<<y0<<endl;
   y=y0+h*f(x);
   y0=y;
   x+=h;
   }
   cout<<endl;

}

int main()
{
    int i;

 // Calling the Euler Function

    Euler(0.5);
    Euler(0.25);
    Euler(0.1);
    return 0;
}

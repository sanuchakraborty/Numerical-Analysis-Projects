#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

//Given differential function

double f(float x,float y)
{
return -2*pow(x,3)+12*x*x-20*x+8.5;
}

// Analytical function after integrating the differential equation

double analytical(float x)
{
return -0.5*pow(x,4)+4*pow(x,3)-10*x*x+8.5*x+1;
}

// Function for RK4 Method

double RK4(float h)
{
   float x=0,y1,y0=1,k1=0,k2=0,k3=0,k4=0;
   ofstream solution("RK4_output(0.1).txt");
   cout<<endl<<"For h="<<h<<endl<<endl<<"x      Analytical      RK4"<<endl;
   while(x<=4)
   {
   cout<<x<<"\t"<<analytical(x)<<"\t\t"<<y0<<endl;
   solution<<x<<"\t"<<analytical(x)<<"\t\t"<<y0<<endl;
        k1=h*f(x,y0);
        k2=h*f(x+h/2,y0+k1/2);
        k3=h*f(x+h/2,y0+k2/2);
        k4=h*f(x+h,y0+k3);
        y1=y0+(double)(k1+2*k2+2*k3+k4)/6;
   y0=y1;
   x+=h;
   }
   cout<<endl;

}

int main()
{
    int i;

 // Calling the RK4 Function

    RK4(0.5);
    RK4(0.25);
    RK4(0.1);
    return 0;
}

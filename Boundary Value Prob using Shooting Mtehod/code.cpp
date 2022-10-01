
#include <iostream>
#include<fstream>
#include<cmath>

using namespace std;
#define tolerance pow(10,-5)

double q(double x,double u,double v,double y, double z)          
{
    return v;
}

double p(double x,double u,double v,double y, double z)           // defining Psi Diffrential Function
{
    return (-z*u-y*v)/8;
}
double g(double x,double y,double z)
{
    return z;
}
double f(double x,double y,double z)                            // defining given differential function
{
    return (32+2*pow(x,3)-y*z)/8;
}
double analytical(double x)
{
    return x*x+16/x;
}

double RK4(int n,double m,int check,double y_value[])
{
    int i=0,k=0;
    double h=0,k1=0,k2=0,k3=0,k4=0,l1=0,l2=0,l3=0,l4=0,y0=17,y1=0,z0=0,z1=0,beta=0,sai=0;
    double x0=1,x1=3,s0=0,s1=1;
    double m1=0,m2=0,m3=0,m4=0,n1=0,n2=0,n3=0,n4=0,u0=0,v0=1,u1=0,v1=0;
    h=(x1-x0)/n;

    z0=m;
    while(x0<=(x1+h))                            // RK4 calculations for Y and Psi Functions are done within one while loop 
    {
        k1=h*f(x0,y0,z0);
        l1=h*g(x0,y0,z0);
        k2=h*f(x0+h/2,y0+k1/2,z0+l1/2);
        l2=h*g(x0+h/2,y0+k1/2,z0+l1/2);
        k3=h*f(x0+h/2,y0+k2/2,z0+l2/2);
        l3=h*g(x0+h/2,y0+k2/2,z0+l2/2);
        k4=h*f(x0+h,y0+k3,z0+l3);
        l4=h*g(x0+h,y0+k3,z0+l3);

        z1=z0+(k1+2*k2+2*k3+k4)/6;
        y1=y0+(l1+2*l2+2*l3+l4)/6;

        y_value[i]=y0;                          // y_value[] is to store the values of y at each step of x, of the last iteration
        i++;

        m1=h*p(x0,u0,v0,y0,z0);
        n1=h*q(x0,u0,v0,y0,z0);
        m2=h*p(x0+h/2,u0+m1/2,v0+n1/2,y0,z0);
        n2=h*q(x0+h/2,u0+m1/2,v0+n1/2,y0,z0);
        m3=h*p(x0+h/2,u0+m2/2,v0+n2/2,y0,z0);
        n3=h*q(x0+h/2,u0+m2/2,v0+n2/2,y0,z0);
        m4=h*p(x0+h,u0+m3,v0+n3,y0,z0);
        n4=h*q(x0+h,u0+m3,v0+n3,y0,z0);

        v1=v0+(m1+2*m2+2*m3+m4)/6;            // u and v are Psi and Psi' respectively
        u1=u0+(n1+2*n2+2*n3+n4)/6;
        
        if(x0>=x1)
        {
            beta=y0;
            sai=u0;
        }
        z0=z1;
        y0=y1;

        v0=v1;
        u0=u1;

        x0+=h;
    }

    if(check==1)
    return beta;
    else
    return sai;
}

double NR(double m,double error,double y_value[])    // Function which takes m value and error and returns the updated m after one iteration of Newton Raphson
{
    return (m-(error)/RK4(20,m,0,y_value));
}


int main()
{
  double y0=17,y1=14.3333333,x0=1,x1=3,y_value[21];      // Defining the boundary values of x and y
  double m=1,beta=0,error=0;
  int j=1,n=20;
  ofstream op("Output_Ass9.txt");
  op<<"Initial Guess = "<<m<<endl<<endl;
  
  do
  {
  
    beta=RK4(n,m,1,y_value);
    error=(beta-y1);
    op<<"error = "<<error<<"\t"<<"and m = "<<m<<"\t"<<"at Iteration "<<j<<endl;
    m=NR(m,error,y_value);
    j++;
  
  }while(fabs(error)>tolerance);         // Limiting condition for the loop
  
  op<<endl<<"x"<<"\t\t"<<"y"<<"\t\t"<<"y_analytical"<<endl<<endl;
  
  for(int i=0;x0<=3+0.1;i++,x0+=0.1)
  {
      op<<x0<<"\t\t"<<y_value[i]<<"\t\t"<<analytical(x0)<<endl;
  }
  
  op<<endl<<"Beta = "<<beta<<"\t"<<"Iteration = "<<j-1<<"\t"<<"m_final = "<<m<<endl;
  return 0;
}


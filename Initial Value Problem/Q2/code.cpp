#include <iostream>
#include <cmath>
#include<fstream>

using namespace std;

double g(double t,double y,double z)              // z= y'
{
return z;
}
double f(double t,double y,double z)
{ 
return 2*y-4*z+2*pow(t,3)-10;                    
} 

double RK4(int n,float L)
{
int i,j;
double h,k1,k2,k3,k4,l1,l2,l3,l4,t0=0,y0=0,z0=1,t1=0,y1=0,z1=0;           // L and t0 are the range of t
ofstream output("ASS8(RK4)n_10.txt");
h=(L-t0)/n;
cout<<" t"<<"\t\t"<<"y"<<"\t\t"<<"y'"<<endl;
output <<" t"<<"\t\t"<<"y"<<"\t\t"<<"y'"<<endl;
while(t0<=(1))
{
k1=h*f(t0,y0,z0);
l1=h*g(t0,y0,z0);
k2=h*f(t0+h/2,y0+k1/2,z0+l1/2);
l2=h*g(t0+h/2,y0+k1/2,z0+l1/2);
k3=h*f(t0+h/2,y0+k2/2,z0+l2/2);
l3=h*g(t0+h/2,y0+k2/2,z0+l2/2);
k4=h*f(t0+h,y0+k3,z0+l3);
l4=h*g(t0+h,y0+k3,z0+l3);
z1=z0+(k1+2*k2+2*k3+k4)/6;
y1=y0+(l1+2*l2+2*l3+l4)/6;
cout<<t0<<"\t   "<<y0<<"\t   "<<z0<<endl;
output <<t0<<"\t   "<<y0<<"\t   "<<z0<<endl;
z0=z1;
y0=y1;
t0+=h;
}
}

int main()
{
int n=10;
float L,t0=0,tn=1;
/*cout<<"Enter time range"<<endl<<"t= ";
cin>>t0;
cout<<"to  ";
cin>>tn;
cout<<endl<<"Enter number of div =";
cin>>n;*/
L=tn-t0;
RK4(n,L);                                  // calling the RK4 function

}

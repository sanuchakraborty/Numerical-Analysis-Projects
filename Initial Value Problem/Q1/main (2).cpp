#include<iostream>
#include<fstream>
#include<cmath> 

using namespace std;

double f(double x, double y)
{
    return ( 2-2*x+4*x*x-4*pow(x,3)-4*pow(x,4) );         //defining the differential function
}

// double g(double x)
// {
//     return ( 1+2*x-x*x+pow(x,3)*(4/3)-pow(x,4)-(4/5)*pow(x,5) );    //Analytical Function
// }


void AdamsBasforth(double h,double x,double y[])
{
    double k=0;
    k=(55*f(x,y[3])-59*f((x-h),y[2])+37.0*f((x-2*h),y[1])-9.0*f((x-3*h),y[0]));

    for(int i=0;i<3;i++)
	    y[i]=y[i+1];

    y[3]+=(h*k/24);

}

double rk4(double x,double y,double h)
{
	double k1=0,k2=0,k3=0,k4=0;
	k1=h*f(x,y);
	k2=h*f((x+h/2),(y+k1/2));
	k3=h*f((x+h/2),(y+k2/2));
	k4=h*f((x+h),(y+k3));
	y+=(k1+2*k2+2*k3+k4)/6;
	return y;
}

int main()
{
    int i=0,n=0;
    double a=0,b=1,h=0.2;
    n=(b-a)/h;
    double x=0,y[4];
    y[0]=1;
    ofstream op("Solution(0.2).txt");
    
    op<<endl<<" x"<<"\t\t"<<"y"<<endl;

	for(i=0;i<3;i++)                            //using RK4 for the first 3 iteration
	{
		op<<x<<"\t\t"<<y[i]<<endl;
		y[i+1]= rk4(x,y[i],h);
		x+=h;
	}

	for(i=3;i<n+1;i++)                          //using AdamsBasforth Function for the rest of the iterations
	{
		op<<x<<"\t\t"<<y[3]<<endl;            
		AdamsBasforth(h,x,y);
		x+=h;
	
	}

return 0;
}

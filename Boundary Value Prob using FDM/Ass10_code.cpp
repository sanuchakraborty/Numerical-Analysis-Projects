#include <iostream>
#include<cmath>
#include<fstream>

using namespace std;
#define n 100

int main()
{
    double c[n+1],d[n+1],a[n+1],b[n+1],A[n][n],B[n],x[n],r[n];
    int i=0;
    double t0=0,t1=1,h=0;
    ofstream op("Output(n=100).txt");
    h=(t1-t0)/n;
    x[0]=0;
    x[n]=1;
    for(i=0;i<=n;i++)               // Coefficients of Y[i-1],Y[i]&Y[i+1] calculation
    {
    c[i]=1-h* cos(t0)/2;
    d[i]=-(2+sin(t0)*h*h);
    a[i]=1+(h*cos(t0)/2);
    b[i]=-exp(t0)*h*h;
    t0=t0+h;
    }

    for(i=1;i<n;i++)
    {
    for(int j=1;j<n;j++)
    {
    if(i==j)
    A[i][j]=d[i];               // A matrix formation
    else if(i==(j+1))
    A[i][j]=a[i];
    else if(j==(i+1))
    A[i][j]=c[i];
    else
    A[i][j]=0;
    }
    }
    B[1]=b[1]-a[1]*x[0];
    B[n-1]=b[n-1]-c[n-1]*x[n];    // B matrix formation 
    for(i=2;i<n-1;i++)
    {
    B[i]= b[i];
    }


  //  Gauss Elimination
    
	for(int k=2;k<n;k++)           
      {
	r[k]=(A[k][k-1]/A[k-1][k-1]);
	A[k][k]=A[k][k]-r[k]*A[k-1][k];
	A[k][k-1]=0;
	}
     for(int k=2;k<n;k++)
     {
	  B[k]=B[k]-r[k]*B[k-1];
     }
     x[n-1]=B[n-1]/A[n-1][n-1];         // Back Substitution
     for(int j=(n-2);j>=1;j--){
	 x[j]=(B[j]-A[j][j+1]*x[j+1])/A[j][j];
     }


     t0=0;
    for(i=0;i<=n;i++)
    {
    op<<t0<<"\t"<<x[i]<<endl;
    t0+=h;
    }
    return 0;
}

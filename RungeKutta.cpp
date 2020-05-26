#include<iostream>
#include<math.h>
#define T0 0
#define Y0 1
#define h 0.02
#define N 100
using namespace std;

double f(double t, double y);
double series(double t, double y);

double series(double t, double y){
    double alpha1=f(t,y);
    double alpha2=f(t+h,y+h*alpha1);
    double series=(y+(h/2)*(alpha1+alpha2));
    return series;
}

double f(double t, double y){
    //return 2*t*y;
    double f=y;
    return f;
}

int main(){
    cout<<"\t ** Runge-Kutta second order **"<<"\n";
    double y= Y0;
    double t=T0;

    FILE *ptr_file;
    ptr_file=fopen("Grafica.txt","w");
    if(!ptr_file){
        return 1;
    }

    for(int i=0; i<=N; ++i){
        y=series(t,y);
        t=T0+(i+1)*h;
        cout<<t<<", "<<y<<endl;
        fprintf(ptr_file,"%f %f \n",t,y);
    }
    return 0;
}
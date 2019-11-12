#include<bits/stdc++.h>
using namespace std;
#define MAX_ITER 10

ofstream myfile;

double func(double x)
{
    return x*x - 4*x - 10;
}


void Secant(double x0, double x1)
{

    for (int i=0; i < MAX_ITER; i++)
    {

        double x2 = x1 - (func(x1)*(x1-x0))/((func(x1)-func(x0)));

        double err = abs((x1-x2)/x2);


        myfile<<fixed<<"  "<<i+1<<"          "<<setprecision(6)<<x0<<"         "<<setprecision(6)<<x1<<"          "<<setprecision(6)<<x2<<"          " <<setprecision(6)<<err<<"\n";

        x0 = x1;
        x1 = x2;

    }

}


int main()
{
    myfile.open ("SecantMethodTableA.txt");

    myfile << "*************Secant Method*************\n\n\n";

    double x0 =4.00000, x1 = 2.00000;

    myfile <<"Iteration         x0           x1                   x2               Error\n\n";

    Secant(x0, x1);

    myfile.close();


    return 0;
}

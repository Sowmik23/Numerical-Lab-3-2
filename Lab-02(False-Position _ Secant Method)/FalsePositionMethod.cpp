#include<bits/stdc++.h>
using namespace std;
#define MAX_ITER 10

ofstream myfile;

double func(double x)
{
    return x*x - 4*x - 10;
}


void FalsePosition(double x0, double x1)
{
    double x2;

    for (int i=0; i < MAX_ITER; i++)
    {

        double x2 = x0 - func(x0)*((x1-x0)/(func(x1)-func(x0)));


        double err = abs((x1-x2)/x2);


        myfile<<fixed<<"  "<<i+1<<"          "<<setprecision(6)<<x0<<"         "<<setprecision(6)<<x1<<"          "<<setprecision(6)<<x2<<"          " <<setprecision(6)<<err<<"\n";

        if (func(x2)*func(x0) < 0)
        {
            x1 = x2;
        }
        else {
            x0 = x2;
        }

    }

}


int main()
{

    myfile.open ("FalsePositonMethodTable.txt");

    myfile << "*************False Position Method*************\n\n\n";

    double x0 =4.00000, x1 = 9.00000;

    myfile <<"Iteration         x0           x1                   x2               Error\n\n";

    FalsePosition(x0, x1);

    return 0;
}

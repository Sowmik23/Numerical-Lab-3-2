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
    double x2;

    for (int i=0; i < MAX_ITER; i++)
    {

        double x2 = x1 - (func(x1)*(x1-x0)/(func(x1)-func(x0)));


        myfile<<i<<"         "<<x0<<<<"         "<<x1<<"     "<<x2<<"\n";

        if (func(x2)*func(x0) < 0)
        {
            x1 = x2;
        }
        else
        {
            x0 = x2;
        }

    }

}


int main()
{
    myfile.open ("SecantA.txt");

    myfile << "*************Secant Method*************\n";

    double x0 =4.00000, x1 = 2.00000;

    myfile <<"Iteration    x0      x1      x2\n";

    Secant(x0, x1);

    myfile.close();


    return 0;
}

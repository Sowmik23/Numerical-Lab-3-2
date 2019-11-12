#include<bits/stdc++.h>

using namespace std;

ofstream outfile;
ifstream infile;

void Decomposition(float arr[100][100], float l[100][100], float u[100][100], int n)
{
   int i = 0, j = 0, k = 0;

   for (i = 0; i < n; i++)
   {
      for (j = 0; j < n; j++)
      {
         if (j < i)
         {
            l[j][i] = 0;
         }

         else
         {
            l[j][i] = arr[j][i];
            for (k = 0; k < i; k++)
            {
               l[j][i] = l[j][i] - l[j][k] * u[k][i];
            }
         }
      }

      for (j = 0; j < n; j++)
      {
         if (j < i){
            u[i][j] = 0;
         }
         else if (j == i)
         {
            u[i][j] = 1;
         }
         else
         {
            u[i][j] = arr[i][j] / l[i][i];
            for (k = 0; k < i; k++) {
               u[i][j] = u[i][j] - ((l[i][k] * u[k][j]) / l[i][i]);
            }
         }
      }

   }
}


int main()
{
   outfile.open ("U_Matrix.txt");
   infile.open("input.txt");

   cout<< "*************LU Decomposition*************\n\n";
   outfile << "*************LU Decomposition*************\n\n";

   float arr[100][100], l[100][100], u[100][100];
   int i = 0, j = 0;
   int n;

   infile >> n;

   cout<<"Given Matrix is :\n"<<n<<"x"<<n<<endl<<endl;
   outfile<<"Given Matrix is :\n"<<n<<"x"<<n<<endl<<endl;
   cout<<"The input Matrix is: \n"<<endl;
   outfile<<"The input Matrix is: \n"<<endl;


   for (i = 0; i < n; i++)
   {
      for (j = 0; j < n; j++)
      {
         infile >> arr[i][j];
         outfile<<arr[i][j]<<"      ";
         cout<<arr[i][j]<<"      ";
      }
      cout<<endl;
      outfile<<"\n";
   }

   cout<<endl;
   outfile<<endl;


   Decomposition(arr, l, u, n);


   cout << "Upper Traingular Matrix is :\n\n";
   outfile << "Upper Traingular Matrix is :\n\n";

   for (i = 0; i < n; i++)
   {
      for (j = 0; j < n; j++)
      {
         cout<<setprecision(5)<<u[i][j]<<"     ";
         outfile<<setprecision(5)<<u[i][j]<<"     ";
      }
      cout << endl;
      outfile<<"\n";
   }

   cout<<endl;
   outfile<<endl;

   cout << "Lower Traingular Matrix is :\n\n";
   outfile << "Lower Traingular Matrix is :\n\n";

   for (i = 0; i < n; i++)
   {
      for (j = 0; j < n; j++)
      {
         cout<<setprecision(5)<<l[i][j]<<"     ";
         outfile<<setprecision(5)<<l[i][j]<<"     ";
      }
      cout << endl;
      outfile<<"\n";
   }


   return 0;
}

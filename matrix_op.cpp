#include <iostream>
#include <iomanip>
#include <math.h>
#include <ctime>
#define sz 20

using namespace std;

float det(float mat[][sz], int);

int main()
{
    float mat[sz][sz], mat2[sz][sz], mat3[sz][sz], d;
    int n;

    cout<<"Enter the dimension of square matrix: ";
    cin>>n;
    cout<<"\nEnter "<<n*n<<" elements: \n";
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>mat[i][j];

    cout<<"Your entered array is: \n";

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout<<setw(5)<<mat[i][j];
        cout<<endl;
    }
    d=det(mat, n);

    /* Finding Cofactors of the matrix */
    int start_s=clock();
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            for(int k=0, r=0; k<n; k++)
            {
                int l,c;
                for(l=0,c=0; l<n; l++)
                {
                    if(k!=i&&l!=j)
                    {
                        mat2[r][c++]=mat[k][l];
                    }
                }
                if (c!=0) r++;
            }
            mat3[i][j]=pow(-1, i+j)*det(mat2, n-1);
        }
    }
    /* Finding transpose of the cofactor matrix to find its adjoint */
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            mat2[i][j]=mat3[j][i];

    cout<<"\nThe adjoint of the given matrix is: \n";

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout<<setw(5)<<mat2[i][j];
        cout<<endl;
    }

    if(d!=0)
    {
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                mat3[i][j]=mat2[i][j]/d;
    }
    int stop_s=clock();

    if(d==0)
        cout<<endl<<"The Inverse of this matrix does not exist as its determinant is zero.";
    else
        cout<<endl<<"The Inverse of the matrix exists. it is: \n";

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout<<setw(9)<<setprecision(4)<<mat3[i][j];
        cout<<endl;
    }
    cout<<"\nThe execution time for program: "<<(stop_s-start_s)/double(CLOCKS_PER_SEC)*1000;
    return 0;
}

/* Function to find determinant of n-th order matrix*/
float det(float mat[][sz], int n)
{
    float sum=0;
    if(n>2)
    {
        float mat2[sz][sz];
        for(int j=0; j<n; j++)
        {
            for(int k=0, r=0; k<n; k++)
            {
                int l, c;
                for(l=0, c=0; l<n; l++)
                {
                    if(k!=0&&l!=j)
                        mat2[r][c++]=mat[k][l];
                }
                if(c!=0) r++;
            }
            sum+= pow(-1, j)*mat[0][j]*det(mat2, n-1);
        }
    }

    else
    {
        sum=(mat[0][0]*mat[1][1])-(mat[0][1]*mat[1][0]);
    }

    return sum;
}

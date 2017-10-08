#include <iostream>

using namespace std;

int main()
{

    for(int i=2;i<=200;i++)
    {
        for(int j=2;j<i;j++)
        {
            for(int k=j;k<i;k++)
            {
                for (int m=k;m<i;m++)
                {
                    if (i*i*i==(j*j*j+k*k*k+m*m*m))
                        cout <<"Cube = "<< i<<", Triple = ("<<j<<","<<k<< ","<<m<<")"<<  endl;
                    if(i*i*i<(j*j*j+k*k*k+m*m*m)) break;
                }
            }
        }
    }

    return 0;
}

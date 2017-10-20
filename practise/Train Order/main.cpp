#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        int n;
        cin>>n;
        int a[n];
        int stk[n];

        for(int i=0;i<n;i++) a[i]=i+1;
        do{
            int i,j,x;
            for(i=0,j=0,x=1;x<=n&&j<n;x++)
            {
                stk[i++]=x;
                while(i>0&&stk[i-1]==a[j]){
                    i--;
                    j++;
                }
            }
            if(j==n)
            {
                for(int i=0;i<n;i++) cout<<a[i];
                cout <<endl;
            }


        }while(next_permutation(a,a+n));
    }
    return 0;
}

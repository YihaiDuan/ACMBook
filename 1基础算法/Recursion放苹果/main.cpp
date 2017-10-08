#include <iostream>

using namespace std;
int rec(int m,int n)
{
    if(m==0||n==1) return  1;
    else if(m<n) return rec(m,m);
    else{
        return rec(m,n-1)+rec(m-n,n);
    }
}
int main()
{
    int a,b;
    int n;
    cin>>n;
    while(n--)
    {
        cin>>a>>b;
        cout << rec(a,b)<<endl;
    }
}

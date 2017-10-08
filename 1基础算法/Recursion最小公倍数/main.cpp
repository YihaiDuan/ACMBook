#include <iostream>

using namespace std;

int gcd(int a,int b)
{
    if(a<b) swap(a,b);
    int temp=a%b;
    if (temp==0) return b;
    return gcd(b,temp);
}
int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        cout << a*b/gcd(a,b)<<endl;
    }
    return 0;
}

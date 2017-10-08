#include <iostream>

using namespace std;
bool check(int a1,int a2,int b,int c)
{
    int m=a2;
    int b1=0,c1=0;
    int arr1[4],arr2[4];
    for(int i=3;i>=0;i--)
    {
        arr1[i]=a1%10;
        a1=a1/10;
        arr2[i]=a2%10;
        a2=a2/10;
    }
    for(int i=0;i<4;i++)
    {
        if(arr1[i]==arr2[i]) c1++;
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(arr1[i]==arr2[j])
            {
                b1++;
                arr2[j]=-1;
                break;
            }
        }
    }
    return (b==b1)&&(c==c1);
}
int main()
{
    int n,a[101],b[101],c[101];
    while(cin>>n&&n)
    {
        for(int i=0;i<n;i++)
            cin>>a[i]>>b[i]>>c[i];
        int ans,cnt=0;
        for(int i=1000;i<10000&&cnt<2;i++)
        {
            int j;
            for( j=0;j<n;j++)
            {
                if(!check(a[j],i,b[j],c[j])) break;
            }
            if(j==n)
            {
                ans=i;cnt++;
            }
        }
        if (cnt==1) cout << ans<<endl;
        else cout << "Not sure" << endl;
    }
    return 0;
}

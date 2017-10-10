#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    int a[1005],b[1005];
    int n;
    while(cin>>n&&n)
    {
        int ans=0;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        sort(a,a+n);
        sort(b,b+n);
        int l1=0,l2=0;
        int r1=n-1,r2=n-1;
        while(l1<=r1)
        {
            if(a[r1]>b[r2])
            {
                r1--;
                r2--;
                ans+=200;
            }
            else if(a[r1]<b[r2])
            {
                l1++;
                r2--;
                ans-=200;
            }
            else{
                if(a[l1]>b[l2])
                {
                    l1++;
                    l2++;
                    ans+=200;
                }
                else {
                    if(a[l1]<b[r2]) ans-=200;
                    l1++;
                    r2--;
                }
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}

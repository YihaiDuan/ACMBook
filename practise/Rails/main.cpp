#include <iostream>
using namespace std;

int main(){
    int stackarr[1005];
    int target[1005];
    int n;
    while (cin>>n&&n!=0)
    {
        while(cin>>target[0]&&target[0]!=0)
        {
            for(int i=1;i<n;i++) cin>>target[i];
            int top,x,m;
            for(top=0,x=1,m=0;x<=n&&m<n;x++,top++)
            {
                stackarr[top]=x;
                while(stackarr[top]==target[m])
                {
                    top--;
                    m++;
                    if(top==-1) break;
                }
            }
            if(m==n) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
        cout<<endl;
    }
    return 0;
}


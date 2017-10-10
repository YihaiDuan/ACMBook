#include <iostream>
#include <algorithm>
using namespace std;
struct Node{
    int x;
    int y;
    bool tour;
};
bool cmp(Node n1,Node n2)
{
    if(n1.x==n2.x ) return n1.y>n2.y;
    else return n1.x>n2.x;
}
Node narr[5005];

int main()
{

    int n,m,cnt;
    cin>>n;
    while(n--)
    {
        cnt=0;
        cin>>m;
        for(int i=0;i<m;i++) {
            cin>>narr[i].x>>narr[i].y;
            narr[i].tour=false;
        }
        sort(narr,narr+m,cmp);
        for(int i=0;i<m;i++)
        {
            if(!narr[i].tour){
                   // cout <<"i:"<<i;
                cnt++;
                int cp=narr[i].y;
                for(int j=i;j<m;j++)
                {
                    if ((!narr[j].tour)&&narr[j].y<=cp)
                    {
                        narr[j].tour=true;
                        cp=narr[j].y;
                    }
                }

            }

        }
        cout<<cnt<<endl;
    }
    return 0;
}

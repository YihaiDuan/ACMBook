#include <iostream>

using namespace std;

int main()
{
    int tag[16][3];
    int r,g,b;
    for (int i=0;i<16;i++) cin>>tag[i][0]>>tag[i][1]>>tag[i][2];

    while (cin>>r>>g>>b&&!(r==b&&b==g&&g==-1))
    {
        int mindis=255*255+255*255+255*255;
        int i,j;
        for(i=0;i<16;i++)
        {
            int temp=(r-tag[i][0])*(r-tag[i][0])+(g-tag[i][1])*(g-tag[i][1])+(b-tag[i][2])*(b-tag[i][2]);
            if (temp<mindis)
            {
                mindis=temp;
                j=i;
                if(mindis==0) break;
            }

        }
        cout << "("<<r<<","<<g<< ","<<b<< ") maps to ("<<tag[j][0]<< ","<<tag[j][1]<< ","<<tag[j][2]<<")"<<endl;
    }
    return 0;
}

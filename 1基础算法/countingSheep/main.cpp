#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int n,c=1;
    cin >> n;
    if (n>20)
        return 0;
    while(n--){
        int m;
        cin >> m;
        if (m>10)
            return 0;
        string str;
        string stdstr="sheep";
        int cnt=0;
        while(m--){
            cin >> str;
            if(!strcmp( str.c_str(), stdstr.c_str() ))
                cnt++;
        }
        cout<<"Case "<< c++ << ": " <<"This list contains "<<cnt <<" sheep."<<endl;
    }
    return 0;
}

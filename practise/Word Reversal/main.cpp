#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    cin.get();
    string str;
    while(n--){
        getline(cin,str);
        string sub;
        int pos;
        while(1){
            pos=str.find(' ');
            if(pos==-1) break;
            sub=str.substr(0,pos);
            for(int i=sub.length()-1;i>=0;i--) cout<<sub[i];
            cout << " ";
            str=str.substr(pos+1,str.length()-pos-1);
        }
        for(int i=str.length()-1;i>=0;i--) cout<<str[i];
        cout <<endl;
    }


    return 0;
}

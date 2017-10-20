#include <iostream>

using namespace std;
int bit=0,fit=0;
string backStack[105];
string forwardStack[105];
string crt="http://www.acm.org/";
void command(string cmd)
{
    if(cmd=="VISIT")
    {
        fit=0;
        backStack[bit++]=crt;
        cin >> crt;
        cout <<crt<<endl;
    }
    if(cmd=="BACK")
    {
        if(bit==0) cout<<"Ignored"<<endl;
        else {
            forwardStack[fit++]=crt;
            crt=backStack[--bit];
            cout<<crt<<endl;
        }
    }
    if(cmd=="FORWARD")
    {
        if(fit==0) cout<<"Ignored"<<endl;
        else {
            backStack[bit++]=crt;
            crt=forwardStack[--fit];
            cout<<crt<<endl;
        }
    }
}
int main()
{

    string cmd;
    while(cin>>cmd&&cmd!="QUIT")
    {
        command(cmd);
    }
    return 0;
}

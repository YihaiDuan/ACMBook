#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <fstream>
using namespace std;
void gettheline(int &s, int &e, string str)
{
    int p=str.find(',');
    s=0;
    for (int i=0;i<p;i++)
    {
        s=s*10+(str[i]-'0');
    }
    e=0;
    for(int i=p+1;i<str.length();i++)
    {
        e=e*10+(str[i]-'0');
    }
}
int main()
{

    int L,n=1,sline,eline;
    int p1,p2,p3;
    bool changed=false;
    cin >> L;
    cin.get();
    string str[105],command,ostr,nstr,lastostr;
    while (L--){
        getline(cin,str[n]);
        n++;
    }
    lastostr="";
    bool flag=false;
    while(getline(cin,command))
    {
        if(command[0]!=':') return 0;
        if(flag) cout << endl;
        flag=true;
        int p=command.find('s');//find()º¯ÊýÓÃ·¨
        if (command[1]=='s')
        {
            sline=1;
            eline=n;
        }
        else{
            gettheline(sline,eline,command.substr(1,p-1));
        }
        p1=p+1;
        p2=command.find(command[p1],p1+1);
        p3=command.find(command[p1],p2+1);
        ostr=command.substr(p1+1,p2-p1-1);
        nstr=command.substr(p2+1,p3-p2-1);
        if(ostr=="")
            ostr=lastostr;
        else
            lastostr=ostr;
        changed=false;
        int ostr_len=ostr.length(),nstr_len=nstr.length();
        for(int i=sline;i<=eline;i++)
        {
            bool c=0;
            int p0=str[i].find(ostr,0);
            while(p0!=-1)
            {
                str[i].replace(p0,ostr_len,nstr);
                p0=str[i].find(ostr,p0+nstr_len);
                c=1;
                changed=true;
            }
            if(c) cout << setw(4) << i<< "  "<<str[i]<<endl;
        }
        if(!changed)cout << "Pattern not found"<<endl;
        cout << endl;


    }

//    for (int i=1;i<n;i++){
//        cout << str[i]<< endl;
//    }

//    cout << 1 << endl;
//    ifstream fin;
//    ofstream fout;
//    fin.open("a.txt");
//    string str;
//    fin >> str;
//    cout << str;
//    fout.open("b.txt");
//    fout << str;
//    char buff[255]="seg";
//    FILE *fp;
//    fp=fopen("a.txt","a+");
//    fprintf(fp,buff);
//    cout << buff;
    return 0;
}

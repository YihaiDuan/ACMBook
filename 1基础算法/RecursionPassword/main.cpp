#include <iostream>

using namespace std;
int t;
char ans[27];
void postorder(string str1,string str2)
{
    if (str1.length()==0) return;
    else if(str1.length()==1)
    {
        ans[t++]=str1[0];
        return;
    }
    char root=str1[0];
    int pos;
    pos=str2.find(root);
    postorder(str1.substr(1,pos),str2.substr(0,pos));
    postorder(str1.substr(pos+1,str1.length()-pos-1),str2.substr(pos+1,str2.length()-pos-1));
    ans[t++]=root;
}
int main()
{
    string str1,str2;
    while(cin>>str1>>str2)
    {
        t=0;
        postorder(str1,str2);
        int len=str1.length();
        ans[len]='\0';
        cout<<ans<<endl;
    }

    return 0;
}

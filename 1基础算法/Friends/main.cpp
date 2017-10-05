#include <iostream>
#include <algorithm>
#define N 255
using namespace std;

string str_op(string str1,string str2,char ch)
{
    if (ch=='+')
    {
        for(int i=0;i<str1.length();i++)
            if (str2.find(str1[i])!=-1) str1.erase(i--,1);
        return str1+str2;
    }
    if(ch=='-')
    {
        for(int i=0;i<str1.length();i++)
            if (str2.find(str1[i])!=-1) str1.erase(i--,1);
        return str1;
    }
    if(ch=='*')
        for(int i=0;i<str1.length();i++)
            if (str2.find(str1[i])==-1) str1.erase(i--,1);
        return str1;
}
int op_cmp(char ch1,char ch2)
{
    if(ch1=='('){
        if(ch2==')') return 0;
        else return -1;
       }
    if(ch1=='+'||ch1=='-')
    {
        if (ch2=='('||ch2=='*') return -1;
        else return 1;
    }
    if(ch1=='*')
        if(ch2=='(') return -1;
        else return 1;
}
string strSort(string str){
	char temp;
	int len = str.length();
	 for (int j = 0; j < len; ++j)
    {
        for (int i = 0; i < len-j-1; ++i)
        {
            if (str[i]>str[i+1])
            {
                temp = str[i];
                str[i] = str[i+1];
                str[i+1] = temp;
            }
        }
    }
	return str;
}

int main()
{
    string stackstr[N];
    char stackop[N];
    int it1=0,it2=0;
    string str,tempStr;
    char tempOp;
    while(getline(cin,str))
    {
        stackop[it2++]='(';
    str.append(1u,')');
    for (int i=0;i<str.length();)
    {

        if(str[i]=='{')
            {
                int pos=str.find('}',i+1);
                tempStr=str.substr(i+1,pos-i-1);
                stackstr[it1++]=tempStr;
                i=pos+1;
            }
        else {
            tempOp=str[i++];
            while(!(tempOp==')'&&stackop[it2-1]=='('))
            {

                int cmp=op_cmp(stackop[it2-1],tempOp);
                if (cmp==-1)
                {
                    stackop[it2++]=tempOp;

                    break;
                }
                else if(cmp==1){
                    tempStr=str_op(stackstr[it1-2],stackstr[it1-1],stackop[--it2]);
                    it1-=2;
                    stackstr[it1++]=tempStr;
                    stackstr[it1]="";
                }

            }
            if(tempOp==')'&&stackop[it2-1]=='(') it2--;

        }
    }

    cout << "{"<<strSort(stackstr[--it1])<<"}" << endl;
    }


//    string str1,str2;
//    char ch;
//    while(cin>>str1>>str2>> ch)
//    {
//        string str=str_op(str1,str2,ch);
//        cout << str<<endl;
//    }


    return 0;
}

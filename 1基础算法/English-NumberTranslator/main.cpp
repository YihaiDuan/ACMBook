#include <iostream>
using namespace std;
int smallnum(string str)
{
    int sum=0;
    int pos=str.find("hundred");
    if(pos!=-1)
    {
        string hnd=str.substr(0,pos-1);
        if(hnd=="one") sum+=100;
        else if(hnd=="two") sum+=200;
        else if(hnd=="three") sum+=300;
        else if(hnd=="four") sum+=400;
        else if(hnd=="five") sum+=500;
        else if(hnd=="six") sum+=600;
        else if(hnd=="seven") sum+=700;
        else if(hnd=="eight") sum+=800;
        else if(hnd=="nine")sum+=900;
        if (str.length()==pos+7) return sum;
        str=str.substr(pos+8);

    }
    pos=str.find(' ');
    if (pos==-1)
    {
        if(str=="zero") return sum;
        else if(str=="one") return sum+1;
        else if(str=="two") return sum+2;
        else if(str=="three") return sum+3;
        else if(str=="four") return sum+4;
        else if(str=="five") return sum+5;
        else if(str=="six") return sum+6;
        else if(str=="seven") return sum+7;
        else if(str=="eight") return sum+8;
        else if(str=="nine") return sum+9;
        else if(str=="ten") return sum+10;
        else if(str=="eleven") return sum+11;
        else if(str=="twelve") return sum+12;
        else if(str=="thirteen") return sum+13;
        else if(str=="fourteen") return sum+14;
        else if(str=="fifteen") return sum+15;
        else if(str=="sixteen") return sum+16;
        else if(str=="seventeen") return sum+17;
        else if(str=="eighteen") return sum+18;
        else if(str=="nineteen") return sum+19;
        else if(str=="twenty") return sum+20;
        else if(str=="thirty") return sum+30;
        else if(str=="forty") return sum+40;
        else if(str=="fifty") return sum+50;
        else if(str=="sixty") return sum+60;
        else if(str=="seventy") return sum+70;
        else if(str=="eighty") return sum+80;
        else if(str=="ninety") return sum+90;

    }
    else {
        string str1=str.substr(0,pos);
        string str2=str.substr(pos+1);
        if (str1=="twenty") sum+=20;
        else if(str1=="thirty")  sum+=30;
        else if(str1=="forty")  sum+=40;
        else if(str1=="fifty")  sum+=50;
        else if(str1=="sixty")  sum+=60;
        else if(str1=="seventy")  sum+=70;
        else if(str1=="eighty")  sum+=80;
        else if(str1=="ninety")sum+=90;
        if(str2=="one") return sum+1;
        else if(str2=="two") return sum+2;
        else if(str2=="three") return sum+3;
        else if(str2=="four") return sum+4;
        else if(str2=="five") return sum+5;
        else if(str2=="six") return sum+6;
        else if(str2=="seven") return sum+7;
        else if(str2=="eight") return sum+8;
        else if(str2=="nine") return sum+9;
    }

}
int translate(string str)
{
    int sum=0;
    int neg=str.find("negative");
    if (neg==0) str=str.substr(9);
    int pos1=0,pos2=0;
    pos1=str.find("million");
    pos2=str.find("thousand");
    string str1,str2,str3;
    if(pos1!=-1)
    {
        str1=str.substr(0,pos1-1);
        sum+=smallnum(str1)*1000000;
        if(pos2!=-1)
        {
            str2=str.substr(pos1+8,pos2-pos1-1);
            sum+=smallnum(str2)*1000;
            if(str.length()==pos2+8) return neg==0?-sum:sum;
            str3=str.substr(pos2+9);
            sum+=smallnum(str3);
            return neg==0?-sum:sum;

        }
        else if(str.length()==pos1+7) return neg==0?-sum:sum;
        str3=str.substr(pos1+8);
        sum+=smallnum(str3);
        return neg==0?-sum:sum;
    }
    else if(pos2!=-1)
    {
        str2=str.substr(0,pos2-1);
        sum+=smallnum(str2)*1000;
        if(str.length()==pos2+8) return neg==0?-sum:sum;
        str3=str.substr(pos2+9);
        sum+=smallnum(str3);
        return neg==0?-sum:sum;
    }
    else
    {
        sum+=smallnum(str);
        return neg==0?-sum:sum;
    }

}

int main()
{

    string str;
    while(getline(cin,str)){
        if (str=="") return 0;
        int a=translate(str);
        cout << a<< endl;
    }

    return 0;
}

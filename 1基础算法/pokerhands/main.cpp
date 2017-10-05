#include <iostream>
#include <algorithm>
using namespace std;
class Poker{
public:
    int num,color;
    Poker(int a=0,int b=0){
    num=a;color=b;
    }
    bool operator<(const Poker p) const
    {
        if(num==p.num)
            return color<p.color;
        return (num<p.num);
    }
};
class Person{
public:
    Poker p[5];
    int pairs[2],three,straight,flush,full,four,str_flush,pos;
    Person(){}
    void regular(){
        sort(p,p+5);
        int arr[15]={0};
        for(int i=0;i<5;i++) arr[p[i].num]++;
        pos=pairs[0]=pairs[1]=three=four=full=str_flush=0;
        for(int i=14;i>1;i--)
        {
            if(arr[i]==4) four=i;
            else if(arr[i]==3) three=i;
            else if(arr[i]==2) pairs[pos++]=i;
        }
        straight=flush=p[4].num;
        for(int i=0;i<4;i++)
        {
            if(p[i].num+1 != p[i+1].num) straight=0;
            if(p[i].color!=p[i+1].color) flush=0;
        }
        str_flush=(straight&&flush);
        if(three&&pairs[0]) full=three;

    }


};
char cc[4],num_char[17]={"..23456789TJQKA"};
Person pa,pb;
Poker getcc(){
    int a,b=4;
    for(int i=2;i<15;i++)
    {
        if(num_char[i]==cc[0]) a=i;
    }
    if (cc[1]=='C') b=1;
    else if (cc[1]=='D') b=2;
    else if (cc[1]=='H') b=3;
    return Poker(a,b);
 }
 int higher(int e=4){
    for(int i=4;i>=0;i--)
    {
        if(pa.p[i].num>pb.p[i].num) return 1;
        else if(pa.p[i].num<pb.p[i].num) return-1;

    }
    return 0;
 }
 int compare()
 {
     if (pa.str_flush||pb.str_flush)
     {
         if(pa.str_flush&&pb.str_flush) return higher();
         else if(pa.str_flush) return 1;
         else return -1;
     }
     if (pa.four||pb.four) return (pa.four>pb.four)*2-1;
//     {
//         if(pa.four&&pb.four) return higher();
//         else if(pa.four) return 1;
//         else return -1;
//     }
     if(pa.full||pb.full) return (pa.three>pb.three)*2-1;
     if(pa.flush||pb.flush)
     {
         if(pa.flush&&pb.flush) return higher();
         else return pa.flush*2-1;
     }
     if(pa.straight||pb.straight)
     {
         if(pa.straight>pb.straight) return 1;
         else if(pa.straight<pb.straight) return -1;
         else return 0;
     }
     if(pa.three||pb.three) return (pa.three-pb.three)*2-1;
     if(pa.pos||pb.pos)
     {
         if(pa.pos>pb.pos) return 1;
         else if(pa.pos<pb.pos) return -1;
         if(pa.pairs[0]>pb.pairs[0]) return 1;
         else if (pa.pairs[0]<pb.pairs[0]) return -1;
         else{
                if (pa.pairs[1]>pb.pairs[1]) return 1;
                else if (pa.pairs[1]<pb.pairs[1]) return -1;
                else {
                    int t1=0,t2=0;
                    for (int i=0;i<5;i++){
                        if(pa.p[i].num!=pa.pairs[0]&&pa.p[i].num!=pa.pairs[1])
                            pa.p[t1++].num=pa.p[i].num;
                        if(pb.p[i].num!=pb.pairs[0]&&pb.p[i].num!=pb.pairs[1])
                            pb.p[t2++].num=pb.p[i].num;
                    }
                    if (pa.pos==1) return higher(2);
                    else return higher(0);
                }

         }
     }
     return higher();

 }
int main()
{
    while(cin>>cc){
        pa.p[0]=getcc();
        for(int i=1;i<5&&cin>>cc;i++)pa.p[i]=getcc();
        for(int i=0;i<5&&cin>>cc;i++)pb.p[i]=getcc();
        pa.regular();
        pb.regular();
        int ans = compare();
        if(ans==1) cout <<"Black wins." << endl;
        else if(ans==-1) cout <<"White wins."<<endl;
        else cout << "Tie." << endl;
    }

    return 0;
}

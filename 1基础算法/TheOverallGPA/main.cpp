#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstring>

using namespace std;

struct Record
{
    string smt;
    string course;
    string name;
    double credit;
    string attr;
    double score;
    double GPA;
};
bool cmp(Record rec1,Record rec2)
{
    return (rec1.smt<rec2.smt);
}
int main()
{
//    string str;
//    getline(cin,str);
//    if (str=="END OF THE FILE") return 0;
//    int num=0;
//    while(str!="END OF THE FILE"){
//        num++;
//        Record rec[255];
//        int cnt=0;
//        while(str!="END"&&str!="END OF THE FILE")
//        {
//            int pos[5]={0};
//            pos[0]=str.find(' ');
//            while(str[pos[0]+1]==' ') pos[0]++;
//            for(int i=1;i<5;i++)
//            {
//                pos[i]=str.find(' ',pos[i-1]+1);
//                while(str[pos[i]+1]==' ') pos[i]++;
//                //cout << pos[i]<<endl;
//            }
//            rec[cnt].smt=str.substr(0,pos[0]);
//            rec[cnt].course=str.substr(pos[0]+1,pos[1]-pos[0]-1);
//            rec[cnt].name=str.substr(pos[1]+1,pos[2]-pos[1]-1);
//            rec[cnt].credit=atof((str.substr(pos[2]+1,pos[3]-pos[2]-1)).c_str());
//            rec[cnt].attr=str.substr(pos[3]+1,pos[4]-pos[3]-1);
//            rec[cnt].score=atof((str.substr(pos[4]+1)).c_str());
//            //string a=str.substr(pos[4]);
//            //cout << rec[cnt].score;
//
//            if (rec[cnt].score>=90) rec[cnt].GPA=4.0;
//            else if (rec[cnt].score>=80) rec[cnt].GPA=3.0;
//            else if (rec[cnt].score>=70) rec[cnt].GPA=2.0;
//            else if (rec[cnt].score>=60) rec[cnt].GPA=1.0;
//            else  rec[cnt].GPA=0;
//            cnt++;
//            getline(cin,str);
//        }
//
//        sort(rec,rec+cnt,cmp);
//        string smtstr=rec[0].smt;
//        int i;
//        double scoresumall=0;
//        double creditsumall=0;
//        double GPAsum=0;
//        cout << "Case :"<< num<<endl;
//        for( i=0;i<cnt;)
//        {
//            double scoresum=0;
//            double creditsum=0;
//            int j;
//            for( j=i;rec[j].smt==smtstr;j++)
//            {
//                scoresum+=rec[j].score*rec[j].credit;
//                creditsum+=rec[j].credit;
//                GPAsum+=rec[j].GPA*rec[j].credit;
//                //cout << smtstr << endl<<rec[j].smt<<endl;
//                //cout << (rec[j].smt==smtstr);
//            }
//            smtstr=rec[j].smt;
//            i=j;
//
//            if(rec[0].smt!=rec[cnt-1].smt)cout <<fixed<<setprecision(2)<< "The average score for " << rec[j-1].smt <<": " << scoresum/creditsum<<endl;
//            scoresumall+=scoresum;
//            creditsumall+=creditsum;
//        }
//        cout << "The average score: " <<fixed<<setprecision(2)<< scoresumall/creditsumall << endl;
//        cout << "The GPA standard: " <<fixed<<setprecision(2)<< GPAsum/creditsumall << endl;
//        if(str=="END OF THE FILE") return 0;
//        getline(cin,str);
//    }
 char p[]="abcd";
 char a='o';
  char * p2=&a;


 cout<<&p<<endl; //数组大小为6
  cout<<&p2<<endl; // 指针大小为4

 // 长度为5

    return 0;
}

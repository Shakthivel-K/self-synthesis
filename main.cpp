#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using namespace std;
void log_ctr()
{
    
    ifstream fin ("ctr.txt");
    int x;
    fin >>x;
    x++;
    remove ("ctr.txt");
    ofstream fout("ctr.txt",ios::app);
    fout <<x<<endl;
    fout.close();
}
void reset_ctr()
{
    remove ("ctr.txt");
    ofstream fout("ctr.txt",ios::app);
    fout <<0<<endl;
}
void gen_log()
{
    ofstream fout("log.txt",ios::app);
    fout <<"add\t0"<<endl;
    fout <<"diff\t0"<<endl;
    fout <<"prod\t0"<<endl;
    fout <<"quo\t0"<<endl;
}
void log_msg(string s)
{
    ofstream fout("log_temp.txt",ios::app);
    ifstream fin ("log.txt");
    int count;
    string fn;
    while (true)
    {
        fin >>fn>>count;
        if (fin.eof())
        {
            break;
        }
        if (fn==s)
        {
            count++;
        }
        fout <<fn<<"\t"<<count<<endl;
    }
    fin.close();
    fout.close();
    remove("log.txt");
    rename("log_temp.txt","log.txt");


}
void log_activation()
{
    string str;
    remove("activation_log.txt");
    ofstream fout ("activation_log.txt",ios::app);
    ifstream fin ("main.cpp");
    while (true)
    {
        if (fin.eof())
        {
            break;
        }
        getline(fin,str,'\n');
        if (str.find("//$")==0)
        {
            fout <<str.substr(3,str.length())<<"\t"<<"active"<<endl;
        }
        else if (str.find("/*$")==0)
        {
            fout <<str.substr(3,str.length())<<"\t"<<"inactive"<<endl;
        }
        
        
    }
    
}

void update_code()
{
    
}

//$add 
int add(int a,int b)
{
    return a+b;
}
////$add

//$diff
int diff(int a,int b)
{
    return a-b;
}
////$diff

//$prod
int prod(int a,int b)
{
    return a*b;
}
////$prod

//$quo
int quo(int a,int b)
{
    return a/b;
}
////$quo

//$main
int main(int argc,char** argv)
{
    reset_ctr();
    //gen_log();
    log_activation();
    
}
////$main
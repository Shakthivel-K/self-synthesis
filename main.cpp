#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using namespace std;
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
    //gen_log();
    log_msg(argv[1]);
    
}
////$main
/* 
statement 1
statement 2
statement 3
*/


#include <iostream>
#include <fstream>
using namespace std;
void rewrite()
{
    string str;
    ifstream fin("sand.cpp");
    ofstream fout("sand_temp.cpp",ios::app);
    while (true)
    {
        if (fin.eof())
        {
            break;
        }
        getline(fin,str,'\n');
        if (str=="statement 2")
        {
            fout <<"statement altered"<<endl;
        }
        else 
        {
            fout <<str<<endl;
        }

    }
    remove("sand.cpp");
    rename("sand_temp.cpp","sand.cpp");
}
int main()
{
    int a=10;
    rewrite();
    

}
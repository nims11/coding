#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class person{
    public:
    string name;int id;
    friend bool operator<(person a, person b)
    {
        return a.name<b.name;
    }
    };
int main()
{
    ifstream fin("/home/nimesh/names.txt");
    person tmp;
    vector <person> names;
    fin.ignore(1);
    int count=1;
    while(getline(fin,tmp.name,'\"'))
    {
        tmp.id=count++;
        fin.ignore(2);
        names.push_back(tmp);
        //cout<<tmp<<endl;
    }
    sort(names.begin(),names.end());
    int j=1;
    long long unsigned result=0;
    for(vector<person>::iterator i=names.begin();i!=names.end();i++)
    {
        cout<<i->name<<" "<<j<<endl;
        int len=i->name.length();
        int x=0;
        for(int k=0;k<len;k++)
        x += i->name[k] - 'A' + 1;

        result+=((j++)*x);
        cout<<"->"<<x<<endl;
    }
    cout<<result<<endl;


    return 0;
}

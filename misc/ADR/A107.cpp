#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;
struct mem
{
    string name;
    vector<string> parents;
    vector<string> kids;
};
int main()
{
    map <string, mem> names;
    map <string, mem>::iterator it,it1,it2;
    mem tmp;
    tmp.name="ANN";
    tmp.kids.push_back("BILL");tmp.kids.push_back("CATHY");tmp.kids.push_back("FRANK");
    names[tmp.name]=tmp;
    tmp.name="MARTY";
    names[tmp.name]=tmp;


    tmp.kids.clear();
    tmp.name="BILL";
    tmp.parents.push_back("ANN");tmp.parents.push_back("MARTY");
    names[tmp.name]=tmp;

    tmp.name="CATHY";
    tmp.kids.push_back("MATT");tmp.kids.push_back("SALLY");
    names[tmp.name]=tmp;

    tmp.name="DON";
    tmp.parents.clear();
    names[tmp.name]=tmp;

    tmp.parents.clear();
    tmp.kids.clear();

    tmp.name="FRANK";
    tmp.parents.push_back("ANN");tmp.parents.push_back("MARTY");
    tmp.kids.push_back("SARAH");names[tmp.name]=tmp;

    tmp.name="JILL";
    tmp.parents.clear();
    tmp.parents.push_back("DEBBIE");tmp.parents.push_back("PHIL");names[tmp.name]=tmp;

    tmp.parents.clear();
    tmp.kids.clear();

    tmp.name="DEBBIE";
    tmp.kids.push_back("JILL");tmp.kids.push_back("BETTY");
    names[tmp.name]=tmp;
    tmp.name="PHIL";
    names[tmp.name]=tmp;

    tmp.parents.clear();
    tmp.kids.clear();

    tmp.name="BETTY";
    tmp.parents.push_back("DEBBIE");tmp.parents.push_back("PHIL");
    tmp.kids.push_back("MARY");tmp.kids.push_back("JANE");tmp.kids.push_back("BART");
    names[tmp.name]=tmp;

    tmp.parents.clear();
    tmp.kids.clear();

    tmp.parents.push_back("BETTY");tmp.parents.push_back("PAUL");

    tmp.name="MARY";
    names[tmp.name]=tmp;
    tmp.name="JANE";
    names[tmp.name]=tmp;
    tmp.name="BART";
    names[tmp.name]=tmp;

    tmp.parents.clear();
    tmp.kids.clear();

    tmp.name="SARAH";
    tmp.parents.push_back("FRANK");tmp.parents.push_back("JILL");
    names[tmp.name]=tmp;

    tmp.parents.clear();
    tmp.kids.clear();

    tmp.name="MATT";
    tmp.parents.push_back("CATHY");tmp.parents.push_back("DON");
    names[tmp.name]=tmp;
    tmp.name="SALLY";
    names[tmp.name]=tmp;

    int t;
    cin>>t;
    while(t--)
    {
        string str1,str2;
        cin>>str1>>str2;

        if(str1=="SIBLING")
        {
            it=names.find(str2);
            it=names.find(it->second.parents[0]);
            for(int i=0;i<it->second.kids.size();i++)
            if(str2!=it->second.kids[i])cout<<it->second.kids[i]<<" ";
            cout<<endl;
        }else
        if(str1=="PARENT")
        {
            it=names.find(str2);
            cout<<it->second.parents[0]<<" "<<it->second.parents[1]<<endl;
        }else
        if(str1=="GRANDCHILD")
        {
            it=names.find(str2);
            for(int i=0;i<it->second.kids.size();i++)
            {
                it2=names.find(it->second.kids[i]);
                mem tmp=it2->second;

                for(int j=0;i<tmp.kids.size();j++)
                cout<<tmp.kids[j]<<" ";
            }
            cout<<endl;
        }
    }
}

#include<iostream>
#include<stack>
#include<vector>
#include<utility>
using namespace std;
pair<long long,int> add(pair<long long,int> a, pair<long long,int> b)
{
//    cerr<<"operator+\n";
//    cerr<<a.first<< " "<<a.second<<"\n";
//    cerr<<b.first<< " "<<b.second<<"\n";
    return make_pair(a.first+b.first, a.second + b.second);
}
class Suminator
{
    public:
    pair<long long, int> k_pop(stack<pair<long long,int> > &foo)
    {
        if(foo.empty())
        return make_pair(0,0);

        pair<long long,int> k = foo.top();
        foo.pop();
        return k;
    }
    int findMissing(vector <int> program, int wantedResult)
    {
        stack<pair<long long, int> > foo;
        int i;
        for(i=0;program[i]!=-1;i++)
        {
            if(program[i]==0)
                foo.push(add(k_pop(foo),k_pop(foo)));
            else
                foo.push(make_pair(program[i],0));
        }
        stack<pair<long long,int> > foo2 = foo;
        int j = i;
        for(;i<program.size();i++)
        {
            if(program[i]<=0)
                foo2.push(add(k_pop(foo2), k_pop(foo2)));
            else
                foo2.push(make_pair(program[i],0));
        }
        if(foo2.top().first == wantedResult) return 0;
        i = j;
        foo.push(make_pair(0,-1));
//        cerr<<program[i]<<"---\n";
        i++;
        for(;i<program.size();i++)
        {
//            cerr<<program[i]<<"---\n";
            if(program[i]==0)
                foo.push(add(k_pop(foo),k_pop(foo)));
            else
                foo.push(make_pair(program[i],0));
        }
        pair<long long, int> aaa = foo.top();
        if(aaa.second == 0)
        {
            if(aaa.first == wantedResult)return 0;
            else return -1;
        }else
        {
            if(wantedResult - aaa.first > 0) return wantedResult - aaa.first;
            else return -1;
        }
    }
};

#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;
double getAns(int len,int typed, vector<double> &p)
{

        vector<double> prob;
        switch(typed)
        {
            case 1:
            prob.push_back(0);
            prob.push_back(1);
            break;

            case 2:
            prob.push_back(0);
            prob.push_back(1);
            prob.push_back(1);
            prob.push_back(2);
            break;

            case 3:
            prob.push_back(0);
            prob.push_back(1);
            prob.push_back(1);
            prob.push_back(1);
            prob.push_back(2);
            prob.push_back(2);
            prob.push_back(2);
            prob.push_back(3);
            break;
        }
        for(int i=0;i<prob.size();i++)
        {
            double x=1;
            for(int j=0;j<typed;j++)
            {
                if((i>>(typed-1-j))&1 == 1)
                x*=(p[j]);
                else
                x*=(1-p[j]);
            }
            prob[prob.size()-i-1]=x;
        }
        vector <int> strokes;
        strokes.push_back(len-typed+1);
        for(int i=1;i<prob.size();i++)
        strokes.push_back(2+len-typed+len);
        vector<double> expected;

        double x=0;
        for(int i=0;i<prob.size();i++)
        x+=prob[i]*strokes[i];
        expected.push_back(x);

        {
            int strokes=2+len;
            expected.push_back(strokes);
        }
        for(int i=1;i<=typed;i++)
        {
            double x=0;
            for(int j=0;j<prob.size();j++)
            {
                if(j>>i == 0)
                x+=prob[j]*(1+i+(len-(typed-i)));
                else
                x+=prob[j]*(i+(len-(typed-i))+1+len+1);
            }
            expected.push_back(x);
        }
//        for(int i=0;i<expected.size();i++)
//        cout<<expected[i]<<endl;
return *(min_element(expected.begin(),expected.end()));
}

int main()
{
    int t;
    cin>>t;
    for(int z=0;z<t;z++)
    {
        vector <double> p;
        int a,b;
        cin>>a>>b;
        for(int i=0;i<a;i++)
        {
            double x;
            cin>>x;
            p.push_back(x);
        }
        double x=getAns(b,a,p);
        cout<<"Case #"<<z+1<<": "<<fixed<<setprecision(6)<<x;
        cout<<endl;
    }
    return 0;
}

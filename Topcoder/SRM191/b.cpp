#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<utility>
#include<map>
#include<set>
#include<algorithm>

#define CLASS CuboidJoin
#define METHOD long long totalVolume(vector <int> cuboids)

using namespace std;

class CLASS
{
    public:
    class CUBOID
    {
        public:
        int x[6];
        set<int> id;

    }tmp1;
    long long getVol(long long x1,long long y1,long long z1,int x2,int y2,int z2)
    {
        long long foo = (x2-x1)*(y2-y1)*(z2-z1);
        return (foo<0?-foo:foo);
    }
    METHOD
    {
        long long ans=0;
        bool flag=true;
        int op=1;
        vector<CUBOID> cuboid;
        for(int i=0;i<cuboids.size();i+=6)
        {
            tmp1.id.clear();
            for(int j=i;j<i+6;j++)
                tmp1.x[j-i]=cuboids[j];
            tmp1.id.insert(i/6);
            cuboid.push_back(tmp1);
//            for(int j=0;j<6;j++)
//            cout<<tmp1.x[j]<<endl;
        }
        vector<CUBOID> cub_tmp,orig=cuboid;
        vector<CUBOID> cub=cuboid;
        while(flag)
        {
            cub_tmp.clear();
            flag=false;
            for(int i=0;i<cub.size();i++)
                ans+=op*getVol(cub[i].x[0],cub[i].x[1],cub[i].x[2],cub[i].x[3],cub[i].x[4],cub[i].x[5]);
//            cout<<ans<<endl;
            for(int i=0;i<orig.size();i++)
            {
                int x1=orig[i].x[0],y1=orig[i].x[1],z1=orig[i].x[2],x2=orig[i].x[3],y2=orig[i].x[4],z2=orig[i].x[5];
                for(int j=0;j<cub.size();j++)
                {
                    if(cub[j].id.find(i)==cub[j].id.end())
                    {
                        set<int>::iterator it = cub[j].id.end();
                        it--;
                        if(*it > i)continue;
                        int x3=cub[j].x[0],y3=cub[j].x[1],z3=cub[j].x[2],x4=cub[j].x[3],y4=cub[j].x[4],z4=cub[j].x[5];
                        tmp1.id=cub[j].id;
                        tmp1.id.insert(i);
                        if(max(x1, x3) < min(x2, x4) && max(y1, y3) < min(y2, y4) && max(z1, z3) < min(z2, z4))
                        {
//                            cout<<"foo"<<endl;
                            flag=true;
                            tmp1.x[0]=(max(x1,x3));
                            tmp1.x[1]=(max(y1,y3));
                            tmp1.x[2]=(max(z1,z3));
                            tmp1.x[3]=(min(x2,x4));
                            tmp1.x[4]=(min(y2,y4));
                            tmp1.x[5]=(min(z2,z4));
                            cub_tmp.push_back(tmp1);
                        }
                    }
                }
            }
            cub=cub_tmp;
            op*=-1;
        }
        return ans;
    }
};
int arr[30]={1430, -2074, -4886, 1603, 2210, -293, -771, -4027, -4386, 2688, -1097, 2217, -4731, -1105, -3863, 2774, 3908, 1286, -3494, -3104, -1166, 2423, 2895, 2156, -1155, -1433, -2990, 4130, 2500, -1061};
//int arr[30]={0, 0, 0, 5000, 5000, 5000, -5000, -5000, -5000, 0, 5000, 5000, 0, -5000, -5000, 5000, 5000, 5000, -5000, -5000, -5000, 5000, 0, 5000, -5000, 0, -5000, 5000, 5000, 5000};
//int arr[12]={0,0,0,4,4,4,0,0,0,1,1,1};
//int arr[30]={-275, -1020, -2918, 921, 2673, 3863, 497, -3921, -1831, 3059, 618, 811, -3106, -1159, -2082, 996, 3280, 3052, 4387, 1735, 244, 4469, 4692, 3278, -369, -366, 2870, 968, -91, 3502};
//int arr[30]={0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1};
//int arr[30]={-5000, -5000, -5000, 5000, 5000, 5000, -5000, -5000, -5000, 0, 5000, 5000, 0, -5000, -5000, 5000, 5000, 5000, -5000, -5000, -5000, 5000, 0, 5000, -5000, 0, -5000, 5000, 5000, 5000};
int main()
{
    CLASS test;
    vector<int> foo;
    for(int i=0;i<30;i++)
    foo.push_back(arr[i]);
//    cout<<"start"<<endl;
    cout<<test.totalVolume(foo);
}

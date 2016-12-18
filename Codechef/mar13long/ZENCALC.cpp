/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<list>
#include<cmath>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#include<utility>
#include<fstream>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)
#define VVVV
using namespace std;
ifstream fin("in");
/*
0 - !
1 - ^
2 - /
3 - *
4 - +
5 - -
10 - NA
*/
char codes[6] = {'!', '^', '/', '*', '+', '-'};

struct token
{
    int idx;
    bool oper;
    int data;
}tokens[1001];
int n;
char str[20];
int opcode[300];

int to_int(char str[])
{
    int i=0;
    bool neg = (str[0]=='-' && ++i);
    int ret = 0;
    while(str[i])
    {
        ret = ret*10 + str[i]-'0';
        i++;
    }
    return neg?(-ret):(ret);
}
int fact[65];
int pow(int r2,int n)
{
    // r2^n
    int ans=1;
    while(n>0)
    {
        if((n&1)>0)
        ans=(ans*r2);
        n>>=1;
        r2=(r2*r2);
    }
    return ans;
}
list<token*>::iterator it_tok;
struct op_node
{
    token* op_token;
    list<token*> operands;
    list<op_node*>::iterator op_list_addr;
    bool valid;
    int op1, op2;
    void set_valid()
    {
        valid = true;
        if(operands.size() == 0)
            valid = false;
        else if(operands.size() == 1 && op_token->data !=0)
            valid = false;
    }
    void do_job()
    {
        op1 = (*operands.begin())->data;
        op2 = -1;
        if(op_token->data == 0)
        {
            if(op1 > 64)(*operands.begin())->data = 0;
            else (*operands.begin())->data = fact[op1];
        }else if(op_token->data == 1)
        {
            it_tok = operands.begin();
            it_tok++;
            op2 = (*it_tok)->data;
            (*it_tok)->data = pow(op1, op2);
            operands.erase(operands.begin());
        }else if(op_token->data == 2)
        {
            it_tok = operands.begin();
            it_tok++;
            op2 = (*it_tok)->data;
            (*it_tok)->data = op1/op2;
            operands.erase(operands.begin());
        }else if(op_token->data == 3)
        {
            it_tok = operands.begin();
            it_tok++;
            op2 = (*it_tok)->data;
            (*it_tok)->data = op1*op2;
            operands.erase(operands.begin());
        }else if(op_token->data == 4)
        {
            it_tok = operands.begin();
            it_tok++;
            op2 = (*it_tok)->data;
            (*it_tok)->data = op1+op2;
            operands.erase(operands.begin());
        }else if(op_token->data == 5)
        {
            it_tok = operands.begin();
            it_tok++;
            op2 = (*it_tok)->data;
            (*it_tok)->data = op1-op2;
            operands.erase(operands.begin());
        }
    }
    friend bool operator<(const op_node &a, const op_node &b)
    {
        if(!a.valid || !b.valid)
        {
            if(a.valid == b.valid)
                return a.op_token->idx<b.op_token->idx;
            else
                return a.valid;
        }
        if(a.op_token->data == 0 || b.op_token->data == 0)
        {
            if(a.op_token->data == b.op_token->data)
                return a.op_token->idx<b.op_token->idx;
            else
                return (a.op_token->data == 0);
        }
        if(a.operands.size()>=3 || b.operands.size()>=3)
        {
            if(a.operands.size()<3 || b.operands.size()<3)
                return (a.operands.size()>=3);
            else
            {
                if(a.op_token->data == b.op_token->data)
                {
                    return a.op_token->idx < b.op_token->idx;
                }else
                    return a.op_token->data < b.op_token->data;
            }
        }
    }
}nodes[1001];
int op_count;
struct cmp{
    bool operator()(const op_node *a, const op_node *b)
    {
        return (*a)<*(b);
    }
};
set<op_node*, cmp> jobs;
set<op_node*, cmp>::iterator it_job;
vector<op_node*> stray;
list<op_node*> ops;
list<op_node*>::iterator it;

int main()
{
    long long x = -4294967281;
    cout<<(int)x<<endl;
    cin>>x;

    fact[0] = 1;
    for(int i=1;i<65;i++)
        fact[i] = fact[i-1]*i;
    opcode['^']=1;opcode['/']=2;opcode['*']=3;opcode['+']=4;opcode['-']=5;opcode['!']=0;
//    in_T
    int t;
    fin>>t;
    while(t--)
    {
        jobs.clear();
        stray.clear();
        ops.clear();
//        in_I(n);
        fin>>n;
        op_count = 0;
        for(int i=0;i<n;i++)
        {
            fin>>str;
//            in_S(str);
            if(str[1] == 0 && (str[0]<'0' || str[0]>'9'))
            {
                tokens[i].idx=i;
                tokens[i].oper = true;
                tokens[i].data = opcode[str[0]];
                op_count++;
            }else
            {
                tokens[i].idx = -1;
                tokens[i].oper = false;
                tokens[i].data = to_int(str);
            }
        }

        int cur = 0;
        nodes[cur].op_token = NULL;
        nodes[cur].operands.clear();
        if(tokens[0].oper)
            nodes[cur].op_token = &tokens[0];
        else
            nodes[cur].operands.push_back(&tokens[0]);
        for(int i=1;i<n;i++)
        {
            if(tokens[i].oper)
            {
                if(nodes[cur].op_token == NULL)
                    stray.push_back(&nodes[cur]);
                else
                {
                    ops.push_back(&nodes[cur]);
                    nodes[cur].op_list_addr = ops.end();
                    nodes[cur].op_list_addr--;
                }
                cur++;

                nodes[cur].op_token = &tokens[i];
                nodes[cur].operands.clear();
            }else
            {
                nodes[cur].operands.push_back(&tokens[i]);
            }
        }
        if(nodes[cur].op_token == NULL)
            stray.push_back(&nodes[cur]);
        else
        {
            ops.push_back(&nodes[cur]);
            nodes[cur].op_list_addr = ops.end();
            nodes[cur].op_list_addr--;
        }
        cur++;
        #ifdef VVVV
        for(it = ops.begin();it!=ops.end();it++)
        {
            cout<<(*it)->op_token->data<<" : ";
            for(it_tok = (*it)->operands.begin();it_tok != (*it)->operands.end(); it_tok++)
            {
                cout<<(*it_tok)->data<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        #endif

        for(it = ops.begin();it!=ops.end();it++)
        {
            (*it)->set_valid();
            jobs.insert(*it);
        }

        op_node *cur_job;
        bool flag = true;
        while(!jobs.empty())
        {
            it_job = jobs.begin();
            if(!(*it_job)->valid)
            {
                flag = false;
                break;
            }
            cur_job = *it_job;
            jobs.erase(it_job);
            cur_job->do_job();
            printf("%d %c %d %d %d\n", cur_job->op_token->idx+1, codes[cur_job->op_token->data], cur_job->op1, cur_job->op2, (*(cur_job->operands.begin()))->data);
            if(ops.begin() == cur_job->op_list_addr)
            {
                stray.push_back(cur_job);
                ops.erase(cur_job->op_list_addr);
            }else
            {
                it = cur_job->op_list_addr;
                it--;
                it_job = jobs.find(*it);
                jobs.erase(it_job);
                ops.erase(cur_job->op_list_addr);
                (*it)->operands.splice((*it)->operands.end(), cur_job->operands);
                (*it)->set_valid();
                jobs.insert((*it));
            }
        }
        if(!flag)
        {
            printf("NOT OK\n");
            continue;
        }

//        for(int i=0;i<n;i++)
//        {
//            if(tokens[i].oper)
//            {
//                tmp_node.next = 100;
//                tmp_node.op_token = tokens+i;
//                if(tokens[i].data == 0 && tokens[i].next && !tokens[i].next->oper)
//                    tmp_node.next = 1;
//                else if(tokens[i].next && !tokens[i].next->oper && tokens[i].next->next && !tokens[i].next->next->oper && tokens[i].next->next->next && !tokens[i].next->next->next->oper)
//                    tmp_node.next = 3;
//                else if(tokens[i].next && !tokens[i].next->oper && tokens[i].next->next && !tokens[i].next->next->oper)
//                    tmp_node.next = 2;
//
//                jobs.insert(tmp_node);
//            }
//        }
//        while(!jobs.empty())
//        {
//
//        }
    }
}

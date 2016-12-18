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
int fact[40];
int opcode[300];
int n;
int const kLowerBound = -(((long long)1)<<31);
int const kUpperBound = (((long long)1)<<31) - 1;
long long const range_size = kUpperBound - (long long)kLowerBound + 1;
int Wrap(long long kX)
{
    if (kX < kLowerBound)
        kX += range_size * ((kLowerBound - kX) / range_size + 1);

    return kLowerBound + (kX - kLowerBound) % range_size;
}
int residual_mul(int a, int b)
{
    return Wrap(a*(long long)b);
}
long long m = ((long long)1)<<32;
int residual_div(long long a, long long b)
{
    long long ret = 0;
    bool flag = false;
    long long x = 0;
    for(int i=0;i<)
}
void init()
{
    opcode['^']=1;opcode['/']=2;opcode['*']=3;opcode['+']=4;opcode['-']=5;opcode['!']=0;
    fact[0] = 1;
    for(int i=1;i<40;i++)
        fact[i] = residual_mul(fact[i-1],i);
}
/*
TO calculate the index of any token at any instance
*/
int BIT[1003];
void update(int idx, int n)
{
	while(idx<=n)
	{
		BIT[idx]--;
		idx+=(idx & -idx);
	}
}
int query(int idx)
{
	int ans=0;
	while(idx>0)
	{
		ans+=BIT[idx];
		idx -= (idx & -idx);
	}
	return ans;
}

struct operand_node{
    operand_node *prev, *next;
    int val;
    int idx;
}operands[2000];
int pow(long long r2,int n)
{
    // r2^n
    long long ans=1;
    while(n>0)
    {
        if((n&1)>0)
        ans=residual_mul(ans, r2);
        n>>=1;
        r2=residual_mul(r2, r2);
    }
    return ans;
}
struct operator_node{
    operator_node *prev, *next;
    int type;
    pair<int, int> comp1, comp2, comp3, comp4;
    operand_node *operands_head ,*operands_tail;
    int operand_size;
    bool valid;
    int idx;
    bool do_job()
    {
        return 1;
        int op1, op2, res;
        switch(type)
        {
            case 0:
                op1 = operands_head->val;
                op2 = -1;
                if(op1>=40 || op1<=40)
                {
                    res = 0;
                }else
                {
                    if(op1>=0)
                        res = fact[op1];
                    else
                        res = fact[op1] * (op1%2?-1:1);
                }
                operands_head->val = res;
            break;
            case 1:
                op1 = operands_head->val;
                update(operands_head->idx, n);
                operands_head = operands_head->next;
                operand_size--;
                op2 = operands_head->val;
                res = pow(op1, op2);
                operands_head->val = res;
            break;
            case 2:
                op1 = operands_head->val;
                update(operands_head->idx, n);
                operands_head = operands_head->next;
                operand_size--;
                op2 = operands_head->val;
                res = residual_div(op1, op2);
                operands_head->val = res;
            break;
            case 3:
                op1 = operands_head->val;
                update(operands_head->idx, n);
                operands_head = operands_head->next;
                operand_size--;
                op2 = operands_head->val;
                res = residual_mul(op1, op2);
                operands_head->val = res;
            break;
            case 4:
                op1 = operands_head->val;
                update(operands_head->idx, n);
                operands_head = operands_head->next;
                operand_size--;
                op2 = operands_head->val;
                res = residual_add(op1, op2);
                operands_head->val = res;
            break;
            case 5:
                op1 = operands_head->val;
                update(operands_head->idx, n);
                operands_head = operands_head->next;
                operand_size--;
                op2 = operands_head->val;
                res = residual_sub(op1, op2);
                operands_head->val = res;
            break;
        }
        printf("%d %c %d %d %d\n", query(idx), codes[type], op1, op2, res);
    }
    void debug()
    {
        cout<<"DEBUG: ";
        cout<<codes[type]<<" ("<<operand_size<<") ";
        operand_node *x = operands_head;
        while(x!=NULL)
        {
            cout<<x->val<<" ";
            x = x->next;
        }
        if(valid)
            cout<<"Valid";
        else
            cout<<"Invalid";
        cout<<endl;
    }
    void set_valid()
    {
        valid = true;
        if(operand_size == 0)
            valid = false;
        else if(operand_size == 1 && type !=0)
            valid = false;
        comp1.first = valid, comp1.second = idx;
        comp2.first = (type == 0), comp2.second = idx;
        comp3.first = (operand_size >=3 ), comp3.second = idx;
        comp4.first = (operand_size<3), comp4.second = idx;
    }
    friend bool operator<(const operator_node &a, const operator_node &b)
    {
//        if(a.comp1!=b.comp1)
//            return a.comp1<b.comp1;
//        if(a.comp2!=b.comp2)
//            return a.comp2<b.comp2;
//        if(a.comp3!=b.comp3)
//            return a.comp3<b.comp3;
//        if(a.comp4!=b.comp4)
//            return a.comp4<b.comp4;
        if(!a.valid || !b.valid)
        {
            if(a.valid == b.valid)
                return a.idx<b.idx;
            else
                return a.valid;
        }
        if(a.type == 0 || b.type == 0)
        {
            if(a.type == b.type)
                return a.idx<b.idx;
            else
                return (a.type == 0);
        }
        if(a.operand_size>=3 || b.operand_size>=3)
        {
            if(a.operand_size<3 || b.operand_size<3)
                return (a.operand_size>=3);
            else
            {
                if(a.type == b.type)
                    return a.idx < b.idx;
                else
                    return a.type < b.type;
            }
        }
        return a.idx<b.idx;
    }
}operators[2000];
char str[100];
struct cmp{
    bool operator()(const operator_node *a, const operator_node *b)
    {
        return (*a)<(*b);
    }
};
// implement separate job queues
set<operator_node*, cmp> jobs;
set<operator_node*, cmp>::iterator it_job;
int main()
{
    init();
    #ifndef VVVV
    in_T
    #endif
    #ifdef VVVV
    int t;fin>>t;while(t--)
    #endif // VVVV
    {
        int operator_cnt = 0;
        int operand_cnt = 0;
        jobs.clear();
        operand_node *stray_head = NULL, *stray_tail = NULL;
        operator_node *head = NULL, *tail = NULL;
        #ifndef VVVV
        in_I(n);
        #endif
        #ifdef VVVV
        fin>>n;
        #endif // VVVV
        for(int i=1;i<=n;i++)
            BIT[i] = 1;
        for(int i=0;i<n;i++)
        {
            #ifndef VVVV
            in_S(str);
            #endif
            #ifdef VVVV
            fin>>str;
            #endif // VVVV
            if(str[1] == 0 && (str[0]<'0' || str[0]>'9'))
            {
                operators[operator_cnt].idx = i+1;
                operators[operator_cnt].type = opcode[str[0]];
                operators[operator_cnt].operands_head = operators[operator_cnt].operands_tail = NULL;
                operators[operator_cnt].operand_size = 0;
                if(head == NULL)
                {
                    tail = head = &operators[operator_cnt];
                    operators[operator_cnt].prev = NULL;
                    operators[operator_cnt].next = NULL;
                }else
                {
                    operators[operator_cnt].prev = tail;
                    tail->next = &operators[operator_cnt];
                    tail = &operators[operator_cnt];
                    operators[operator_cnt].next = NULL;
                }
                operator_cnt++;
            }else
            {
                operands[operand_cnt].idx = i;
                operands[operand_cnt].val = atoi(str);
                if(operator_cnt == 0)
                {
                    if(stray_head == NULL)
                    {
                        stray_head = stray_tail = &operands[operand_cnt];
                        operands[operand_cnt].prev = operands[operand_cnt].next = NULL;
                    }else
                    {
                        operands[operand_cnt].prev = stray_tail;
                        stray_tail->next = &operands[operand_cnt];
                        stray_tail = &operands[operand_cnt];
                        operands[operand_cnt].next = NULL;
                    }
                }else
                {
                    if(operators[operator_cnt-1].operands_head == NULL)
                    {
                        operators[operator_cnt-1].operands_head = operators[operator_cnt-1].operands_tail = &operands[operand_cnt];
                        operands[operand_cnt].prev = operands[operand_cnt].next = NULL;
                    }else
                    {
                        operands[operand_cnt].prev = operators[operand_cnt-1].operands_tail;
                        operators[operator_cnt-1].operands_tail->next = &operands[operand_cnt];
                        operators[operator_cnt-1].operands_tail = &operands[operand_cnt];
                        operands[operand_cnt].next = NULL;
                    }
                    operators[operator_cnt-1].operand_size++;
                }
                operand_cnt++;
            }
        }
        for(int i=0;i<operator_cnt;i++)
            operators[i].set_valid();
        #ifdef VVVV
        cout<<"testing link list formation :\n"<<endl;
        cout<<"Strays: ";
        operand_node *x = stray_head;
        while(x!=NULL)
        {
            cout<<x->val<<" ";
            x = x->next;
        }
        cout<<endl;
        cout<<"Main"<<endl;
        operator_node *y = head;
        while(y!=NULL)
        {
            cout<<codes[y->type]<<" ("<<y->operand_size<<") ";
            x = y->operands_head;
            while(x!=NULL)
            {
                cout<<x->val<<" ";
                x = x->next;
            }
            if(y->valid)
                cout<<"Valid";
            else
                cout<<"Invalid";
            cout<<endl;
            y = y->next;
        }
        #endif // VVVV

        for(int i=0;i<operator_cnt;i++)
            jobs.insert(&operators[i]);
        operator_node *cur_job, *prev_job;
        bool flag = true;
        while(!jobs.empty())
        {
            it_job = jobs.begin();
            cur_job = *it_job;
            cur_job->debug();
            jobs.erase(it_job);
            if(!cur_job->valid)
            {
                flag = false;
                break;
            }
//            if(!cur_job->do_job())
//            {
//                flag = false;
//                break;
//            }
            if(head == cur_job)
            {
                if(stray_head == NULL)
                {
                    stray_head = cur_job->operands_head;
                    stray_tail = cur_job->operands_tail;
                }else
                {
                    stray_tail->next = cur_job->operands_head;
                    cur_job->operands_head->prev =stray_tail;
                    stray_tail = cur_job->operands_tail;
                }
                head = cur_job->next;
                if(head == NULL)
                    tail = NULL;
                else
                {
                    jobs.erase(jobs.find(head));
                    head->prev = NULL;
                    jobs.insert(head);
                }
            }else
            {
                prev_job = cur_job->prev;
                it_job = jobs.find(prev_job);
                jobs.erase(it_job);
                if(prev_job->operands_head == NULL)
                {
                    prev_job->operands_head = cur_job->operands_head;
                    prev_job->operands_tail = cur_job->operands_tail;
                    prev_job->operand_size = cur_job->operand_size;
                }else
                {
                    prev_job->operand_size+=cur_job->operand_size;
                    prev_job->operands_tail->next = cur_job->operands_head;
                    cur_job->operands_head->prev = prev_job->operands_tail;
                    prev_job->operands_tail = cur_job->operands_tail;
                }
                if(cur_job->next != NULL)
                {
//                    cout<<" ";cur_job->next->debug();
//                    for(it_job = jobs.begin();it_job!=jobs.end();it_job++)
//                        (*it_job)->debug();
//                    if(jobs.find(cur_job->next) == jobs.end())
//                        cout<<"BOO!"<<endl;
                    jobs.erase(jobs.find(cur_job->next));
                    cur_job->next->prev = prev_job;
                    jobs.insert(cur_job->next);
                }
                prev_job->next = cur_job->next;
                prev_job->set_valid();
                jobs.insert(prev_job);
            }
        }
        if(!flag)
        {
            printf("NOT OK\n");
        }
    }
}

/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<cstring>
#include<cmath>
#include<stack>
#include<set>
#include<utility>
#define in_T int t;for(scanf("%d\n",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)


#define IS_DIGIT(a) (a>='0' && a<='9')
#define IS_UPPER(a) (a>='A' && a<='Z')
#define VALID_TO(a) (a->str.size() == 1 && a->times.first == 1 && a->times.second == 1)
#define RAISE {ret->error = 1; return ret;}
using namespace std;
char F[1005], ID[2005];
string kws[] = {"", "to", "or", "times", "optional", "digit", "letter", "exactly", "upto", "digits", "letters"};
int kws_map[200][200];
int Q;
struct RegExNode
{
    // Type
    // 0 - String
    // 1 - AND
    // 2 - OR
    // 3 - range

    int type;Sir Alex
    string str;
    vector<RegExNode*> options;
    int error;
    pair<int, int> times;
    pair<char, char> range;
    void clear()
    {
        error = 0;
        str.clear();
        options.clear();
        times.first = times.second = 1;
    }
    int get_INT()
    {
        int ret = 0;
        for(int i=0;i<str.size();i++)
        {
            if(!IS_DIGIT(str[i]))
                return -1;
            ret = ret*10 + (str[i]-'0');
        }
        return ret;
    }
    friend ostream& operator<<(ostream &os, const RegExNode &a)
    {
        os<<"Type: "<<a.type<<endl;
        os<<"Str: "<<a.str<<endl;
        os<<"Times: "<<a.times.first<<" "<<a.times.second<<endl;
        os<<"Range: "<<a.range.first<<" "<<a.range.second<<endl;
        os<<"Options.size: "<<a.options.size()<<endl;
        return os;
    }
}digits[10], letters[26], nodes[500000];
int cnt;
char* nxt_kw(char *G)
{

    while(*G != ' ' && *G != '(' && *G != ')')G++;
    return G;
}
int id_kw(char *F, char *G)
{

    int x = kws_map[*F][*(G-1)];
    if(x == 0)
        return 0;
    if(kws[x].size() != int(G-F))
        return 0;
    for(int i=0;i<kws[x].size();i++,F++)
        if(*F != kws[x][i])
        return 0;
    return x;
}
bool valid_str(char *F, char *G)
{
    while(F!=G)
    {
        if(*F != '-' && (*F<'A' || *F>'Z') && (*F<'0' || *F>'9'))
            return false;
        F++;
    }
    return true;
}
RegExNode* compile_F(char *&F)
{
    nodes[cnt].clear();
    RegExNode* ret = &nodes[cnt++], *tmp, *last_OR, *pre, *nxt;
    ret->type = 1;
    int x;
    bool OR_FLAG = false;
    while(1)
    {
        if(*F == '(')
        {
            RegExNode *tmp = compile_F(++F);
            if(tmp->error || tmp->options.size() == 0)
                RAISE
            else
            {
                if(!OR_FLAG)
                    ret->options.push_back(tmp);
                else
                    last_OR->options.push_back(tmp);
            }
            F++;
        }else if(*F == ')')
        {
            break;
        }else if(*F == ' ')
            F++;
        else if(*F == 0)
            break;
        else
        {
            char *G = nxt_kw(F);
            int kw_type = id_kw(F, G);
//            cout<<kw_type<<" "<<string(F, G)<<endl;
            switch(kw_type)
            {
            case 0:
                if(!valid_str(F, G))
                    RAISE
                nodes[cnt].clear();
                nodes[cnt].type = 0;
                nodes[cnt].str = string(F, G);
                if(!OR_FLAG)
                    ret->options.push_back(&nodes[cnt]);
                else
                    last_OR->options.push_back(&nodes[cnt]), OR_FLAG = false;
                cnt++;
                F = G;
                break;
            case 1:
                // HANDLE OR PRECEDENCE!!!
                if(ret->options.size() == 0)
                    RAISE
                pre = ret->options.back();
                nxt = NULL;
                F = G;
                while(*F == ' ')F++;
                if(*F == '(' || *F == ')')
                    RAISE
                G = nxt_kw(F);
                nodes[cnt].clear();
                nxt = &nodes[cnt++];
                nxt->type = id_kw(F, G);
                if(nxt->type != 0)
                    RAISE
                nxt->str = string(F, G);
                if(pre->type == 0)
                {}
                else if(pre->type == 2)
                {
                    OR_FLAG = false;
                    if(pre->options.size() == 0)
                        RAISE
                    pre = pre->options.back();
                    if(pre->type != 0)
                        RAISE
                }else
                    RAISE

                if(VALID_TO(pre) && VALID_TO(nxt) && ((IS_DIGIT(pre->str[0]) && IS_DIGIT(nxt->str[0])) || (IS_UPPER(pre->str[0]) && IS_UPPER(nxt->str[0]))) && pre->str[0]<=nxt->str[0])
                {}
                else
                    RAISE
                pre->type = 3;
                pre->range.first = pre->str[0];
                pre->range.second = nxt->str[0];
                F = G;
                break;
            case 2:
                if(OR_FLAG)
                    RAISE
                OR_FLAG = true;
                if(ret->options.size() == 0)
                    RAISE
                pre = ret->options.back();
                if(pre->type != 2)
                {
                    nodes[cnt].clear();
                    tmp = &nodes[cnt++];
                    tmp->type = 2;
                    tmp->options.push_back(pre);
                    ret->options[ret->options.size()-1] = tmp;
                }
                last_OR = ret->options.back();
                F = G;
                break;
            case 3:
                if(OR_FLAG)
                    RAISE
                if(ret->options.size()<2)
                    RAISE
                pre = ret->options.back();
                ret->options.pop_back();
                if(pre->type != 0)
                    RAISE
                x = pre->get_INT();
                if(x<2 || x>12)
                    RAISE
                pre = ret->options.back();
                if(pre->type == 2)
                {
                    if(pre->options.size() == 0)
                        RAISE
                    pre = pre->options.back();
                }
                pre->times.first = pre->times.second = x;
                F = G;
                break;
            case 4:
                if(OR_FLAG)
                    RAISE
                if(ret->options.size() == 0)
                    RAISE
                ret->options.back()->times.first = 0;
                F = G;
                break;
            case 5:
                nodes[cnt].clear();
                pre = &nodes[cnt++];
                pre->type = 3;
                pre->range.first = '0';
                pre->range.second = '9';
                if(!OR_FLAG)
                    ret->options.push_back(pre);
                else
                    last_OR->options.push_back(pre), OR_FLAG = false;
                F = G;
                break;
            case 6:
                nodes[cnt].clear();
                pre = &nodes[cnt++];
                pre->type = 3;
                pre->range.first = 'A';
                pre->range.second = 'Z';
                if(!OR_FLAG)
                    ret->options.push_back(pre);
                else
                    last_OR->options.push_back(pre), OR_FLAG = false;
                F = G;
                break;
            case 7:
                F = G;
                while(*F == ' ')F++;
                if(*F == '(' || *F == ')')
                    RAISE
                G = nxt_kw(F);
                nodes[cnt].clear();
                pre = &nodes[cnt++];
                pre->type = id_kw(F, G);
                if(pre->type != 0)
                    RAISE
                pre->str = string(F, G);
                x = pre->get_INT();
                if(x<2 || x>12)
                    RAISE
                F = G;
                while(*F == ' ')F++;
                if(*F == '(' || *F == ')')
                    RAISE
                G = nxt_kw(F);
                nodes[cnt].clear();
                nxt = &nodes[cnt++];
                nxt->type = id_kw(F, G);
                if(nxt->type == 9)
                {
                    pre->type = 3;
                    pre->range.first = '0';
                    pre->range.second = '9';
                    pre->times.first = pre->times.second = x;
                }else if(nxt->type == 10)
                {
                    pre->type = 3;
                    pre->range.first = 'A';
                    pre->range.second = 'Z';
                    pre->times.first = pre->times.second = x;
                }else
                    RAISE

                if(!OR_FLAG)
                    ret->options.push_back(pre);
                else
                    last_OR->options.push_back(pre), OR_FLAG = false;
                F = G;
                break;
            case 8:
                F = G;
                while(*F == ' ')F++;
                if(*F == '(' || *F == ')')
                    RAISE
                G = nxt_kw(F);
                nodes[cnt].clear();
                pre = &nodes[cnt++];
                pre->type = id_kw(F, G);
                if(pre->type != 0)
                    RAISE
                pre->str = string(F, G);
                x = pre->get_INT();
                if(x<2 || x>12)
                    RAISE
                F = G;
                while(*F == ' ')F++;
                if(*F == '(' || *F == ')')
                    RAISE
                G = nxt_kw(F);
                nodes[cnt].clear();
                nxt = &nodes[cnt++];
                nxt->type = id_kw(F, G);
                if(nxt->type == 9)
                {
                    pre->type = 3;
                    pre->range.first = '0';
                    pre->range.second = '9';
                    pre->times.first = 0;
                    pre->times.second = x;
                }else if(nxt->type == 10)
                {
                    pre->type = 3;
                    pre->range.first = 'A';
                    pre->range.second = 'Z';
                    pre->times.first = 0;
                    pre->times.second = x;
                }else
                    RAISE

                if(!OR_FLAG)
                    ret->options.push_back(pre);
                else
                    last_OR->options.push_back(pre), OR_FLAG = false;
                F = G;
                break;
            default:
                RAISE
                break;
            }
        }
    }
    if(OR_FLAG)
        RAISE
    return ret;
}
int traverse(RegExNode* curr)
{
//    cout<<*curr<<endl;
    int ret = 0;
    switch(curr->type)
    {
    case 0:
        ret = curr->str.length();
        break;
    case 1:
        for(int i=0;i<curr->options.size();i++)
            ret += traverse(curr->options[i]);
        break;
    case 2:
        for(int i=0;i<curr->options.size();i++)
            ret = max(ret, traverse(curr->options[i]));
        break;
    case 3:
        ret = 1;
        break;
    }
    return ret*curr->times.second;
}
vector<char*> prob;
void match(RegExNode* curr)
{
    switch(curr->type)
    {
    case 0:
        for(int i=0;i<prob.size();i++)
            if(prob[i] != NULL)
            {
                int j = 0;
                while(j<curr->str.size() && *prob[i] == )
            }
        break;
    }
}
int main()
{
    for(int i=0;i<10;i++)
        digits[i].type = 0, digits[i].str.push_back('0'+i);
    for(char ch = 'A'; ch<='Z';ch++)
        letters[ch-'A'].type = 0, letters[ch-'A'].str.push_back(ch);
    for(int i=1;i<=10;i++)
        kws_map[kws[i][0]][kws[i][kws[i].size()-1]] = i;

    in_T
    {
        cin.getline(F+1, 3000);
        cnt = 0;
        F[0] = '(';
        int len = strlen(F);
        F[len+1] = 0;
        F[len] = ')';
        cout<<F<<endl;
        char *tmp = F;
        RegExNode *result = compile_F(tmp);
        if(result->error)
            printf("Format does not conform\n");
        if(traverse(result)>2000)
            printf("Matches too long ID\n");
        in_I(Q);
        while(Q--)
        {
            prob.clear();
            in_S(F);
            prob.push_back(F);
            match(result, F);
            if(!prob.empty())
                printf("Valid-ID\n");
            else
                printf("Invalid-ID\n");
        }
        newline;
    }
}

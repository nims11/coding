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
#include<cmath>
#include<stack>
#include<utility>
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

using namespace std;
class node
{
public:
    int data;
    node *left,*right,*parent;
    node(int val, node *l, node *r, node *par):data(val),left(l),right(r),parent(par),size(0){}
    int size;
};
class BST
{
public:
    node *root;
    node *insert(int value);
    void remove(int value);
    node *find(int value, bool getClosest);
    node *successor(node *n);
    void inorder(node *x);
    BST():root(NULL){}
};
node *BST::insert(int value)
{
    node *ret;
    if(root == NULL)
    {
        root = new node(value,NULL,NULL,NULL);
        ret = root;
    }else
    {
        node *parent, *child = root;
        while(child!=NULL)
        {
            parent = child;
            if(child->data > value)
                child = child->left;
            else if(child->data < value)
                child = child->right;
            else
                return child;
        }
        if(parent->data > value)
        {
            parent->left = new node(value, NULL, NULL, parent);
            ret = parent->left;
        }else
        {
            parent->right = new node(value, NULL, NULL, parent);
            ret = parent->right;
        }
        parent = ret->parent;
        while(parent!=NULL)
        {
            parent->size++;
            parent = parent->parent;
        }
    }
    return ret;
}
node *BST::find(int value, bool getClosest = false)
{
    if(root == NULL)
        return NULL;
    else
    {
        node *parent, *child = root;
        while(child!=NULL)
        {
            parent = child;
            if(child->data > value)
                child = child->left;
            else if(child->data < value)
                child = child->right;
            else
                return child;
        }
        return getClosest?parent:NULL;
    }
}
node *BST::successor(node *n)
{
    node *parent, *child = n->right;
    while(child != NULL)
    {
        parent = child;
        child = child->left;
    }
    return parent;
}
void BST::remove(int value)
{
    node *x = find(value);
    if(x == NULL)
        return;
    if(x->left == NULL && x->right == NULL)
    {
        if(root == x)
            root = NULL;
        else if(x == x->parent->left)
            x->parent->left = NULL;
        else
            x->parent->right = NULL;
        node *tmp = x->parent;
        while(tmp != NULL)
        {
            tmp->size--;
            tmp = tmp->parent;
        }
        delete x;
    }else if(x->left != NULL && x->right == NULL)
    {
        if(root == x)
        {
            root = x->left;
            x->left->parent = NULL;
        }
        else if(x == x->parent->left)
        {
            x->parent->left = x->left;
            x->left->parent = x->parent;
        }
        else
        {
            x->parent->right = x->left;
            x->left->parent = x->parent;
        }
        node *tmp = x->parent;
        while(tmp != NULL)
        {
            tmp->size--;
            tmp = tmp->parent;
        }
        delete x;
    }else if(x->left == NULL && x->right != NULL)
    {
        if(root == x)
        {
            root = x->right;
            x->right->parent = NULL;
        }
        else if(x == x->parent->left)
        {
            x->parent->left = x->right;
            x->right->parent = x->parent;
        }
        else
        {
            x->parent->right = x->right;
            x->right->parent = x->parent;
        }
        node *tmp = x->parent;
        while(tmp != NULL)
        {
            tmp->size--;
            tmp = tmp->parent;
        }
        delete x;
    }else if(x->left != NULL && x->right != NULL)
    {
        node *s = successor(x);
        node *tmp = s->parent;
        while(tmp!=NULL)
        {
            tmp->size--;
            tmp = tmp->parent;
        }
        s->size = x->size;
        if(x == root)
        {
            if(s == x->right)
            {
                s->parent = NULL;
                x->left->parent = s;
                s->left = x->left;
                root = s;
            }else
            {
                if(s->right == NULL)
                    s->parent->left = NULL;
                else
                {
                    s->parent->left = s->right;
                    s->right->parent = s->parent;
                }
                s->parent = NULL;
                s->left = x->left;
                s->right = x->right;
                x->right->parent = s;
                x->left->parent = s;
                root = x;
            }
        }
        else
        {
            if(s == x->right)
            {
                s->parent = x->parent;
                x->left->parent = s;
                s->left = x->left;
                if(x == x->parent->left)
                    x->parent->left = s;
                else
                    x->parent->right = s;
            }else
            {
                if(s->right == NULL)
                    s->parent->left = NULL;
                else
                {
                    s->parent->left = s->right;
                    s->right->parent = s->parent;
                }
                s->parent = x->parent;
                if(x == x->parent->left)
                    x->parent->left = s;
                else
                    x->parent->right = s;
                s->left = x->left;
                s->right = x->right;
                x->right->parent = s;
                x->left->parent = s;
            }
        }
        delete x;
    }
}
void BST::inorder(node *x)
{
    if(x!=NULL)
    {
        inorder(x->left);
        cout<<x->data<<endl;
        inorder(x->right);
    }
}
void find_kth(node *x, int k)
{
//    if(x == NULL)
//    {
//        printf("invalid\n");
//        return;
//    }
    int left_size = (x->left == NULL)?0:(1+x->left->size);
    int right_size = (x->right == NULL)?0:(1+x->right->size);
    if(left_size>=k)
    {
        find_kth(x->left, k);
    }else if(left_size+1 == k)
    {
        printf("%d\n", x->data);
    }else
        find_kth(x->right, k - left_size - 1);
}
int find_c(node *x, int val)
{
    if(x==NULL)return 0;
    if(x->data==val)
    {
        return (x->left == NULL? 0:(1+x->left->size));
    }else if(x->data < val)
    {
        return 1+(x->left == NULL? 0:(1+x->left->size)) + find_c(x->right, val);
    }else
    {
        return find_c(x->left, val);
    }
}
char s[3];
int p;
int main()
{
    int Q;
    in_I(Q);
    BST foo;
    while(Q--)
    {
        scanf("%s %d", s, &p);
        if(s[0] == 'I')
        {
            foo.insert(p);
        }else if(s[0] == 'D')
        {
            foo.remove(p);
        }else if(s[0] == 'K')
        {
            if(foo.root == NULL || p>foo.root->size+1)
                printf("invalid\n");
            else
            find_kth(foo.root, p);
        }else
        {
            printf("%d\n", find_c(foo.root, p));
        }
//        foo.inorder(foo.root);
    }
}

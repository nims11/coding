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
    node(int val, node *l, node *r, node *par):data(val),left(l),right(r),parent(par){}
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
            parent->left = new node(value, NULL, NULL, NULL);
            ret = parent->left;
        }else
        {
            parent->right = new node(value, NULL, NULL, NULL);
            ret = parent->right;
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
        delete x;
    }else
    {
        node *s = successor(x);
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
int main()
{
    BST foo;
    foo.insert(9);
    foo.insert(1);
    foo.insert(12);
    foo.insert(4);
    foo.insert(-2);
    foo.insert(4);
    foo.insert(-10);
    foo.inorder(foo.root);
}

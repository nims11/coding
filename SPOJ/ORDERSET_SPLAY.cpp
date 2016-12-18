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
class BST_splay
{
public:
    node *root;
    node *insert(int value);
    void remove(int value);
    node *find(int value, bool getClosest);
    node *successor(node *n);
    void inorder(node *x);
    BST_splay():root(NULL){}
    void splay(node *x);
    void rotate_left(node *x);
    void rotate_right(node *x);
};
void BST_splay::rotate_left(node *x)
{
    x->parent->right = x->left;
    if(x->left != NULL)
        x->left->parent = x->parent;
    x->left = x->parent;
    if(x->parent->parent!=NULL)
    {
        if(x->parent == x->parent->parent->left)
            x->parent->parent->left = x;
        else
            x->parent->parent->right = x;
    }
    node *tmp = x->parent;
    x->parent->size = (x->parent->left == NULL?0:(1+x->parent->left->size)) + (x->parent->right == NULL?0:(1+x->parent->right->size));
    x->parent = x->parent->parent;
    tmp->parent = x;
    x->size = (x->left == NULL?0:(1+x->left->size)) + (x->right == NULL?0:(1+x->right->size));
    if(x->parent == NULL)
        root = x;
}
void BST_splay::rotate_right(node *x)
{
    x->parent->left = x->right;
    if(x->right != NULL)
        x->right->parent = x->parent;
    x->right = x->parent;
    if(x->parent->parent!=NULL)
    {
        if(x->parent == x->parent->parent->left)
            x->parent->parent->left = x;
        else
            x->parent->parent->right = x;
    }
    node *tmp = x->parent;
    x->parent->size = (x->parent->left == NULL?0:(1+x->parent->left->size)) + (x->parent->right == NULL?0:(1+x->parent->right->size));
    x->parent = x->parent->parent;
    tmp->parent = x;
    x->size = (x->left == NULL?0:(1+x->left->size)) + (x->right == NULL?0:(1+x->right->size));
    if(x->parent == NULL)
        root = x;
}
void BST_splay::splay(node *x)
{
    if(x == root)
        return;
    if(x == NULL)
        return;
    if(x->parent == root)   //zig
    {
        if(x == x->parent->left)
            rotate_right(x);
        else
            rotate_left(x);
    }else if(x == x->parent->left && x->parent == x->parent->parent->right)  //zig-zag
    {
        rotate_right(x);
        rotate_left(x);
    }else if(x == x->parent->right && x->parent == x->parent->parent->left)  //zig-zag
    {
        rotate_left(x);
        rotate_right(x);
    }else if(x == x->parent->right && x->parent == x->parent->parent->right) //zig-zig
    {
        rotate_left(x->parent);
        rotate_left(x);
    }else if(x == x->parent->left && x->parent == x->parent->parent->left)  //zig-zig
    {
        rotate_right(x->parent);
        rotate_right(x);
    }
    splay(x);
}
node *BST_splay::insert(int value)
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
            {
                splay(child);
                return child;
            }
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
    splay(ret);
    return ret;
}
node *BST_splay::find(int value, bool getClosest = false)
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
node *BST_splay::successor(node *n)
{
    node *parent, *child = n->right;
    while(child != NULL)
    {
        parent = child;
        child = child->left;
    }
    return parent;
}
void BST_splay::remove(int value)
{
    if(root == NULL)
        return;
    node *x = find(value, true);
    if(x->data != value)
    {
        splay(x);
        return;
    }
    node *p = x->parent;
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
        p = tmp;
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
                p = s;
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
                p = s;
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
    if(p!=NULL)
        splay(p);
}
void BST_splay::inorder(node *x)
{
    if(x!=NULL)
    {
        inorder(x->left);
        cout<<x->data<<endl;
        inorder(x->right);
    }
}
BST_splay foo;
void find_kth(node *x, int k)
{
    while(1)
    {
        int q = 1+(x->left==NULL?0:(1+x->left->size));
        if(k==q)
            break;
        if(q<k)
        {
            if(x->right == NULL)
                return;
            k-=q;x = x->right;
        }else
        {
            if(x->left == NULL)
                return;
            x = x->left;
        }
    }
    foo.splay(x);printf("%d\n",x->data);
}
int find_c(node *x, int val)
{
    if(x==NULL)return 0;
    int ans = 0;
    while(1)
    {
        if(x->data<val)
        {
            ans += 1+(x->left == NULL?0:(1+x->left->size));
            if(x->right != NULL)
                x = x->right;
            else break;
        }else if(x->data == val)
        {
            ans += x->left == NULL? 0:(1+x->left->size);
            break;
        }else
        {
            if(x->left != NULL)
            {
                x = x->left;
            }else break;
        }
    }
    foo.splay(x);
    return ans;
}
char s[3];
int p;
int main()
{
    int Q;
    in_I(Q);
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

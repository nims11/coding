#include<iostream>
//TODO MIN_HEAP
template<class T, size_t N=100>
class TREE
{
    size_t size;
    size_t capacity;
    size_t heap_size;
    T *a;
    int PARENT(int i){return i>>1;}
    int LEFT(int i){return i<<1;}
    int RIGHT(int i){return (i<<1)+1;}

    public:
    TREE(){size=0;capacity=N;a=new T[capacity];};
    T & operator[](int i){return a[i];}
    T* getArr(){return a;}
    void getInput();
    void make_heap();
    void max_heapify(int i);
    void heap_sort();
    void show(){for(int i=0;i<size;i++)std::cout<<(*this)[i]<<' ';std::cout<<"\n";}
};
template<class T, size_t N>
void TREE<T,N>::getInput()
{
    std::cout<<"Enter no. of elts : ";std::cin>>size;
    if(size>capacity){size=0;std::cout<<"Size>capacity\n";return;}

    std::cout<<"Enter elts: ";
    for(int i=0;i<size;i++)
    std::cin>>a[i];
}
template<class T, size_t N>
void TREE<T,N>::make_heap()
{
    heap_size=size;
    for(int i=(size-1)/2;i>=0;i--)
    {
        max_heapify(i);
    }
}
template<class T, size_t N>
void TREE<T,N>::max_heapify(int i)
{
    int l=LEFT(i),r=RIGHT(i);
    int max;
    if(l<heap_size && a[l]>a[i])
    max=l;
    else max=i;
    if(r<heap_size && a[r]>a[max])
    max=r;
    if(max!=i)
    {
        T tmp=a[i];
        a[i]=a[max];
        a[max]=tmp;
        max_heapify(max);
    }
}
template<class T, size_t N>
void TREE<T,N>::heap_sort()
{
    make_heap();
    for(int i=(size-1);i>0;i--)
    {
        T tmp=a[0];
        a[0]=a[i];
        a[i]=tmp;
        heap_size--;
        max_heapify(0);
    }
}
int main()
{
    TREE<std::string,100> heap;
    heap.getInput();
    heap.heap_sort();
    heap.show();
}


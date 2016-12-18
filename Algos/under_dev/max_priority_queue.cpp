#include<iostream>
//TODO input
template<class T, size_t N=100>
class HEAP
{
    size_t capacity;
    size_t heap_size;
    T *a;
    int PARENT(int i){return i>>1;}
    int LEFT(int i){return i<<1;}
    int RIGHT(int i){return (i<<1)+1;}

    public:
    HEAP(){heap_size=0;capacity=N;a=new T[capacity];};
    T & operator[](int i){return a[i];}
    void make_heap();
    void max_heapify(int i);
    T heap_max(){return a[0];}
    T extract_max();
    void inc_key(int i,T key);
    void heap_insert(T key);
    void show(){for(int i=0;i<heap_size;i++)std::cout<<(*this)[i]<<' ';std::cout<<"\n";}
};
template<class T, size_t N>
T HEAP<T,N>::extract_max()
{
    if(heap_size==0){std::cout<<"heap underflow";return NULL;}
    T max=a[0];
    a[0]=a[heap_size-1];
    heap_size--;
    max_heapify(0);
}
template<class T, size_t N>
void HEAP<T,N>::make_heap()
{
    for(int i=(heap_size-1)/2;i>=0;i--)
    {
        max_heapify(i);
    }
}
template<class T, size_t N>
void HEAP<T,N>::max_heapify(int i)
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
void HEAP<T,N>::inc_key(int i,T key)
{
    if(key<a[i]){std::cout<<"New key smaller!!\n";return;}
    a[i]=key;
    while(i>0 && a[PARENT(i)]<a[i])
    {
        T tmp=a[i];
        a[i]=a[PARENT(i)];
        a[PARENT(i)]=a[i];
    }
}
template<class T, size_t N>
void HEAP::heap_insert(T key)
{


}
int main()
{
    HEAP<int,100> heap;
    heap.show();
}

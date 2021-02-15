#include <stdlib.h>
template <class T>
class vector
{
private:
    T * v;
    int s;
    int c;

public:
    vector()
    {
        s = 0;
        v = NULL;
    }

    vector(int capacity)
    {
        s = 0;
        c = capacity;
        v = new T[capacity];
        for(int i = 0; i < capacity; i++) v[i] = 0;

    }

    void resize(int newSize)
    {
        T * temp = new T[newSize];
        if(newSize < s)
        {
            for(int i = 0; i < newSize; i++) temp[i] = v[i];
            delete v;
            v = temp;
            return;
        }
        for(int i = 0; i < newSize; i++)
        {
            if(i <= s - 1) temp[i] = v[i];
            else temp[i] = 0;
        }
        delete v;
        v = temp;

    }

    //copy constructor
    vector(vector<T> & other)
    {
        s = other.s;
        v = other.v;
    }

    vector & operator=(vector<T> & other)
    {
        if (s != 0) delete v;
        s = other.s;
        T * temp = new T[s];
        for(int i = 0; i < s; i++)
        {
            temp[i] = other.v[i];
        }
        v = temp;
        return * this;
    }

    T & operator[](int num)
    {
        return v[num];
    }

    T & at(int num)
    {
        try
        {
            if(s == 0) throw 0;
            if(num <= 0 || num > s - 1) throw 0; 

            return v[num];
        }
        catch(int e)
        {
            
        }
    }

    ~vector()
    {
        delete[] v;
    }



    int size()
    {
        return s;
    }

    void push_back(T ele)
    {
        T *temp;
        temp = new T[++s];
        if(s > c) c = s;
        for (int i = 0; i < s - 1; i++)
            temp[i] = v[i];
        delete[] v;
        v = temp;
        v[s - 1] = ele;
    }
};
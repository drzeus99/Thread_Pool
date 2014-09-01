#ifndef THREAD_HELPER_H_INCLUDED
#define THREAD_HELPER_H_INCLUDED

template <class I>
struct thread_helper
{
    void *(I::*method)(void *); //enables you to call and get information from any non static class method
    I *ptr; //this is the class pointer used to call the member pointer
    void *info; //this is what you pass into the member pointer
};

class dummy
{

};

extern "C"
{
    void *method(void *in);
}

#endif // THREAD_HELPER_H_INCLUDED

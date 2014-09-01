#include "thread_helper.h"

extern "C"
{
    void *method(void *in)
    {
        thread_helper<dummy> *utilize = static_cast<thread_helper<dummy> *>(in);
        return (utilize->ptr->*utilize->method)(utilize->info);
    }
}

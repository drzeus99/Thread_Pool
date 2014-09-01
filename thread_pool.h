#ifndef THREAD_POOL_H
#define THREAD_POOL_H
#include <vector>


class thread_pool //cannot have mixed class even though its a void*
{
    //should I just change this to a templated class as well
public:
    thread_pool();
    thread_pool(int num);
    void add_job(void *in);
    void run_jobs(int start=0, int end=0);
private:
    std::vector<void *> jobs; //Since these pointers are passed to the class
    //they do not need deleting in the class.
    //this class is a temporary owner of these pointers.
    std::vector<pthread_t> threads;
    int max_threads;
};


#endif // THREAD_POOL_H

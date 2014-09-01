#include "thread_pool.h"
#include "thread_helper.h"
using namespace std;

thread_pool::thread_pool() : max_threads(2)
{
    threads.resize(2);
}

thread_pool::thread_pool(int num) : max_threads(num)
{
    threads.resize(max_threads);
}
void thread_pool::add_job(void *in)
{
    jobs.push_back(in);
}

void thread_pool::run_jobs(int start, int end)
{
    int tasks;
    //initialize number of tasks to be run
    if (end == 0)
        tasks = jobs.size();
    else  //fix bug here
    {
        if (end > jobs.size())
        {
            end = jobs.size();
        }
        tasks = end;
    }
    //initialize starting task
    if (start<0)
    {
        start = 0;
    }
    int task = start;
    //initialize number of threads currently running
    int thread_num = 0;
    //execute thread_pool
    while (task < tasks )
    {
        while (thread_num < max_threads)
        {
            //cout<<"begining thread "<<task<<" with" <<thread_num<<" active\n";
            pthread_create(&threads[thread_num], NULL, method, jobs[task]);
            //cout<<"finished creating thread\n";
            //cout<<"finised thread "<<task<<" thread num is now "<<thread_num<<endl;
            thread_num++;
            task++;
            if (task >= tasks)
                break;
        }
        //join threads
        for (int cnt = 0; thread_num > 0; thread_num--, cnt++)
        {
            //cout<<"the thread num is "<<cnt<<endl;
            pthread_join(threads[cnt], NULL);
        }
    }
}

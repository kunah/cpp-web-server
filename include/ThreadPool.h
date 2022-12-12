#ifndef CPP_WEB_SERVER_THREADPOOL_H
#define CPP_WEB_SERVER_THREADPOOL_H

#include <iostream>

#include <vector>
#include <queue>
#include <mutex>
#include <thread>

#include <Logger.h>

typedef void (*itemFnc)(void*);

struct WorkItem{
    itemFnc fnc;
    void * params;
};

/// Class to take care of threads that do repetitive tasks
/// Better creating multiple threads at once and than giving them work than creating every time a new thread
class ThreadPool {
public:
    /// Default constructor that initialise thread pool
    /// \param _size size of the thread pool
    ThreadPool(uint16_t _size);
    ~ThreadPool();

    /// If thread pool is under huge load allocate new threads
    /// \param _size # of threads to allocate
    /// \return function success
    bool HigherLoad(uint16_t _size);

    /// Adds work item to the thread pool queue to process
    /// \param _wi work item with params
    void Add(WorkItem _wi);

private:

    static void ThreadTask(uint16_t thID, std::queue<WorkItem> & poolItems, std::mutex & itemsMtx);

    std::vector<std::thread> pool;

    std::mutex itemsMtx;
    std::queue<WorkItem> poolItems;
};


#endif //CPP_WEB_SERVER_THREADPOOL_H

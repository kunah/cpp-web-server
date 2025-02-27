#ifndef CPP_WEB_SERVER_THREADPOOL_H
#define CPP_WEB_SERVER_THREADPOOL_H


#include <queue>
#include <mutex>
#include <vector>
#include <thread>
#include <atomic>
#include <condition_variable>

#include <Logger.h>
#include <ClientRequest.h>

#define CV_LOCK(MTX, CV) { \
std::unique_lock<std::mutex> lk(MTX); \
CV.wait(lk); \

#define CV_LOCK_PREDICATE(MTX, CV, PREDICATE) { \
std::unique_lock<std::mutex> lk(MTX); \
CV.wait(lk, PREDICATE); \


#define CV_UNLOCK }
#define CV_UNLOCK_ONE(CV) CV.notify_one(); \
}

#define CV_UNLOCK_ALL(CV) CV.notify_all(); \
}

#define CV_UNLOCK_ONE_CONDITION(CV, CON) CON = false; \
CV.notify_one(); \
}

#define CV_UNLOCK_ALL_CONDITION(CV, CON) CON = false; \
CV.notify_all(); \
}

namespace ws::threads {

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
        void Add(int _wi);

    private:

        static void
        ThreadTask(uint16_t thID, std::atomic<bool> &appRunning, std::queue<int> &poolItems, std::mutex &itemsMtx,
                   std::condition_variable &cvItems);

        std::vector<std::thread> pool;

        std::atomic<bool> appRunning;
        std::mutex itemsMtx;
        std::condition_variable cvItems;
        std::queue<int> poolItems;
    };

} //namespace ws::threads

#endif //CPP_WEB_SERVER_THREADPOOL_H

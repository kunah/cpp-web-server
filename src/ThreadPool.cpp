#include "ThreadPool.h"


ThreadPool::ThreadPool(uint16_t _size) {
    Logger::debug("Creating ThreadPool");
    for(uint16_t i = 0; i < _size; ++i){
        pool.emplace_back(&ThreadPool::ThreadTask, pool.size(), std::ref(poolItems), std::ref(itemsMtx));
    }
}

ThreadPool::~ThreadPool() {
    Logger::debug("Destroying ThreadPool");
    for (auto &th : pool) {
        th.join();
    }
}

void ThreadPool::ThreadTask(uint16_t thID, std::queue<WorkItem> &poolItems, std::mutex &itemsMtx) {
    // TODO: implement thread safe queue mechanism
    Logger::debug("Thread", thID, "started working");
}

bool ThreadPool::HigherLoad(uint16_t _size) {
    // TODO: better logic for higher load
    Logger::debug("Creating", _size, "new threads");
    for(uint16_t i = 0; i < _size; ++i){
        pool.emplace_back(&ThreadPool::ThreadTask, pool.size(), std::ref(poolItems), std::ref(itemsMtx));
    }
    return true;
}

void ThreadPool::Add(WorkItem _wi) {
    // Temporary implementation
    // TODO: add working item to thread safe queue
    Logger::debug("Adding work item to the thread pool queue");
    itemsMtx.lock();
    poolItems.push(_wi);
    itemsMtx.unlock();
}


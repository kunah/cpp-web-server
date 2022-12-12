#include "ThreadPool.h"


ThreadPool::ThreadPool(uint16_t _size) {
    for(uint16_t i = 0; i < _size; ++i){
        pool.emplace_back(&ThreadPool::ThreadTask, std::ref(poolItems), std::ref(itemsMtx));
    }
}

void ThreadPool::ThreadTask(std::queue<WorkItem> &poolItems, std::mutex &itemsMtx) {
    std::cout << "Thread " <<  std::this_thread::get_id() << " started working" << std::endl;
}
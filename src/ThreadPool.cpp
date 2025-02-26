#include <ThreadPool.h>

namespace th = ws::threads;

th::ThreadPool::ThreadPool(uint16_t _size) : appRunning(true) {
    Logger::debug("Creating ThreadPool");
    for(uint16_t i = 0; i < _size; ++i){
        pool.emplace_back(&ThreadPool::ThreadTask, pool.size(), std::ref(appRunning), std::ref(poolItems), std::ref(itemsMtx), std::ref(cvItems));
    }
}

th::ThreadPool::~ThreadPool() {
    Logger::debug("Destroying ThreadPool");
    appRunning = false;
    for (auto &th : pool) {
        th.detach();
    }
}

void th::ThreadPool::ThreadTask(uint16_t thID, std::atomic<bool> & appRunning, std::queue<int> &poolItems, std::mutex &itemsMtx, std::condition_variable & cvItems) {

    Logger::debug("Thread", thID, "started working");

    auto fnc = [&poolItems, &appRunning]{return !poolItems.empty() || !appRunning;};

    while(appRunning){

        int item;
        CV_LOCK_PREDICATE(itemsMtx, cvItems, fnc)
        if(!appRunning)
            break;
        Logger::debug("Getting item from thread pool queue");
        item = poolItems.front();
        poolItems.pop();
        CV_UNLOCK
        Logger::debug("New connection on socket:", item);

        ClientRequest request(item);
        request.Run();

    }
}

bool th::ThreadPool::HigherLoad(uint16_t _size) {
    // TODO: better logic for higher load
    Logger::debug("Creating", _size, "new threads");
    for(uint16_t i = 0; i < _size; ++i){
        pool.emplace_back(&ThreadPool::ThreadTask, pool.size(), std::ref(appRunning), std::ref(poolItems), std::ref(itemsMtx), std::ref(cvItems));
    }
    return true;
}

void th::ThreadPool::Add(int _wi) {
    Logger::debug("Adding work item to the thread pool queue");
    std::unique_lock<std::mutex> lk(itemsMtx);
    poolItems.push(_wi);
    Logger::debug("Work item added");
    cvItems.notify_one();
    lk.unlock();
}


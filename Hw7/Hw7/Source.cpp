#include <iostream> 
#include <queue> 
#include <mutex> 
#include <thread> 
#include <condition_variable> 

template <typename T>
class SafeQueue {
public:
    SafeQueue() {}

    void push(const T& value) {
        std::unique_lock<std::mutex> lock(mutex_);
        queue_.push(value);
        cv_.notify_one();
    }

    bool pop(T& value) {
        std::unique_lock<std::mutex> lock(mutex_);
        if (queue_.empty()) {
            return false;
        }
        value = queue_.front();
        queue_.pop();
        return true;
    }

    bool empty() const {
        std::unique_lock<std::mutex> lock(mutex_);
        return queue_.empty();
    }

private:
    std::queue<T> queue_;
    mutable std::mutex mutex_;
    std::condition_variable cv_;
};

void test(SafeQueue<int>& safeQueue) {
    safeQueue.push(5);
    safeQueue.push(2);
    safeQueue.push(3);

    int value;

    if (safeQueue.pop(value)) {
        std::cout << "Popped value: " << value << std::endl;
    }

    if (!safeQueue.empty()) {
        std::cout << "Queue is not empty." << std::endl;
    }
    else {
        std::cout << "Queue is empty." << std::endl;
    }

   
}

int main() {
    SafeQueue<int> safeQueue;

    std::thread thread1(test, std::ref(safeQueue));
    std::thread thread2(test, std::ref(safeQueue));
    std::thread thread3(test, std::ref(safeQueue));

    thread1.join();
    thread2.join();
    thread3.join();

    return 0;
}

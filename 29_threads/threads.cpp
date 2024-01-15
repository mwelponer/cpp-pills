#include <iostream>
#include <thread>
#include <chrono>

static bool s_finished = false;
using namespace std::literals::chrono_literals;


void myThreadFunc(){
    std::cout << "started." << std::endl;
    std::cout << "thread id: " << std::this_thread::get_id() << std::endl;

    while(!s_finished){
        std::cout << "..working" << std::endl;
        std::this_thread::sleep_for(3s);
    }
}

int main(){
    std::cout << "main thread id: " << std::this_thread::get_id() << std::endl;

    std::thread myThread(myThreadFunc); // immediately start what is in myThreadFunc()
    // so now we have main thread running and myThread running in parallel

    // this creates another thread that waits for console input
    // but myThread keeps working
    std::cin.get();
    // I set s_finished to true and (next line) tell main to wait for myThread to end
    s_finished = true;
    myThread.join(); // main thread will not proceed until myThread is finished 

    // once myThread ends we can continue with main thread
    std::cout << "finished." << std::endl;
    std::cout << "thread id: " << std::this_thread::get_id() << std::endl;
}
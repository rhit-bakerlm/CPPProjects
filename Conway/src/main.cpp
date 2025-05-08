#include <iostream>
#include <chrono>
#include <thread>

#include "GameManager.h"

const std::chrono::duration<int64_t, std::micro> UPDATE_DELAY = std::chrono::microseconds(1000000 / 10);

int main() {
    int size;
    std::cin >> size;

    GameManager manager(size);

    do {
        manager.update();
        manager.render(); 

        std::this_thread::sleep_for(UPDATE_DELAY);
    } while (true);
}
#include <iostream>
#include <queue>
#include <string>
#include <sstream>

int main() {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    std::string operation;

    while (std::getline(std::cin, operation) && operation != "#") {
        std::stringstream ss(operation);
        std::string command;
        ss >> command;

        if (command == "PUSH") {
            int e;
            ss >> e;
            minHeap.push(e);  
        } else if (command == "POP") {
            if (!minHeap.empty()) {
                std::cout << minHeap.top() << std::endl; 
                minHeap.pop(); 
            } else {
                std::cout << "NULL" << std::endl;
            }
        }
    }

    return 0;
}

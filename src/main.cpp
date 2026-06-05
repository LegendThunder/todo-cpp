#include <iostream>
#include "todo.h"
#include "storage.h"

int main() {
    const std::string FILENAME = "tasks.txt";
    std::vector<Task> tasks = loadTasksFromFile(FILENAME);
    int choice;
    std::string desc;

    while (true) {
        std::cout << "\n=== Todo Manager ===\n";
        std::cout << "1. Add task\n";
        std::cout << "2. List tasks\n";
        std::cout << "3. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                std::cout << "Enter task: ";
                std::getline(std::cin, desc);
                tasks.push_back({desc, false});
                saveTasksToFile(tasks, FILENAME);
                std::cout << "Task added.\n";
                break;
            case 2:
                if (tasks.empty()) {
                    std::cout << "No tasks.\n";
                } else {
                    std::cout << "Tasks:\n";
                    for (size_t i = 0; i < tasks.size(); ++i) {
                        std::cout << i+1 << ". " << tasks[i].description
                                  << " [" << (tasks[i].completed ? "Done" : "Pending") << "]\n";
                    }
                }
                break;
            case 3:
                saveTasksToFile(tasks, FILENAME);
                std::cout << "Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice.\n";
        }
    }
}

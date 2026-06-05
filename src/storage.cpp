#include "storage.h"
#include <fstream>
#include <sstream>
#include <iostream>

void saveTasksToFile(const std::vector<Task>& tasks, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Error: Cannot open file for writing: " << filename << "\n";
        return;
    }

    for (const auto& task : tasks) {
        outFile << task.description << "|" << (task.completed ? "1" : "0") << "\n";
    }

    outFile.close();
}

std::vector<Task> loadTasksFromFile(const std::string& filename) {
    std::vector<Task> tasks;
    std::ifstream inFile(filename);

    if (!inFile) {
        // File doesn't exist yet — that's fine, return empty list
        return tasks;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        if (line.empty()) continue;

        // Find the separator '|'
        size_t pos = line.rfind('|');
        if (pos == std::string::npos) continue; // malformed line, skip

        std::string description = line.substr(0, pos);
        std::string statusStr = line.substr(pos + 1);

        bool completed = (statusStr == "1");
        tasks.push_back({description, completed});
    }

    inFile.close();
    return tasks;
}

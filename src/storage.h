#ifndef STORAGE_H
#define STORAGE_H

#include <string>
#include <vector>
#include "todo.h"

void saveTasksToFile(const std::vector<Task>& tasks, const std::string& filename);
std::vector<Task> loadTasksFromFile(const std::string& filename);

#endif // STORAGE_H

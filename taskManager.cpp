#include "taskManager.h"
#include <iostream>

// Default constructor added
Task::Task() : taskID(0), name(""), description(""), assignedMemberID(-1), status(TaskStatus::NotStarted) {}

Task::Task(int id, const std::string& name, const std::string& desc, int assignedID, TaskStatus status)
    : taskID(id), name(name), description(desc), assignedMemberID(assignedID), status(status) {}

int Task::getTaskID() const {
    return taskID;
}

void Task::displayDetails() const {
    std::cout << "Task ID: " << taskID << ", Name: " << name
              << ", Description: " << description << ", Assigned To ID: " << assignedMemberID
              << ", Status: " << static_cast<int>(status) << std::endl;
}

void Task::setStatus(TaskStatus newStatus) {
    status = newStatus;
}

int Task::getAssignedMemberID() const {
    return assignedMemberID;
}

void Task::assignMember(int memberID) {
    assignedMemberID = memberID;
}

// TaskManager Implementation
TaskManager::TaskManager() : nextTaskID(1) {}

void TaskManager::addTask(const std::string& name, const std::string& desc) {
    Task newTask(nextTaskID, name, desc, -1, TaskStatus::NotStarted);
    tasks[nextTaskID] = newTask;
    std::cout << "Added task with ID: " << nextTaskID << std::endl;
    nextTaskID++;
}

void TaskManager::assignTask(int taskID, int memberID) {
    auto it = tasks.find(taskID);
    if (it != tasks.end()) {
        it->second.assignMember(memberID);
        std::cout << "Assigned member ID " << memberID << " to task " << taskID << std::endl;
    } else {
        std::cout << "Task ID not found.\n";
    }
}

void TaskManager::updateTaskStatus(int taskID, TaskStatus newStatus) {
    auto it = tasks.find(taskID);
    if (it != tasks.end()) {
        it->second.setStatus(newStatus);
        std::cout << "Updated task " << taskID << " status." << std::endl;
    } else {
        std::cout << "Task ID not found.\n";
    }
}

void TaskManager::removeTask(int taskID) {
    if (tasks.erase(taskID)) {
        std::cout << "Task ID " << taskID << " removed.\n";
    } else {
        std::cout << "Task ID not found.\n";
    }
}

void TaskManager::displayAllTasks() const {
    for (const auto& pair : tasks) {
        pair.second.displayDetails();
    }
}
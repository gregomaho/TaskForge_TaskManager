#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <string>
#include <unordered_map>

// Enum for task status
enum class TaskStatus {
    NotStarted,
    InProgress,
    Completed
};

// Task class
class Task {
public:
    Task(); // Default constructor
    Task(int id, const std::string& name, const std::string& desc,
         int assignedID, TaskStatus status);

    int getTaskID() const;
    void displayDetails() const;
    void setStatus(TaskStatus newStatus);
    int getAssignedMemberID() const;
    void assignMember(int memberID);

private:
    int taskID;
    std::string name;
    std::string description;
    int assignedMemberID;
    TaskStatus status;
};

// TaskManager class
class TaskManager {
public:
    TaskManager();

    void addTask(const std::string& name, const std::string& desc);
    void assignTask(int taskID, int memberID);
    void updateTaskStatus(int taskID, TaskStatus newStatus);
    void removeTask(int taskID);
    void displayAllTasks() const;

private:
    std::unordered_map<int, Task> tasks;
    int nextTaskID;
};

#endif

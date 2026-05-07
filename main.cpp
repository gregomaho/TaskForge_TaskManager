#include "teamMember.h"
#include "taskManager.h"
#include "projectManager.h"
#include <iostream>

int main() {
    // Create managers
    TeamMemberManager teamManager;
    TaskManager taskManager;
    ProjectManager projectManager;

    // Sample options in a loop
    int choice;
    do {
        std::cout << "\n1. Add Project\n2. Add Phase to Project\n3. Add Task\n4. Assign Task to Member\n5. Update Task Status\n6. Move Task to Phase\n7. Display Projects\n8. Display Tasks\n0. Exit\nChoice: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string projectName;
            std::cout << "Enter project name: ";
            std::cin >> projectName;
            projectManager.addProject(projectName);
        } else if (choice == 2) {
            std::string projectName, phaseName;
            std::cout << "Enter project name: ";
            std::cin >> projectName;
            Project* proj = projectManager.getProject(projectName);
            if (proj) {
                std::cout << "Enter phase name: ";
                std::cin >> phaseName;
                proj->addPhase(phaseName);
            } else {
                std::cout << "Project not found!\n";
            }
        } else if (choice == 3) {
            std::string taskName, taskDesc;
            std::cout << "Enter task name: ";
            std::cin >> taskName;
            std::cout << "Enter task description: ";
            std::cin >> taskDesc;
            taskManager.addTask(taskName, taskDesc);
        } else if (choice == 4) {
            int taskID, memberID;
            std::cout << "Enter task ID: ";
            std::cin >> taskID;
            std::cout << "Enter member ID: ";
            std::cin >> memberID;
            taskManager.assignTask(taskID, memberID);
        } else if (choice == 5) {
            int taskID, statusInt;
            std::cout << "Enter task ID: ";
            std::cin >> taskID;
            std::cout << "Enter new status (0 = NotStarted, 1 = InProgress, 2 = Completed): ";
            std::cin >> statusInt;
            taskManager.updateTaskStatus(taskID, static_cast<TaskStatus>(statusInt));
        } else if (choice == 6) {
            int taskID;
            std::string projectName, phaseName;
            std::cout << "Enter task ID: ";
            std::cin >> taskID;
            std::cout << "Enter project name: ";
            std::cin >> projectName;
            std::cout << "Enter phase name: ";
            std::cin >> phaseName;
            Project* proj = projectManager.getProject(projectName);
            if (proj) {
                proj->moveTaskToPhase(taskID, phaseName);
            } else {
                std::cout << "Project not found!\n";
            }
        } else if (choice == 7) {
            projectManager.displayAllProjects();
        } else if (choice == 8) {
            taskManager.displayAllTasks();
        }
    } while (choice != 0);

    return 0;
}
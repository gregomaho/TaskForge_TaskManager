#include "projectManager.h"
#include <iostream>

// Project Implementation
Project::Project(const std::string& projectName) : name(projectName) {}

void Project::addPhase(const std::string& phaseName) {
    phases.push_back(Phase{phaseName, {}});
}

void Project::moveTaskToPhase(int taskID, const std::string& phaseName) {
    for (auto& phase : phases) {
        if (phase.name == phaseName) {
            phase.taskIDs.push_back(taskID);
            std::cout << "Task " << taskID << " moved to phase: " << phaseName << " in project " << name << std::endl;
            return;
        }
    }
    std::cout << "Phase " << phaseName << " not found in project " << name << std::endl;
}

void Project::displayPhases() const {
    std::cout << "Project: " << name << std::endl;
    for (const auto& phase : phases) {
        std::cout << "  Phase: " << phase.name << " | Tasks: ";
        for (int taskID : phase.taskIDs) {
            std::cout << taskID << " ";
        }
        std::cout << std::endl;
    }
}

// ProjectManager Implementation
void ProjectManager::addProject(const std::string& projectName) {
    projects.emplace(projectName, Project(projectName));
    std::cout << "Project '" << projectName << "' added." << std::endl;
}

Project* ProjectManager::getProject(const std::string& projectName) {
    auto it = projects.find(projectName);
    if (it != projects.end()) {
        return &(it->second);
    }
    return nullptr;  // Not found
}

void ProjectManager::displayAllProjects() const {
    for (const auto& pair : projects) {
        pair.second.displayPhases();
    }
}
#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H

#include <string>
#include <unordered_map>
#include <vector>

// A phase within a project
struct Phase {
    std::string name;
    std::vector<int> taskIDs;
};

// A project with phases
class Project {
public:
    Project(const std::string& projectName);

    void addPhase(const std::string& phaseName);
    void moveTaskToPhase(int taskID, const std::string& phaseName);
    void displayPhases() const;

private:
    std::string name;
    std::vector<Phase> phases;
};

// Manages multiple projects
class ProjectManager {
public:
    void addProject(const std::string& projectName);
    Project* getProject(const std::string& projectName);  // Return pointer to modify project

    void displayAllProjects() const;

private:
    std::unordered_map<std::string, Project> projects;
};

#endif
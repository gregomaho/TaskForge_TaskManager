#include "teamMember.h"
#include <iostream>

// Default constructor added
TeamMember::TeamMember() : userID(0), name(""), role("") {}

TeamMember::TeamMember(int id, const std::string& name, const std::string& role)
    : userID(id), name(name), role(role) {}

int TeamMember::getUserID() const {
    return userID;
}

void TeamMember::displayDetails() const {
    std::cout << "ID: " << userID << " | Name: " << name
              << " | Role: " << role << std::endl;
}

TeamMemberManager::TeamMemberManager() : nextID(3) {
    // Initialize with two predefined members
    addMember("Greg", "Builder");
    addMember("Wife", "Project Manager");
}

void TeamMemberManager::addMember(const std::string& name, const std::string& role) {
    TeamMember member(nextID, name, role);
    members[nextID] = member;
    std::cout << "Added member with ID: " << nextID << std::endl;
    nextID++;
}

void TeamMemberManager::displayAllMembers() const {
    for (const auto& pair : members) {
        pair.second.displayDetails();
    }
}

void TeamMemberManager::removeMember(int id) {
    if (members.erase(id)) {
        std::cout << "Member with ID " << id << " removed.\n";
    } else {
        std::cout << "No member found with ID " << id << std::endl;
    }
}

bool TeamMemberManager::findMember(int id, TeamMember& member) const {
    auto it = members.find(id);
    if (it != members.end()) {
        member = it->second;
        return true;
    }
    return false;
}
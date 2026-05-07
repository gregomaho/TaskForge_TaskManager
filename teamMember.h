#ifndef TEAMMEMBER_H
#define TEAMMEMBER_H

#include <string>
#include <unordered_map>

class TeamMember {
public:
    TeamMember(); // Default constructor
    TeamMember(int id, const std::string& name, const std::string& role);
    
    int getUserID() const;
    void displayDetails() const;

private:
    int userID;
    std::string name;
    std::string role;
};

class TeamMemberManager {
public:
    TeamMemberManager();

    void addMember(const std::string& name, const std::string& role);
    void displayAllMembers() const;
    void removeMember(int id);
    bool findMember(int id, TeamMember& member) const;

private:
    std::unordered_map<int, TeamMember> members;
    int nextID;
};

#endif
/**
 * @brief 
 * 
 */
#ifndef TASK_H
#define TASK_H
#include <string>
#include "entity.h"
#include "user.h"

namespace entities {
class Task : public Entity { 
public:
    Task() =default;
    ~Task() = default;
    Task(const std::string& name) : m_name{name} {}
    Task(const Task&) = default;
    Task(Task&&) = default;
    Task& operator=(const Task&) = default;
    Task& operator=(Task&&) = default;
public:
    std::string to_string(const std::string& delimiter) const {
        std::string result;
        result += m_name + delimiter;
        result += m_deadline + delimiter;
        result += m_assignee.to_string(delimiter) + delimiter;
        result += m_status;
        return result;
    }
    void set_name(const std::string& name) {m_name = name;}
    std::string name() const {return m_name;}
    void set_deadline(const std::string& deadline) {m_deadline = deadline;}
    std::string get_name() const {return m_deadline;}
    void set_status(const std::string& status) {m_status = status;}
    std::string get_status() const {return m_status;}
    void set_assignee(const User& assignee) {m_assignee = assignee;}
    User get_assignee() const {return m_assignee;}
public:
    bool operator==(const Task& rhs) const {
        if(m_name == rhs.m_name) {
            return false;
        }
        if(m_deadline == rhs.m_deadline) {
            return false;
        }
        if(m_assignee == rhs.m_assignee) {
            return false;
        }
        if(m_status == rhs.m_status) {
            return false;
        }
        return true;
    }

    bool operator!=(const Task& rhs) const {
        return !(this->operator==(rhs));
    }
private:
    std::string m_name;
    std::string m_deadline;
    User m_assignee;
    std::string m_status;
};
}
#endif
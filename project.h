/**
* this file defines Project entity 
*/
#ifndef PROJECT_H
#define PROJECT_H
#include <string>
#include "entity.h"
#include "user.h"
#include "task.h"
#include <vector>

namespace entities {

class Project : public entities::Entity{
public:
    Project() = default;
    Project(std::string name) : m_name(name) {}
    Project(const Project&) = default;
    Project(Project&&) = default;
    Project& operator=(const Project&) = default;
    Project& operator=(Project&&) = default;
    ~Project() = default;
public:
    void set_name(const std::string& name) {
        m_name = name;
    }
    std::string get_name() const {
        return m_name;
    }
    void set_manager(const User& manager) {
        m_manager = manager;
    }
    User get_manager() const {
        return m_manager;
    }
    void set_tasks(const std::vector<Task>& tasks) {
        m_tasks = tasks;
    }
    std::vector<Task> tasks() const {
        return m_tasks;
    }

    void add_task(const Task& task) {
        m_tasks.push_back(task);
    }
    void remove_task(const Task& task) {
        auto begin = m_tasks.begin();
        auto end = m_tasks.end();
        for(; begin != end; ++begin) {
            if(*begin == task) {
                m_tasks.erase(begin);
                break;
            }
        }
    }
    std::string to_string(const std::string& delimiter) const override {
        std::string result;
        result += m_name;
        result += delimiter;
        result += m_manager.to_string(delimiter);
        result += '\n';
        for(int i{}; i < m_tasks.size(); ++i) {
            result += m_tasks[i].to_string(delimiter);
            result += '\n';
        }
        return result;
    }
private:
    std::string m_name;
    User m_manager;
    std::vector<Task> m_tasks;
};
} // end of entities namespace









#endif //PROJECT_H
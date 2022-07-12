#include <iostream>
#include <vector>
#include "core/file-controller.h"
#include "entities/user.h"
#include "entities/project.h"
#include "entities/task.h"
std::vector<entities::Project> projects;
std::vector<entities::User> users;
int main() {
    entities::User u1;
    u1.set_name("Juan");
    u1.set_email("name.surname@gmail.com");
    u1.set_password("karasavchik21");
    u1.set_title("Senior");
    entities:: User u2;
    u2.set_name("Pablo");
    u2.set_email("email@gmail.com");
    u2.set_password("kavchik24");
    u2.set_title("junior");
    users.push_back(u1);
    users.push_back(u2);

    entities::Project p1;
    p1.set_manager(u1);

    entities::Task t1;
    t1.set_deadline("15.10.2022");
    t1.set_assignee(u2);
    p1.add_task(t1);
    projects.push_back(p1);

    core::FileController* f;
    
    for(const auto& u : users) {
        f->save(u1);
    }
    for(const auto& p : projects) {
        f->save(p1);
    }
}
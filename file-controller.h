/**
 *Licence information/File information/Descrioption of what this file does
 *@file file-controller.h
 *@author Karen Serobyan/ Probs shouldn't use this one(few reasons) 
 *
 * To save or load contents from files for entities
 * user, project, and task
 */

#ifndef CORE_FILE_CONTROLLER_H
#define CORE_FILE_CONTROLLER_H
#include <fstream>
#include <string>
#include "../entities/entity.h"

namespace core { 

//Static class FileController

class FileController {
public:
    FileController() = delete;
    ~FileController() = delete;
    static void save(const entities::Entity& entity) {
        std::fstream f;
        f.open("entities.txt", std::ios::out);
        f << entity.to_string(" | ");
        f.close();
    }
};

} //end of core namespace
#endif // CORE_FILE_CONTROLLER_H
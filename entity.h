#ifndef ENTITY_H
#define ENTITY_H
#include <string>

namespace entities {
class Entity {
public:
    virtual std::string to_string(const std::string&) const = 0;
};
}
#endif
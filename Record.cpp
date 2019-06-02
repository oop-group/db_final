#include "Record.h"
#include "Value.h"
#include <memory>
#include <vector>

Record::Record(const std::vector<std::shared_ptr<Value>> &field)
    : field(field) {}

std::shared_ptr<Value> Record::get_field(int attr_id) const {
    return field[attr_id];
}

void Record::update(int id, std::shared_ptr<Value> vptr) { field[id] = vptr; }

int Record::size() const {
    return field.size();
}
//
// Created by Dmitry Zakharov on 17.11.2026.
//

#ifndef UNTITLED_CL_BASE_H
#define UNTITLED_CL_BASE_H
#include <iostream>
#include <vector>
#include <string>

class cl_base {
private:
    std::string s_name;
    cl_base* p_head_obj;
    std::vector<cl_base*> p_sub_objects;

public:
    cl_base(cl_base* p_head_obj, std::string s_name = "Base object");
    virtual ~cl_base();

    void set_name(std::string s_new_name);
    std::string get_name() const;
    void print_tree() const;

    // Оставил только этот метод, так как он нужен для поиска дубликатов при построении
    cl_base* get_sub_object(std::string s_name) const;
};
#endif //UNTITLED_CL_BASE_H

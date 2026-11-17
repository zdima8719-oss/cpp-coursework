//
// Created by Dmitry Zakharov on 17.11.2026.
//

#ifndef UNTITLED_CL_APPLICATION_H
#define UNTITLED_CL_APPLICATION_H
#include "cl_base.h"
#include "cl_1.h"

class cl_application : public cl_base {
public:
    cl_application(cl_base* p_head_obj);
    void build_tree_objects();
    int exec_app();
};

#endif //UNTITLED_CL_APPLICATION_H

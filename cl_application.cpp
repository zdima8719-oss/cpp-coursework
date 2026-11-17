//
// Created by Dmitry Zakharov on 17.11.2026.
//
#include "cl_application.h"
#include <iostream>
#include <string>

cl_application::cl_application(cl_base* p_head_obj) : cl_base(p_head_obj) {}

void cl_application::build_tree_objects() {
    std::string s_head, s_sub;
    std::cin >> s_head;
    this->set_name(s_head);

    while (true) {
        std::cin >> s_head >> s_sub;
        if (s_head == s_sub) break;

        cl_base* p_head = nullptr;
        if (s_head == this->get_name()) {
            p_head = this;
        } else {
            // Ищем родителя среди прямых детей корня
            p_head = this->get_sub_object(s_head);
        }

        // Если родитель найден, создаем потомка
        if (p_head != nullptr) {
            new cl_1(p_head, s_sub);
        }
    }
}
int cl_application::exec_app() {
    // Просто выводим дерево и завершаем работу
    this->print_tree();
    return 0;
}
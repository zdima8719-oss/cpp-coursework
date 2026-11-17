//
// Created by Dmitry Zakharov on 17.11.2026.
//
#include "cl_base.h"

cl_base::cl_base(cl_base* p_head_obj, std::string s_name) {
    this->s_name = s_name;
    this->p_head_obj = p_head_obj;
    if (p_head_obj != nullptr) {
        p_head_obj->p_sub_objects.push_back(this);
    }
}

cl_base::~cl_base() {
    for (size_t i = 0; i < p_sub_objects.size(); i++) {
        delete p_sub_objects[i];
    }
    p_sub_objects.clear();
}

void cl_base::set_name(std::string s_new_name) {
    this->s_name = s_new_name;
}

std::string cl_base::get_name() const {
    return s_name;
}

cl_base* cl_base::get_sub_object(std::string s_name) const {
    for (size_t i = 0; i < p_sub_objects.size(); i++) {
        if (p_sub_objects[i]->get_name() == s_name) {
            return p_sub_objects[i];
        }
    }
    return nullptr;
}

// ПРАВИЛЬНЫЙ ВЫВОД (по уровням)

void cl_base::print_tree() const {
    // 1. Выводим корень
    std::cout << this->get_name() << std::endl;

    // 2. Если у корня нет детей, завершаем
    if (p_sub_objects.empty()) return;

    // 3. Выводим строку для первого уровня (все прямые дети корня)
    std::cout << this->get_name() << " ";
    for (size_t i = 0; i < p_sub_objects.size(); i++) {
        std::cout << p_sub_objects[i]->get_name() << " ";
    }
    std::cout << std::endl;

    // 4. Проходим по каждому ребенку корня, у которого есть свои дети
    for (size_t i = 0; i < p_sub_objects.size(); i++) {
        cl_base* child = p_sub_objects[i];
        if (!child->p_sub_objects.empty()) {
            // Выводим имя этого ребенка (как родителя) и всех его детей
            std::cout << child->get_name() << " ";
            for (size_t j = 0; j < child->p_sub_objects.size(); j++) {
                std::cout << child->p_sub_objects[j]->get_name() << " ";
            }
            std::cout << std::endl;
        }
    }
}
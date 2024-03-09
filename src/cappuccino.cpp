#include "cappuccino.h"

#include <iostream>

#include "sub_ingredients.h"

Cappuccino::Cappuccino() {
    name = "Cappuccino";
    this->ingredients.emplace_back(new Espresso(2));
    this->ingredients.emplace_back(new Milk(2));
    this->ingredients.emplace_back(new MilkFoam(1));
    side_items = std::vector<Ingredient *>{};
}

Cappuccino::Cappuccino(const Cappuccino &cap)  : EspressoBased(cap) {
    if (this == &cap) {
        return;
    }
    for (const auto &ingredient : side_items) {
        delete ingredient;
    }
    for (const auto &ingredient : cap.side_items) {
        this->side_items.push_back(ingredient->clone());
    }
}


std::string Cappuccino::get_name() {
    return name;
}

std::vector<Ingredient *> &Cappuccino::get_side_items() {
    return side_items;
}

void Cappuccino::add_side_item(Ingredient *side) {
    side_items.push_back(side);
}

double Cappuccino::price() {
    double sum = 0.0;
    for (const auto &ingredient : ingredients) {
        sum += ingredient->price();
    }
    for (const auto &ingredient : side_items) {
        sum += ingredient->price();
    }
    return sum;
}

Cappuccino::~Cappuccino() {
    for (const auto &i : side_items) {
        delete i;
    }
    side_items.clear();
}

void Cappuccino::operator=(const Cappuccino &cap) {
    if (this != &cap) {
        for (const auto &ingredient : side_items) {
            delete ingredient;
        }
        side_items.clear();
        for (const auto &ingredient : cap.side_items) {
            this->side_items.push_back(ingredient->clone());
        }
    }
}


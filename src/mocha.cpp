#include "mocha.h"

#include <sub_ingredients.h>

std::string Mocha::get_name() {
    return name;
}

std::vector<Ingredient *> &Mocha::get_side_items() {
    return side_items;
}

void Mocha::add_side_item(Ingredient *side) {
    side_items.emplace_back(side);
}

double Mocha::price() {
    double sum = 0.0;
    for (const auto &ingredient : ingredients) {
        sum += ingredient->price();
    }
    for (const auto &ingredient : side_items) {
        sum += ingredient->price();
    }
    return sum;
}

Mocha::Mocha() {
    name = "Mocha";
    ingredients.emplace_back(new Espresso(2));
    ingredients.emplace_back(new Milk(2));
    ingredients.emplace_back(new MilkFoam(1));
    ingredients.emplace_back(new Chocolate(1));
    side_items = std::vector<Ingredient *>{};
}

Mocha::Mocha(const Mocha &cap) : EspressoBased(cap) {
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

void Mocha::operator=(const Mocha &cap) {
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

Mocha::~Mocha() {
    for (const auto &i : side_items) {
        delete i;
    }
    side_items.clear();
}





#include "espresso_based.h"

#include <iostream>
#include <list>

EspressoBased::EspressoBased() {
    ingredients = std::vector<Ingredient *>{};
}

EspressoBased::EspressoBased(const EspressoBased& esp) {
    if (this == &esp) {
        return;
    }
    for (const auto &i : ingredients) {
        delete i;
    }
    for (const auto &i : esp.ingredients) {
        this->ingredients.push_back(i->clone());
    }
    name = esp.name;
}

EspressoBased::~EspressoBased() {
    for (const auto& i : ingredients) {
        delete i;
    }
    ingredients.clear();
}

std::vector<Ingredient*>& EspressoBased::get_ingredients() {
    return this->ingredients;
}

void EspressoBased::operator=(const EspressoBased &esp) {
    if (this != &esp) {
        for (const auto& i: ingredients) {
            delete i;
        }
        ingredients.clear();
        for (const auto& i : ingredients) {
            this->ingredients.push_back(i->clone());
        }
    }
}

void EspressoBased::brew() {
    std::string reset_position;
    int x_length = 20;
    int y_length = 6;
    auto espresso = text("espresso") | hcenter | vcenter |  bold | color(Color::Green) | bgcolor(Color::Orange1)
        | size(WIDTH, EQUAL, x_length)
        | size(HEIGHT, EQUAL, y_length);
    auto milk = text("milk") | hcenter | vcenter | bold | color(Color::Black) | bgcolor(Color::White)
        | size(WIDTH, EQUAL, x_length)
        | size(HEIGHT, EQUAL, y_length);
    auto Foam = text("foam") | hcenter | vcenter | bold | color(Color::White) | bgcolor(Color::Red)
        | size(WIDTH, EQUAL, x_length)
        | size(HEIGHT, EQUAL, 4);

    auto display_ingredients = std::list<Element>{espresso};

    for (int start = 0; start <= 100; start += 1) {
        switch (start) {
            case 30:
                display_ingredients.push_front(milk);
                break;
            case 70:
                display_ingredients.push_front(Foam);
                break;
            default:
                ;
        }
        std::string data_downloaded =
            std::to_string(start) + "/100";
        auto top_part = hbox({
            text("brewing:"),
            gauge(static_cast<float>(start) / 100.0f) | color(Color::Blue) | flex ,
            text(" " + data_downloaded),
        });
        top_part |= borderDashed;
        auto container_border = border | size(WIDTH, EQUAL, 24);
        std::vector<Element> tmp(std::begin(display_ingredients), std::end(display_ingredients));
        auto bottom_part_with_border = vbox(std::move(tmp)) | container_border;
        bottom_part_with_border |= hcenter;
        auto element = vbox({
            top_part,
            bottom_part_with_border,
        });
        auto screen = Screen::Create(Dimension::Full(), Dimension::Fit(element));
        Render(screen, element);
        std::cout << reset_position;
        screen.Print();
        reset_position = screen.ResetPosition();

        std::this_thread::sleep_for(0.1s);
    }
}




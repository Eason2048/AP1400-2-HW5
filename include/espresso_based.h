#ifndef ESPRESSO_BASED_H
#define ESPRESSO_BASED_H
#include <ingredient.h>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <thread>
#include <chrono>

using namespace ftxui;
using namespace std::chrono_literals;

class EspressoBased {
public:
    virtual std::string get_name() = 0;
    virtual double price() = 0;

    void brew();
    std::vector<Ingredient*>& get_ingredients();

    virtual ~EspressoBased();

protected:
    EspressoBased();
    EspressoBased(const EspressoBased& esp);
    void operator=(const EspressoBased& esp);

    std::vector<Ingredient*> ingredients{};
    std::string name{};
};

#endif // ESPRESSO_BASED_H
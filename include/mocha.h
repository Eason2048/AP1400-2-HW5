#ifndef MOCHA_H
#define MOCHA_H

#include <espresso_based.h>

class Mocha final : public EspressoBased {
public:
    Mocha();
    Mocha(const Mocha& cap);
    ~Mocha() override;
    void operator=(const Mocha& cap);

    std::string get_name() override;
    double price() override;

    void add_side_item(Ingredient* side);
    std::vector<Ingredient*>& get_side_items();

private:
    std::vector<Ingredient*> side_items;
};

#endif // MOCHA_H
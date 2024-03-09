#ifndef INGREDIENT_H
#define INGREDIENT_H
#include <string>

class Ingredient {
public:
    virtual double get_price_unit() { return price_unit; }

    virtual size_t get_units() { return units; }
    virtual std::string get_name() const = 0;

    virtual double price() { return price_unit * static_cast<double>(units); }

    virtual Ingredient* clone() const = 0;

    virtual ~Ingredient() = default;

protected:
    Ingredient(double price_unit, size_t units) : price_unit(price_unit), units(units) {}

    double price_unit;
    size_t units;
    std::string name;
};

#endif // INGREDIENT_H
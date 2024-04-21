// gf class that extends Character class

#include <citro2d.h>
#include "character.hpp"

#ifndef GF_HPP
#define GF_HPP

class GF : public Character {
public:
    GF(int x, int y);
    ~GF();
    void draw();
};

#endif
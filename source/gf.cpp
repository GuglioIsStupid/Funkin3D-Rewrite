#include <citro2d.h>
#include "gf.hpp"
#include <vector>
#include <tuple>

GF::GF(int x, int y) : Character::Character("gf.t3x", x, y) {
    this->addAnimation("idle", 0, 14, 12);
}

GF::~GF() {
    // do nothing
}

void GF::draw() { 
    /* C2D_SpriteMove(&this->sprite, this->x, this->y);
    C2D_SpriteScale(&this->sprite, this->scaleX, this->scaleY); */
    C2D_DrawSprite(&this->sprite);
}

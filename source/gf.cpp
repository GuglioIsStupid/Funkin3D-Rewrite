#include <citro2d.h>
#include "gf.hpp"
#include <vector>
#include <tuple>

GF::GF(int x, int y) : Character::Character("gf.t3x", x, y) {
    this->addAnimation("idle", 0, 13, 12);

    /* this->frames = std::tuple<float, float> */
    this->frames = std::vector<std::tuple<float, float>>();
    
    // IDLE ANIM
    this->frames.push_back(std::tuple<float, float>(0.0f, -2.76f));
    this->frames.push_back(std::tuple<float, float>(0.0f, -2.53f));
    this->frames.push_back(std::tuple<float, float>(0.0f, -2.07f));
    this->frames.push_back(std::tuple<float, float>(0.0f, 0.46f));
    this->frames.push_back(std::tuple<float, float>(0.0f, 0.46f));
    this->frames.push_back(std::tuple<float, float>(0.0f, 0.46f));
    this->frames.push_back(std::tuple<float, float>(0.0f, 0.46f));
    this->frames.push_back(std::tuple<float, float>(0.46f, -2.3f));
    this->frames.push_back(std::tuple<float, float>(0.0f, -2.3f));
    this->frames.push_back(std::tuple<float, float>(0.0f, -2.07f));
    this->frames.push_back(std::tuple<float, float>(0.0f, -0.69f));
    this->frames.push_back(std::tuple<float, float>(0.0f, -0.69f));
    this->frames.push_back(std::tuple<float, float>(0.0f, -0.92f));
}

GF::~GF() {
    // do nothing
}

void GF::draw() { 
    /* C2D_SpriteMove(&this->sprite, this->x, this->y);
    C2D_SpriteScale(&this->sprite, this->scaleX, this->scaleY); */
    // 163x149
    C2D_DrawSprite(&this->sprite);
}

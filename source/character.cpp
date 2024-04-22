#include <citro2d.h>
#include "character.hpp"
#include <vector>
#include <tuple>

Character::Character(std::string name, int x, int y) {
    this->filePath = name;
    this->x = x;
    this->y = y;
    this->scaleX = 1;
    this->scaleY = 1;
    this->frame = 0;
    this->frameTime = 0;
    // NAME, START, END, SPEED
    this->animations = std::vector<std::tuple<std::string, int, int, double>>();
    this->currentAnimation = std::tuple<std::string, int, int, double>("", 0, 0, 0);

    this->frames = std::vector<int>(
        { // IDLE

        }
    );;

    this->playing = false;

    // all files are in romfs:/
    this->spriteSheet = C2D_SpriteSheetLoad(std::string("romfs:/" + name).c_str());
    C2D_SpriteFromSheet(&this->sprite, this->spriteSheet, 0); // first frame

    // TODO: Frames
}

Character::~Character() {
    C2D_SpriteSheetFree(this->spriteSheet);
}

void Character::draw() {
    /* C2D_DrawSprite(&this->sprite, this->x, this->y, 0, this->scaleX, this->scaleY, 1); */
    /* C2D_SpriteMove(&this->sprite, this->x, this->y);
    C2D_SpriteScale(&this->sprite, this->scaleX, this->scaleY); */
    C2D_DrawSpriteFromFramePos(&this->sprite, 0, 0, 75, 75);
}

void Character::addAnimation(std::string name, int start, int end, double speed) {
    this->animations.push_back(std::tuple<std::string, int, int, double>(name, start, end, speed));
    this->currentAnimation = std::tuple<std::string, int, int, double>(name, start, end, speed);
    this->playing = true;
}

void Character::update(double delta) {
    // update frame if playing (3rd element of tuple is framerate)
    // so basically,
    if (this->playing) {
        this->frameTime += std::get<3>(this->currentAnimation) * delta;
        if (this->frameTime >= std::get<3>(this->currentAnimation)) {
            this->frameTime = 0;
            this->frame += 1;
            if (this->frame > std::get<2>(this->currentAnimation)) {
                this->frame = std::get<1>(this->currentAnimation);
            }
            /* C2D_SpriteFromSheet(&this->sprite, this->spriteSheet, this->frame); */
        }
    }
}

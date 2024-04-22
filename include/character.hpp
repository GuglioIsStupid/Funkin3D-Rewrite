#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <citro2d.h>
#include <vector>
#include <tuple>

class Character {
public:
    // Passes: file, x, y
    Character(std::string name, int x, int y);
    ~Character();
    void draw();
    void update(double delta);
    void addAnimation(std::string name, int start, int end, double speed);
    
    // has x, y, scale x and scale y
    float x, y;
    float scaleX, scaleY;
    int frame;
    double frameTime;
    bool playing;

    std::vector<std::tuple<std::string, int, int, double>> animations;
    std::tuple<std::string, int, int, double> currentAnimation;
    // list of frame indexs
    std::vector<std::tuple<float, float>> frames;
    
    std::string filePath;
    C2D_SpriteSheet spriteSheet;
    C2D_Sprite sprite;
};

#endif
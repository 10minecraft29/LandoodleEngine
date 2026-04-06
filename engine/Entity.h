#pragma once
#include "Animation.h"

struct Entity {
    float x, y;
    float vx, vy;
    float w, h;
    bool onGround;

    Animation* anim;

    Entity(float x, float y, float w, float h)
        : x(x), y(y), vx(0), vy(0), w(w), h(h), onGround(false), anim(nullptr) {}
};

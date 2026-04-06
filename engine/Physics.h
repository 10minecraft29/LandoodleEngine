#pragma once
#include "Entity.h"
#include "TileMap.h"

class Physics {
public:
    static void applyGravity(Entity& e, float dt) {
        e.vy += 2000.0f * dt;
    }

    static void move(Entity& e, TileMap& map, float dt) {
        e.onGround = false;

        // Horizontal
        e.x += e.vx * dt;
        resolve(e, map, true);

        // Vertical
        e.y += e.vy * dt;
        resolve(e, map, false);
    }

private:
    static void resolve(Entity& e, TileMap& map, bool horizontal) {
        int left = (int)(e.x / 32);
        int right = (int)((e.x + e.w) / 32);
        int top = (int)(e.y / 32);
        int bottom = (int)((e.y + e.h) / 32);

        for (int y = top; y <= bottom; y++) {
            for (int x = left; x <= right; x++) {
                if (map.isSolid(x, y)) {
                    if (horizontal) {
                        if (e.vx > 0)
                            e.x = x * 32 - e.w;
                        else if (e.vx < 0)
                            e.x = (x + 1) * 32;
                        e.vx = 0;
                    } else {
                        if (e.vy > 0) {
                            e.y = y * 32 - e.h;
                            e.vy = 0;
                            e.onGround = true;
                        } else if (e.vy < 0) {
                            e.y = (y + 1) * 32;
                            e.vy = 0;
                        }
                    }
                }
            }
        }
    }
};

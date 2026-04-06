#pragma once
#include <glad/glad.h>

class SpriteRenderer {
public:
    static void draw(float x, float y, float w, float h,
                     float u1, float v1, float u2, float v2) {

        glEnable(GL_TEXTURE_2D);

        glBegin(GL_QUADS);
        glTexCoord2f(u1, v1); glVertex2f(x, y);
        glTexCoord2f(u2, v1); glVertex2f(x + w, y);
        glTexCoord2f(u2, v2); glVertex2f(x + w, y + h);
        glTexCoord2f(u1, v2); glVertex2f(x, y + h);
        glEnd();
    }
};

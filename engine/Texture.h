#pragma once
#include <glad/glad.h>
#define STB_IMAGE_IMPLEMENTATION
#include "../thirdparty/stb_image.h"

class Texture {
public:
    GLuint id;

    Texture(const char* path) {
        glGenTextures(1, &id);
        glBindTexture(GL_TEXTURE_2D, id);

        int w, h, channels;
        unsigned char* data = stbi_load(path, &w, &h, &channels, 4);

        if (!data) {
            printf("Failed to load texture: %s\n", path);
            return;
        }

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0,
                     GL_RGBA, GL_UNSIGNED_BYTE, data);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        stbi_image_free(data);
    }

    void bind() {
        glBindTexture(GL_TEXTURE_2D, id);
    }
};

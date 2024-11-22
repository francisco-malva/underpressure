//
// Created by gyaru on 22/11/2024.
//

#ifndef UNDERPRESSURE_RAYLIB_RENDERER_H
#define UNDERPRESSURE_RAYLIB_RENDERER_H

#include "renderer.h"

class raylib_renderer : public renderer {
public:

    ~raylib_renderer() override;
    void on_register() override;
};


#endif //UNDERPRESSURE_RAYLIB_RENDERER_H

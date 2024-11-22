//
// Created by gyaru on 22/11/2024.
//

#include <raylib.h>
#include "raylib_renderer.h"

void raylib_renderer::on_register() {
    InitWindow(640,480,"Underpressure");
}

raylib_renderer::~raylib_renderer() {
    CloseWindow();
}

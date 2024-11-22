//
// Created by gyaru on 22/11/2024.
//

#include "engine.h"
#include "renderer.h"
#include "raylib_renderer.h"

service_provider &engine::get_service_provider() {
    return serviceProvider;
}

void engine::run() {


    service_provider& sp = get_service_provider();

    sp.register_service<renderer, raylib_renderer>();
}

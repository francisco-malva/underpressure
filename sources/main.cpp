#include "engine.h"

int main() {

    engine::init_instance();
    engine::get_instance().run();
    engine::destroy_instance();
    return 0;
}

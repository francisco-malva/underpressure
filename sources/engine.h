//
// Created by gyaru on 22/11/2024.
//

#ifndef UNDERPRESSURE_ENGINE_H
#define UNDERPRESSURE_ENGINE_H

#include "singleton.h"
#include "service_provider.h"

class engine : public singleton<engine> {


public:
    void run();
    [[nodiscard]] service_provider& get_service_provider();
private:
    service_provider serviceProvider;
};


#endif //UNDERPRESSURE_ENGINE_H

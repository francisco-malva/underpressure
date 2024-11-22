//
// Created by gyaru on 22/11/2024.
//

#ifndef UNDERPRESSURE_ID_PROVIDER_H
#define UNDERPRESSURE_ID_PROVIDER_H

#include <cstdint>

using tid_t = std::uint32_t;

class id_provider {

public:
    template<typename T>
    static tid_t get_type_id();
private:
    static tid_t idCounter;
};

template<typename T>
tid_t id_provider::get_type_id() {
    static tid_t id = idCounter++;
    return id;
}


#endif //UNDERPRESSURE_ID_PROVIDER_H

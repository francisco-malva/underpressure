//
// Created by gyaru on 22/11/2024.
//

#ifndef UNDERPRESSURE_SERVICE_PROVIDER_H
#define UNDERPRESSURE_SERVICE_PROVIDER_H

#include <unordered_map>
#include <memory>
#include <cassert>
#include "id_provider.h"


class service{
public:
    virtual ~service() = default;

    virtual void on_register();
};

class service_provider {

public:
    template<class T>
     T* get_service();


    template<class ServiceType, class ImplementorType>
    ServiceType* register_service();
private:
    std::unordered_map<tid_t, std::unique_ptr<service>> registeredServices;
};

template<class ServiceType, class ImplementorType>
ServiceType* service_provider::register_service() {

    auto service = std::make_unique<ImplementorType>();
    service->on_register();
    registeredServices[id_provider::get_type_id<ServiceType>()] = std::move(service);

    return get_service<ServiceType>();
}

template<class T>
T *service_provider::get_service() {

    auto it = registeredServices.find(id_provider::get_type_id<T>());
    assert(it != registeredServices.end() && "Service not registered!");

    service* service = it->second.get();

    T* cast = nullptr;
#if NDEBUG

    cast = static_cast<T*>(service);
#else

    cast = dynamic_cast<T*>(service);

    assert(cast && "Service is not of the correct type!");
#endif

    return cast;
}


#endif //UNDERPRESSURE_SERVICE_PROVIDER_H

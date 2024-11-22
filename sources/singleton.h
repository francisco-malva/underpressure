//
// Created by gyaru on 22/11/2024.
//

#ifndef UNDERPRESSURE_SINGLETON_H
#define UNDERPRESSURE_SINGLETON_H

#include <memory>
#include <cassert>

template<class T>
class singleton {
public:

    static void init_instance(){
        instance = std::make_unique<T>();
    }
    static T& get_instance(){
        assert(instance != nullptr);
        return *instance.get();
    }

    static void destroy_instance(){
        instance = nullptr;
    }
private:
    inline static std::unique_ptr<T> instance;
};


#endif //UNDERPRESSURE_SINGLETON_H

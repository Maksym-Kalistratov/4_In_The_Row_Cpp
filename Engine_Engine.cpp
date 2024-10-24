#include "Engine_Engine.h"

#include <iostream>

JNIEXPORT JNICALL auto Java_Engine_Engine_greeter(

        JNIEnv *, jclass

) -> void {

    std::cout << "Greetings from C++ library!\n";

}
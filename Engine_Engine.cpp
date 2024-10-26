#include "Engine_Engine.h"
#include "GameProcessing.h"
#include <iostream>

JNIEXPORT JNICALL auto Java_Engine_Engine_greeter(JNIEnv *, jclass) -> void {

    std::cout << "Greetings from C++ library!\n";

}
JNIEXPORT auto JNICALL Java_Engine_Engine_getColor
        (JNIEnv *, jclass, jint x, jint y) -> jint{
    return GameProcessing::getInstance().getColor(x,y);
}
JNIEXPORT auto JNICALL Java_Engine_Engine_nextMove
        (JNIEnv *, jclass, jint col) -> jint{
    return GameProcessing::getInstance().nextMove(col-1);
}
JNIEXPORT auto JNICALL Java_Engine_Engine_getTurn
        (JNIEnv *, jclass) -> jint{
    return GameProcessing::getInstance().getTurn();
}
JNIEXPORT auto JNICALL Java_Engine_Engine_getState
        (JNIEnv *, jclass) -> jint{
    return GameProcessing::getInstance().getState();
}
JNIEXPORT auto JNICALL Java_Engine_Engine_resetBoard
        (JNIEnv *, jclass) -> void{
    GameProcessing::getInstance().resetBoard();
}
JNIEXPORT auto JNICALL Java_Engine_Engine_getCount
        (JNIEnv *, jclass, jint i) -> jint {
    return GameProcessing::getInstance().getCount(i);
}

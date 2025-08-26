#include "pch.h"

#include "MathWrapperB.h"

using namespace MathLibrary;

namespace MathWrapper {

    MathBridge::MathBridge() {}

    int MathBridge::Add(int x, int y) {
        MathLibrary::Math^ math = gcnew MathLibrary::Math();
        return math->Add(x, y);
    }

    int MathBridge::Substract(int x, int y) {
        MathLibrary::Math^ math = gcnew MathLibrary::Math();
        return math->Substract(x, y);
    }

}

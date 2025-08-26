#pragma once

#using <mscorlib.dll>
using namespace System;

namespace MathWrapper {
    public ref class MathBridge {
    public:
        MathBridge();
        int Add(int x, int y);
        int Substract(int x, int y);
    };
}

// Type of project: CLR Class Library (.NET Framework 4.7.2 <-- the same as MathLibraryB, with 5.0 does not work)
// Properties / Common Language Runtime Support / clr (not netcore)
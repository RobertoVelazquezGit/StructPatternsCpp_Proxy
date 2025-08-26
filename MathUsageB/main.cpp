
#using <MathWrapperB.dll>  // Though the namespace without B
using namespace MathWrapper;

int main()
{
    MathBridge^ bridge = gcnew MathBridge();
    int resultado = bridge->Add(2, 3);
    System::Console::WriteLine("Resultado: {0}", resultado);

    return 0;
}

// In Properties/ C C++ / Command Line / Aditional Options
// /AI"C:\Dev\curso2425\StructPatternsCpp\Projects\Proxy\x64\Debug" <-- here is where the *.dll are left by Visual Studio
 


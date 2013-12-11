#include "MathHeaders.h"
#include "App/DebugApp.h"

using namespace EX3;

int main(int argc, char* argv[])
{
    DebugApp* debugApp = new DebugApp();
    debugApp->Run();
    delete debugApp;

    return 0;
}

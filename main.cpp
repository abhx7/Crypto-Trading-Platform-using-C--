#include "MerkelMain.h"

int main()
{
    try
    {
        MerkelMain app{};
        app.init();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Application error: " << e.what() << std::endl;
    }
    return 0;
}

// #include "MerkelMain.h" 

// int main()
// {
//     MerkelMain app{};
//     app.init();
// }
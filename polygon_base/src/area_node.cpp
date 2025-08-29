#include <iostream>

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;

    // Apenas simulando a execução do plugin
    double triangle_area = 43.30;
    double square_area = 100.00;

    std::cout << "Triangle area: " << triangle_area << std::endl;
    std::cout << "Square area: " << square_area << std::endl;

    return 0;
}


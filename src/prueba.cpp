#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/screen/terminal.hpp>
#include <iostream>
#include <thread>
#include <cmath>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    std::string reset_position;
    int frame = 1;
    float velocidadX = 2.0f;
    float velocidadY = 0.0f;
    float gravedad = 0.5f;
    float posX = 50.0f;
    float posY = 10.0f;
    int radio = 3;
    int altura_suelo = 98;

    while (true)
    {
        Screen pantalla = Screen::Create(Dimension::Full(), Dimension::Full());
        auto can = Canvas(100, 100);

        posX += velocidadX;
        posY += velocidadY;

        velocidadY += gravedad;

        if (posX <= 0 || posX + radio >= 100)
        {
            velocidadX = -velocidadX;
        }
        if (posY + radio >= altura_suelo)
        {
            posY = altura_suelo - radio;
            velocidadY = -velocidadY * 0.9f;
        }

        can.DrawPointCircle(posX, posY, radio);

        Element lienzo = bgcolor(Color::Orange1, border(canvas(&can)));
        Render(pantalla, lienzo);
        std::cout << reset_position;
        pantalla.Print();
        reset_position = pantalla.ResetPosition(true);

        this_thread::sleep_for(0.02s);
        frame++;
    }

    return 0;
}
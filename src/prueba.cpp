#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/screen/terminal.hpp>
#include <iostream>
#include <thread>

using namespace std;
using namespace ftxui;

int posicionX(int posicion, int velocidad, int tiempo)
{
    return posicion + velocidad + tiempo;
}

int posicionY(int posicion, int velocidad, int tiempo)
{
    return 0.5 + (9.81) + (tiempo + tiempo);
}

int main(int argc, char const *argv[])
{
    std::string reset_position;
    int frame = 0;
    int vix = 1;
    int viy = 1;
    int posx = 0;
    int posy = 0;

    auto can = Canvas(200, 200);
    auto ColorSupport = vbox({});

    while (true)
    {
        Screen pantalla = Screen::Create(Dimension::Full(), Dimension::Full());
        can.DrawPointCircle(
            posicionX(posx, vix, frame),
            posicionY(posy, viy, frame),
            2);

        Element lienzo = bgcolor(Color::Orange1, border(vbox(ColorSupport, canvas(&can))));
        Render(pantalla, lienzo);
        std::cout << reset_position;
        pantalla.Print();
        reset_position = pantalla.ResetPosition(true);
        this_thread::sleep_for(0.1s);
        frame++;
    }

    return 0;
}
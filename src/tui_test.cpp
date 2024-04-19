#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <thread>
#include <iostream>
#include <string>
#include <experimental/random>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    int fotograma = 0;
    string reset;

    while (true)
    {
        fotograma++;

        // Estas lineas sirven para asignarle un numero aleatorio a cada variable para mostrar un efecto de RGB
        /*
            int r = std::experimental::randint(0, 255);
            int g = std::experimental::randint(0, 255);
            int b = std::experimental::randint(0, 255);
        */

        Element personaje = spinner(21, fotograma);
        Decorator cfondo = bgcolor(Color::GrayDark);
        Decorator ctexto = color(Color::White);
        // Color es para colorear el texto y bgcolor para el background
        Element dibujo = border({

            // Esta linea es para imprimir el personaje con el efecto RGB
            // hbox(personaje)
            hbox(personaje) | cfondo | ctexto

        }) //| cfondo | ctexto
            // Esta linea es para asignarle el efecto de RGB al monito
            ;

        Dimensions Alto = Dimension::Fixed(10);
        Dimensions Ancho = Dimension::Full();

        Screen pantalla = Screen::Create(Ancho, Alto); // Create es un metodo estatico que tiene la clase Screen

        Render(pantalla, dibujo);

        pantalla.Print();
        reset = pantalla.ResetPosition();
        cout << reset;
        this_thread::sleep_for(0.1s);
    }

    return 0;
}
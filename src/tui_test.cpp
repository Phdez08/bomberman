#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <thread>
#include <iostream>
#include <string>
#include <experimental/random>
#include <list>
#include <fstream>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    list<string> textos;
    fstream imagen;
    imagen.open("./assets/imagen.txt");

    string linea;
    while (getline(imagen, linea))
    {
        textos.push_back(linea);
    }
    imagen.close();


    int fotograma = 0;
    string reset;

    int posX = 0;
    int posY = 0;

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

        int l = 0;
        for (auto &&texto : textos)
        {

            int i = 0;
            for (auto &&letra : texto)
            {
                pantalla.PixelAt(posX + i, posY + l).character = letra;
                i++;
            }
            l++;
        }

        /*
        for (int i = 0; i < 6; i++)
        {
            pantalla.PixelAt(posX + i, 6).character = "-";
        }*/

        posX++;

        pantalla.Print();
        reset = pantalla.ResetPosition();
        cout << reset;
        this_thread::sleep_for(0.1s);
    }

    return 0;
}
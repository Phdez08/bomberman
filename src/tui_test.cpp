#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    const string texto = "Hola mundo";
    Element textElement = text(texto);

    Element dibujo = hbox(textElement | border);

    Dimensions Alto = Dimension::Fixed(10);
    Dimensions Ancho= Dimension::Fixed(10);
    

    Screen pantalla = Screen::Create(Ancho, Alto); // Create es un metodo estatico que tiene la clase Screen

    Render(pantalla, dibujo);

    pantalla.Print();

    cout<<endl;

    return 0;
}

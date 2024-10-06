#include "Menu.h"
using namespace std;

Menu::Menu(float width, float height){
    selectedOption = 0;
    if(font.loadFromFile("arial.ttf")){
        vector<string> options = {"BubbleSort", "QuickSort", "MergeSort", "Exit"}; //Opciones del menú
        for(int i = 0; i< options.size(); i++){
            sf::Text text; //Crea un objeto de texto
            text.setFont(font); //Asigna la fuente al texto
            text.setString(options[i]); //Asigna el texto a la opción
            text.setPosition(sf::Vector2f(width/2, height/(options.size() + 1) * (i+1))); //Hace que los textos estén centrados
            menuOptions.push_back(text); //Añade el texto al vector de opciones
        }
    }
}

void Menu::draw(sf::RenderWindow &window){
    for(int i = 0; i < menuOptions.size(); i++){
        if(i == selectedOption){
            menuOptions[i].setFillColor(sf::Color::Red); //Si la opción está seleccionada, se pone en rojo
        } else {
            menuOptions[i].setFillColor(sf::Color::White); //Si no, se pone en blanco
        }
        window.draw(menuOptions[i]); //Dibuja la opción
    }
}

void Menu::moveUp(){
    if (selectedOption > 0){
        selectedOption--; //Si la opción seleccionada no es la primera, se mueve hacia arriba
    }
}

void Menu::moveDown(){
    if (selectedOption < menuOptions.size() - 1){
        selectedOption++; //Si la opción seleccionada no es la última, se mueve hacia abajo
    }
}

int Menu::getSelectedOption() const{
    return selectedOption; //Devuelve la opción seleccionada
}
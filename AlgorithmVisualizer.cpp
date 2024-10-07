#include "AlgorithmVisualizer.h"
#include <iostream>
#include <sstream>
#include <random>

void AlgorithmVisualizer::promptForInput(sf::RenderWindow &window) {
    sf::Font font;
    font.loadFromFile("arial.ttf");

    // Obtener el número de elementos
    sf::Text prompt("Ingresa el numero de elementos:", font, 24);
    prompt.setPosition(50, 50);

    sf::Text inputText("_", font, 24);
    inputText.setPosition(50, 100);

    string userInput;
    bool inputComplete = false;

    while (window.isOpen() && !inputComplete) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode == '\b' && userInput.size() > 0) {
                    userInput.pop_back();
                } else if (event.text.unicode >= '0' && event.text.unicode <= '9') {
                    userInput += static_cast<char>(event.text.unicode);
                }
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                if (!userInput.empty()) {
                    inputComplete = true;
                }
            }
        }

        window.clear();
        window.draw(prompt);

        inputText.setString(userInput);
        window.draw(inputText);

        window.display();
    }

    // Convertir el texto a entero
    stringstream ss(userInput);
    int numElements;
    ss >> numElements;

    // Permitir al usuario ingresar valor
    data.clear();
    for (int i = 0; i < numElements; ++i) {
        userInput = "";
        inputComplete = false;
        while (window.isOpen() && !inputComplete) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }

                if (event.type == sf::Event::TextEntered) {
                    if (event.text.unicode == '\b' && userInput.size() > 0) {
                        userInput.pop_back();
                    } else if ((event.text.unicode >= '0' && event.text.unicode <= '9') || event.text.unicode == '-') {
                        userInput += static_cast<char>(event.text.unicode);
                    }
                }

                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                    if (!userInput.empty()) {
                        inputComplete = true;
                    }
                }
            }

            window.clear();

            // Actualizar el prompt para mostrar el índice actual
            string valuePrompt = "Ingresa el valor " + to_string(i + 1) + ":";
            prompt.setString(valuePrompt);
            window.draw(prompt);

            inputText.setString(userInput);
            window.draw(inputText);

            window.display();
        }

        // Convertir el texto ingresado a un entero
        stringstream ss(userInput);
        int value;
        ss >> value;
        data.push_back(value);
    }
}

void AlgorithmVisualizer::displayInputData(sf::RenderWindow &window, const vector<int> &data) {
    window.clear();
    float xPos = 50.0f;
    float barWidth = std::min(700.0f / data.size(), 50.0f); // Ajustar el ancho de las barras
    for (int i = 0; i < data.size(); i++) {
        sf::RectangleShape bar(sf::Vector2f(barWidth, data[i] * 5));
        bar.setFillColor(sf::Color::White);
        bar.setPosition(xPos, 500 - data[i] * 5);
        window.draw(bar);
        xPos += barWidth + 5.0f;
    }
    window.display();
}

void AlgorithmVisualizer::executeAlgorithm(const string &algorithmName){
    if (algorithmName == "BubbleSort"){
        algorithm = new BubbleSort();
    } else if (algorithmName == "QuickSort"){
        algorithm = new QuickSort();
    } else if (algorithmName == "MergeSort"){
        algorithm = new MergeSort();
    }

    if (algorithm) {
        stats.startTimer();
        algorithm->sort(data);
        stats.stopTimer();    
    }
}

void AlgorithmVisualizer::showResults(sf::RenderWindow &window, const vector<int> &data, const string &algorithmName){
    displayInputData(window, data);

    sf::Font font;
    font.loadFromFile("arial.ttf");

    sf::Text executionTimeText("Tiempo de ejecución: " + to_string(stats.getExecutionTime()) + " segundos", font, 24);
    executionTimeText.setPosition(50, 50);

    sf::Text complexityText(stats.getComplexity(algorithmName), font, 24);
    complexityText.setPosition(50, 80);

    sf::Text repeatText("Presiona R para repetir el algoritmo", font, 24);
    repeatText.setPosition(50, 140);

    sf::Text menuText("Presiona M para regresar al menú", font, 24);
    menuText.setPosition(50, 170);

    bool waitingForInput = true;
    while (window.isOpen() && waitingForInput) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::R) {
                    // Repetir el algoritmo
                    executeAlgorithm(algorithmName);
                    displayInputData(window, data);
                } else if (event.key.code == sf::Keyboard::M) {
                    // Regresar al menú
                    waitingForInput = false;
                    delete algorithm;
                    algorithm = nullptr;
                    return;
                }
            }
        }

        window.clear();
        displayInputData(window, data);
        window.draw(executionTimeText);
        window.draw(complexityText);
        window.draw(repeatText);
        window.draw(menuText);
        window.display();
    }
}

const vector<int> &AlgorithmVisualizer::getData() const {
    return data;
}
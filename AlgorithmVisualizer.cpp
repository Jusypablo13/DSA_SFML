#include "AlgorithmVisualizer.h"
#include <iostream>
#include <sstream>

void AlgorithmVisualizer::promptForInput(sf::RenderWindow &window) {
    sf::Font font;
    font.loadFromFile("arial.ttf");
    
    sf::Text prompt("Enter the number of elements:", font, 24);
    prompt.setPosition(50, 50);
    
    sf::Text inputText("", font, 24);
    inputText.setPosition(50, 100);

    string userInput;
    bool inputComplete = false;

    while (window.isOpen() && !inputComplete) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode == '\b' && userInput.size() > 0) {
                    userInput.pop_back();  // Borrar el último carácter si se presiona retroceso
                } else if (event.text.unicode >= '0' && event.text.unicode <= '9') {
                    userInput += static_cast<char>(event.text.unicode);  // Agregar dígito al texto
                }
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                inputComplete = true;
            }
        }

        window.clear();
        window.draw(prompt);
        
        inputText.setString(userInput);
        window.draw(inputText);

        window.display();
    }

    // Convertir el texto ingresado a un entero
    stringstream ss(userInput);
    int numElements;
    ss >> numElements;

    data.clear();
    for (int i = 0; i < numElements; ++i) {
        // Generar elementos aleatorios para el ejemplo
        data.push_back(rand() % 100);
    }
}

void AlgorithmVisualizer::displayInputData(sf::RenderWindow &window, const vector<int> &data){
    window.clear();
    float xPos = 50.0f;
    for (int i = 0; i < data.size(); i++){
        sf::RectangleShape bar(sf::Vector2f(30, data[i] * 10)); //Cada barra tendrá una altura proporcional al valor del dato
        bar.setFillColor(sf::Color::White); //Color de la barra
        bar.setPosition(xPos, 500 - data[i] * 10); //La barra se dibujará de abajo hacia arriba
        window.draw(bar); //Dibujar la barra
        xPos += 40.0; //Espacio entre barras
    }
    window.display();
}

void AlgorithmVisualizer::executeAlgorithm(const string &algorithmName){
    if (algorithmName == "BubbleSort"){
        algorithm = new BubbleSort();
    } else if (algorithmName == "QuickSort"){
        algorithm = new QuickSort();
    }

    if (algorithm) {
        stats.startTimer();
        algorithm->sort(data);
        stats.stopTimer();    
    }
}

void AlgorithmVisualizer::showResults(sf::RenderWindow &window, const vector<int> &data, const string &algorithmName){
    displayInputData(window, data);

    cout << "Execution time: " << stats.getExecutionTime() << " seconds" << endl;
    stats.displayComplexity(algorithmName);

    cout << "Do you want to repeat the algorithm (y/n)? ";
    char choice;
    cin >> choice;
    if (choice == 'y'){
        executeAlgorithm(algorithmName);
        showResults(window, data, algorithmName);
    } else {
        delete algorithm;
    }
}

const vector<int> &AlgorithmVisualizer::getData() const {
    return data;
}
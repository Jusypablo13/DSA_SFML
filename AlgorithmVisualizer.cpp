#include "AlgorithmVisualizer.h"
#include <iostream>
#include <random>

void AlgorithmVisualizer::promptForInput(){
    int numElements;
    cout << "Enter the number of elements: ";
    cin >> numElements;

    data.clear(); //Para evitar que se acumulen los datos
    for(int i = 0; i < numElements; i++){
        int value;
        cout << "Enter element " << i + 1 << ": ";
        cin >> value;
        data.push_back(value);
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
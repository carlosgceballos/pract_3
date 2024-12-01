#include <iostream>
#include <cmath>
using namespace std;


struct Point{
    float x, y;
};

//Función para calcular la distancia entre dos puntos
float calcularDistancia(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

//Función para encontrar la distancia máxima entre dos puntos dentro de un cuadrante
void distanciaMaxima(Point puntos[], int n, float xmin, float xmax, float ymin, float ymax) {
    float maxDistancia = 0.0;
    Point p1, p2;
    bool encontrados = false;

    for (int i = 0; i < n; i++) {
        //Verificar si el punto está dentro del cuadrante
        if (puntos[i].x >= xmin && puntos[i].x <= xmax && puntos[i].y >= ymin && puntos[i].y <= ymax) {
            for (int j = i + 1; j < n; j++) {
                if (puntos[j].x >= xmin && puntos[j].x <= xmax && puntos[j].y >= ymin && puntos[j].y <= ymax) {
                    float distancia = calcularDistancia(puntos[i], puntos[j]);
                    if (distancia > maxDistancia) {
                        maxDistancia = distancia;
                        p1 = puntos[i];
                        p2 = puntos[j];
                        encontrados = true;
                    }
                }
            }
        }
    }

    if (encontrados){
        cout << "La distancia maxima es " << maxDistancia << " entre los puntos ("
             << p1.x << ", " << p1.y << ") y (" << p2.x << ", " << p2.y << ").\n";
    } else {
        cout << "No se encontraron puntos dentro del cuadrante.\n";
    }
}

// Función para imprimir la distancia de un punto a todos los demás puntos dentro del mismo cuadrante
void imprimirDistancias(Point puntos[], int n, Point puntoReferencia, float xmin, float xmax, float ymin, float ymax) {
    cout << "Distancias desde el punto (" << puntoReferencia.x << ", " << puntoReferencia.y << "):\n";
    for (int i = 0; i < n; i++) {
        if (puntos[i].x >= xmin && puntos[i].x <= xmax && puntos[i].y >= ymin && puntos[i].y <= ymax) {
            if (puntos[i].x != puntoReferencia.x || puntos[i].y != puntoReferencia.y) {
                float distancia = calcularDistancia(puntoReferencia, puntos[i]);
                cout << "Distancia al punto (" << puntos[i].x << ", " << puntos[i].y << "): " << distancia << "\n";
            }
        }
    }
}

int main() {
    int n;
    cout << "Ingrese la cantidad de puntos: ";
    cin >> n;

    Point puntos[n];
    for (int i = 0; i < n; i++) {
        cout << "Ingrese las coordenadas del punto " << i + 1 << endl;
        cout<<"X: ";
        cin >> puntos[i].x;
        cout<<"Y: ";
        cin>> puntos[i].y;
    }

    //Limites del cuadrante
    float xmin, xmax, ymin, ymax;
    cout << "Ingrese los limites del cuadrante"<<endl;
    cout<<"Xmin: ";
    cin >> xmin; 
    cout<<"Xmax: ";
    cin>> xmax; 
    cout<<"ymin: ";
    cin>> ymin; 
    cout<<"Ymax: ";
    cin>> ymax;

    //Calcular la distancia máxima dentro del cuadrante
    distanciaMaxima(puntos, n, xmin, xmax, ymin, ymax);

    // Elegir un punto de referencia para calcular distancias
    Point puntoReferencia;
    cout << "Ingrese las coordenadas del punto de referencia: "<<endl;
    cout<<"X: ";
    cin >> puntoReferencia.x;
    cout<<"Y: ";
    cin >> puntoReferencia.y;

    //Calcular distancias desde el punto de referencia a otros puntos en el cuadrante
    imprimirDistancias(puntos, n, puntoReferencia, xmin, xmax, ymin, ymax);

    return 0;
}

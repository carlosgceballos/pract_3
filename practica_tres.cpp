#include <iostream>
using namespace std;

struct Point{
    float x, y;
};

//Función para detectar el cuadrante de un punto
void detectarCuadrante(Point p) {
    if (p.x > 0 && p.y > 0)
        cout << "El punto (" << p.x << ", " << p.y << ") esta en el cuadrante I\n";
    else if (p.x < 0 && p.y > 0)
        cout << "El punto (" << p.x << ", " << p.y << ") esta en el cuadrante II\n";
    else if (p.x < 0 && p.y < 0)
        cout << "El punto (" << p.x << ", " << p.y << ") esta en el cuadrante III\n";
    else if (p.x > 0 && p.y < 0)
        cout << "El punto (" << p.x << ", " << p.y << ") esta en el cuadrante IV\n";
    else
        cout << "El punto (" << p.x << ", " << p.y << ") esta en uno de los ejes\n";
}

bool enMismaLinea(Point p1, Point p2, Point p3) {
    return (p2.y - p1.y) * (p3.x - p1.x) == (p3.y - p1.y) * (p2.x - p1.x);
}

void calcularEcuacion(Point p1, Point p2) {
    float m = (p2.y - p1.y) / (p2.x - p1.x); // Pendiente
    float b = p1.y - m * p1.x;              // Interseccion con el eje y
    cout << "La ecuacion de la linea es: y = " << m << "x + " << b << "\n";
}
//Función para verificar si hay pares de puntos que estén en la misma línea
void verificarLineas(Point puntos[], int n) {
    cout << "\nVerificando pares de puntos en la misma linea:\n";
    bool encontrado = false;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (enMismaLinea(puntos[i], puntos[j], puntos[k])) {
                    cout << "Los puntos (" << puntos[i].x << ", " << puntos[i].y << "), ("
                         << puntos[j].x << ", " << puntos[j].y << "), y ("
                         << puntos[k].x << ", " << puntos[k].y << ") estan en la misma linea.\n";
                    calcularEcuacion(puntos[i], puntos[j]);
                    encontrado = true;
                }
            }
        }
    }
    if (!encontrado) {
        cout << "No hay puntos que esten en la misma linea.\n";
    }
}

int main() {
    int n;
    cout << "Ingrese la cantidad de puntos: ";
    cin >> n;

    Point puntos[n];
    for (int i = 0; i < n; i++) {
        cout << "Ingrese las coordenadas del punto " << i + 1<<endl;
        cout<< "X: ";
        cin >> puntos[i].x; 
        cout<< "Y: ";
        cin>> puntos[i].y;
        detectarCuadrante(puntos[i]);
    }
    // Verificar si los puntos están en la misma línea
    verificarLineas(puntos, n);

    return 0;
}


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// Estructura para el reporte final (Parte 3 y 4 de la rúbrica)
struct Reporte {
    float promedio;
    float mayor;
    float menor;
    int aprobados;
    int reprobados;
};

// --- PARTE 2: Operaciones Matemáticas ---
void operacionesBasicas() {
    float n1, n2;
    cout << "\n--- Operaciones Basicas ---" << endl;
    cout << "Ingrese primer numero: "; cin >> n1;
    cout << "Ingrese segundo numero: "; cin >> n2;
    cout << "Suma: " << n1 + n2 << " | Resta: " << n1 - n2 << endl;
    if (n2 != 0){
     cout << "Multiplicacion: " << n1 * n2 << endl;
    cout << "Division: " << n1 / n2 << endl;
    }
    else cout << "Error: No se puede dividir para cero." << endl;
}

// --- PARTE 3 y 4: Lectura, Procesamiento y Persistencia ---
void procesarListaAlumnos() {
    ifstream archivoLectura("alumnos.txt");
    ofstream archivoResultados("resultados.txt");

    if (!archivoLectura.is_open()) {
        cout << "\n[!] Error: No encontre 'alumnos.txt'. Crealo en la carpeta del proyecto." << endl;
        return;
    }

    string linea;
    float globalSuma = 0;
    int totalAlumnos = 0;
    float notaMaxima = -1;

    cout << "\n--- Procesando Alumnos de la FISEI ---" << endl;
    archivoResultados << "REPORTE DE NOTAS - PROYECTO C++\n----------------------------\n";

    while (getline(archivoLectura, linea)) {
        stringstream ss(linea);
        string nombre, tempNota;
        float sumaNotas = 0, promIndividual = 0;

        getline(ss, nombre, ','); // Leer nombre
        for (int i = 0; i < 5; i++) {
            if(getline(ss, tempNota, ',')) {
                float n = stof(tempNota);
                sumaNotas += n;
                if (n > notaMaxima) notaMaxima = n;
            }
        }
        promIndividual = sumaNotas / 5;
        globalSuma += promIndividual;
        totalAlumnos++;

        cout << "Alumno: " << nombre << " | Promedio: " << promIndividual << endl;
        archivoResultados << "Estudiante: " << nombre << " | Promedio: " << promIndividual << endl;
    }

    if (totalAlumnos > 0) {
        cout << "\nPromedio General del Curso: " << globalSuma / totalAlumnos << endl;
        cout << "Nota mas alta registrada: " << notaMaxima << endl;
        archivoResultados << "\nRESUMEN FINAL:\nPromedio Grupal: " << globalSuma / totalAlumnos;
    }

    archivoLectura.close();
    archivoResultados.close();
    cout << "\n[OK] Datos guardados en 'resultados.txt'." << endl;
}

// --- PARTE 1: Menú Principal ---
int main() {
    int opcion;
    do {
        cout << "\n================================" << endl;
        cout << "   SISTEMA DE GESTION - FISEI   " << endl;
        cout << "================================" << endl;
        cout << "1. Operaciones Matematicas" << endl;
        cout << "2. Cargar y Procesar Alumnos (TXT)" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione: ";
        cin >> opcion;

        switch(opcion) {
            case 1: operacionesBasicas(); break;
            case 2: procesarListaAlumnos(); break;
            case 3: cout << "Cerrando programa..." << endl; break;
            default: cout << "Opcion invalida." << endl;
        }
    } while (opcion != 3);
    return 0;
}

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Interfaz.h"

using namespace std;

void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pausa() {
    cout << "Presione una tecla para continuar...";
    cin.get();
    cin.get();
}

class INTERFAZ {
private:
    string proyecto;
    string descripcion;
    string fechaInicio;
    string fechaFin;
    string asistentes;
    string tarea;
    string estadoTarea;

public:
void menuPrincipal() {
        int opcion;
        do {
            limpiarPantalla();
            cout << "MENÚ PRINCIPAL" << endl;
            cout << "1. REQUERIMIENTOS DE PROYECTOS" << endl;
            cout << "2. GESTIÓN DE PROYECTOS" << endl;
            cout << "3. GESTIÓN DE EMPLEADOS" << endl;
            cout << "4. SALIR" << endl;
            cout << "INGRESE UNA OPCIÓN: ";
            cin >> opcion;

            switch (opcion) {
            case 1:
                cout << "EN PROGRESO..." << endl;
                pausa();
                break;
            case 2:
                gestionProyectos();
                break;
            case 3:
                cout << "EN PROGRESO..." << endl;
                pausa();
                break;
            case 4:
                cout << "SALIENDO..." << endl;
                pausa();
                break;
            default:
                cout << "OPCIÓN INVÁLIDA. INTENTE NUEVAMENTE." << endl;
                pausa();
            }
        } while (opcion != 4);
    }

 void gestionProyectos() {
        int opcion;
        do {
            limpiarPantalla();
            cout << "GESTIÓN DE PROYECTOS" << endl;
            cout << "1. CREAR PROYECTO" << endl;
            cout << "2. REUNIONES DE SEGUIMIENTO" << endl;
            cout << "3. REGRESAR" << endl;
            cout << "INGRESE UNA OPCIÓN: ";
            cin >> opcion;

            switch (opcion) {
            case 1:
                crearProyecto();
                break;
            case 2:
                reunionesSeguimiento();
                break;
            case 3:
                cout << "REGRESANDO..." << endl;
                pausa();
                break;
            default:
                cout << "OPCIÓN INVÁLIDA. INTENTE NUEVAMENTE." << endl;
                pausa();
            }
        } while (opcion != 3);
    }

void crearProyecto() {
        limpiarPantalla();
        cout << "CREAR PROYECTO" << endl;
        cout << "Descripción: ";
        cin.ignore();
        getline(cin, descripcion);
        cout << "Fecha de Inicio: ";
        cin >> fechaInicio;
        cout << "Fecha de Fin: ";
        cin >> fechaFin;
        cout << "ASIGNAR EMPLEADOS" << endl;
        cout << "1. EMPLEADO 1" << endl;
        cout << "2. EMPLEADO 2" << endl;
        cout << "3. EMPLEADO 3" << endl;
        cout << "SELECCIONE EMPLEADOS (separe con comas): ";
        cin >> asistentes;
        pausa();
    }

void reunionesSeguimiento() {
        int opcion;
        do {
            limpiarPantalla();
            cout << "REUNIONES DE SEGUIMIENTO" << endl;
            cout << "1. PROYECTO 1" << endl;
            cout << "2. PROYECTO 2" << endl;
            cout << "3. PROYECTO 3" << endl;
            cout << "4. REGRESAR" << endl;
            cout << "INGRESE UNA OPCIÓN: ";
            cin >> opcion;

            switch (opcion) {
            case 1:
            case 2:
            case 3:
                agendarReunion();
                break;
            case 4:
                cout << "REGRESANDO..." << endl;
                pausa();
                break;
            default:
                cout << "OPCIÓN INVÁLIDA. INTENTE NUEVAMENTE." << endl;
                pausa();
            }
        } while (opcion != 4);
    }

void agendarReunion() {
    limpiarPantalla();
    cout << "AGENDAR REUNIÓN" << endl;
    string fechaReunion;
    string horaReunion;
    cout << "Fecha de la Reunión: ";
    cin >> fechaReunion;
    cout << "Hora de la Reunión: ";
    cin >> horaReunion;
    cout << "Asistentes: " << endl;
    cout << "1. EMPLEADO 1" << endl;
    cout << "2. EMPLEADO 2" << endl;
    cout << "3. EMPLEADO 3" << endl;
    cout << "SELECCIONE ASISTENTES (separe con comas): ";
    cin >> asistentes;

    seleccionarTarea();
    pausa();
}

void seleccionarTarea() {
    int opcion;
    do {
        limpiarPantalla();
        cout << "SELECCIONE UNA TAREA" << endl;
        cout << "1. TAREA 1 - PENDIENTE" << endl;
        cout << "2. TAREA 2 - EN PROGRESO" << endl;
        cout << "3. TAREA 3 - FINALIZADA" << endl;
        cout << "4. REGRESAR" << endl;
        cout << "INGRESE UNA OPCIÓN: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
        case 2:
        case 3:
            estadoActualTarea();
            break;
        case 4:
            cout << "REGRESANDO..." << endl;
            pausa();
            break;
        default:
            cout << "OPCIÓN INVÁLIDA. INTENTE NUEVAMENTE." << endl;
            pausa();
        }
    } while (opcion != 4);
}

void estadoActualTarea() {
    limpiarPantalla();
    cout << "ESTADO ACTUAL DE LA TAREA" << endl;
    cout << "Tarea: " << tarea << endl;
    cout << "Estado: " << estadoTarea << endl;

    cambiarEstadoTarea();
    pausa();
}

void cambiarEstadoTarea() {
    char opcion;
    limpiarPantalla();
    cout << "CAMBIAR ESTADO DE LA TAREA" << endl;
    cout << "A) PENDIENTE" << endl;
    cout << "B) EN PROGRESO" << endl;
    cout << "C) FINALIZADA" << endl;
    cout << "D) NO CAMBIAR" << endl;
    cout << "INGRESE UNA OPCIÓN: ";
    cin >> opcion;

    switch (opcion) {
    case 'A':
    case 'a':
        estadoTarea = "PENDIENTE";
        break;
    case 'B':
    case 'b':
        estadoTarea = "EN PROGRESO";
        break;
    case 'C':
    case 'c':
        estadoTarea = "FINALIZADA";
        break;
    case 'D':
    case 'd':
        break;
    }

    proximaAccion();
    pausa();
}

void proximaAccion() {
    char opcion;
    limpiarPantalla();
    cout << "PRÓXIMA ACCIÓN: RECOMENDACIONES" << endl;
    cout << "A) Agendar reunión de seguimiento" << endl;
    cout << "B) Asignar nueva tarea a empleado" << endl;
    cout << "C) Ver avance del proyecto" << endl;
    cout << "D) Regresar" << endl;
    cout << "INGRESE UNA OPCIÓN: ";
    cin >> opcion;

    switch (opcion) {
    case 'A':
    case 'a':
        agendarReunion();
        break;
    case 'B':
    case 'b':
        // Asignar nueva tarea a empleado
        break;
    case 'C':
    case 'c':
        // Ver avance del proyecto
        break;
    case 'D':
    case 'd':
        menuPrincipal();
        break;
    }
}
};

#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <iostream>
#include <string>

class INTERFAZ {
public:
    void menuPrincipal();
    void gestionProyectos();
    void crearProyecto();
    void reunionesSeguimiento();
    void agendarReunion();
    void seleccionarTarea();
    void estadoActualTarea();
    void cambiarEstadoTarea();
    void proximaAccion();

private:
    std::string proyecto;
    std::string descripcion;
    std::string fechaInicio;
    std::string fechaFin;
    std::string asistentes;
    std::string tarea;
    std::string estadoTarea;
};

void limpiarPantalla();
void pausa();

#endif  // INTERFAZ_H

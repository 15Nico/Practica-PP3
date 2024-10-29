//
// Created by Nico on 24/10/2024.
//

#include "ReunionSeguimiento.h"
#include <iostream>

using namespace std;

int ReunionSeguimiento::contadorId = 0;

ReunionSeguimiento::ReunionSeguimiento(string nombre, string fecha, string hora, string proyecto, vector<string> asistentes, vector<string> temasDiscutidos, string resumenDecisiones, vector<string> proximasAcciones)
    : nombre(nombre), fecha(fecha), hora(hora), proyecto(proyecto), asistentes(asistentes), temasDiscutidos(temasDiscutidos), resumenDecisiones(resumenDecisiones), proximasAcciones(proximasAcciones) {
    contadorId++;
    idReunion = contadorId;
}

// Getters
int ReunionSeguimiento::getIdReunion() const {
    return idReunion;
}

string ReunionSeguimiento::getNombre() const {
    return nombre;
}

string ReunionSeguimiento::getFecha() const {
    return fecha;
}

string ReunionSeguimiento::getHora() const {
    return hora;
}

string ReunionSeguimiento::getProyecto() const {
    return proyecto;
}

vector<string> ReunionSeguimiento::getAsistentes() const {
    return asistentes;
}

vector<string> ReunionSeguimiento::getTemasDiscutidos() const {
    return temasDiscutidos;
}

string ReunionSeguimiento::getResumenDecisiones() const {
    return resumenDecisiones;
}

vector<string> ReunionSeguimiento::getProximasAcciones() const {
    return proximasAcciones;
}

// Setters
void ReunionSeguimiento::setNombre(const string& nombre) {
    this->nombre = nombre;
}

void ReunionSeguimiento::setFecha(const string& fecha) {
    this->fecha = fecha;
}

void ReunionSeguimiento::setHora(const string& hora) {
    this->hora = hora;
}

void ReunionSeguimiento::setProyecto(const string& proyecto) {
    this->proyecto = proyecto;
}

void ReunionSeguimiento::setAsistentes(const vector<string>& asistentes) {
    this->asistentes = asistentes;
}

void ReunionSeguimiento::setTemasDiscutidos(const vector<string>& temasDiscutidos) {
    this->temasDiscutidos = temasDiscutidos;
}

void ReunionSeguimiento::setResumenDecisiones(const string& resumenDecisiones) {
    this->resumenDecisiones = resumenDecisiones;
}

void ReunionSeguimiento::setProximasAcciones(const vector<string>& proximasAcciones) {
    this->proximasAcciones = proximasAcciones;
}

void ReunionSeguimiento::imprimirReunion() const {
    cout << "ID Reunion: " << idReunion << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Fecha: " << fecha << endl;
    cout << "Hora: " << hora << endl;
    cout << "Proyecto: " << proyecto << endl;
    cout << "Asistentes: ";
    for (const auto& asistente : asistentes) {
        cout << asistente << ", ";
    }
    cout << endl;
    cout << "Temas discutidos: ";
    for (const auto& tema : temasDiscutidos) {
        cout << tema << ", ";
    }
    cout << endl;
    cout << "Resumen de decisiones: " << resumenDecisiones << endl;
    cout << "Proximas acciones: ";
    for (const auto& accion : proximasAcciones) {
        cout << accion << ", ";
    }
    cout << "\n" << endl;
}
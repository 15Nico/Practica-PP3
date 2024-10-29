//
// Created by Nico on 24/10/2024.
//

#ifndef REUNIONSEGUIMIENTO_H
#define REUNIONSEGUIMIENTO_H

#include <string>
#include <vector>

using namespace std;

class ReunionSeguimiento {
private:
    static int contadorId;
    int idReunion;
    string nombre;
    string fecha;
    string hora;
    string proyecto;
    vector<string> asistentes;
    vector<string> temasDiscutidos;
    string resumenDecisiones;
    vector<string> proximasAcciones;

public:
    ReunionSeguimiento(string nombre, string fecha, string hora, string proyecto, vector<string> asistentes, vector<string> temasDiscutidos, string resumenDecisiones, vector<string> proximasAcciones);

    // Getters
    int getIdReunion() const;
    string getNombre() const;
    string getFecha() const;
    string getHora() const;
    string getProyecto() const;
    vector<string> getAsistentes() const;
    vector<string> getTemasDiscutidos() const;
    string getResumenDecisiones() const;
    vector<string> getProximasAcciones() const;

    // Setters
    void setNombre(const string& nombre);
    void setFecha(const string& fecha);
    void setHora(const string& hora);
    void setProyecto(const string& proyecto);
    void setAsistentes(const vector<string>& asistentes);
    void setTemasDiscutidos(const vector<string>& temasDiscutidos);
    void setResumenDecisiones(const string& resumenDecisiones);
    void setProximasAcciones(const vector<string>& proximasAcciones);

    void imprimirReunion() const;

};

#endif // REUNIONSEGUIMIENTO_H
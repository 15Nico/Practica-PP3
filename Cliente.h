//
// Created by nicolas on 24/10/2024.
//

#ifndef GESTORPROYECTOS_CLIENTE_H
#define GESTORPROYECTOS_CLIENTE_H

#include<string>
using namespace std;

class Cliente {
private:
    static int contadorId;
    int idCliente;
    string nombre;
    string apellido;
    string empresa;
    string correoElectronico;
    string telefono;
    string direccion;

public:
    Cliente(string nom, string ape, string emp, string corr, string tel, string dir);

    // Getters
    int getIdCliente() const;
    string getNombre() const;
    string getApellido() const;
    string getEmpresa() const;
    string getCorreoElectronico() const;
    string getTelefono() const;
    string getDireccion() const;

    // Setters
    void setIdCliente(int id);
    void setNombre(string nom);
    void setApellido(string ape);
    void setEmpresa(string emp);
    void setCorreoElectronico(string corr);
    void setTelefono(string tel);
    void setDireccion(string dir);


};

#endif // GESTORPROYECTOS_CLIENTE_H

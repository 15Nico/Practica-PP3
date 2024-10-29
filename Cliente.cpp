//
// Created by nicolas on 24/10/2024.
//

#include "Cliente.h"
#include <iostream>
int Cliente::contadorId = 1;

Cliente::Cliente(string nom, string ape, string emp, string corr, string tel, string dir)
    : idCliente(contadorId++), nombre(nom), apellido(ape), empresa(emp), correoElectronico(corr), telefono(tel), direccion(dir) {}

// Getters
int Cliente::getIdCliente() const { return idCliente; }
string Cliente::getNombre() const { return nombre; }
string Cliente::getApellido() const { return apellido; }
string Cliente::getEmpresa() const { return empresa; }
string Cliente::getCorreoElectronico() const { return correoElectronico; }
string Cliente::getTelefono() const { return telefono; }
string Cliente::getDireccion() const { return direccion; }

// Setters
void Cliente::setIdCliente(int id) { idCliente = id; }
void Cliente::setNombre(string nom) { nombre = nom; }
void Cliente::setApellido(string ape) { apellido = ape; }
void Cliente::setEmpresa(string emp) { empresa = emp; }
void Cliente::setCorreoElectronico(string corr) { correoElectronico = corr; }
void Cliente::setTelefono(string tel) { telefono = tel; }
void Cliente::setDireccion(string dir) { direccion = dir; }



/** @file Problema.cc
    @brief Código de la clase Problema
*/

#include "Problema.hh"

Problema::Problema(){
    env_correctos=0;
    env_totales=0;
}

Problema::Problema(const Problema& p){
    env_correctos=p.env_correctos;
    env_totales=p.env_totales;
}

void Problema::incrementar_correctos(){
    ++env_correctos;
    ++env_totales;
}

void Problema::incrementar_totales(){
    ++env_totales;
}

int Problema::consultar_correctos() const{
    return env_correctos;
}

int Problema::consultar_totales() const{
    return env_totales;
}
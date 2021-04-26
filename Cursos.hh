/** @file Cursos.hh
    @brief Especificación de la clase Cursos 
*/

#ifndef _CURSOS_HH_
#define _CURSOS_HH_

#ifndef NO_DIAGRAM
using namespace std;
#include <vector>
#include <list>
#include <iostream>
#endif 

#include "Sesion.hh"
#include "Curso.hh"

    /** @class Cursos
    @brief Representa todo el conjunto de Cursos.
    */
class Cursos
{
private:
    vector<Curso> list_cursos;

public:
    //Constructoras
    /** @brief Creadora por defecto. 

        Se ejecuta automáticamente al declarar un problema.
        \pre <em>cierto</em>
        \post El resultado es un map de cursos vacío, con id igual a "0" y con N = 0.
    */
    Cursos();

    //Modificadoras
    /** @brief Añade al parámetro implícito el nuevo curso.
        \pre <em>cierto</em>
        \post El resultado es el parámetro implícito pero añadiendo c a este.
    */
    void afegir_curso(const Curso& c);

    //Consultoras
    /** @brief Consulta el número de sesiones que existen
        \pre <em>cierto</em>
        \post El resultado es el número de sesiones que hay en total.
    */
    int num_cursos() const;

    /** @brief Consulta si existe una sesión con identificador id.
        \pre <em>cierto</em>
        \post El resultado es el true si existe una sesión con identificador id, y false si no exsite.
    */
    bool existe_curso(int id);

    /** @brief Devuelve una lista con las sesiones que tiene el curso c
        \pre <em>cierto</em>
        \post El resultado es una lista con las sesiones que tiene el curso c.
    */
    list<string> lista_sesiones(int c);

    /** @brief Consulta el número de usuarios inscritos en el curso <em>c</em>. 
        \pre Tiene que existir el curso c.
        \post El resultado es el número de usuarios inscritos en el curso <em>c</em>.
    */
    int consultar_num_usuarios(int c);

    //Escritura y lecttura
    /** @brief Escribe por el canal standard de salida el map de cursos de forma ordenada. 
        \pre <em>cierto</em>
        \post El resultado es escribir en el canal standard de salida el map de cursos de forma ordenada.
    */
    void Escribir();

    /** @brief Escribe por el canal standard de salida el curso concreto. 
        \pre El curso identificado por id tiene que existir.
        \post El resultado es escribir en el canal standard de salida el curso concreto.
    */
    void Escribir(int id);

    /** @brief Lee por el canal standard de entrada el conjunto de cursos. 
        \pre El parametro implicito no esta inicializado.
        \post El resultado es leer del canal standard de entrada el conjunto de cursos y ponerlos en el parametro implícito.
    */
    void leer(int N);
};

#endif

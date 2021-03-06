/** @file Usuarios.hh
    @brief Especificación de la clase Usuarios 
*/


#ifndef _USUARIOS_HH_
#define _USUARIOS_HH_

#ifndef NO_DIAGRAM
using namespace std;
#include <iostream>
#include <map>
#include <list>
#endif 

#include "Sesiones.hh"
#include "Usuari.hh"
#include "Cursos.hh"
#include "Problemas.hh"

    /** @class Usuarios
    @brief Representa todo el conjunto de Usuarios.
    */
class Usuarios
{
private:
    /** @brief  Lista de usuarios, ordenados por su identificado */
    map<string,Usuari> lista_usuaris;

public:
    //Constructoras
    /** @brief Creadora por defecto. 

        Se ejecuta automáticamente al declarar la clase Usuarios.
        \pre <em>cierto</em>
        \post El resultado es un conjunto de usuarios sin inicializar.
    */
    Usuarios();

    //Modificadoras
    /** @brief Añade al parámetro implícito el nuevo usuario.
        \pre No existe ningún usuario con el mismo identificador.
        \post El resultado és el parámetro implícito pero añadiendo u en este.
    */
    void afegir_usauri(const string id);

    /** @brief Borra al usuario identificado por id del parámetro implícito.
        \pre Existe un usuario con el identificador id.
        \post El resultado és el parámetro implícito pero sin u en este.
    */
    void baja_usuario(string id);

    /** @brief Inscribe a un usuario a un curso.
        \pre Existe un usuario con el identificador id que no esta inscrito a ningún curso y también un curso con identificador c.
        \post Inscribe al usuario identificado por id al curso con identificador c.
    */
    void inscribir_usuario_curso(Cursos& c, Sesiones& s, string id, int curs);

    /** @brief Se aumenta en 1 el numero de envios a cierto problema del conjunto de problemas enviables del usuario concreto.
        \pre p esta en el connunto de problemas enviables.
        \post Se aumenta en 1 el númerode envios al problema p del conjunto de problemas enviables del usuario id.
    */
    void aumentar_problema_enviable(const string id, const string p);

    /** @brief Se añade un problema al conjunto de problemas intentados del usuario concreto.
        \pre <em>cierto</em>
        \post Se añade p al conjunto de problemas intentados del usuario id.
    */
    void afegir_problema_intentado(const string id, const string p);

    /** @brief Aumenta en 1 el número total de envios realizados por el usuario concreto.
        \pre <em>cierto</em>
        \post El parámetro implícito del usuario id pasa a tener 1 envío mas.
    */
    void aumentar_numero_envios(const string id);

    /** @brief Se añade un problema al conjunto de problemas resueltos de un usuario concreto.
        \pre p tiene que pertenecer al conjunto de problemas enviables.
        \post Se añade p al conjunto de problemas resueltos del usaurio id.
    */
    void afegir_problema_resuelto(const string id, const string p);

    /** @brief Se añade un problema al conjunto de problemas enviables del usuario concreto.
        \pre p no esta ya en el conjunto.
        \post Se añade p al conjunto de problemas enviables del usuario id.
    */
    void afegir_problema_enviable(const string id, const string p);

    /** @brief Se añade un conjunto de problemas al conjunto de problemas enviables del usuario concreto.
        \pre p no esta ya en el conjunto.
        \post Se añade L al conjunto de problemas enviables del usuario id.
    */
    void afegir_problemas_enviable(const string id, const list<string>& L);

    /** @brief Modifica si el usuario concreto esta o no inscrito en un curso.
        \pre <em>cierto</em>
        \post El parametro implicito del usuario id pasa a tener s como inscrito en curso.
    */
    void modificar_inscrito_en_curso(const string id, bool s);

    /** @brief Modifica el usuario por parametro y devuelve el usuario de conjunto de usuarios 
        \pre <em>cierto</em>
        \post Se modifica el usuario pasado por parametro, y se guarda el usuario identificado por id del conjunto de usuarios en el usuario pasado por referencia.
    */
    void devolver_usuario(Usuari& u, const string id);

    /** @brief Modifica el usuario identificado por id, substituyendole por u.
        \pre <em>cierto</em>
        \post Se modifica el usuario identificado por id, del conjunto de usuario, substituyendolo por u.
    */
    void actualizar_usuario(Usuari& u, const string id);

    /** @brief Modifica el usuario identificado por id, segun el envio sea correcto o incorrecto.
        \pre Tiene que existir el usuario identificado por id, así como que este inscrito en un curso al que el problema p pertenezca, y que también el problema este dentro del conjunto de problemas al que el usuario puede hacer envios.
        \post Se modifica las estadísticas del usuario identificado por id, así como también las del problema enviado.
    */
    void enivio_problema(int r, string id, string p, string ses, Problemas& cjt_problemas, Sesiones& cjt_sesiones);

    //Consultoras

    /** @brief Consultora de el número de problemas enviables de un usuario concreto.
        \pre <em>cierto</em>
        \post El resultado es el número de problemas que se pueden enviar del usuario id.
    */   
    int consultar_num_enviables(const string id);

    /** @brief Consulta el número de usuarios registrados.
        \pre <em>cierto</em>
        \post El resultado és el número total de usuarios registrados en la plataforma.
    */
    int num_usuarios() const;

    /** @brief Consulta el curso en el que està apuntado un usuario.
        \pre Existe un usuario identificado por id.
        \post El resultado és el curso el que està apuntadon el usuario, o zero si no esta apuntado a ningún curso.
    */
    int curso_usuario(string id);

    /** @brief Consulta si existe un usario con identificador id.
        \pre <em>cierto</em>
        \post El resultado és el true si existe un usario con identificador id, y false si no exsite.
    */
    bool existe_usuarios(string id) const;

    /** @brief Consultora de si el usuario está inscrito en un curso.
        \pre <em>cierto</em>
        \post El resultado es true si el usuario está inscrito en un curso y false si no lo está.
    */   
    bool consultar_incscrito_curso(string id);
    
    /** @brief Consulta si un usuario puede enviar un problema. 
        \pre Tiene que existir el problema p.
        \post El resultado es true si el problema p es enviable para el usuario id, y false en caso contrario.
    */
    bool problema_enviable(string id, string p);

    //Escritura y lectura

    /** @brief Escribe por el canal standard de salida el conjunto de usuarios de forma ordenada. 
        \pre <em>cierto</em>
        \post El resultado es escribir en el canal standard de salida el conjunto de usuarios de forma ordenada.
    */
    void Escribir();

    /** @brief Escribe por el canal standard de salida el usuario concreto. 
        \pre El usuario identificado por id tiene que existir.
        \post El resultado es escribir en el canal standard de salida el usuario concreto.
    */
    void Escribir(string id);

    /** @brief Escribe en el canal standard de salida los problemas resueltos por el usuario identificado por id.
        \pre <em>cierto</em>
        \post Se ha escrito en el canal standard de salida los problemas resueltos por el usuario id en orden creciente.
    */   
    void escribir_resueltos(string id);

    /** @brief Escribe en el canal standard de salida los problemas enviables por el usuario identificado por id.
        \pre <em>cierto</em>
        \post Se ha escrito en el canal standard de salida los problemas enviables por el usuario id en orden creciente.
    */   
    void escribir_enviables(string id);

    /** @brief Lee por el canal standard de entrada el conjunto de usuarios. 
        \pre M > 0
        \post El resultado es leer del canal standard de entrada el conjunto de <em>P</em> usuarios.
    */
    void leer();
};

#endif

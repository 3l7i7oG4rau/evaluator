/**
 * @author Gerard Oliva Viñas
 * @mainpage 
 * Practica de Gerard Oliva Viñas, completando el proyecto EVALUATOR.
 * La implementación del programa principa se encuentra en program.cc.
 */

/** @file program.cc
    @brief Programa principal d'EVALUATOR <em>Plataforma de gestión de problemas i cursos de programación</em>.
*/

#ifndef NO_DIAGRAM 
using namespace std;
#include <iostream>
#endif

#include "Problema.hh"
#include "Problemas.hh"
#include "Usuari.hh"
#include "Sesion.hh"
#include "Usuarios.hh"
#include "Sesiones.hh"
#include "Curso.hh"
#include "Cursos.hh"

int main() {
    Problemas conjunt_problemes; //Se inicializan todos los conjunto como conjuntos vacíos.
    Usuarios conjunto_usuarios;
    Sesiones conjunto_sesiones;
    Cursos conjunto_cursos;
    conjunt_problemes.leer(); //Se lee cada conjunto para inicializarlos a los valores correctos de entrada.
    conjunto_sesiones.leer();
    conjunto_cursos.leer(conjunto_sesiones);
    conjunto_usuarios.leer();
    string comando;
    cin >> comando; //Se lee el comando que se queire ejecutar.
    while(comando != "fin"){
        //Cada <em>if</em> representa un comando, con su codigo correspondiente para poder realizar dicho comando.
        if(comando == "nuevo_problema" or comando == "np"){
            cout << "#" << comando;
            string id;
            cin >> id;
            cout << " " << id << endl;
            if(not conjunt_problemes.existe_problema(id)){
                conjunt_problemes.afegir_problema(id);
                cout << conjunt_problemes.num_problemas() << endl;
            }
            else cout << "error: el problema ya existe" << endl;
        }
        else if(comando == "nueva_sesion" or comando == "ns"){
            cout << "#" << comando;
            string s;
            cin >> s;
            cout << " " << s << endl;
            if(not conjunto_sesiones.existe_sesion(s)){
                Sesion ses;
                ses.leer();
                conjunto_sesiones.afegir_sesion(s,ses);
                cout << conjunto_sesiones.num_sesiones() << endl;
            }
            else cout << "error: la sesion ya existe" << endl;
        }
        else if(comando == "nuevo_curso" or comando == "nc"){
            cout << "#" << comando << endl;
            int s;
            cin >> s;
            Curso c;
            c.leer(s);
            if(conjunto_sesiones.poner_problemas_sesion(c)){
                conjunto_cursos.afegir_curso(c);
                cout << conjunto_cursos.num_cursos() << endl;
            }
            else cout << "error: curso mal formado" << endl;
        }
        else if(comando == "alta_usuario" or comando == "a"){
            cout << "#" << comando;
            string id;
            cin >> id;
            cout << " " << id << endl;
            if(not conjunto_usuarios.existe_usuarios(id)){
                conjunto_usuarios.afegir_usauri(id);
                cout << conjunto_usuarios.num_usuarios() << endl;
            }
            else cout << "error: el usuario ya existe" << endl;
        }
        else if(comando == "baja_usuario" or comando == "b"){
            cout << "#" << comando;
            string id;
            cin >> id;
            cout << " " << id << endl;
            if(conjunto_usuarios.existe_usuarios(id)){
                if(conjunto_usuarios.consultar_incscrito_curso(id)){
                    int c = conjunto_usuarios.curso_usuario(id);
                    conjunto_cursos.decrementar_usuarios_inscritos(c);
                }
                conjunto_usuarios.baja_usuario(id);
                cout << conjunto_usuarios.num_usuarios() << endl;
            }
            else cout << "error: el usuario no existe" << endl;
        }
        else if(comando == "inscribir_curso" or comando == "i"){
            cout << "#" << comando;
            string id;
            cin >> id;
            int c;
            cin >> c;
            cout << " " << id << " " << c << endl;
            if(conjunto_usuarios.existe_usuarios(id)){
                if(conjunto_cursos.existe_curso(c)){
                    if(not conjunto_usuarios.consultar_incscrito_curso(id)){
                        conjunto_usuarios.inscribir_usuario_curso(conjunto_cursos,conjunto_sesiones,id,c);
                        cout << conjunto_cursos.consultar_num_usuarios(c) << endl;
                    }
                    else cout << "error: usuario inscrito en otro curso" << endl;
                }
                else cout << "error: el curso no existe" << endl;
            }
            else cout << "error: el usuario no existe" << endl;
        }
        else if(comando == "curso_usuario" or comando == "cu"){
            cout << "#" << comando;
            string id;
            cin >> id;
            cout << " " << id << endl;
            if(conjunto_usuarios.existe_usuarios(id)){
                if(conjunto_usuarios.consultar_incscrito_curso(id)){
                    cout << conjunto_usuarios.curso_usuario(id) << endl;
                }
                else cout << 0 << endl;
            }
            else cout << "error: el usuario no existe" << endl;
        }
        else if(comando == "sesion_problema" or comando == "sp"){
            cout << "#" << comando;
            int c;
            cin >> c;
            string p;
            cin >> p;
            cout << " " << c << " " << p << endl;
            if(conjunto_cursos.existe_curso(c)){
                if(conjunt_problemes.existe_problema(p)){
                    string ses = conjunto_cursos.devolver_sesion_especifica(p,c);
                    if(ses!="0"){
                        cout << ses << endl;
                    }
                    else cout << "error: el problema no pertenece al curso" << endl;
                }
                else cout << "error: el problema no existe" << endl;
            }
            else cout << "error: el curso no existe" << endl;
        }
        else if(comando == "problemas_resueltos" or comando == "pr"){
            cout << "#" << comando;
            string id;
            cin >> id;
            cout << " " << id << endl;
            if(conjunto_usuarios.existe_usuarios(id)){
                conjunto_usuarios.escribir_resueltos(id);
            }
            else cout << "error: el usuario no existe" << endl;
        }
        else if(comando == "problemas_enviables" or comando == "pe"){
            cout << "#" << comando;
            string id;
            cin >> id;
            cout << " " << id << endl;
            if(conjunto_usuarios.existe_usuarios(id)){
                if(conjunto_usuarios.consultar_incscrito_curso(id)){
                    conjunto_usuarios.escribir_enviables(id);
                }
                else cout << "error: usuario no inscrito en ningun curso" << endl;
            }
            else cout << "error: el usuario no existe" << endl;
        }
        else if(comando == "envio" or comando == "e"){
            string id;
            cin >> id;
            string p;
            cin >> p;
            int r;
            cin >> r;
            cout << "#" << comando << " " << id << " " << p << " " << r << endl;
            int c = conjunto_usuarios.curso_usuario(id);
            conjunto_usuarios.enivio_problema(r,id,p,conjunto_cursos.devolver_sesion_especifica(p,conjunto_usuarios.curso_usuario(id)),conjunt_problemes,conjunto_sesiones);
            if(not conjunto_usuarios.consultar_incscrito_curso(id)){
                conjunto_cursos.decrementar_usuarios_inscritos(c);
                conjunto_cursos.incrementar_veces_resuelto(c);
            }
        }
        else if(comando == "listar_problemas" or comando == "lp"){
            cout << "#" << comando;
            cout << endl;
            conjunt_problemes.Escribir();
        }
        else if(comando == "escribir_problema" or comando == "ep"){
            cout << "#" << comando;
            string p;
            cin >> p;
            cout << " " << p << endl;
            if(conjunt_problemes.existe_problema(p)){
                conjunt_problemes.Escribir(p);
            }
            else cout << "error: el problema no existe" << endl;
        }
        else if(comando == "listar_sesiones" or comando == "ls"){
            cout << "#" << comando;
            cout << endl;
            conjunto_sesiones.Escribir();
        }
        else if(comando == "escribir_sesion" or  comando == "es"){
            cout << "#" << comando;
            string s;
            cin >> s;
            cout << " " << s << endl;
            if(conjunto_sesiones.existe_sesion(s)){
                conjunto_sesiones.Escribir(s);
            }
            else cout << "error: la sesion no existe" << endl;
        }
        else if(comando == "listar_cursos" or comando == "lc"){
            cout << "#" << comando;
            cout << endl;
            conjunto_cursos.Escribir();
        }
        else if(comando == "escribir_curso" or comando == "ec"){
            cout << "#" << comando;
            int c;
            cin >> c;
            cout << " " << c << endl;
            if(conjunto_cursos.existe_curso(c)){
                conjunto_cursos.Escribir(c);
            }
            else cout << "error: el curso no existe" << endl;
        }
        else if(comando == "listar_usuarios" or comando == "lu"){
            cout << "#" << comando;
            cout << endl;
            conjunto_usuarios.Escribir();
        }
        else if(comando == "escribir_usuario" or comando == "eu"){
            cout << "#" << comando;
            string id;
            cin >> id;
            cout << " " << id << endl;
            if(conjunto_usuarios.existe_usuarios(id)){
                conjunto_usuarios.Escribir(id);
            }
            else cout << "error: el usuario no existe" << endl;
        }
        //Por último se lee el siguiente que se quiere realizar, en caso que el comando sea <em>fin</em> el programa finaliza.
        cin >> comando;
    }
}

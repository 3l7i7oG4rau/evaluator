#include "Curso.hh"

    Curso::Curso(){
        veces_completado=0;
        usuarios_incritos=0;
    }

    int Curso::consultar_num_sesiones(){
        return conjunto_sesiones.size();
    }

    int Curso::consultar_num_usuarios(){
        return usuarios_incritos;
    }

    int Curso::consultar_veces_resuelto(){
        return veces_completado;
    }

    void Curso::incrementar_usuarios_inscritos(){
        ++usuarios_incritos;
    }

    void Curso::incrementar_veces_resuelto(){
        ++veces_completado;
    }

    list<string> Curso::lista_sesiones(){
        return conjunto_sesiones;
    }

    bool Curso::leer(int s){
        for(int i=0; i<s; ++i){
            string id;
            cin >> id;
            conjunto_sesiones.push_back(id);
        }
        return true;
    }

    void Curso::escribir_sesiones(){
        cout << "(";
        for(list<string>::iterator it=conjunto_sesiones.begin(); it!=conjunto_sesiones.end(); ++it){
            cout << (*it) << " ";
        }
        cout << '\b' << ")";
    }
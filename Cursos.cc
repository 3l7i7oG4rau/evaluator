#include "Cursos.hh"

    Cursos::Cursos(){}

    void Cursos::afegir_curso(const Curso& c){
        list_cursos.push_back(c);
    }

    int Cursos::num_cursos() const {
        return list_cursos.size();
    }

    bool Cursos::existe_curso(int id){
        if(list_cursos.size()<= id-1) return true;
        else return false;
    }

    int Cursos::consultar_num_usuarios(int c) {
        return list_cursos[c-1].consultar_num_usuarios();
    }

    list<string> Cursos::lista_sesiones(int c){
        list<string> L = list_cursos[c-1].lista_sesiones();
        return L;
    }

    void Cursos::Escribir(){
        for(int i=0; i<list_cursos.size(); ++i){
            cout << i+1 << " " << list_cursos[i].consultar_veces_resuelto() << " ";
            cout << list_cursos[i].consultar_num_usuarios() << " ";
            cout << list_cursos[i].consultar_num_sesiones() << " ";
            list_cursos[i].escribir_sesiones();
            cout << endl;
        }
    }

    void Cursos::Escribir(int i){
        cout << i << " " << list_cursos[i-1].consultar_veces_resuelto() << " ";
        cout << list_cursos[i-1].consultar_num_usuarios() << " ";
        cout << list_cursos[i-1].consultar_num_sesiones() << " ";
        list_cursos[i-1].escribir_sesiones();
        cout << endl;
    }

    void Cursos::leer(int N){
        for(int i=0; i<N; ++i){
            Curso c;
            list_cursos.push_back(c);
        }
    }
#include <iostream>
using namespace std;
class Lista
{
private:
    string cabeza;
    string cola;

public:
    string getCabeza(){
        return cabeza;
    }
    string getCola(){
        return cola;
    }
    void removerInicioYFin(string &s)  //quitar el primero y el ultimo parentesis.
    {
        s.erase(0, 1);
        s.erase(s.length() - 1, 1);
    }
    void setComponentes(string s) //hace el set de la lista y el de la cola, en un solo metodo para no copy pastear codigo.
    {
        removerInicioYFin(s);
        int indiceFinal = 0; //indice donde termina la cabeza
        string cabeza;
        int counter = 0;
        bool cabezaEncontrada = false;
        for (int i = 0; i < s.length() && !cabezaEncontrada; ++i)
        {
            char c = s[i];
            cabeza += c;
            if (c == '(')
            {
                ++counter;
            }
            else
            {
                if (c == ')')
                {
                    if (counter == 1)
                    {
                        this->cabeza=cabeza;
                        cabezaEncontrada = true;
                        indiceFinal = i;
                    }
                    else
                    {
                        --counter;
                    }
                }
            }
        }
        cola = s.substr(indiceFinal+1); //La cola va desde donde termina la cabeza, hasta el final de la lista
    }
};
int main()
{
    string s ="((4)((1 3)(2 1))(1))";
    Lista l;
    l.setComponentes(s);
    cout<<"Cabeza: "<<l.getCabeza()<<endl;
    cout <<"Cola: "<<l.getCola()<<endl;
    return 0;
}
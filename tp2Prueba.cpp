#include <iostream>
#include "List.h"
using namespace std;
class Decoder
{
public:
    void removerInicioYFin(string& s)  //quitar el primero y el ultimo parentesis.
    {
        s.erase(0, 1);
        s.erase(s.length() - 1, 1);
    }
    bool esListaBasica(string s) {
        return s.length() == 5 && s[0] == '(' && isdigit(s[1]) && s[2] == ' ' && isdigit(s[3]) && s[4] == ')';
    }
    bool esSoloCabeza(string s) {
        return s.length() == 3 && s[0] == '(' && isdigit(s[1]) && s[2] == ')';
    }
    List<int>* stringToList(string s) //hace el set de la lista y el de la cola, en un solo metodo para no copy pastear codigo.
    {
        List<int>* l= nullptr;
        List<int>* head = nullptr;
        List<int>* tail = nullptr;
        int valorAtomico = -1;
        if (esSoloCabeza(s)) {
            valorAtomico = (int)(s[1]-48);//Well, in ASCII code, the numbers(digits) start from 48. Stack Overflow es la biblia
        }
        else {
            if (esListaBasica(s)) {
                head = new List<int>((int)(s[1] - 48));  //deben ser pointers al parecer.
                tail = new List<int>((int)(s[3] - 48));
            }
            else {
                removerInicioYFin(s);
                string cabeza;
                int indiceFinal = 0; //indice donde termina la cabeza
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
                                head=stringToList(cabeza);
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
                string cola = s.substr(indiceFinal + 1); //La cola va desde donde termina la cabeza, hasta el final de la lista
                tail=stringToList(cola);
            }
        }
        l = new List<int>(head, tail, valorAtomico);
        return l;
     }
        
    };
int main()
{
    string s = "(((1 2)(3 4))(8 9))";
    Decoder d;
    List<int>* l=d.stringToList(s);
    cout <<"La cola de la cabeza es: "<< l->getHead()->getTail()->toString();
    return 0;
}
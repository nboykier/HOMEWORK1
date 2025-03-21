#include <iostream>
#include <memory>
using namespace std;

struct Node {
    int data;
    shared_ptr<Node> next;
};
//hago el struct que va a tener mi nodo con el dato y el puntero a next.

shared_ptr<Node> create_node(int value) {
    return make_shared<Node>(Node{value, nullptr});
}
//creo un nodo con un puntero a next que por ser el primer nodo es vacio.
//uso shared pointers para que se libere y maneje sola la memoria.

void push_front(shared_ptr<Node>& head, int value) {
    shared_ptr<Node> new_node = create_node(value);
    new_node->next = head;
    head = new_node;
}
//creo un nuevo nodo con un valor que le paso por parametro y tambien le paso el nodo head que va a ser el que creemos primero (en la primer ocasion) 
//y me sirve para tener una referncia precisa de que nodo es el primero asi inserto delante. Obviamente despues el nodo head pasa a ser nuestro nuevo nodo.

void push_back(shared_ptr<Node>& head, int value) {
    //paso como referencia el nodo head y el valor que le voy a poner al nuevo nodo.
    //si el head es null significa que la lista esta vacia y asigno este nodo como head.
    //en caso que haya head le asigno el valor de temp(temporal) y voy recorriendo nodos hasta que el next sea nulo.
    //eso significa que llegamos al final y ahi asignamos el valor next al nuevo nodo posicionandolo ultimo.

    shared_ptr<Node> new_node = create_node(value);
    if (!head) {
        head = new_node;
        return;
    }
    shared_ptr<Node> temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void insert(shared_ptr<Node>& head, int value, int position) {
    //voy buscando la posicion correcta con el while mientras recorro la lista.
    //si lo encuentro y es valido sale del while y no entra en el if y asigna el nodo en el lugar correspondiente con su debido puntero next.
    //en caso de que la posicion indicada es mas grande que el largo podemos hacer uso de la funcion de insertar al final, imprimimos el mensaje e insertamos.
    shared_ptr<Node> new_node = create_node(value);
    shared_ptr<Node> temp = head;
    int index = 0;
    while (temp && index < position - 1) {
        temp = temp->next;
        index++;
    }
    if (!temp) {  
    cout << "La posición indicada es más grande que el largo, por lo que se agregará al final." << endl;
    push_back(head, value);
    return;
}
    new_node->next = temp->next;
    temp->next = new_node;
}

void erase(shared_ptr<Node>& head, int position) {
    //si la posición es 0, se borra el primer nodo, como uso shared pointers no me tengo que preocupar por liberar la memroia.
    if (position == 0) {
        head = head->next;
        return;
    }
    //asigno el head como el nodo en el que empiezo a recorrer.
    shared_ptr<Node> temp = head;
    int index = 0;
    
    while (temp && index < position - 1) {
        temp = temp->next;
        index++;
    }

    if (!temp || !temp->next) {
      cout << "la lista no es tan larga, se borrara el ultimo." << endl;

      //si la lista tiene solo un nodo
      if (head && !head->next) {
          head = nullptr;
          return;
      }
      //buscamos el anteultimo nodo.
      temp = head;
      while (temp && temp->next && temp->next->next) {
          temp = temp->next;
      }

      //si el anteultimo tiene un siguiente lo borramos.
      if (temp && temp->next) {
          temp->next = nullptr;
      }
      return;
  }
    shared_ptr<Node> node_to_erase = temp->next;
    temp->next = temp->next->next;
    node_to_erase = nullptr;
    }

void print_list(shared_ptr<Node> head) {
    if (!head) {
        cout << "La lista está vacía." << endl;
        return;
    }//si la lista esta vacia no imprimo nada.

    shared_ptr<Node> temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) {
            cout << " -> ";
        }
        temp = temp->next;
    }//imprimo hasta que el nodo en el que estoy sea nulo y quiere decir que ya terminamos.
    cout << endl;
}

int main() {
    shared_ptr<Node> head = nullptr;
    //hago una secuencia de testeos con las mismas funciones para ir mostrando que funcionan.
    push_front(head, 10);
    push_front(head, 20);
    push_front(head, 30);
    cout << "Lista después de push_front: " << endl;
    print_list(head);

    push_back(head, 40);
    push_back(head, 50);
    cout << "Lista después de push_back:" << endl;
    print_list(head);

    insert(head, 25, 1);
    insert(head, 60, 100);
    cout << "Lista después de insert:" << endl;
    print_list(head);

    erase(head, 3);
    erase(head, 100);
    cout << "Lista después de erase:" << endl;
    print_list(head);
    return 0;
}
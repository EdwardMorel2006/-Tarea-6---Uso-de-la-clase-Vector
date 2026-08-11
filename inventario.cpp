
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;


struct Producto
{
    string nombre;
    float precio;
};
vector<Producto> inventario;

int main() {
    int cantidad;
    cout << "INGRESE LA CANTIDAD DE PRODUCTOS: ";
    cin >> cantidad;
    for (int i = 0; i < cantidad; i++)
    {
        Producto p;
        cout << "PRODUCTO " << i + 1 << endl;

        cout << "INGRESE EL NOMBRE DEL PRODUCTO: ";
        cin >> p.nombre;

        cout << "INGRESE EL PRECIO: ";
        cin >> p.precio;
        inventario.push_back(p);
    }

    cout << "LISTA DE PRODUCTOS" << endl;

    for (Producto p : inventario)
    {
        cout << p.nombre << " RD$ " << p.precio << endl;
        cout << endl;
    }

  // CONTINUACION: MODIFICAR PRECIO


    int posicion;
    float nuevoPrecio;

    cout << "INGRESE LA POSICION DEL PRODUCTO A MODIFICAR: ";
    cin >> posicion;

    try
    {
        cout << "Producto seleccionado: "
            << inventario.at(posicion).nombre << endl;

        cout << "Precio actual: RD$ "
            << inventario.at(posicion).precio << endl;

        cout << "INGRESE EL NUEVO PRECIO: ";
        cin >> nuevoPrecio;

        inventario.at(posicion).precio = nuevoPrecio;

        cout << "PRECIO MODIFICADO CORRECTAMENTE." << endl;
    }
    catch (out_of_range)
    {
        cout << "POSICION INVALIDA." << endl;
    }

 
    // CALCULAR PRECIO PROMEDIO
    

    float suma = 0;

    for (Producto p : inventario)
    {
        suma += p.precio;
    }

    float promedio = suma / inventario.size();

    cout << "\nPRECIO PROMEDIO: RD$ "
        << fixed << setprecision(2)
        << promedio << endl;

    // MOSTRAR LISTA ACTUALIZADA
  

    cout << "\nLISTA ACTUALIZADA DE PRODUCTOS" << endl;

    for (int i = 0; i < inventario.size(); i++)
    {
        cout << "Posicion: " << i
            << " | Producto: " << inventario[i].nombre
            << " | Precio: RD$ "
            << fixed << setprecision(2)
            << inventario[i].precio << endl;
    }

    return 0;
}

#include <iostream>
#include "../model/detalleFactura.h"
#include <vector>
#include <fstream>
using namespace std;
class DetalleFacturaController
{
private:
  vector<DetalleFactura> vectorDetalleFactura;

public:
  DetalleFacturaController()
  {
    cargarDatosDelArchivoAlVector();
  }
  void add(DetalleFactura obj)
  {
    vectorDetalleFactura.push_back(obj);
  }
  DetalleFactura get(int pos)
  {
    return vectorDetalleFactura[pos];
  }
  int size()
  {
    return vectorDetalleFactura.size();
  }
  void grabarArchivo(DetalleFactura obj)
  {
    try
    {
      fstream archivoDetalleFactura;
      archivoDetalleFactura.open("detalleFacturas.csv", ios::app);
      if(archivoDetalleFactura.is_open())
      {
        archivoDetalleFactura<<obj.getCodFac()<<";"<<obj.getCodProducto()<<";"<<obj.getPrecioProducto()<<";"<<obj.getCantidad()<<";"<<obj.getImporteProducto()<<";"<<endl;
        archivoDetalleFactura.close();
      }
    }
    catch(exception e)
    {
      cout<<"Ocurrio un error no se pudo grabar los datos en el archivo :c "<<endl;
    }
  }
  DetalleFactura buscar(int dato)
  {
    DetalleFactura objError;
    objError.setEstado("Error");
    for(int i = 0; i < vectorDetalleFactura.size(); i++)
    {
      if(dato == vectorDetalleFactura[i].getCodFac())
      {
        return vectorDetalleFactura[i];
      }
    }
    return objError;
  }
  bool modificar(DetalleFactura ObjOld, DetalleFactura ObjNew)
  {
    for(int i = 0; i < vectorDetalleFactura.size(); i++)
    {
      if(ObjOld.getCodFac() == vectorDetalleFactura[i].getCodFac())
      {
        vectorDetalleFactura[i].setCodFac(ObjNew.getCodFac());
        vectorDetalleFactura[i].setCodProducto(ObjNew.getCodProducto());
        vectorDetalleFactura[i].setPrecioProducto(ObjNew.getPrecioProducto());
        vectorDetalleFactura[i].setCantidad(ObjNew.getCantidad());
        vectorDetalleFactura[i].setSubTotal(ObjNew.getImporteProducto());
        vectorDetalleFactura[i].setEstado(ObjNew.getEstadoProducto());
        return true;
      }    
    }
    return false;
  }
  int getPostArray(DetalleFactura obj)
  {
    for(int i = 0; i < vectorDetalleFactura.size();i++)
    {
      if(obj.getCodFac() == vectorDetalleFactura[i].getCodFac())
      {
        return i;
      }
    } return -1;
  }
  void eliminar(DetalleFactura objEncontrado)
  {
    vectorDetalleFactura.erase(vectorDetalleFactura.begin() + getPostArray(objEncontrado));
  }
  void grabarDatosEliminadouModificadoAlVector()
  {
    try
    {
      fstream archivoDetalleFactura;
      archivoDetalleFactura.open("detalleFacturas.csv", ios::out);
      if(archivoDetalleFactura.is_open())
      {
        for(DetalleFactura x:vectorDetalleFactura)
        {
          archivoDetalleFactura<<x.getCodFac()<<";"<<x.getCodProducto()<<";"<<x.getPrecioProducto()<<";"<<x.getCantidad()<<";"<<x.getImporteProducto()<<";"<<endl;
        }
        archivoDetalleFactura.close();
      }
    }
    catch(exception e)
    {
      cout<<"No se graba la modificacion de los datos en el archivo :( "<<endl;
    }
  }
  void cargarDatosDelArchivoAlVector()
  {
    try
    {
      int i; 
      size_t posi;
      string linea;
      string temporal[6];
      fstream archivoDetalleFactura;
      archivoDetalleFactura.open("detalleFacturas.csv", ios::in);
      if(archivoDetalleFactura.is_open())
      {
        while(!archivoDetalleFactura.eof() && getline(archivoDetalleFactura, linea))
        {
          i = 0;
          while((posi = linea.find(";")) != string :: npos)
          {
            temporal[i] = linea.substr(0, posi);
            linea.erase(0, posi + 1);
            ++i; 
          }
          DetalleFactura objDetalleFactura(stoi(temporal[0]), stoi(temporal[1]), stoi(temporal[2]), stoi(temporal[3]), stoi(temporal[4]), temporal[5]);
          add(objDetalleFactura);
        }
      }
    }
    catch(exception e)
    {
      cout<<"Ocurrio un error al grabar el archivo :c "<<endl;
    }
  }
};

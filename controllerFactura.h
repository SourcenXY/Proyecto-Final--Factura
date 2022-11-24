#include <iostream>
#include <vector>
#include "../model/factura.h"
#include <fstream>
using namespace std;
class FacturaController
{
private:
  vector<Factura> vectorFactura;

public:
  FacturaController()
  {
    cargarDatosDelArchivoAlVector();
  }
  void add(Factura obj)
  {
    vectorFactura.push_back(obj);
  }
  Factura get(int pos)
  {
    return vectorFactura[pos];
  }
  int size()
  {
    return vectorFactura.size();
  }
  int getCorrelativo()
  {
    int i = 0;
    try
    {
      size_t posi;
      string linea;
      string temporal[4];
      fstream archivoFactura;
      archivoFactura.open("facturas.csv", ios::in);
      if(archivoFactura.is_open())
      {
        while(!archivoFactura.eof())
        {
          while (getline(archivoFactura, linea))
          {
            i += 1;
          }
          
        }
        archivoFactura.close();
      }
    }
    catch(exception e)
    {
      cout<<"Ocurrio un error con el archivo\n"<<endl;
    }
    return i;
  
  }
  void grabarArchivo(Factura obj)
  {
    try
    {
      fstream archivoFactura;
      archivoFactura.open("facturas.csv", ios::app);
      if(archivoFactura.is_open())
      {
        archivoFactura<<obj.getCodFactura()<<";"<<obj.getCodCliente()<<";"<<obj.getFechaFactura()<<";"<<obj.getImporteTotal()<<endl;
        archivoFactura.close();
      }
    }
    catch(exception e)
    {
      cout<<"Ocurrio un error, no se pudo grabar los datos en el archivo :c "<<endl;
    }
  }
  Factura buscar(int dato)
  {
    Factura objError;
    objError.setFechaFactura("Error");
    for(int i = 0; i < vectorFactura.size(); i++)
    {
      if(dato == vectorFactura[i].getCodFactura())
      {
        return vectorFactura[i];
      }
    }
    return objError;
  }
  int getPostArray(Factura obj)
  {
    for(int i = 0; i < vectorFactura.size();i++)
    {
      if(obj.getCodFactura() == vectorFactura[i].getCodFactura())
      {
        return i;
      }
    } return -1;
  }
  bool modificar(Factura ObjOld, Factura ObjNew)
  {
    for(int i = 0; i < vectorFactura.size(); i++)
    {
      if(ObjOld.getCodFactura() == vectorFactura[i].getCodFactura())
      {
        vectorFactura[i].setCodFactura(ObjNew.getCodFactura());
        vectorFactura[i].setCodCliente(ObjNew.getCodCliente());
        vectorFactura[i].setFechaFactura(ObjNew.getFechaFactura());
        vectorFactura[i].setImporteTotal(ObjNew.getImporteTotal());
        return true;
      }    
    }
    return false;
  }
  void eliminar(Factura objEncontrado)
  {
    vectorFactura.erase(vectorFactura.begin() + getPostArray(objEncontrado));
  }
  void grabarDatosEliminadouModificadoAlVector()
  {
    try
    {
      fstream archivoFactura;
      archivoFactura.open("facturas.csv", ios::out);
      if(archivoFactura.is_open())
      {
        for(Factura x:vectorFactura)
        {
          archivoFactura<<x.getCodFactura()<<";"<<x.getCodCliente()<<";"<<x.getFechaFactura()<<";"<<x.getImporteTotal()<<";"<<endl;
        }
        archivoFactura.close();
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
      string temporal[4];
      fstream archivoFactura;
      archivoFactura.open("facturas.csv", ios::in);
      if(archivoFactura.is_open())
      {
        while(!archivoFactura.eof() && getline(archivoFactura, linea))
        {
          i = 0;
          while((posi = linea.find(";")) != string :: npos)
          {
            temporal[i] = linea.substr(0, posi);
            linea.erase(0, posi + 1);
            ++i; 
          }
          Factura objFactura(stoi(temporal[0]), stoi(temporal[1]), temporal[2], stoi(temporal[3]));
          add(objFactura);
        }
      }
    }
    catch(exception e)
    {
      cout<<"Ocurrio un error al grabar el archivo :c "<<endl;
    } 
  }
};
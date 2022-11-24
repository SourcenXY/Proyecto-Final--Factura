#include <iostream>
#include <vector>
#include "../model/producto.h"
#include <fstream>
using namespace std;
class ProductoController
{
private:
  vector<Producto> vectorProducto;

public: 
  ProductoController()
  {
    cargarDatosDelArchivoAlVector();
  }
  void add(Producto obj)
  {
    vectorProducto.push_back(obj);
  }
  Producto get(int pos)
  {
    return vectorProducto[pos];
  }
  int size()
  {
    return vectorProducto.size();
  }
  int getCorrelativo()
  {
    if(size() == 0)
    {
      return 1;
    }
    else
    {
      return vectorProducto[size()-1].getCodPro()+1;
    }
  }
  void grabarArchivo(Producto obj)
  {
    try
    {
      fstream archivoProducto;
      archivoProducto.open("productos.csv", ios::app);
      if(archivoProducto.is_open())
      {
        archivoProducto<<obj.getCodPro()<<";"<<obj.getNomPro()<<";"<<obj.getPrePro()<<";"<<obj.getStockPro()<<";"<<obj.getCodCategoria()<<";"<<endl;
        archivoProducto.close();
      }
    }
    catch(exception e)
    {
      cout<<"Ocurrio un error no se pudo grabar los datos en el archivo :c "<<endl;
    }
  }
  Producto buscar(string dato)
  {
    Producto objError;
    objError.setNomPro("Error");
    for(int i = 0; i < vectorProducto.size(); i++)
    {
      if(dato == vectorProducto[i].getNomPro())
      {
        return vectorProducto[i];
      }
    }
    return objError;
  }
  Producto buscar2(int dato)
  {
    Producto objError;
    objError.setNomPro("Error");
    for(int i = 0; i < vectorProducto.size(); i++)
    {
      if(dato == vectorProducto[i].getCodPro())
      {
        return vectorProducto[i];
      }
    }
    return objError;
  }
  int getPostArray(Producto obj)
  {
    for(int i = 0; i < vectorProducto.size();i++)
    {
      if(obj.getNomPro() == vectorProducto[i].getNomPro())
      {
        return i;
      }
    } return -1;
  }
  bool modificar(Producto ObjOld, Producto ObjNew)
  {
    for(int i = 0; i < vectorProducto.size();i++)
    {
      if(ObjOld.getNomPro() == vectorProducto[i].getNomPro())
      {
        vectorProducto[i].setCodPro(ObjNew.getCodPro());
        vectorProducto[i].setNomPro(ObjNew.getNomPro());
        vectorProducto[i].setPrePro(ObjNew.getPrePro());
        vectorProducto[i].setStockPro(ObjNew.getStockPro());
        vectorProducto[i].setCodCategoria(ObjNew.getCodCategoria());
        return true;
      }    
    }
    return false;
  }
  
  void eliminar(Producto objEncontrado)
  {
    vectorProducto.erase(vectorProducto.begin() + getPostArray(objEncontrado));
  }
  void grabarDatosEliminadouModificadoAlVector()
  {
    try
    {
      fstream archivoProducto;
      archivoProducto.open("productos.csv", ios::out);
      if(archivoProducto.is_open())
      {
        for(Producto x:vectorProducto)
        {
          archivoProducto<<x.getCodPro()<<";"<<x.getNomPro()<<";"<<x.getPrePro()<<";"<<x.getStockPro()<<";"<<x.getCodCategoria()<<";"<<endl;
        }
        archivoProducto.close();
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
      string temporal[5];
      fstream archivoProducto;
      archivoProducto.open("productos.csv",ios::in);
      if(archivoProducto.is_open())
      {
        while(!archivoProducto.eof() && getline(archivoProducto, linea))
        {
          i = 0;
          while((posi = linea.find(";")) != string :: npos)
          {
            temporal[i] = linea.substr(0, posi);
            linea.erase(0, posi + 1);
            ++i;
          }
          Producto objProducto(stoi(temporal[0]), temporal[1], stoi(temporal[2]), stoi(temporal[3]), stoi(temporal[4]));
          add(objProducto);
        }
      }
      archivoProducto.close();
		}
		catch(exception e)
		{
			cout<<"Ocurrio un error al grabar el archivo :c "<<endl;
		}
	}
};
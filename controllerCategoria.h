#include <iostream>
#include <vector>
#include "../model/categoria.h"
#include <fstream>
using namespace std;
class CategoriaController
{
private: 
  vector<Categoria> vectorCategoria;

public:
  CategoriaController()
  {
    cargarDatosDelArchivoAlVector();
  }
  void add(Categoria obj)
  {
    vectorCategoria.push_back(obj);
  }
  Categoria get(int pos)
  {
    return vectorCategoria[pos];
  }
  int size()
  {
    return vectorCategoria.size();
  }
  int getCorrelativo()
  {
    if(size() == 0)
    {
      return 1;
    }
    else
    {
      return vectorCategoria[size()-1].getCodigo()+1;
    }
  }
  void grabarArchivo(Categoria obj)
  {
    try
    {
      fstream archivoCategoria;
      archivoCategoria.open("categorias.csv", ios::app);
      if(archivoCategoria.is_open())
      {
        archivoCategoria<<obj.getCodigo()<<";"<<obj.getNomCat()<<";"<<endl;
        archivoCategoria.close();
      }
    }
    catch(exception e)
    {
      cout<<"Ocurrio un error no se pudo grabar los datos en el archivo :c "<<endl;
    }
  }
  Categoria buscar(int dato)
  {
    Categoria objError;
    objError.setNomCat("Error");
    for(int i = 0; i < vectorCategoria.size(); i++)
    {
      if(dato==vectorCategoria[i].getCodigo())
      {
        return vectorCategoria[i];
      }
    }
    return objError;
  }
  int getPostArray(Categoria obj)
  {
    for(int i = 0; i < vectorCategoria.size();i++)
    {
      if(obj.getCodigo() == vectorCategoria[i].getCodigo())
      {
        return i;
      }
    } return -1;
  }
  bool modificar(Categoria ObjOld, Categoria ObjNew)
  {
    for(int i = 0; i < vectorCategoria.size(); i++)
    {
      if(ObjOld.getCodigo() == vectorCategoria[i].getCodigo())
      {
        vectorCategoria[i].setCodigo(ObjNew.getCodigo());
        vectorCategoria[i].setNomCat(ObjNew.getNomCat());
        return true;
      }    
    }
    return false;
  }
  void eliminar(Categoria objEncontrado)
  {
    vectorCategoria.erase(vectorCategoria.begin() + getPostArray(objEncontrado));
  }
  void grabarDatosEliminadouModificadoAlVector()
  {
    try
    {
      fstream archivoCategoria;
      archivoCategoria.open("categorias.csv", ios::out);
      if(archivoCategoria.is_open())
      {
        for(Categoria x:vectorCategoria)
        {
          archivoCategoria<<x.getCodigo()<<";"<<x.getNomCat()<<";"<<endl;
        }
        archivoCategoria.close();
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
      string temporal[2];
      fstream archivoCategoria;
      archivoCategoria.open("categorias.csv", ios::in);
      if(archivoCategoria.is_open())
      {
        while(!archivoCategoria.eof() && getline(archivoCategoria, linea))
        {
          i = 0;
          while((posi = linea.find(";")) != string :: npos)
          {
            temporal[i] = linea.substr(0, posi);
            linea.erase(0, posi + 1);
            ++i; 
          }
          Categoria objCategoria(stoi(temporal[0]), temporal[1]);
          add(objCategoria);
        }
      }
      archivoCategoria.close();
    }
    catch(exception e)
    {
      cout<<"Ocurrio un error al grabar el archivo :c "<<endl;
    } 
  }
};
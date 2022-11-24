#include <iostream>
#include "../model/tipoPersonal.h"
#include <vector>
#include <fstream>
using namespace std;
class TipoPersonalController
{
private:
  vector<TipoPersonal> vectorTipoPersonal;

public:
  TipoPersonalController()
  {
    GrabarDatosDelArchivoAlVector();
  }
  void add(TipoPersonal obj)
  {
    vectorTipoPersonal.push_back(obj);
  }
  TipoPersonal get(int pos)
  {
    return vectorTipoPersonal[pos];
  }
  int size()
  {
    return vectorTipoPersonal.size();
  }
  int getCorrelativo()
  {
    if(size() == 0)
    {
      return 1;
    }
    else
    {
      return vectorTipoPersonal[size()-1].getCodTipPer()+1;
    }
  }
  void GrabarArchivo(TipoPersonal obj)
  {
    try
    {
      fstream archivoTipoPersonal;
      archivoTipoPersonal.open("tipoPersonal.csv", ios::app);
      if(archivoTipoPersonal.is_open())
      {
        archivoTipoPersonal<<obj.getCodTipPer()<<";"<<obj.getNomTipPer()<<";"<<endl;
        archivoTipoPersonal.close();
      }
    }
    catch(exception e)
    {
      cout<<"Ocurrio un error al grabar en el archivo :c "<<endl;
    }
  }
  TipoPersonal buscar(int dato)
  {
    TipoPersonal objError;
    objError.setNomTipPer("Error");
    for(int i = 0; i < vectorTipoPersonal.size(); i++)
    {
      if(dato==vectorTipoPersonal[i].getCodTipPer())
      {
        return vectorTipoPersonal[i];
      }
    }
    return objError;
  }
  bool modificar(TipoPersonal ObjOld, TipoPersonal ObjNew)
  {
    for(int i = 0; i < vectorTipoPersonal.size();i++)
    {
      if(ObjOld.getCodTipPer() == vectorTipoPersonal[i].getCodTipPer())
      {
        vectorTipoPersonal[i].setCodTipPer(ObjNew.getCodTipPer());
        vectorTipoPersonal[i].setNomTipPer(ObjNew.getNomTipPer());
        return true;
      }    
    }
    return false;
  }
  int getPostArray(TipoPersonal obj)
  {
    for(int i = 0; i < vectorTipoPersonal.size();i++)
    {
      if(obj.getCodTipPer() == vectorTipoPersonal[i].getCodTipPer())
      {
        return i;
      }
    } return -1;
  }
  void eliminar(TipoPersonal objEncontrado)
  {
    vectorTipoPersonal.erase(vectorTipoPersonal.begin() + getPostArray(objEncontrado));
  }
  void grabarDatosEliminadouModificadoAlVector()
  {
    try
    {
      fstream archivoTipoPersonal;
      archivoTipoPersonal.open("tipoPersonal.csv", ios::out);
      if(archivoTipoPersonal.is_open())
      {
        for(TipoPersonal x:vectorTipoPersonal)
        {
          archivoTipoPersonal<<x.getCodTipPer()<<";"<<x.getNomTipPer()<<";"<<endl;
        }
        archivoTipoPersonal.close();
      }
    }
    catch(exception e)
    {
      cout<<"No se graba la modificacion de los datos en el archivo :( "<<endl;
    }
  }
  void GrabarDatosDelArchivoAlVector()
  {
    try
    {
      int i;
      size_t posi;
      string linea;
      string temporal[2];
      fstream archivoTipoPersonal;
      archivoTipoPersonal.open("tipoPersonal.csv", ios::in);
      if(archivoTipoPersonal.is_open())
      {
        while(!archivoTipoPersonal.eof() && getline(archivoTipoPersonal, linea))
        {
          i = 0;
          while((posi = linea.find(";")) != string :: npos)
          {
            temporal[i] = linea.substr(0, posi);
            linea.erase(0, posi + 1);
            ++i;
          }
          TipoPersonal objTipoPersonal(stoi(temporal[0]), temporal[1]);
          add(objTipoPersonal);
        }
      }
    }
    catch(exception e)
    {
      cout<<"Ocurrio un error al grabar en el archivo :c "<<endl;
    }
  }
};
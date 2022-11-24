#include <iostream>
#include "../model/personal.h"
#include <vector>
#include <fstream>
using namespace std;
class PersonalController
{
private:
  vector<Personal> vectorPersonal;

public:
  PersonalController()
  {
    GrabarDatosDelArchivoAlVector();
  }
  void add(Personal obj)
  {
    vectorPersonal.push_back(obj);
  }
  Personal get(int pos)
  {
    return vectorPersonal[pos];
  }
  int size()
  {
    return vectorPersonal.size();
  }
  int getCorrelativo()
  {
    if(size() == 0)
    {
      return 1;
    }
    else
    {
      return vectorPersonal[size()-1].getCodPersonal()+1;
    }
  }
  void GrabarArchivo(Personal obj)
  {
    try
    {
      fstream archivoPersonal;
      archivoPersonal.open("personal.csv", ios::app);
      if(archivoPersonal.is_open())
      {
        archivoPersonal<<obj.getCodPersonal()<<";"<<obj.getNomApePer()<<";"<<obj.getDniPer()<<";"<<obj.getSuelPer()<<";"<<obj.getCodTipPer()<<";"<<endl;
        archivoPersonal.close();
      }
    }
    catch(exception e)
    {
      cout<<"Ocurrio un error al grabar en el archivo :c "<<endl;
    }
  }
  Personal buscar(int dato)
  {
    Personal objError;
    objError.setNomApePer("Error");
    for(int i = 0; i < vectorPersonal.size(); i++)
    {
      if(dato==vectorPersonal[i].getCodPersonal())
      {
        return vectorPersonal[i];
      }
    }
    return objError;
  }
  bool modificar(Personal ObjOld, Personal ObjNew)
  {
    for(int i = 0; i < vectorPersonal.size();i++)
    {
      if(ObjOld.getCodPersonal() == vectorPersonal[i].getCodPersonal())
      {
        vectorPersonal[i].setCodPersonal(ObjNew.getCodPersonal());
        vectorPersonal[i].setNomApePer(ObjNew.getNomApePer());
        vectorPersonal[i].setDniPer(ObjNew.getDniPer());
        vectorPersonal[i].setSuelPer(ObjNew.getSuelPer());
        vectorPersonal[i].setCodTipPer(ObjNew.getCodTipPer());
        return true;
      }    
    }
    return false;
  }
  int getPostArray(Personal obj)
  {
    for(int i = 0; i < vectorPersonal.size();i++)
    {
      if(obj.getCodPersonal() == vectorPersonal[i].getCodPersonal())
      {
        return i;
      }
    } return -1;
  }
  void eliminar(Personal objEncontrado)
  {
    vectorPersonal.erase(vectorPersonal.begin() + getPostArray(objEncontrado));
  }
  void grabarDatosEliminadouModificadoAlVector()
  {
    try
    {
      fstream archivoPersonal;
      archivoPersonal.open("personal.csv", ios::out);
      if(archivoPersonal.is_open())
      {
        for(Personal x:vectorPersonal)
        {
          archivoPersonal<<x.getCodPersonal()<<";"<<x.getNomApePer()<<";"<<x.getDniPer()<<";"<<x.getSuelPer()<<";"<<x.getCodTipPer()<<";"<<endl;
        }
        archivoPersonal.close();
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
      string temporal[5];
      fstream archivoPersonal;
      archivoPersonal.open("personal.csv", ios::in);
      if(archivoPersonal.is_open())
      {
        while(!archivoPersonal.eof() && getline(archivoPersonal, linea))
        {
          i = 0;
          while((posi = linea.find(";")) != string :: npos)
          {
            temporal[i] = linea.substr(0, posi);
            linea.erase(0, posi + 1);
            ++i;
          }
          Personal objPersonal(stoi(temporal[0]), temporal[1], temporal[2], stoi(temporal[3]), stoi(temporal[4]));
          add(objPersonal);
        }
      }
    }
    catch(exception e)
    {
      cout<<"Ocurrio un error al grabar en el archivo :c "<<endl;
    }
  }
};
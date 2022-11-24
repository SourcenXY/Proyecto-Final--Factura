#include <iostream>
#include <vector>
#include "../model/cliente.h"
#include <fstream>
using namespace std;
class ClienteController
{
private:
  vector<Cliente> vectorCliente;

public:
  ClienteController()
  {
    GrabarDatosDelArchivoAlVector();
  }
  void add(Cliente obj)
  {
    vectorCliente.push_back(obj);
  }
  Cliente get(int pos)
  {
    return vectorCliente[pos];
  }
  int size()
  {
    return vectorCliente.size();
  }
  int getCorrelativo()
  {
    if(size() == 0)
    {
      return 1;
    }
    else
    {
      return vectorCliente[size()-1].getCodCliente()+1;
    }
  }
  void GrabarArchivo(Cliente obj)
  {
    try
    {
      fstream archivoCliente;
      archivoCliente.open("cliente.csv", ios::app);
      if(archivoCliente.is_open())
      {
        archivoCliente<<obj.getCodCliente()<<";"<<obj.getNomCliente()<<";"<<obj.getDniCliente()<<";"<<endl;
        archivoCliente.close();
      }
      archivoCliente.close();
    }
    catch(exception e)
    {
      cout<<"Ocurrio un error al grabar en el archivo :c "<<endl;
    }
  }
  Cliente buscar(int dato)
  {
    Cliente objError;
    objError.setNomCliente("Error");
    for(int i = 0; i < vectorCliente.size(); i++)
    {
      if(dato==vectorCliente[i].getCodCliente())
      {
        return vectorCliente[i];
      }
    }
    return objError;
  }
  int getPostArray(Cliente obj)
  {
    for(int i = 0; i < vectorCliente.size();i++)
    {
      if(obj.getCodCliente() == vectorCliente[i].getCodCliente())
      {
        return i;
      }
    } return -1;
  }
  bool modificar(Cliente ObjOld, Cliente ObjNew)
  {
    for(int i = 0; i < vectorCliente.size();i++)
    {
      if(ObjOld.getCodCliente() == vectorCliente[i].getCodCliente())
      {
        vectorCliente[i].setCodCliente(ObjNew.getCodCliente());
        vectorCliente[i].setNomCliente(ObjNew.getNomCliente());
        vectorCliente[i].setDniCliente(ObjNew.getDniCliente());
        return true;
      }    
    }
    return false;
  }
  void eliminar(Cliente objEncontrado)
  {
    vectorCliente.erase(vectorCliente.begin() + getPostArray(objEncontrado));
  }
  void grabarDatosEliminadouModificadoAlVector()
  {
    try
    {
      fstream archivoCliente;
      archivoCliente.open("cliente.csv", ios::out);
      if(archivoCliente.is_open())
      {
        for(Cliente x:vectorCliente)
        {
          archivoCliente<<x.getCodCliente()<<";"<<x.getNomCliente()<<";"<<x.getDniCliente()<<";"<<endl;
        }
        archivoCliente.close();
      }
    }
    catch(exception e)
    {
      cout<<"No se grabo la modificacion de los datos en el archivo :( "<<endl;
    }
  }
  void GrabarDatosDelArchivoAlVector()
  {
    try
    {
      int i;
      size_t posi;
      string linea;
      string temporal[3];
      fstream archivoCliente;
      archivoCliente.open("cliente.csv", ios::in);
      if(archivoCliente.is_open())
      {
        while(!archivoCliente.eof() && getline(archivoCliente, linea))
        {
          i = 0;
          while((posi = linea.find(";")) != string :: npos)
          {
            temporal[i] = linea.substr(0, posi);
            linea.erase(0, posi + 1);
            ++i;
          }
          Cliente objCliente(stoi(temporal[0]), temporal[1], temporal[2]);
          add(objCliente);
        }
      }
      archivoCliente.close();
    }
    catch(exception e)
    {
      cout<<"Ocurrio un error al grabar en el archivo :c "<<endl;
    }
  }
};
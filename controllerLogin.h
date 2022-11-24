#include <iostream>
#include <vector>
#include "../model/login.h"
#include <fstream>
using namespace std;

class LoginController
{
  private:
  vector<Login> vectorLogin;

  public:
  LoginController()
  {
    cargarDatosDelArchivoAlVector();
  }
  void add(Login obj)
  {
    vectorLogin.push_back(obj);
  }
  Login get(int pos)
  {
    return vectorLogin[pos];
  }
  int size()
  {
    return vectorLogin.size();
  }
  void grabarDatosAlArchivo(Login obj)
  {
    try
    {
      fstream archivoLogin;
      archivoLogin.open("login.csv", ios::app);
      if(archivoLogin.is_open())
      {
        archivoLogin<<obj.getUsuario()<<";"<<obj.getContraseña()<<";"<<endl;
        archivoLogin.close();
      }
    }
    catch(exception e)
    {
      cout<<"El archivo no se guardo de manera correcta ";
    }
  }
  Login login(string dato1, string dato2)
  {
    Login objError;
    objError.setUsuario("Error");
    for(int i = 0; i < vectorLogin.size(); i++)
    {
      if(dato1 == vectorLogin[i].getUsuario() && dato2 == vectorLogin[i].getContraseña())
      {
        return vectorLogin[i];
      }
    }
    return objError;
  }
  void cargarDatosDelArchivoAlVector()
  {
    try
    {
      int i;
      size_t pos;
      string linea;
      string temporal[2];
      fstream archivoLogin;
      archivoLogin.open("login.csv",ios::in);
      if(archivoLogin.is_open())
      {
        while (!archivoLogin.eof() && getline(archivoLogin, linea))
        {
          i = 0;
          while((pos = linea.find(";")) != string :: npos)
          {
            temporal[i] = linea.substr(0,pos);
            linea.erase(0, pos + 1);
            ++i;
          }
          Login objLogin(temporal[0], temporal[1]);
          add(objLogin);
        }
      }
    }
    catch(exception e)
    {
      cout<<"No se grabaron los datos de manera correcta en el archivo ";
    }
  }
};
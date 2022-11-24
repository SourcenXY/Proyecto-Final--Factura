#include <iostream>
using namespace std;
class Login
{
private:
  string usuario;
  string contraseña;

public:
  Login()
  {

  }
  Login(string usuario, string contraseña)
  {
    this->usuario = usuario;
    this->contraseña = contraseña;
  }
  
  void setUsuario(string usuario)
  {
    this->usuario = usuario;
  }
  void setContraseña(string contraseña)
  {
    this->contraseña = contraseña;
  }
  
  string getUsuario()
  {
    return this->usuario;
  }
  string getContraseña()
  {
    return this->contraseña;
  }
};
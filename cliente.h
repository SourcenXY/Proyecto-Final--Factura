#include <iostream>
using namespace std;
class Cliente
{
private:
  int codCliente;
  string nomCliente;
  string dniCliente;

public:
  Cliente()
  {

  }
  Cliente(int codCliente, string nomCliente, string dniCliente)
  {
    this->codCliente = codCliente;
    this->nomCliente = nomCliente;
    this->dniCliente = dniCliente;
  }

  void setCodCliente(int codCliente)
  {
    this->codCliente = codCliente;
  }
  void setNomCliente(string nomCliente)
  {
    this->nomCliente = nomCliente;
  }
  void setDniCliente(string DniCliente)
  {
    this->dniCliente = dniCliente;
  }

  int getCodCliente()
  {
    return this->codCliente;
  }
  string getNomCliente()
  {
    return this->nomCliente;
  }
  string getDniCliente()
  {
    return this->dniCliente;
  }
};
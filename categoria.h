#include <iostream>
using namespace std;
class Categoria
{
private:
  int codigo;
  string nomCat;

public:
  Categoria()
  {

  }
  Categoria(int codigo, string nomCat)
  {
    this->codigo = codigo;
    this->nomCat = nomCat;
  }

  void setCodigo(int codigo)
  {
    this->codigo = codigo;
  }
  void setNomCat(string nomCat)
  {
    this->nomCat = nomCat;
  }

  int getCodigo()
  {
    return this->codigo;
  }
  string getNomCat()
  {
    return this->nomCat;
  }
};
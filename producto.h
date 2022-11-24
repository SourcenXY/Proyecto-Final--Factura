#include <iostream>
using namespace std;
class Producto
{
private:
  int codPro;
  string nomPro;
  float prePro;
  int stockPro;
  int codCategoria;

public: 
  Producto()
  {

  }
  Producto(int codPro, string nomPro, float prePro, int stockPro, int codCategoria)
  {
    this->codPro = codPro;
    this->nomPro = nomPro;
    this->prePro = prePro;
    this->stockPro = stockPro;
    this->codCategoria = codCategoria;
  }
  
  void setCodPro(int codPro)
  {
    this->codPro = codPro;
  }
  void setNomPro(string nomPro)
  {
    this->nomPro = nomPro;
  }
  void setPrePro(float prePro)
  {
    this->prePro = prePro;
  }
  void setStockPro(int stockPro)
  {
    this->stockPro = stockPro;
  }
  void setCodCategoria(int codCategoria)
  {
    this->codCategoria = codCategoria;
  }

  int getCodPro()
  {
    return this->codPro;
  }
  string getNomPro()
  {
    return this->nomPro;
  }
  float getPrePro()
  {
    return this->prePro;
  }
  int getStockPro()
  {
    return this->stockPro;
  }
  int getCodCategoria()
  {
    return this->codCategoria;
  }
};
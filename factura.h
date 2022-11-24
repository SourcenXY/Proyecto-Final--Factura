#include <iostream>
using namespace std;
class Factura 
{
private:
  int codFactura;
  int codCliente;
  string fechaFactura;
  float importeTotal;

public:
  Factura()
  {

  }
  Factura(int codFactura, int codCliente, string fechaFactura, float importeTotal)
  {
    this->codFactura = codFactura;
    this->codCliente = codCliente;
    this->fechaFactura = fechaFactura;
    this->importeTotal = importeTotal;
  }
  
  void setCodFactura(int codFactura)
  {
    this->codFactura = codFactura;
  }
  void setCodCliente(int codCliente)
  {
    this->codCliente = codCliente;
  }
  void setFechaFactura(string fechaFactura)
  {
    this->fechaFactura = fechaFactura;
  }
  void setImporteTotal(float importeTotal)
  {
    this->importeTotal = importeTotal;
  }
  
  int getCodFactura()
  {
    return this->codFactura;
  }
  int getCodCliente()
  {
    return this->codCliente;
  }
  string getFechaFactura()
  {
    return this->fechaFactura;
  }
  float getImporteTotal()
  {
    return this->importeTotal;
  }
  
};
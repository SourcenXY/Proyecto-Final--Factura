#include <iostream>
using namespace std;
class DetalleFactura
{
private:

  int codFac;
  int codProducto;
  float precioProducto;
  int cantidad;
  float subTotal;
  string estado;

public:
  DetalleFactura()
  {

  }
  DetalleFactura(int codFac, int codProducto, float precioProducto, int cantidad, float subTotal, string estado)
  {
    this->codFac = codFac;
    this->codProducto = codProducto;
    this->precioProducto = precioProducto;
    this->cantidad = cantidad;
    this->subTotal = subTotal;
    this->estado = estado;
  }

  void setCodFac(int codFac)
  {
    this->codFac = codFac;
  }
  void setCodProducto(int codProducto)
  {
    this->codProducto = codProducto;
  }
  void setPrecioProducto(float precioProducto)
  {
    this->precioProducto = precioProducto;
  }
  void setCantidad(int cantidad)
  {
    this->cantidad = cantidad;
  }
  void setSubTotal(float subTotal)
  {
    this->subTotal = subTotal;
  }
  void setEstado(string estado)
  {
    this->estado = estado;
  }

  int getCodFac()
  {
    return this->codFac;
  }
  int getCodProducto()
  {
    return this->codProducto;
  }
  float getPrecioProducto()
  {
    return this->precioProducto;
  }
  int getCantidad()
  {
    return this->cantidad;
  }
  float getImporteProducto()
  {
    return this->subTotal;
  }
  string getEstadoProducto()
  {
    return this->estado;
  }
};
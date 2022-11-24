#include <iostream>
using namespace std;
class Personal
{
private:
  int codPersonal;
  string nomApePer;
  string dniPer;
  float suelPer;
  int codTipPer;

public:
  Personal()
  {

  }
  Personal(int codPersonal, string nomApePer, string dniPer, float suelPer, int codTipPer)
  {
    this->codPersonal = codPersonal;
    this->nomApePer = nomApePer;
    this->dniPer = dniPer;
    this->suelPer = suelPer;
    this->codTipPer = codTipPer;
  }

  void setCodPersonal(int codPersonal)
  {
    this->codPersonal = codPersonal;
  }
  void setNomApePer(string nomApePer)
  {
    this->nomApePer = nomApePer;
  }
  void setDniPer(string dniPer)
  {
    this->dniPer = dniPer;
  }
  void setSuelPer(float suelPer)
  {
    this->suelPer = suelPer;
  }
  void setCodTipPer(int codTipPer)
  {
    this->codTipPer = codTipPer;
  }
  
  int getCodPersonal()
  {
    return this->codPersonal;
  }
  string getNomApePer()
  {
    return this->nomApePer;
  }
  string getDniPer()
  {
    return this->dniPer;
  }
  float getSuelPer()
  {
    return this->suelPer;
  }
  int getCodTipPer()
  {
    return this->codTipPer;
  }
};
#include <iostream>
#include <string>
#include <cstdlib>
#include "controller/controllerLogin.h"
#include "controller/controllerCliente.h"
#include "controller/controllerPersonal.h"
#include "controller/controllerTipoPersonal.h"
#include "controller/controllerProducto.h"
#include "controller/controllerCategoria.h"
#include "controller/controllerFactura.h"
#include "controller/controllerDetalleFactura.h"
using namespace std;
LoginController* logController = new LoginController();
ClienteController* clieController = new ClienteController();
PersonalController* perController = new PersonalController();
TipoPersonalController* tipPerController = new TipoPersonalController();
ProductoController* proController = new ProductoController();
CategoriaController* cateController = new CategoriaController();
FacturaController* factuController = new FacturaController();
DetalleFacturaController* detaFactuController = new DetalleFacturaController();
void menuOpciones();
void Cuenta();
void crearCuenta();
void iniciarSesion();
void menu();
void ClienteMenu();
void registrarCliente();
void buscarCliente();
void modificarCliente();
void eliminarCliente();
void listarCliente();
void PersonalMenu();
void registrarPersonal();
void buscarPersonal();
void modificarPersonal();
void eliminarPersonal();
void listarPersonal();
void tipoPersonalMenu();
void registrarTipoPersonal();
void buscarTipoPersonal();
void modificarTipoPersonal();
void eliminarTipoPersonal();
void listarTipoPersonal();
void ProductoMenu();
void registrarProducto();
void buscarProducto();
void modificarProducto();
void eliminarProducto();
void listarProducto();
void CategoriaMenu();
void registrarCategoria();
void buscarCategoria();
void modificarCategoria();
void eliminarCategoria();
void listarCategoria();
void FacturaMenu();
void registrarFactura();
void buscarFactura();
void modificarFactura();
void eliminarFactura();
void listarFactura();
int main()
{
  menuOpciones();

  return 0;
}
void menuOpciones()
{
  int opt;
  do
  {
    cout<<"\t\tBIENVENIDO AL PROGRAMA\n";
    cout<<"CREAR NUEVA CUENTA*****[1]\n";
    cout<<"INICIAR SESION*********[2]\n";
    cout<<"SALIR DEL PROGRAMA*****[3]\n";
    cout<<"\n";
    cout<<"Ingrese una opcion: "; cin>>opt;

    switch(opt)
    {
      case 1: system("cls"); crearCuenta(); break;
      case 2: system("cls"); iniciarSesion(); break;
      case 3: cout<<"Gracias por usar nuestro programa :) "; break;
      default: cout<<"Ingrese una opcion [1-3]: \n"<<endl;
    }
  } while(opt!=3);
}
void crearCuenta()
{
  string flag;
  string usu;
  string contra;

  do
  {
    cout<<"\tCREAR CUENTA\n"<<endl;
    cin.ignore();
    cout<<"Ingrese un Usuario: "; getline(cin, usu);
    cout<<"Ingrese una Contraseña: "; getline(cin, contra);
    cout<<"\n";
    cout<<"Desea continuar (S/s): "; cin>>flag;

    Login objLogin(usu, contra);
    logController->add(objLogin);
    logController->grabarDatosAlArchivo(objLogin);
    system("cls");

  } while (flag == "S" || flag == "s");
}
void iniciarSesion()
{
  string usu;
  string contra;

  cout<<"\tINICIAR SESION\n"<<endl;
  cin.ignore();
  cout<<"Ingrese su usuario: "; getline(cin, usu);
  cout<<"Ingrese su contraseña: "; getline(cin, contra);
  Login objInicio = logController->login(usu, contra);
  if(objInicio.getUsuario() != "Error")
  {
    system("cls");
    cout<<"\t\tBIENVENIDO\n"<<endl;
    cout<<"Ahora registre los datos :) "<<endl;
    cout<<"\n";
    menu();
  }
  else
  {
    cout<<"El usuario o contraseña esta(n) incorrectas "<<endl;
    system("pause");
    system("cls");
  }

}
void menu()
{
  int opt;
  do
  {
    cout<<"*****************CLIENTE*****************[1]\n";
    cout<<"*****************PERSONAL****************[2]\n";
    cout<<"*****************TIPO PERSONAL***********[3]\n";
    cout<<"*****************PRODUCTO****************[4]\n";
    cout<<"*****************CATEGORIA***************[5]\n";
    cout<<"*****************FACTURA*****************[6]\n";
    cout<<"REGRESAR A LA PAGINA PRINCIPAL***********[7]\n";
    cout<<"Ingrese una opcion: "; cin>>opt;

    switch (opt)
    {
    case 1: system("cls"); ClienteMenu(); break;
    case 2: system("cls"); PersonalMenu(); break;
    case 3: system("cls"); tipoPersonalMenu(); break;
    case 4: system("cls"); ProductoMenu(); break;
    case 5: system("cls"); CategoriaMenu(); break;
    case 6: system("cls"); FacturaMenu(); break;
    case 7: system("cls"); menuOpciones(); break;
    default: cout<<"Ingrese una opcion[1-7]: "<<endl;

    }
  } while (opt != 7);
  
}
void ClienteMenu()
{
  int opt;
  do
  {
    cout<<"\t\t\tCLIENTE\n"<<endl;
    cout<<"REGISTRAR CLIENTE********************[1]\n";
    cout<<"BUSCAR CLIENTE***********************[2]\n";
    cout<<"MODIFICAR CLIENTE********************[3]\n";
    cout<<"ELIMINAR CLIENTE*********************[4]\n";
    cout<<"LISTAR CLIENTE***********************[5]\n";
    cout<<"REGRESAR A LA MENU DE OPCIONES*******[6]\n";
    cout<<"Ingrese una opcion: "; cin>>opt;

    switch (opt)
    {
    case 1: system("cls"); registrarCliente(); break;
    case 2: system("cls"); buscarCliente(); break;
    case 3: system("cls"); modificarCliente(); break;
    case 4: system("cls"); eliminarCliente(); break;
    case 5: system("cls"); listarCliente(); break;
    case 6: system("cls"); menu(); break;
    default: cout<<"Ingrese una opcion[1-6]: "<<endl;

    }
  } while (opt != 6);
  
}
void registrarCliente()
{
  int codCliente;
  string nomApeCliente;
  string dni;
  string flag;
  do
  {
    cout<<"\t\tCLIENTE\n"<<endl;
    codCliente = clieController->getCorrelativo();
    cout<<"\t*****CODIGO CLIENTE["<<codCliente<<"]*****"<<endl;
    cin.ignore();
    cout<<"Ingrese el nombre y apellido del Cliente: "; getline(cin, nomApeCliente);
    cout<<"Ingrese el DNI del Cliente: "; getline(cin, dni);
    cout<<"Desea continuar(S/s): "; cin>>flag;

    Cliente objClie(codCliente, nomApeCliente, dni);
    clieController->add(objClie);
    clieController->GrabarArchivo(objClie);
    system("cls");
  } while (flag == "S" || flag == "s");
  
}
void buscarCliente()
{
  int codClie;
  cout<<"Ingrese el codigo del Cliente ha buscar: "; cin>>codClie;
  Cliente objEncontrado = clieController->buscar(codClie);
  if(objEncontrado.getNomCliente() != "Error")
  {
    cout<<"Cliente encontrado "<<endl;
    cout<<"Codigo del Cliente: "<<objEncontrado.getCodCliente()<<endl;
    cout<<"Nombre del Cliente: "<<objEncontrado.getNomCliente()<<endl;
    cout<<"DNI: "<<objEncontrado.getDniCliente()<<endl;
  }
  else
  {
    cout<<"No se encontro el objeto encontrado "<<endl;
  }
  system("pause");
  system("cls");
}
void modificarCliente()
{
  int codClie;
  cout<<"Ingrese codigo ha buscar: "; cin>>codClie;
  Cliente objEncontrado = clieController->buscar(codClie);
  if(objEncontrado.getNomCliente() != "Error")
  {
    cout<<"Cliente encontrado \n"<<endl;
    cout<<"Codigo del Cliente: "<<objEncontrado.getCodCliente()<<endl;
    cout<<"Nombre del Cliente: "<<objEncontrado.getNomCliente()<<endl;
    cout<<"DNI: "<<objEncontrado.getDniCliente()<<endl;

    string nomClie;
    string dni;
    cin.ignore();
    cout<<"Ingrese el nuevo nombre del Cliente: "; getline(cin, nomClie);
    cout<<"Ingrese el nuevo DNI del Cliente: "; getline(cin, dni);

    Cliente ObjNew(objEncontrado.getCodCliente(), nomClie, dni);
    bool estado = clieController->modificar(objEncontrado, ObjNew);
    clieController->grabarDatosEliminadouModificadoAlVector();
    if(estado == true)
    {
      cout<<"Cliente modificado satisfactoriamente "<<endl;
    }
    else
    {
      cout<<"No se modifico el Cliente "<<endl;
    }
  }
  else
  {
    cout<<"No se encontro el codigo del Cliente ingresado :c "<<endl;
  }
  system("pause");
  system("cls");
}
void eliminarCliente()
{
  int codClie;
  cout<<"Ingrese el codigo del Cliente ha eliminar: "; cin>>codClie;
  Cliente objEliminar = clieController->buscar(codClie);
  if(objEliminar.getNomCliente() != "Error")
  {
    cout<<"Cliente eliminado satisfactoriamente \n"<<endl;
    cout<<"Codigo del Cliente: "<<objEliminar.getCodCliente()<<endl;
    cout<<"Nombre del Cliente: "<<objEliminar.getNomCliente()<<endl;
    cout<<"DNI: "<<objEliminar.getDniCliente()<<endl;
    clieController->eliminar(objEliminar);
    clieController->grabarDatosEliminadouModificadoAlVector();
  }
  else
  {
    cout<<"No se encontro el codigo del Cliente ingresado "<<endl;
  }
  system("pause");
  system("cls");
}
void listarCliente()
{
  cout<<"COD"<<"\t"
      <<"NOMAPE"<<"\t\t"
      <<"DNI"<<"\t"<<endl;
  for(int i = 0; i < clieController->size(); i++)
  {
    cout<<clieController->get(i).getCodCliente()<<"\t"
        <<clieController->get(i).getNomCliente()<<"\t"
        <<clieController->get(i).getDniCliente()<<"\t"<<endl;
  }
  system("pause");
  system("cls");
}
void PersonalMenu()
{
  int opt;
  do
  {
    cout<<"\t\t\tPERSONAL\n"<<endl;
    cout<<"REGISTRAR PERSONAL********************[1]\n";
    cout<<"BUSCAR PERSONAL***********************[2]\n";
    cout<<"MODIFICAR PERSONAL********************[3]\n";
    cout<<"ELIMINAR PERSONAL*********************[4]\n";
    cout<<"LISTAR PERSONAL***********************[5]\n";
    cout<<"REGRESAR A LA MENU DE OPCIONES********[6]\n";
    cout<<"Ingrese una opcion: "; cin>>opt;

    switch (opt)
    {
    case 1: system("cls"); registrarPersonal(); break;
    case 2: system("cls"); buscarPersonal(); break;
    case 3: system("cls"); modificarPersonal(); break;
    case 4: system("cls"); eliminarPersonal(); break;
    case 5: system("cls"); listarPersonal(); break;
    case 6: system("cls"); menu(); break;
    default: cout<<"Ingrese una opcion[1-6]: "<<endl;

    }
  } while (opt != 6);
  
}
void registrarPersonal()
{
  int codPersonal;
  string nomApePer;
  string dniPer;
  float suePer;
  int codTipPer;
  string flag;
  do
  {
    cout<<"\t\tPERSONAL\n"<<endl;
    codPersonal = perController->getCorrelativo();
    cout<<"\t*****CODIGO Personal["<<codPersonal<<"]*****"<<endl;
    cin.ignore();
    cout<<"Ingrese el nombre y apellido del Personal: "; getline(cin, nomApePer);
    cout<<"Ingrese el dni del Personal: "; getline(cin, dniPer);
    cout<<"Ingrese el sueldo del Personal: "; cin>>suePer;
    cout<<"\n";
    cout<<"CODTIPPER"<<"\t"
        <<"NOMTIPPER"<<"\t"<<endl;
    for(int i = 0; i < tipPerController->size(); i++)
    {
      cout<<tipPerController->get(i).getCodTipPer()<<"\t\t"
          <<tipPerController->get(i).getNomTipPer()<<"\t"<<endl;
    }
    cout<<"\n";
    cout<<"Ingrese el codigo del Tipo de Personal: "; cin>>codTipPer;
    cout<<"Desea continuar(S/s): "; cin>>flag;

    Personal objPer(codPersonal, nomApePer, dniPer, suePer, codTipPer);
    perController->add(objPer);
    perController->GrabarArchivo(objPer);
    system("cls");

  } while (flag == "S" || flag == "s");
}
void buscarPersonal()
{
  int codPer;
  cout<<"Ingrese el codigo del Personal ha buscar: "; cin>>codPer;
  Personal objEncontrado = perController->buscar(codPer);
  if(objEncontrado.getNomApePer() != "Error")
  {
    cout<<"Personal encontrado "<<endl;
    cout<<"Codigo del Personal: "<<objEncontrado.getCodPersonal()<<endl;
    cout<<"Nombre del Personal: "<<objEncontrado.getNomApePer()<<endl;
    cout<<"Dni del Personal: "<<objEncontrado.getDniPer()<<endl;
    cout<<"Sueldo del Personal: "<<objEncontrado.getSuelPer()<<endl;
    cout<<"Codigo del Personal: "<<objEncontrado.getCodTipPer()<<endl;
  }
  else
  {
    cout<<"No se encontro el codigo del Personal ingresado "<<endl;
  }
  system("pause");
  system("cls");
}
void modificarPersonal()
{
  int codPer;
  cout<<"Ingrese codigo del Personal ha buscar: "; cin>>codPer;
  Personal objEncontrado = perController->buscar(codPer);
  if(objEncontrado.getNomApePer() != "Error")
  {
    cout<<"Personal encontrado \n"<<endl;
    cout<<"Codigo del Personal: "<<objEncontrado.getCodPersonal()<<endl;
    cout<<"Nombre del Personal: "<<objEncontrado.getNomApePer()<<endl;
    cout<<"Dni del Personal: "<<objEncontrado.getDniPer()<<endl;
    cout<<"Sueldo del Personal: "<<objEncontrado.getSuelPer()<<endl;
    cout<<"Codigo del Tipo Personal: "<<objEncontrado.getCodTipPer()<<endl;

    string nomApePer;
    string dni;
    float suelPer;
    int codTipPer;
    cin.ignore();
    cout<<"Ingrese el nuevo Nombre y Apellido del Personal: "; getline(cin, nomApePer);
    cout<<"Ingrese el dni del Personal: "; getline(cin, dni);
    cout<<"Ingrese el nuevo sueldo del Personal: "; cin>>suelPer;
    cout<<"\n";
    cout<<"CODTIPPER"<<"\t"
        <<"NOMTIPPER"<<"\t"<<endl;
    for(int i = 0; i < tipPerController->size(); i++)
    {
      cout<<tipPerController->get(i).getCodTipPer()<<"\t\t"
          <<tipPerController->get(i).getNomTipPer()<<"\t"<<endl;
    }
    cout<<"\n";
    cout<<"Ingrese el nuevo codigo del Tipo de Personal: "; cin>>codTipPer;

    Personal ObjNew(objEncontrado.getCodPersonal(), nomApePer, dni, suelPer, codTipPer);
    bool estado = perController->modificar(objEncontrado, ObjNew);
    perController->grabarDatosEliminadouModificadoAlVector();
    if(estado == true)
    {
      cout<<"Personal modificado satisfactoriamente "<<endl;
    }
    else
    {
      cout<<"No se modifico el Personal "<<endl;
    }
  }
  else
  {
    cout<<"No se encontro el codigo del Personal ingresado "<<endl;
  }
  system("pause");
  system("cls");
}
void eliminarPersonal()
{
  int codPer;
  cout<<"Ingrese el codigo del Personal ha eliminar: "; cin>>codPer;
  Personal objEliminar = perController->buscar(codPer);
  if(objEliminar.getNomApePer() != "Error")
  {
    cout<<"Personal eliminado satisfactoriamente \n"<<endl;
    cout<<"Codigo del Personal: "<<objEliminar.getCodPersonal()<<endl;
    cout<<"Nombre del Persona: "<<objEliminar.getNomApePer()<<endl;
    cout<<"DNI del Personal: "<<objEliminar.getDniPer()<<endl;
    cout<<"Sueldo del Personal: "<<objEliminar.getSuelPer()<<endl;
    cout<<"Codigo del Tipo del Personal: "<<objEliminar.getCodTipPer()<<endl;
    perController->eliminar(objEliminar);
    perController->grabarDatosEliminadouModificadoAlVector();
  }
  else
  {
    cout<<"No se encontro el codigo del Personal ingresado "<<endl;
  }
  system("pause");
  system("cls");
}
void listarPersonal()
{
  cout<<"CODPER"<<"\t"
      <<"NOMBREAPELL"<<"\t"
      <<"DNI"<<"\t\t"
      <<"SUELDO"<<"\t"
      <<"CODTIPPER"<<"\t"<<endl;
  for(int i = 0; i < perController->size(); i++)
  {
    cout<<perController->get(i).getCodPersonal()<<"\t"
        <<perController->get(i).getNomApePer()<<"\t"
        <<perController->get(i).getDniPer()<<"\t"
        <<perController->get(i).getSuelPer()<<"\t"
        <<perController->get(i).getCodTipPer()<<"\t"<<endl;
  }
  system("pause");
  system("cls");
}
void tipoPersonalMenu()
{
  int opt;
  do
  {
    cout<<"\t\t\tTIPO DEL PERSONAL\n"<<endl;
    cout<<"REGISTRAR EL TIPO DEL PERSONAL********************[1]\n";
    cout<<"BUSCAR EL TIPO DEL PERSONAL***********************[2]\n";
    cout<<"MODIFICAR EL TIPO DEL PERSONAL********************[3]\n";
    cout<<"ELIMINAR EL TIPO DEL PERSONAL*********************[4]\n";
    cout<<"LISTAR EL TIPO DEL PERSONAL***********************[5]\n";
    cout<<"REGRESAR A LA MENU DE OPCIONES********************[6]\n";
    cout<<"Ingrese una opcion: "; cin>>opt;

    switch (opt)
    {
    case 1: system("cls"); registrarTipoPersonal(); break;
    case 2: system("cls"); buscarTipoPersonal(); break;
    case 3: system("cls"); modificarTipoPersonal(); break;
    case 4: system("cls"); eliminarTipoPersonal(); break;
    case 5: system("cls"); listarTipoPersonal(); break;
    case 6: system("cls"); menu(); break;
    default: cout<<"Ingrese una opcion[1-6]: "<<endl;

    }
  } while (opt != 6);
  
}
void registrarTipoPersonal()
{
  int codTipPer;
  string nomTipPer;
  string flag;
  do
  {
    cout<<"\t\tTIPO DE PERSONAL\n"<<endl;
    codTipPer = tipPerController->getCorrelativo();
    cout<<"\t*****CODIGO DEL TIPO DE PERSONAL["<<codTipPer<<"]*****"<<endl;
    cin.ignore();
    cout<<"Ingrese el nombre del Tipo de Personal: "; getline(cin, nomTipPer);
    cout<<"Desea continuar(S/s): "; cin>>flag;

    TipoPersonal objTipPer(codTipPer, nomTipPer);
    tipPerController->add(objTipPer);
    tipPerController->GrabarArchivo(objTipPer);
    system("cls");

  } while (flag == "S" || flag == "s");
}
void buscarTipoPersonal()
{
  int codTipPer;
  cout<<"Ingrese el codigo del Tipo de Personal ha buscar: "; cin>>codTipPer;
  TipoPersonal objEncontrado = tipPerController->buscar(codTipPer);
  if(objEncontrado.getNomTipPer() != "Error")
  {
    cout<<"Objeto encontrado :) "<<endl;
    cout<<"Codigo del Tipo de Personal: "<<objEncontrado.getCodTipPer()<<endl;
    cout<<"Nombre del Tipo de Personal: "<<objEncontrado.getNomTipPer()<<endl;
  }
  else
  {
    cout<<"No se encontro el codigo del Tipo de Personal ingresado "<<endl;
  }
  system("pause");
  system("cls");
}
void modificarTipoPersonal()
{
  int codTipPer;
  cout<<"Ingrese codigo del Tipo de Personal ha buscar: "; cin>>codTipPer;
  TipoPersonal objEncontrado = tipPerController->buscar(codTipPer);
  if(objEncontrado.getNomTipPer() != "Error")
  {
    cout<<"Objeto encontrado :) \n"<<endl;
    cout<<"Codigo del Tipo de Personal: "<<objEncontrado.getCodTipPer()<<endl;
    cout<<"Nombre del Tipo de Personal: "<<objEncontrado.getNomTipPer()<<endl;

    string nomTipPer;
    cin.ignore();
    
    cout<<"Ingrese el nuevo Tipo de Personal: "; getline(cin, nomTipPer);

    TipoPersonal ObjNew(objEncontrado.getCodTipPer(), nomTipPer);
    bool estado = tipPerController->modificar(objEncontrado, ObjNew);
    tipPerController->grabarDatosEliminadouModificadoAlVector();
    if(estado == true)
    {
      cout<<"Tipo de Personal modificado satisfactoriamente "<<endl;
    }
    else
    {
      cout<<"No se modifico el Tipo de Personal "<<endl;
    }
  }
  else
  {
    cout<<"No se encontro el codigo del Tipo de Personal ingresado "<<endl;
  }
  system("pause");
  system("cls");
}
void eliminarTipoPersonal()
{
  int codTipPer;
  cout<<"Ingrese el codigo del Tipo de Personal ha buscar: "; cin>>codTipPer;
  TipoPersonal objEliminar = tipPerController->buscar(codTipPer);
  if(objEliminar.getNomTipPer() != "Error")
  {
    cout<<"Regristo eliminado satisfactoriamente : ) \n"<<endl;
    cout<<"Codigo del Tipo de Personal: "<<objEliminar.getCodTipPer()<<endl;
    cout<<"Nombre del Tipo de Personal: "<<objEliminar.getNomTipPer()<<endl;
    tipPerController->eliminar(objEliminar);
    tipPerController->grabarDatosEliminadouModificadoAlVector();
  }
  else
  {
    cout<<"No se encontro el codigo del Tipo del Personal ingresado "<<endl;
  }
  system("pause");
  system("cls");
}
void listarTipoPersonal()
{
  cout<<"CODTIPPER"<<"\t"
      <<"NOMTIPPER"<<"\t"<<endl;
  for(int i = 0; i < tipPerController->size(); i++)
  {
    cout<<tipPerController->get(i).getCodTipPer()<<"\t\t"
        <<tipPerController->get(i).getNomTipPer()<<"\t"<<endl;
  }
  system("pause");
  system("cls");
}
void ProductoMenu()
{
  int opt;
  do
  {
    cout<<"\t\t\tPRODUCTO\n"<<endl;
    cout<<"REGISTRAR PRODUCTO*************************[1]\n";
    cout<<"BUSCAR PRODUCTO****************************[2]\n";
    cout<<"MODIFICAR PRODUCTO*************************[3]\n";
    cout<<"ELIMINAR PRODUCTO**************************[4]\n";
    cout<<"LISTAR PRODUCTO****************************[5]\n";
    cout<<"REGRESAR A LA MENU DE OPCIONES*************[6]\n";
    cout<<"Ingrese una opcion: "; cin>>opt;

    switch (opt)
    {
    case 1: system("cls"); registrarProducto(); break;
    case 2: system("cls"); buscarProducto(); break;
    case 3: system("cls"); modificarProducto(); break;
    case 4: system("cls"); eliminarProducto(); break;
    case 5: system("cls"); listarProducto(); break;
    case 6: system("cls"); menu(); break;
    default: cout<<"Ingrese una opcion[1-6]: "<<endl;

    }
  } while (opt != 6);
  
}
void registrarProducto()
{
  int codPro;
  string nomPro;
  float prePro;
  int stockPro;
  int codCategoria;
  string flag;
  do
  {
    cout<<"\t\tPRODUCTO\n"<<endl;
    codPro = proController->getCorrelativo();
    cout<<"\t*****CODIGO PRODUCTO["<<codPro<<"]*****"<<endl;
    cin.ignore();
    cout<<"Ingrese el nombre del Producto: "; getline(cin, nomPro);
    cout<<"Ingrese el precio del Producto: "; cin>>prePro;
    cout<<"Ingrese el stock del Producto: "; cin>>stockPro;
    cout<<"\n";
    cout<<"COD"<<"\t"
        <<"NOMBRE"<<"\t"<<endl;
    for(int i = 0; i < cateController->size(); i++)
    {
      cout<<cateController->get(i).getCodigo()<<"\t"
          <<cateController->get(i).getNomCat()<<"\t"<<endl;
    }
    cout<<"\n";
    cout<<"Ingrese el codigo de la categoria del Producto: "; cin>>codCategoria;
    cout<<"Desea continuar (S/s): "; cin>>flag;

    Producto objPro(codPro, nomPro, prePro, stockPro, codCategoria);
    proController->add(objPro);
    proController->grabarArchivo(objPro);
    system("cls");

  } while (flag == "S" || flag == "s");
  
}
void buscarProducto()
{
  int cod;
  cin.ignore();
  cout<<"Ingrese el codigo del Producto ha buscar: "; cin>>cod;
  Producto objEncontrado = proController->buscar2(cod);
  if(objEncontrado.getNomPro() != "Error")
  {
    cout<<"Objeto encontrado :) "<<endl;
    cout<<"Codigo del Producto: "<<objEncontrado.getCodPro()<<endl;
    cout<<"Nombre del Producto: "<<objEncontrado.getNomPro()<<endl;
    cout<<"Precio del Producto: "<<objEncontrado.getPrePro()<<endl;
    cout<<"Stock del Producto: "<<objEncontrado.getStockPro()<<endl;
    cout<<"Codigo de la Categoria: "<<objEncontrado.getCodCategoria()<<endl;
  }
  else
  {
    cout<<"No se encontro el objeto encontrado "<<endl;
  }
  system("pause");
  system("cls");
}
void modificarProducto()
{
  int codPro;
  cin.ignore();
  cout<<"Ingrese el codigo del producto ha buscar: "; cin>>codPro;
  Producto objEncontrado = proController->buscar2(codPro);
  if(objEncontrado.getNomPro() != "Error")
  {
    cout<<"Producto encontrado :) \n"<<endl;
    cout<<"Codigo del Producto: "<<objEncontrado.getCodPro()<<endl;
    cout<<"Nombre del Producto: "<<objEncontrado.getNomPro()<<endl;
    cout<<"Precio del Producto: "<<objEncontrado.getPrePro()<<endl;
    cout<<"Stock del Producto: "<<objEncontrado.getStockPro()<<endl;
    cout<<"Codigo de la Categoria: "<<objEncontrado.getCodCategoria()<<endl;

    string nomPro;
    float prePro;
    int stockPro;
    int codCate;

    cin.ignore();
    cout<<"Ingrese el nuevo nombre del Producto: "; getline(cin, nomPro);
    cout<<"Ingrese el nuevo precio del Producto: "; cin>>prePro;
    cout<<"Ingrese el nuevo stock del Producto: "; cin>>stockPro;
    cout<<"COD"<<"\t"
        <<"NOMBRE"<<"\t"<<endl;
    for(int i = 0; i < cateController->size(); i++)
    {
      cout<<cateController->get(i).getCodigo()<<"\t"
          <<cateController->get(i).getNomCat()<<"\t"<<endl;
    }
    cout<<"Ingrese el nuevo codigo de la Categoria del Producto: "; cin>>codCate;

    Producto ObjNew(objEncontrado.getCodPro(), nomPro, prePro, stockPro, codCate);
    bool estado = proController->modificar(objEncontrado, ObjNew);
    proController->grabarDatosEliminadouModificadoAlVector();
    if(estado == true)
    {
      cout<<"Producto modificado satisfactoriamente "<<endl;
    }
    else
    {
      cout<<"No se modifico el producto "<<endl;
    }
  }
  else
  {
    cout<<"No se encontro el codigo del Producto ingresado "<<endl;
  }
  system("pause");
  system("cls");
}
void eliminarProducto()
{
  int codPro;
  cin.ignore();
  cout<<"Ingrese el codigo del producto ha buscar: "; cin>>codPro;
  Producto objEliminar = proController->buscar2(codPro);
  if(objEliminar.getNomPro() != "Error")
  {
    cout<<"Regristo eliminado satisfactoriamente : ) \n"<<endl;
    cout<<"Codigo del Producto: "<<objEliminar.getCodPro()<<endl;
    cout<<"Nombre del Producto: "<<objEliminar.getNomPro()<<endl;
    cout<<"Precio del Producto: "<<objEliminar.getPrePro()<<endl;
    cout<<"Stock del Producto: "<<objEliminar.getStockPro()<<endl;
    cout<<"Codigo de la Categoria del Producto: "<<objEliminar.getCodCategoria()<<endl;
    proController->eliminar(objEliminar);
    proController->grabarDatosEliminadouModificadoAlVector();
  }
  else
  {
    cout<<"No se encontro el codigo ingresado :c "<<endl;
  }
  system("pause");
  system("cls");
}
void listarProducto()
{
  cout<<"CODIGO"<<"\t"
      <<"NOMBRE"<<"\t\t\t"
      <<"PRECIO"<<"\t\t"
      <<"STOCK"<<"\t"
      <<"CODCATE"<<"\t"<<endl;
  for(int i = 0; i < proController->size(); i++)
  {
    cout<<proController->get(i).getCodPro()<<"\t"
        <<proController->get(i).getNomPro()<<"\t\t"
        <<proController->get(i).getPrePro()<<"\t\t"
        <<proController->get(i).getStockPro()<<"\t"
        <<proController->get(i).getCodCategoria()<<"\t"<<endl;
  }
  system("pause");
  system("cls");
}
void CategoriaMenu()
{
  int opt;
  do
  {
    cout<<"\t\t\tCATEGORIA\n"<<endl;
    cout<<"REGISTRAR CATEGORIA**************************[1]\n";
    cout<<"BUSCAR CATEGORIA*****************************[2]\n";
    cout<<"MODIFICAR CATEGORIA**************************[3]\n";
    cout<<"ELIMINAR CATEGORIA***************************[4]\n";
    cout<<"LISTAR CATEGORIA*****************************[5]\n";
    cout<<"REGRESAR A LA MENU DE OPCIONES***************[6]\n";
    cout<<"Ingrese una opcion: "; cin>>opt;

    switch (opt)
    {
    case 1: system("cls"); registrarCategoria(); break;
    case 2: system("cls"); buscarCategoria(); break;
    case 3: system("cls"); modificarCategoria(); break;
    case 4: system("cls"); eliminarCategoria(); break;
    case 5: system("cls"); listarCategoria(); break;
    case 6: system("cls"); menu(); break;
    default: cout<<"Ingrese una opcion[1-6]: "<<endl;

    }
  } while (opt != 6);
  
}
void registrarCategoria()
{
  int codigo;
  string nomCate;
  string flag;

  do
  {
    cout<<"\tCATEGORIAS\n"<<endl;
    codigo = cateController->getCorrelativo();
    cout<<"\t*****CODIGO CATEGORIA["<<codigo<<"]*****"<<endl;
    cin.ignore();
    cout<<"Ingrese el nombre de la Categoria: "; getline(cin, nomCate);
    cout<<"Desea continuar (S/s): "; cin>>flag;

    Categoria objCate(codigo, nomCate);
    cateController->add(objCate);
    cateController->grabarArchivo(objCate);
  } while (flag == "S" || flag == "s");
  
}
void buscarCategoria()
{
  int cod;
  cout<<"Ingrese el codigo de la Categoria ha buscar: "; cin>>cod;
  Categoria objEncontrado = cateController->buscar(cod);
  if(objEncontrado.getNomCat() != "Error")
  {
    cout<<"Categoria encontrado :) "<<endl;
    cout<<"Codigo de la Categoria: "<<objEncontrado.getCodigo()<<endl;
    cout<<"Nombre de la Categoria: "<<objEncontrado.getNomCat()<<endl;
  }
  else
  {
    cout<<"No se encontro el codigo de la Categoria ingresado "<<endl;
  }
  system("pause");
  system("cls");
}
void modificarCategoria()
{
  int cod;
  cout<<"Ingrese el codigo de la Categoria ha buscar: "; cin>>cod;
  Categoria objEncontrado = cateController->buscar(cod);
  if(objEncontrado.getNomCat() != "Error")
  {
    cout<<"Objeto encontrado :) "<<endl;
    cout<<"Codigo de la Categoria: "<<objEncontrado.getCodigo()<<endl;
    cout<<"Nombre de la Categoria: "<<objEncontrado.getNomCat()<<endl;

    string nomCate;
    cin.ignore();
    cout<<"Ingrese el nuevo nombre de la Categoria: "; getline(cin, nomCate);

    Categoria ObjNew(objEncontrado.getCodigo(), nomCate);
    bool estado = cateController->modificar(objEncontrado, ObjNew);
    cateController->grabarDatosEliminadouModificadoAlVector();
    if(estado == true)
    {
      cout<<"Categoria modificado "<<endl;
    }
    else
    {
      cout<<"No se modifico la Categora "<<endl;
    }
  }
  else
  {
    cout<<"No se el encontro el codigo de la Categoria ingresado "<<endl;
  }
  system("pause");
  system("cls");
}
void eliminarCategoria()
{
  int cod;
  cout<<"Ingrese el codigo de la Categoria ha elminar: "; cin>>cod;
  Categoria objEliminar = cateController->buscar(cod);
  if(objEliminar.getNomCat() != "Error")
  {
    cout<<"Categoria eliminado satisfactoriamente"<<endl;
    cout<<"Codigo de la Categoria: "<<objEliminar.getCodigo()<<endl;
    cout<<"Nombre de la Categoria: "<<objEliminar.getNomCat()<<endl;
    cateController->eliminar(objEliminar);
    cateController->grabarDatosEliminadouModificadoAlVector();
  }
  else
  {
    cout<<"No se encontro el codigo de la Categoria ingresado "<<endl;
  }
  system("pause");
  system("cls");
}
void listarCategoria()
{
  cout<<"COD"<<"\t"
      <<"NOMBRE"<<"\t"<<endl;
  for(int i = 0; i < cateController->size(); i++)
  {
    cout<<cateController->get(i).getCodigo()<<"\t"
        <<cateController->get(i).getNomCat()<<"\t"<<endl;
  }
  system("pause");
  system("cls");
}
void FacturaMenu()
{
  int opt;
  do
  {
    cout<<"\t\t\tFACTURA\n"<<endl;
    cout<<"REGISTRAR FACTURA**************************[1]\n";
    cout<<"BUSCAR FACTURA*****************************[2]\n";
    cout<<"MODIFICAR FACTURA**************************[3]\n";
    cout<<"ANULAR FACTURA*****************************[4]\n";
    cout<<"LISTAR FACTURA*****************************[5]\n";
    cout<<"REGRESAR A LA MENU DE OPCIONES*************[6]\n";
    cout<<"Ingrese una opcion: "; cin>>opt;

    switch (opt)
    {
    case 1: system("cls"); registrarFactura(); break;
    case 2: system("cls"); buscarFactura(); break;
    case 3: system("cls"); modificarFactura(); break;
    case 4: system("cls"); eliminarFactura(); break;
    case 5: system("cls"); listarFactura(); break;
    case 6: system("cls"); menu(); break;
    default: cout<<"Ingrese una opcion[1-6]: "<<endl;

    }
  } while (opt != 6);
  
}
void registrarFactura()
{
  int codPro;
  int cantidad;
  int codFactura;
  int codCliente;
  float prePro;
  string nomPro;
  string fecha;
  string estado;
  float subTotal;
  float total = 0;
  string flag;
  string flag2;

  do
  {
    cout<<"\t\t\tFACTURA\n"<<endl;
    codFactura = factuController->getCorrelativo();
    cout<<"\t*****CODIGO FACTURA["<<codFactura<<"]*****"<<endl;
    cout<<"Ingrese la fecha de la Facturacion: "; cin>>fecha;
    cout<<"Ingrese el codigo del Cliente: "; cin>>codCliente;
    Cliente objEncontrado = clieController->buscar(codCliente);
    if(objEncontrado.getNomCliente() != "Error")
    {
      cout<<"Cliente encontrado "<<endl;
      cout<<"Codigo del Cliente: "<<objEncontrado.getCodCliente()<<endl;
      cout<<"Nombre del Cliente: "<<objEncontrado.getNomCliente()<<endl;
      cout<<"Dni del Cliente: "<<objEncontrado.getDniCliente()<<endl;
    }
    else
    {
      cout<<"No se encontro el Cliente"<<endl;
      system("pause");
      system("cls");
    }
    do
    {
      cin.ignore();
      cout<<"Ingrese el nombre del Producto ha buscar: "; getline(cin, nomPro);
      Producto objEncontrado = proController->buscar(nomPro);
      if(objEncontrado.getNomPro() != "Error")
      {
        cout<<"Producto encontrado "<<endl;
        cout<<"Codigo del Producto: "<<objEncontrado.getCodPro()<<endl;
        cout<<"Nombre del Producto: "<<objEncontrado.getNomPro()<<endl;
        cout<<"Precio del Producto: "<<objEncontrado.getPrePro()<<endl;
        cout<<"Stock del Producto: "<<objEncontrado.getStockPro()<<endl;
        cout<<"Codigo de la Categoria del Producto: "<<objEncontrado.getCodCategoria()<<endl;
      }
      else
      {
        cout<<"No se encontro el Producto: "<<endl;
        system("pause");
        system("cls");
      }
      cout<<"\n"<<endl;
      cout<<"Ingrese el codigo del Producto: "; cin>>codPro;
      cin.ignore();
      cout<<"Ingrese el nombre del Producto: "; getline(cin, nomPro);
      cout<<"Ingrese el precio del Producto: "; cin>>prePro;
      cout<<"Ingrese la cantidad del Producto que se va a comprar: "; cin>>cantidad;
      estado = "Registrado";
      subTotal = prePro * cantidad;
      total += subTotal;
      cout<<"El estado del Producto es "<<estado<<endl;
      cout<<"\n"<<endl;
      cout<<"CODIGO"<<"\t"
          <<"NOMBRE"<<"\t\t\t"
          <<"PRECIO"<<"\t\t"
          <<"CANTIDAD"<<"\t"
          <<"IMPORTE"<<"\t"<<endl;
      cout<<codPro<<"\t"
          <<nomPro<<"\t\t"
          <<prePro<<"\t\t"
          <<cantidad<<"\t\t"
          <<subTotal<<"\t"<<endl;
      cout<<"\n"<<endl;
      cout<<"El total de la factura es: "<<total<<endl;
      cout<<"Desea agregar otro Producto a la Factura (S/s): "; cin>>flag;
      DetalleFactura objDetaFac(codFactura, codPro, prePro ,cantidad, subTotal, estado);
      detaFactuController->add(objDetaFac);
      detaFactuController->grabarArchivo(objDetaFac);
      system("cls");

    } while (flag == "S" || flag == "s");
    
    cout<<"Desea agregar otra factura (S/s): "; cin>>flag2;
    Factura objFac(codFactura, codCliente, fecha, total);
    factuController->add(objFac);
    factuController->grabarArchivo(objFac);
    
  } while (flag == "S" || flag == "s");
  
  system("pause");
  system("cls");
}
void buscarFactura()
{
  int codFactu;
  cout<<"Ingrese el codigo de la Factura ha buscar: "; cin>>codFactu;
  Factura objEncontrado = factuController->buscar(codFactu);
  if(objEncontrado.getFechaFactura() != "Error")
  {
    cout<<"Factura enontrado :) "<<endl;
    cout<<"Codigo de la Factura: "<<objEncontrado.getCodFactura()<<endl;
    cout<<"Codigo del Cliente: "<<objEncontrado.getCodCliente()<<endl;
    cout<<"Fecha de la Factura: "<<objEncontrado.getFechaFactura()<<endl;

    DetalleFactura objEncontrado2 = detaFactuController->buscar(codFactu);
    if(objEncontrado2.getEstadoProducto() != "Error")
    {
      cout<<"Codigo del Producto: "<<objEncontrado2.getCodProducto()<<endl;
      cout<<"Precio del Producto:  "<<objEncontrado2.getPrecioProducto()<<endl;
      cout<<"Cantidad del Producto: "<<objEncontrado2.getCantidad()<<endl;
      cout<<"Importe de la Producto: "<<objEncontrado2.getImporteProducto()<<endl;
    }
    cout<<"Importe total de la Factura: "<<objEncontrado.getImporteTotal()<<endl;
  }
  else
  {
    cout<<"No se encontro el codigo de la Factura ingresado "<<endl;
  }
  system("pause");
  system("cls");

}
void modificarFactura()
{
  int codFac;
  cout<<"Ingrese el codigo de la Factura ha buscar: "; cin>>codFac;
  Factura objEncontrado = factuController->buscar(codFac);
  if(objEncontrado.getFechaFactura() != "Error")
  {
    cout<<"Factura enontrado :) "<<endl;
    cout<<"Codigo de la Factura: "<<objEncontrado.getCodFactura()<<endl;
    cout<<"Codigo del Cliente: "<<objEncontrado.getCodCliente()<<endl;
    cout<<"Fecha de la Factura: "<<objEncontrado.getFechaFactura()<<endl;

    DetalleFactura objEncontrado2 = detaFactuController->buscar(codFac);
    if(objEncontrado2.getEstadoProducto() != "Error")
    {
      cout<<"Codigo del Producto: "<<objEncontrado2.getCodProducto()<<endl;
      cout<<"Precio del Producto:  "<<objEncontrado2.getPrecioProducto()<<endl;
      cout<<"Cantidad del Producto: "<<objEncontrado2.getCantidad()<<endl;
      cout<<"Importe de la Producto: "<<objEncontrado2.getImporteProducto()<<endl;
    }
    cout<<"Importe total de la Factura: "<<objEncontrado.getImporteTotal()<<endl;

    int codPro;
    float precio;
    int cant;
    string esta = "Registrado";
    float importe = 0;
    float total = 0;

    cout<<"Ingrese el nuevo codigo de Producto: "; cin>>codPro;
    cout<<"Ingrese el nuevo precio del Producto: "; cin>>precio;
    cout<<"Ingrese la nueva cantidad del Producto: "; cin>>cant;
    cout<<"El estado del Producto es: "<<esta<<endl;
    importe = precio * cant;
    cout<<"El nuevo importe es: "<<importe<<endl;
    DetalleFactura ObjNew(objEncontrado2.getCodFac(), codPro, precio, cant, importe, esta);
    bool estado = detaFactuController->modificar(objEncontrado2, ObjNew);
    detaFactuController->grabarDatosEliminadouModificadoAlVector();
    if(estado == true)
    {
      cout<<"Datos modificados :) "<<endl;
    }
    else
    {
      cout<<"No se modifico la Factura "<<endl;
    }
  }
  else
  {
    cout<<"No se el encontro el codigo de la Factura "<<endl;
  }
  system("pause");
  system("cls");
}
void eliminarFactura()
{
  int codFac;
  cout<<"Ingrese el codigo de la Factura que desea anular: "; cin>>codFac;
  Factura objEliminar = factuController->buscar(codFac);
  if(objEliminar.getFechaFactura() != "Error")
  {
    cout<<"Factura anulada satisfactoriamente: "<<endl;
    cout<<"Codigo de la Factura: "<<objEliminar.getCodFactura()<<endl;
    cout<<"Codigo del Cliente: "<<objEliminar.getCodCliente()<<endl;
    cout<<"Fecha de la Factura: "<<objEliminar.getFechaFactura()<<endl;
    DetalleFactura objEliminar2 = detaFactuController->buscar(codFac);
    if(objEliminar2.getEstadoProducto() != "Error")
    {
      cout<<"Codigo del Producto: "<<objEliminar2.getCodProducto()<<endl;
      cout<<"Precio del Producto: "<<objEliminar2.getPrecioProducto()<<endl;
      cout<<"Cantidad del Producto: "<<objEliminar2.getCantidad()<<endl;
      cout<<"Importe del Producto: "<<objEliminar2.getImporteProducto()<<endl;
    }
    factuController->eliminar(objEliminar);
    factuController->grabarDatosEliminadouModificadoAlVector();
    detaFactuController->eliminar(objEliminar2);
    detaFactuController->grabarDatosEliminadouModificadoAlVector();
    cout<<"Importe total de la Factura: "<<objEliminar.getImporteTotal()<<endl;

  }
  system("pause");
  system("cls");

}
void listarFactura()
{
  cout<<"CODIGO"<<"\t"
      <<"CLIENTE"<<"\t\t"
      <<"FECHA"<<"\t\t"
      <<"TOTAL"<<"\t"<<endl;
  for(int i = 0; i < factuController->size(); i++)
  {
    cout<<factuController->get(i).getCodFactura()<<"\t"
        <<factuController->get(i).getCodCliente()<<"\t\t"
        <<factuController->get(i).getFechaFactura()<<"\t"
        <<factuController->get(i).getImporteTotal()<<"\t"<<endl;
  }
  cout<<"\n"<<endl;
  cout<<"CODIGO"<<"\t"
      <<"PRODUCTO"<<"\t"
      <<"PRECIO"<<"\t\t"
      <<"CANTIDAD"<<"\t"
      <<"IMPORTE DEL PRODUCTO"<<"\t"<<endl;
  for(int i = 0; i < detaFactuController->size(); i++)
  {
    cout<<detaFactuController->get(i).getCodFac()<<"\t"
        <<detaFactuController->get(i).getCodProducto()<<"\t\t"
        <<detaFactuController->get(i).getPrecioProducto()<<"\t\t\t"
        <<detaFactuController->get(i).getCantidad()<<"\t"
        <<detaFactuController->get(i).getImporteProducto()<<"\t"<<endl;
  }
  system("pause");
  system("cls");
}

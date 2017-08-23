#include <iostream>

/*declaring functions to be defined later*/
void  use_std_cout(const char*);

/*Defining Namespace*/
namespace custom
{
  /*Variable inside a namespace*/
  int var = 0;
  /*Fucntions inside a namespace*/
  int fun(int i) {return 1;}

  /*Class in side function*/
  class custom_cout
  {
  public:
    /*operator overloading*/
    void operator <<(const char *){/*does nothing*/}
  };

  /*objects inside a namespace*/
  custom_cout cout;
}

int main()
{
  /*to specify which namespace to use*/
  std::cout << "This will actually print\n";
  //std is standard namespace defines inside iostream
  custom::cout << "This will not print\n";

  /*calling function*/
  use_std_cout("Hello World\n");

  /*to allow access to only specific component in namespace*/
  using  custom::var;
  var = 10; 

  /*
   * //Uncommenting this block will lead to compiler error
   * using namespace std;
   * using namespace custom;
   * cout << "Hello World\n";
   * // This is because reference to ‘cout’ is ambiguous
   */
}


void  use_std_cout(const char* print_this)
{
  /*to declare which namespace to use*/
  using namespace std; //everything that follows will use std namespace
  cout << print_this << endl;
}

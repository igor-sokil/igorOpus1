#define  boolean          int

#include "const_global_total.h"
#include "const_global.h"
#include "variables_external_m.h"

/**************************************/
//Стартовая инициализация компонентов
/**************************************/
void global_component_installation(void) {
  constructorIUSmallComponent(&(config_array[IUSMALLCOMPONENT]));//подготовка компонента iu
  constructorACMDSmallComponent(&(config_array[ACMDSMALLCOMPONENT]));//подготовка компонента acmd
  constructorGCMDSmallComponent(&(config_array[GCMDSMALLCOMPONENT]));//подготовка компонента gcmd
  constructorRPRSmallComponent(&(config_array[RPRSMALLCOMPONENT]));//подготовка компонента rpr
  constructorDOUTSmallComponent(&(config_array[DOUTSMALLCOMPONENT]));//подготовка компонента dout
  constructorDVSmallComponent(&(config_array[DVSMALLCOMPONENT]));//подготовка компонента dv
  constructorKEYSmallComponent(&(config_array[KEYSMALLCOMPONENT]));//подготовка компонента key
  constructorSDISmallComponent(&(config_array[SDISMALLCOMPONENT]));//подготовка компонента sdi
  constructorAISmallComponent(&(config_array[AISMALLCOMPONENT]));//подготовка компонента aismall
  constructorPKVBigComponent(&(config_array[PKVBIGCOMPONENT]));//подготовка компонента pkv
  constructorREG1BigComponent(&(config_array[REG1BIGCOMPONENT]));//подготовка компонента reg
  constructorREG2BigComponent(&(config_array[REG2BIGCOMPONENT]));//подготовка компонента reg
  constructorYustBigComponent(&(config_array[YUSTBIGCOMPONENT]));//подготовка компонента yust
  constructorPREGBigComponent(&(config_array[PREGBIGCOMPONENT]));//подготовка компонента reg

  constructorUVVComponent2021(&(config_array2021func[UVVCOMPONENT2021]));//подготовка компонента UVVCOMPONENT2021
  constructorPROTComponent2021(&(config_array2021func[PROTCOMPONENT2021]));//подготовка компонента PROTCOMPONENT2021
  constructorPERIFComponent2021(&(config_array2021func[PERIFCOMPONENT2021]));//подготовка компонента PERIFCOMPONENT2021
}//global_vareiables_installation_bo(void)


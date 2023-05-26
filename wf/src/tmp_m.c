void calc_symbol_and_put_into_working_ekran(
unsigned char* point_in_working_ekran,//<= позиція на екрані
//.(working_ekran[i] + j)
void* point_value, 
//./у змінну value поміщаємо значення уставки
void* point_vaga, 
//.//максимальний ваговий коефіцієнт для вилілення старшого розряду
unsigned int* point_first_symbol, //вказує чи виведено перед комою хоч один символ,щоб прибрати незначущі 0
//.first_symbol = 0; //помічаємо, що ще ніодин значущий символ не виведений. Як тільки перед комою з'явил число одразу в !=0, щоб все виводити
unsigned int current_position_x, 
//.номер символа, який зараз виводиться
unsigned int position_comma, 
//.COL_PICKUP_DZO1_COMMA номер позиції коми
unsigned int view, 
//.режим редагування якщо ми не у режимі редагування, то нулі перед комою  приховуємо
unsigned int v_32_64
//.селектор типу 32 чи 64

){
	
unsigned int temp_data;
  if (v_32_64 == 0)
  {
    temp_data = (*((unsigned int*)point_value))
	/ (*((unsigned int*)point_vaga)); //виділяємо число,
//. яке треба перетворити у символ і помістити у дану позицію екрану
    *((unsigned int*)point_value) %= *((unsigned int*)point_vaga); //вираховуємо число без символа, 
//.який ми зараз будемо виводити на екран
    *((unsigned int*)point_vaga) /=10; //зменшуємо ваговий коефіцієнт в 10 разів
  }
  else
  {
    temp_data = (*((unsigned long long*)point_value))
	/ (*((unsigned long long*)point_vaga)); //виділяємо 
//.число, яке треба перетворити у символ і помістити у дану позицію екрану
    *((unsigned long long*)point_value) %=
	*((unsigned long long*)point_vaga); //вираховуємо число
//. без символа, який ми зараз будемо виводити на екран
    *((unsigned long long*)point_vaga) /=10; //зменшуємо ваговий коефіцієнт в 10 разів
  }
  
  
  if (view == false) *point_in_working_ekran = temp_data + 0x30;
  else
  {
    //У випадку, якщо ми не у режимі редагування, то нулі перед комою (за винятком останнього, 
//.якщо такий є) приховуємо
    if ((temp_data !=0) || ((*point_first_symbol) != 0))
    {
      *point_in_working_ekran = temp_data + 0x30;
      if ((*point_first_symbol) == 0) *point_first_symbol = 1;
    }
    else
    {
      if (current_position_x < (position_comma - 1) ) *point_in_working_ekran = ' ';
      else
      {
        *point_in_working_ekran = temp_data + 0x30;
        if ((*point_first_symbol) == 0) *point_first_symbol = 1;
      }
    }
	
  }
  
  
}


edition_settings.pickup_dzo_Io3g_Io1g[group] = 
edit_setpoint(0, edition_settings.pickup_dzo_Io3g_Io1g[group], 1, 
 COL_PICKUP_DZO_K_ICE_COMMA, COL_PICKUP_DZO_K_ICE_END, 1);
/*****************************************************/
//Редагування величин вводимих значень
/*****************************************************
Вхідні параметри
  0 - натснуто кнопку вниз
  1 - натиснуто кнопку вверх
Вхідні параметри
  Немає
*****************************************************/
unsigned int edit_setpoint(unsigned int action,
//.вказує збільшувати чи зменшувати
unsigned int value, 
//.величина уставки
unsigned int floating_value, 
//.селектор число з комою чи ні
unsigned int comma, 
//.COL_PICKUP_DZO_K_ICE_COMMA
unsigned int end, 
//.COL_PICKUP_DZO_K_ICE_END
unsigned int min_step
//.1
){
  unsigned int rozrjad, vaga = min_step, temp_value, data_return;
  //Вираховуємо розряд числа на який зараз вказує курсор
  rozrjad = end - current_ekran.position_cursor_x;
  
  //У разі якщо редаговане число є числом з комою, то враховуємо позицію коми
  if (floating_value != 0)
    if (current_ekran.position_cursor_x < ((int)comma)) rozrjad--;
      
  for(unsigned int i=0; i < rozrjad; i++)  vaga *= 10;
  
  //Виділяємо число , яке трба змінити
  temp_value = (value / vaga) % 10;
  
  //У вхідному числі, який нас цікавить редагований розряд скидаємо в нуль відніманням
  data_return = value - temp_value*vaga;
  //. зберігає остачу
  //Змінюємо виділений розняд
  inc_or_dec_value(&temp_value, action);
  
  //Вводимо зміненй розряд у кінцевий результат
  data_return += temp_value*vaga;
  
  
  return data_return;
}

/*****************************************************/
//Перевіряємо достовірність даних
/*
Результат
  1 - дані достовірні
  0 - дані недостовірні
*/
/*****************************************************/
unsigned int check_data_setpoint(unsigned int current_value, unsigned int min_value, unsigned int max_value)
{
  if ((current_value < min_value) || (current_value > max_value)) return 0;

  //Вихід з повідомленням, що уставко в межах допуску
  return 1;
}
unsigned int check_data_setpoint_sign(int current_value, int min_value, int max_value)
{
  if ((current_value < min_value) || (current_value > max_value)) return 0;

  //Вихід з повідомленням, що уставко в межах допуску
  return 1;
}
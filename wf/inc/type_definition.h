#ifndef __TYPE_DEFINITION__
#define __TYPE_DEFINITION__

#define SRAM1 _Pragma("location=\"variables_RAM1\"")
#define SRAM1_AR _Pragma("location=\"Analog_Registrator_Buffer\"")

typedef struct
{
  int current_level;                  //Текучий рівень відображуваного екрану
 
  int index_position;                 //Вказує на якій ми зараз є позиції

  int position_cursor_x;              //X - координата курсору
  int position_cursor_y;              //Y - координата курсору
  
  unsigned int edition;               //0 - вікно зараз не в режимі редагується;
                                      //1 - вікно зараз в режимі редагування;
                                      //2 - вікно чекає підтвердження редагування
                                      //3 - у вікні виведено повідомлення про те, що під час введення даних була зафіксована помилка величиниданих
  
  unsigned int cursor_on;             //1 - курсор відображається/ 0 - курсор не відображається
  unsigned int cursor_blinking_on;    //1 - курсор мигає/ 0 - курсор не мигає
  
  unsigned int current_action;        //Дія яку треба виконати з текучим екраном
                                      //0 - Нічого не виконувати
                                      //1 - Перемістити курсор, ш/або змінити стан його відображення
                                      //2 - Повністю обновити інформацію

} __CURRENT_EKRAN;

typedef struct
{
  int position_cursor_x;              //X - координата курсору

  unsigned int cursor_on;             //1 - курсор відображається/ 0 - курсор не відображається
  unsigned int cursor_blinking_on;    //1 - курсор мигає/ 0 - курсор не мигає
} __PREVIOUS_STATE_CURSOR;

typedef struct
{
  //Тип пристрою
  unsigned int device_id;
  
  //Дискретні входи
  unsigned int type_of_input;                          //Тип дискретного входу 0 - прямий, 1 - інверсний
  unsigned int type_of_input_signal;                   //Тип сигналу дискретного входу 0 - постійний , 1 - змінний
  unsigned int dopusk_dv[NUMBER_INPUTS];              //Допуски ДВ
    
  unsigned int ranguvannja_inputs[N_SMALL*NUMBER_INPUTS]; //Ранжування дискретних входів
  unsigned int ranguvannja_outputs[N_BIG*NUMBER_OUTPUTS]; //Ранжування дискретних вхиодів
  unsigned int ranguvannja_leds[N_BIG*NUMBER_LEDS];       //Ранжування свіотіндикаторів

  unsigned int ranguvannja_analog_registrator[N_BIG];     //Ранжування аналогового реєстратора
  unsigned int ranguvannja_digital_registrator[N_BIG];    //Ранжування дискретного реєстратора
  
  int timeout_prolongation_work_digital_registrator;        //Час продолвження роботи  дискретного реєстратора
  
  //Блок увімкнення-вимкнення вимикача
  unsigned int ranguvannja_off_cb[N_BIG];                 //Ранжування блоку вимкнення силового вимикача
  unsigned int ranguvannja_on_cb[N_BIG];                  //Ранжування блоку увімкнення силового вимикача
 
  unsigned int ranguvannja_off_cb_oh[N_BIG];                 //Ранжування блоку вимкнення силового вимикача
  unsigned int ranguvannja_on__cb_oh[N_BIG];                 //Ранжування блоку увімкнення силового вимикача
  unsigned int ranguvannja_off_cb_rl[N_BIG];                 //Ранжування блоку вимкнення силового вимикача
  unsigned int ranguvannja_on__cb_rl[N_BIG];                 //Ранжування блоку увімкнення силового вимикача
 
  
  //Тип дискретних виходів
  unsigned int type_of_output;                        //Тип дискретних виходів
                                                      //0 - Командний
                                                      //1 - Сигналький (постійний або імпульсний)
  
  unsigned int type_of_output_modif;                  //Тип дискретних сигнальних виходів
                                                      //0 - Сигналький (постійний)
                                                      //1 - Сигналький (імпульсний)
  
  //Тип світлоіндикаторів
  unsigned int type_of_led;                           //Тип світлоіндикаторі
                                                      //0 - Нормальний
                                                      //1 - Тригерний
    
  unsigned int number_iteration_el;                                             //Максимальна кількість ітерацій для розширеної логіки
//  unsigned int number_defined_df;                                               //Кількість визначуваних функцій у конфігурації приладу
//  unsigned int number_defined_dt;                                               //Кількість визначуваних тригерів у конфігурації приладу
//  unsigned int number_defined_and;                                              //Кількість визначуваних "І" у конфігурації приладу
//  unsigned int number_defined_or;                                               //Кількість визначуваних "АБО" у конфігурації приладу
//  unsigned int number_defined_xor;                                              //Кількість визначуваних "Викл.ВБО" у конфігурації приладу
//  unsigned int number_defined_not;                                              //Кількість визначуваних "НЕ" у конфігурації приладу

  //Опреділювальні функції
  unsigned int type_df;                                                     //Тип опреділювавльної функції
                                                                            //0 - Пряма
                                                                            //1 - Зворотня
  int timeout_pause_df[NUMBER_DEFINED_FUNCTIONS];                           //Час затримки спрацюваня опреділювальної функції
  int timeout_work_df[NUMBER_DEFINED_FUNCTIONS];                            //Час роботи опреділювальної функції
  unsigned int ranguvannja_df_source_plus[N_BIG*NUMBER_DEFINED_FUNCTIONS];  //Ранжування прямих команд опреділювальниї функцій
  unsigned int ranguvannja_df_source_minus[N_BIG*NUMBER_DEFINED_FUNCTIONS]; //Ранжування інверсних команд опреділювальниї функцій
  unsigned int ranguvannja_df_source_blk[N_BIG*NUMBER_DEFINED_FUNCTIONS];   //Ранжування команд блокування опреділювальниї функцій

  unsigned int ranguvannja_set_dt_source_plus[N_BIG*NUMBER_DEFINED_TRIGGERS];   //Ранжування прямих команд встановлення опреділювальних триґерів
  unsigned int ranguvannja_set_dt_source_minus[N_BIG*NUMBER_DEFINED_TRIGGERS];  //Ранжування інверсних команд встановлення опреділювальних триґерів
  unsigned int ranguvannja_reset_dt_source_plus[N_BIG*NUMBER_DEFINED_TRIGGERS]; //Ранжування прямих команд скидання опреділювальних триґерів
  unsigned int ranguvannja_reset_dt_source_minus[N_BIG*NUMBER_DEFINED_TRIGGERS];//Ранжування інверсних команд скидання опреділювальних триґерів

  unsigned int ranguvannja_d_and[N_BIG*NUMBER_DEFINED_AND];                     //Ранжування команд джерел визначуваних "І"
  unsigned int ranguvannja_d_or[N_BIG*NUMBER_DEFINED_OR];                       //Ранжування команд джерел визначуваних "АБО"
  unsigned int ranguvannja_d_xor[N_BIG*NUMBER_DEFINED_XOR];                     //Ранжування команд джерел визначуваних "Викл.АБО"
  unsigned int ranguvannja_d_not[N_BIG*NUMBER_DEFINED_NOT];                     //Ранжування команд джерел визначуваних "НЕ"
  
  uint32_t ranguvannja_tf[NUMBER_TRANSFER_FUNCTIONS];                           //Ранжування передавальних функцій
  
  uint32_t buttons_mode;                                                        //Режими роботи ФК
                                                                                //0 - Звичайна кнопка
                                                                                //1 - Двопозиційний ключ
  unsigned int ranguvannja_buttons[N_SMALL*NUMBER_DEFINED_BUTTONS];             //Ранжування опреділюваних кнопок
  
  unsigned int configuration;         //Конфігурація приладу
  
  unsigned int grupa_ustavok;         //Група уставок
                                      // 1 - Група 1
                                      // 2 - Група 2
                                      // 3 - Група 3
                                      // 4 - Група 4
  //"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
  //~~~~~~~~~~~  OBSOLETE	OBSOLETE obsolete This for reference only part                                      ~~~~~~~
  //___________________________________________________________________________________________________________________
  //```````````````````````````````````````````````````````````````````````````````````````````````````````````````````
  //ДЗ
  /*uint32_t pickup_dz_k[NUMBER_GROUP_USTAVOK];                   //Коефіцієнт компенсації п.5.27.5 [0; 3] крок 0,01
  
  uint32_t pickup_dz1[NUMBER_GROUP_USTAVOK];                    //Уставка ДЗ1 за опором п.5.27.6 [0.01; 300] крок 0,01 Ом
  uint32_t pickup_dz1_amtz[NUMBER_GROUP_USTAVOK];               //Уставка ДЗ1 для АМСЗ за струмом п.5.27.18 [2; 150] крок 0,01А

  int32_t pickup_dz2_angle[NUMBER_GROUP_USTAVOK];               //Кут нижньої межі сектора для ДЗ2 п.5.27.10 [-10, 40] крок 1
  int32_t pickup_dz2_angle_cos1[NUMBER_GROUP_USTAVOK];           //Косинус кута нижньої межі сектора для ДЗ2 (сектор спрацювання)
  int32_t pickup_dz2_angle_sin1[NUMBER_GROUP_USTAVOK];           //Синус кута нижньої межі сектора для ДЗ2 (сектор спрацювання)
  int32_t pickup_dz2_angle_cos2[NUMBER_GROUP_USTAVOK];           //Косинус кута нижньої межі сектора для ДЗ2 (сектор відпускання)
  int32_t pickup_dz2_angle_sin2[NUMBER_GROUP_USTAVOK];           //Синус кута нижньої межі сектора для ДЗ2 (сектор відпускання)
  uint32_t pickup_dz2_dir[NUMBER_GROUP_USTAVOK];                //Уставка ДЗ2 за опором п.5.27.7 [0.01; 300] крок 0,01 Ом
  uint32_t pickup_dz2_inv[NUMBER_GROUP_USTAVOK];                //Уставка ДЗ2 за опором п.5.27.7 [0.01; 300] крок 0,01 Ом
  uint32_t pickup_dz2_amtz[NUMBER_GROUP_USTAVOK];               //Уставка ДЗ2 для АМСЗ за струмом п.5.27.18 [2; 150] крок 0,01А

  int32_t pickup_dz3_angle[NUMBER_GROUP_USTAVOK];               //Кут нижньої межі сектора для ДЗ3 п.5.27.10 [-10, 40] крок 1
  int32_t pickup_dz3_angle_cos1[NUMBER_GROUP_USTAVOK];           //Косинус кута нижньої межі сектора для ДЗ3 (сектор спрацювання) 
  int32_t pickup_dz3_angle_sin1[NUMBER_GROUP_USTAVOK];           //Синус кута нижньої межі сектора для ДЗ3 (сектор спрацювання)
  int32_t pickup_dz3_angle_cos2[NUMBER_GROUP_USTAVOK];           //Косинус кута нижньої межі сектора для ДЗ2 (сектор відпускання)
  int32_t pickup_dz3_angle_sin2[NUMBER_GROUP_USTAVOK];           //Синус кута нижньої межі сектора для ДЗ2 (сектор відпускання)
  uint32_t pickup_dz3_dir[NUMBER_GROUP_USTAVOK];                //Уставка ДЗ3 за опором п.5.27.7 [0.01; 300] крок 0,01 Ом
  uint32_t pickup_dz3_inv[NUMBER_GROUP_USTAVOK];                //Уставка ДЗ3 за опором п.5.27.7 [0.01; 300] крок 0,01 Ом
  uint32_t pickup_dz3_amtz[NUMBER_GROUP_USTAVOK];               //Уставка ДЗ3 для АМСЗ за струмом п.5.27.18 [2; 150] крок 0,01А

  int32_t pickup_dz4_angle[NUMBER_GROUP_USTAVOK];               //Кут нижньої межі сектора для ДЗ4 п.5.27.10 [-10, 40] крок 1
  int32_t pickup_dz4_angle_cos1[NUMBER_GROUP_USTAVOK];           //Косинус кута нижньої межі сектора для ДЗ4 (сектор спрацювання)
  int32_t pickup_dz4_angle_sin1[NUMBER_GROUP_USTAVOK];           //Синус кута нижньої межі сектора для ДЗ4 (сектор спрацювання)
  int32_t pickup_dz4_angle_cos2[NUMBER_GROUP_USTAVOK];           //Косинус кута нижньої межі сектора для ДЗ2 (сектор відпускання)
  int32_t pickup_dz4_angle_sin2[NUMBER_GROUP_USTAVOK];           //Синус кута нижньої межі сектора для ДЗ2 (сектор відпускання)
  uint32_t pickup_dz4_dir[NUMBER_GROUP_USTAVOK];                //Уставка ДЗ4 за опором п.5.27.7 [0.01; 300] крок 0,01 Ом
  uint32_t pickup_dz4_inv[NUMBER_GROUP_USTAVOK];                //Уставка ДЗ4 за опором п.5.27.7 [0.01; 300] крок 0,01 Ом
  uint32_t pickup_dz4_amtz[NUMBER_GROUP_USTAVOK];               //Уставка ДЗ4 для АМСЗ за струмом п.5.27.18 [2; 150] крок 0,01А

  int32_t timeout_dz1[NUMBER_GROUP_USTAVOK];                    //Витримка ДЗ1 п.5.27.6 [0.05; 32] крок 0,01с
  int32_t timeout_dz1_amtz[NUMBER_GROUP_USTAVOK];               //Витримка ДЗ1 для АМСЗ п.5.27.18 [0.05; 32] крок 0,01с

  int32_t timeout_dz2_dir[NUMBER_GROUP_USTAVOK];                //Витримка ДЗ2 ВПЕРЕД п.5.27.7 [0.05; 32] крок 0,01с
  int32_t timeout_dz2_dir_pr[NUMBER_GROUP_USTAVOK];             //Витримка ДЗ2 ВПЕРЕД  прискорений п.5.27.26.4 [0; 5] крок 0,01с
  int32_t timeout_dz2_inv[NUMBER_GROUP_USTAVOK];                //Витримка ДЗ2 НАЗАД п.5.27.7 [0.05; 32] крок 0,01с
  int32_t timeout_dz2_inv_pr[NUMBER_GROUP_USTAVOK];             //Витримка ДЗ2 НАЗАД  прискорений п.5.27.26.4 [0; 5] крок 0,01с
  int32_t timeout_dz2_amtz[NUMBER_GROUP_USTAVOK];               //Витримка ДЗ2 для АМСЗ п.5.27.18 [0.05; 32] крок 0,01с
  int32_t timeout_dz2_amtz_pr[NUMBER_GROUP_USTAVOK];            //Витримка ДЗ2 прискорений для АМСЗ п.5.27.27.4 [0; 5] крок 0,01с
  int32_t timeout_dz2_vvid_pr[NUMBER_GROUP_USTAVOK];            //Витримка вводу прискорення ДЗ2 п.5.27.26.2 [0,1; 5] крок 0,01с
  int32_t timeout_dz2_amtz_vvid_pr[NUMBER_GROUP_USTAVOK];       //Витримка вводу прискорення ДЗ2 для АМСЗ п.5.27.27.2 [0,1; 5] крок 0,01с

  int32_t timeout_dz3_dir[NUMBER_GROUP_USTAVOK];                //Витримка ДЗ3 ВПЕРЕД п.5.27.7 [0.05; 32] крок 0,01с
  int32_t timeout_dz3_dir_pr[NUMBER_GROUP_USTAVOK];             //Витримка ДЗ3 ВПЕРЕД  прискорений п.5.27.26.4 [0; 5] крок 0,01с
  int32_t timeout_dz3_inv[NUMBER_GROUP_USTAVOK];                //Витримка ДЗ3 НАЗАД п.5.27.7 [0.05; 32] крок 0,01с
  int32_t timeout_dz3_inv_pr[NUMBER_GROUP_USTAVOK];             //Витримка ДЗ3 НАЗАД  прискорений п.5.27.26.4 [0; 5] крок 0,01с
  int32_t timeout_dz3_amtz[NUMBER_GROUP_USTAVOK];               //Витримка ДЗ3 для АМСЗ п.5.27.18 [0.05; 32] крок 0,01с
  int32_t timeout_dz3_amtz_pr[NUMBER_GROUP_USTAVOK];            //Витримка ДЗ3 прискорений для АМСЗ п.5.27.27.4 [0; 5] крок 0,01с
  int32_t timeout_dz3_vvid_pr[NUMBER_GROUP_USTAVOK];            //Витримка вводу прискорення ДЗ3 п.5.27.26.2 [0,1; 5] крок 0,01с
  int32_t timeout_dz3_amtz_vvid_pr[NUMBER_GROUP_USTAVOK];       //Витримка вводу прискорення ДЗ3 для АМСЗ для АМСЗ п.5.27.27.2 [0,1; 5] крок 0,01с

  int32_t timeout_dz4_dir[NUMBER_GROUP_USTAVOK];                //Витримка ДЗ4 ВПЕРЕД п.5.27.7 [0.05; 32] крок 0,01с
  int32_t timeout_dz4_dir_pr[NUMBER_GROUP_USTAVOK];             //Витримка ДЗ4 ВПЕРЕД  прискорений п.5.27.26.4 [0; 5] крок 0,01с
  int32_t timeout_dz4_inv[NUMBER_GROUP_USTAVOK];                //Витримка ДЗ4 НАЗАД п.5.27.7 [0.05; 32] крок 0,01с
  int32_t timeout_dz4_inv_pr[NUMBER_GROUP_USTAVOK];             //Витримка ДЗ4 НАЗАД  прискорений п.5.27.26.4 [0; 5] крок 0,01с
  int32_t timeout_dz4_amtz[NUMBER_GROUP_USTAVOK];               //Витримка ДЗ4 для АМСЗ п.5.27.18 [0.05; 32] крок 0,01с
  int32_t timeout_dz4_amtz_pr[NUMBER_GROUP_USTAVOK];            //Витримка ДЗ4 прискорений для АМСЗ п.5.27.27.4 [0; 5] крок 0,01с
  int32_t timeout_dz4_vvid_pr[NUMBER_GROUP_USTAVOK];            //Витримка вводу прискорення ДЗ4 п.5.27.26.2 [0,1; 5] крок 0,01с
  int32_t timeout_dz4_amtz_vvid_pr[NUMBER_GROUP_USTAVOK];       //Витримка вводу прискорення ДЗ4 для АМСЗ для АМСЗ п.5.27.27.2 [0,1; 5] крок 0,01с
  
  int32_t timeout_nkn_dz[NUMBER_GROUP_USTAVOK];                 //Витримка ДЗ "Т НКН ДЗ" п.5.27.19.5 [0; 1] крок 0,01с

  uint32_t control_dz;                                          //Поле для управління ДЗ
  */
  //МТЗ
  int type_mtz1;                                                //Тип МТЗ1 (0 - Простий, 1 - Спрямований, 2 -  З пуском по напрузі)
  unsigned int setpoint_mtz_1[NUMBER_GROUP_USTAVOK];            //Уставка МТЗ першої ступені (простий)
  unsigned int setpoint_mtz_1_n_vpered[NUMBER_GROUP_USTAVOK];   //Уставка МТЗ першої ступені (спрямований:вперед)
  unsigned int setpoint_mtz_1_n_nazad[NUMBER_GROUP_USTAVOK];    //Уставка МТЗ першої ступені (спрямований:назад)
  unsigned int setpoint_mtz_1_angle[NUMBER_GROUP_USTAVOK];      //Уставка МТЗ першої ступені (кут довороту)
           int setpoint_mtz_1_angle_cos[NUMBER_GROUP_USTAVOK];  //Уставка МТЗ першої ступені (косинус кута довороту)
           int setpoint_mtz_1_angle_sin[NUMBER_GROUP_USTAVOK];  //Уставка МТЗ першої ступені (синус кута довороту)
  unsigned int setpoint_mtz_1_po_napruzi[NUMBER_GROUP_USTAVOK]; //Уставка МТЗ першої ступені (по напрузі)
  unsigned int setpoint_mtz_1_U[NUMBER_GROUP_USTAVOK];          //Уставка МТЗ першої ступені (напруга пуску)
  int type_mtz2;                                                //Тип МТЗ2 (0 - Простий, 1 - Спрямований, 2 -  З пуском по напрузі, 3 - Залежний А, 4 - Залежний В, 5 - Залежний С)
  unsigned int setpoint_mtz_2[NUMBER_GROUP_USTAVOK];            //Уставка МТЗ другої ступені
  unsigned int setpoint_mtz_2_n_vpered[NUMBER_GROUP_USTAVOK];   //Уставка МТЗ другої ступені (спрямований:вперед)
  unsigned int setpoint_mtz_2_n_nazad[NUMBER_GROUP_USTAVOK];    //Уставка МТЗ другої ступені (спрямований:назад)
  unsigned int setpoint_mtz_2_angle[NUMBER_GROUP_USTAVOK];      //Уставка МТЗ другої ступені (кут довороту)
           int setpoint_mtz_2_angle_cos[NUMBER_GROUP_USTAVOK];  //Уставка МТЗ другої ступені (косинус кута довороту)
           int setpoint_mtz_2_angle_sin[NUMBER_GROUP_USTAVOK];  //Уставка МТЗ другої ступені (синус кута довороту)
  unsigned int setpoint_mtz_2_po_napruzi[NUMBER_GROUP_USTAVOK]; //Уставка МТЗ другої ступені (по напрузі)
  unsigned int setpoint_mtz_2_U[NUMBER_GROUP_USTAVOK];          //Уставка МТЗ другої ступені (напруга пуску)
  int type_mtz3;                                                //Тип МТЗ3 (0 - Простий, 1 - Спрямований, 2 -  З пуском по напрузі)
  unsigned int setpoint_mtz_3[NUMBER_GROUP_USTAVOK];            //Уставка МТЗ третьої ступені
  unsigned int setpoint_mtz_3_n_vpered[NUMBER_GROUP_USTAVOK];   //Уставка МТЗ третьої ступені (спрямований:вперед)
  unsigned int setpoint_mtz_3_n_nazad[NUMBER_GROUP_USTAVOK];    //Уставка МТЗ третьої ступені (спрямований:назад)
  unsigned int setpoint_mtz_3_angle[NUMBER_GROUP_USTAVOK];      //Уставка МТЗ третьої ступені (кут довороту)
           int setpoint_mtz_3_angle_cos[NUMBER_GROUP_USTAVOK];  //Уставка МТЗ третьої ступені (косинус кута довороту)
           int setpoint_mtz_3_angle_sin[NUMBER_GROUP_USTAVOK];  //Уставка МТЗ третьої ступені (синус кута довороту)
  unsigned int setpoint_mtz_3_po_napruzi[NUMBER_GROUP_USTAVOK]; //Уставка МТЗ третьої ступені (по напрузі)
  unsigned int setpoint_mtz_3_U[NUMBER_GROUP_USTAVOK];          //Уставка МТЗ третьої ступені (напруга пуску)
  int type_mtz4;                                                //Тип МТЗ4 (0 - Простий, 1 - Спрямований, 2 -  З пуском по напрузі)
  unsigned int setpoint_mtz_4[NUMBER_GROUP_USTAVOK];            //Уставка МТЗ четвертої ступені
  unsigned int setpoint_mtz_4_n_vpered[NUMBER_GROUP_USTAVOK];   //Уставка МТЗ четвертої ступені (спрямований:вперед)
  unsigned int setpoint_mtz_4_n_nazad[NUMBER_GROUP_USTAVOK];    //Уставка МТЗ четвертої ступені (спрямований:назад)
  unsigned int setpoint_mtz_4_angle[NUMBER_GROUP_USTAVOK];      //Уставка МТЗ четвертої ступені (кут довороту)
           int setpoint_mtz_4_angle_cos[NUMBER_GROUP_USTAVOK];  //Уставка МТЗ четвертої ступені (косинус кута довороту)
           int setpoint_mtz_4_angle_sin[NUMBER_GROUP_USTAVOK];  //Уставка МТЗ четвертої ступені (синус кута довороту)
  unsigned int setpoint_mtz_4_po_napruzi[NUMBER_GROUP_USTAVOK]; //Уставка МТЗ четвертої ступені (по напрузі)
  unsigned int setpoint_mtz_4_U[NUMBER_GROUP_USTAVOK];          //Уставка МТЗ четвертої ступені (напруга пуску)

  int timeout_mtz_1[NUMBER_GROUP_USTAVOK];                      //Витримка МТЗ першої ступені
  int timeout_mtz_1_n_vpered[NUMBER_GROUP_USTAVOK];             //Витримка МТЗ першої ступені (спрямований:вперед)
  int timeout_mtz_1_n_nazad[NUMBER_GROUP_USTAVOK];              //Витримка МТЗ першої ступені (спрямований:назад)
  int timeout_mtz_1_po_napruzi[NUMBER_GROUP_USTAVOK];           //Витримка МТЗ першої ступені (по напрузі)
  int timeout_mtz_2[NUMBER_GROUP_USTAVOK];                      //Витримка МТЗ другої ступені
  int timeout_mtz_2_pr[NUMBER_GROUP_USTAVOK];                   //Витримка присторення МТЗ другої ступені
  int timeout_mtz_2_n_vpered[NUMBER_GROUP_USTAVOK];             //Витримка МТЗ другої ступені (спрямований:вперед)
  int timeout_mtz_2_n_vpered_pr[NUMBER_GROUP_USTAVOK];          //Витримка присторення МТЗ другої ступені (спрямований:вперед)
  int timeout_mtz_2_n_nazad[NUMBER_GROUP_USTAVOK];              //Витримка МТЗ другої ступені (спрямований:назад)
  int timeout_mtz_2_n_nazad_pr[NUMBER_GROUP_USTAVOK];           //Витримка присторення МТЗ другої ступені (спрямований:назад)
  int timeout_mtz_2_po_napruzi[NUMBER_GROUP_USTAVOK];           //Витримка МТЗ другої ступені (по напрузі)
  int timeout_mtz_2_po_napruzi_pr[NUMBER_GROUP_USTAVOK];        //Витримка присторення МТЗ другої ступені (по напрузі)
  int timeout_mtz_2_vvid_pr[NUMBER_GROUP_USTAVOK];              //Витримка вводу присорення МТЗ2
  int timeout_mtz_3[NUMBER_GROUP_USTAVOK];                      //Витримка МТЗ третьої ступені
  int timeout_mtz_3_n_vpered[NUMBER_GROUP_USTAVOK];             //Витримка МТЗ третьої ступені (спрямований:вперед)
  int timeout_mtz_3_n_nazad[NUMBER_GROUP_USTAVOK];              //Витримка МТЗ третьої ступені (спрямований:назад)
  int timeout_mtz_3_po_napruzi[NUMBER_GROUP_USTAVOK];           //Витримка МТЗ третьої ступені (по напрузі)
  int timeout_mtz_4[NUMBER_GROUP_USTAVOK];                      //Витримка МТЗ четвертої ступені
  int timeout_mtz_4_n_vpered[NUMBER_GROUP_USTAVOK];             //Витримка МТЗ третьої ступені (спрямований:вперед)
  int timeout_mtz_4_n_nazad[NUMBER_GROUP_USTAVOK];              //Витримка МТЗ третьої ступені (спрямований:назад)
  int timeout_mtz_4_po_napruzi[NUMBER_GROUP_USTAVOK];           //Витримка МТЗ третьої ступені (по напрузі)

  unsigned int control_mtz;                                 //Поле для управління МТЗ
  //`````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
  //~~~~~~~~~~              End of obsolete                                                                            ~~~~~~~~~~~~~~
  //_________________________________________________________________________________________________________________________________
  //.................................................................................................................................
  /*
  unsigned int control_mto;                                 //Поле для управління МТЗO
  unsigned int control_mtr;                                 //Поле для управління МТЗP
  
   int type_mtzo1;  
                                              //Тип МТЗO1 (0 - Простий, 1 - Спрямований, 2 -  З пуском по напрузі)
  unsigned int setpoint_mtzo_1[NUMBER_GROUP_USTAVOK];            //Уставка МТЗO першої ступені (простий)
  unsigned int setpoint_mtzo_1_n_vpered[NUMBER_GROUP_USTAVOK];   //Уставка МТЗO першої ступені (спрямований:вперед)
  unsigned int setpoint_mtzo_1_n_nazad[NUMBER_GROUP_USTAVOK];    //Уставка МТЗO першої ступені (спрямований:назад)

  unsigned int setpoint_mtzo_1_po_napruzi[NUMBER_GROUP_USTAVOK]; //Уставка МТЗO першої ступені (по напрузі)
  unsigned int setpoint_mtzo_1_U[NUMBER_GROUP_USTAVOK];          //Уставка МТЗO першої ступені (напруга пуску)
  int type_mtzo2;                                                //Тип МТЗO2 (0 - Простий, 1 - Спрямований, 2 -  З пуском по напрузі, 3 - Залежний А, 4 - Залежний В, 5 - Залежний С)
  unsigned int setpoint_mtzo_2[NUMBER_GROUP_USTAVOK];            //Уставка МТЗO другої ступені
  unsigned int setpoint_mtzo_2_n_vpered[NUMBER_GROUP_USTAVOK];   //Уставка МТЗO другої ступені (спрямований:вперед)
  unsigned int setpoint_mtzo_2_n_nazad[NUMBER_GROUP_USTAVOK];    //Уставка МТЗO другої ступені (спрямований:назад)

  unsigned int setpoint_mtzo_2_po_napruzi[NUMBER_GROUP_USTAVOK]; //Уставка МТЗO другої ступені (по напрузі)
  unsigned int setpoint_mtzo_2_U[NUMBER_GROUP_USTAVOK];          //Уставка МТЗO другої ступені (напруга пуску)
  int type_mtzo3;                                                //Тип МТЗO3 (0 - Простий, 1 - Спрямований, 2 -  З пуском по напрузі)
  unsigned int setpoint_mtzo_3[NUMBER_GROUP_USTAVOK];            //Уставка МТЗO третьої ступені
  unsigned int setpoint_mtzo_3_n_vpered[NUMBER_GROUP_USTAVOK];   //Уставка МТЗO третьої ступені (спрямований:вперед)
  unsigned int setpoint_mtzo_3_n_nazad[NUMBER_GROUP_USTAVOK];    //Уставка МТЗO третьої ступені (спрямований:назад)

  unsigned int setpoint_mtzo_3_po_napruzi[NUMBER_GROUP_USTAVOK]; //Уставка МТЗO третьої ступені (по напрузі)
  unsigned int setpoint_mtzo_3_U[NUMBER_GROUP_USTAVOK];          //Уставка МТЗO третьої ступені (напруга пуску)
  int type_mtzo4;                                                //Тип МТЗO4 (0 - Простий, 1 - Спрямований, 2 -  З пуском по напрузі)
  unsigned int setpoint_mtzo_4[NUMBER_GROUP_USTAVOK];            //Уставка МТЗO четвертої ступені
  unsigned int setpoint_mtzo_4_n_vpered[NUMBER_GROUP_USTAVOK];   //Уставка МТЗO четвертої ступені (спрямований:вперед)
  unsigned int setpoint_mtzo_4_n_nazad[NUMBER_GROUP_USTAVOK];    //Уставка МТЗO четвертої ступені (спрямований:назад)

  unsigned int setpoint_mtzro_4_po_napruzi[NUMBER_GROUP_USTAVOK]; //Уставка МТЗO четвертої ступені (по напрузі)
  unsigned int setpoint_mtzro_4_U[NUMBER_GROUP_USTAVOK];          //Уставка МТЗO четвертої ступені (напруга пуску)

  int type_mtzr1;                                                //Тип МТЗO3 (0 - Простий, 1 - Спрямований, 2 -  З пуском по напрузі)
  unsigned int setpoint_mtzr_1[NUMBER_GROUP_USTAVOK];            //Уставка МТЗP першої ступені
  unsigned int setpoint_mtzr_1_n_vpered[NUMBER_GROUP_USTAVOK];   //Уставка МТЗP першої ступені (спрямований:вперед)
  unsigned int setpoint_mtzr_1_n_nazad[NUMBER_GROUP_USTAVOK];    //Уставка МТЗP першої ступені (спрямований:назад)

  unsigned int setpoint_mtzr_1_po_napruzi[NUMBER_GROUP_USTAVOK]; //Уставка МТЗP першої ступені (по напрузі)
  unsigned int setpoint_mtzr_1_U[NUMBER_GROUP_USTAVOK];          //Уставка МТЗP першої ступені (напруга пуску)
  int type_mtzr2;                                                //Тип МТЗO4 (0 - Простий, 1 - Спрямований, 2 -  З пуском по напрузі)
  unsigned int setpoint_mtzr_2[NUMBER_GROUP_USTAVOK];            //Уставка МТЗP другої ступені
  unsigned int setpoint_mtzr_2_n_vpered[NUMBER_GROUP_USTAVOK];   //Уставка МТЗP другої ступені (спрямований:вперед)
  unsigned int setpoint_mtzr_2_n_nazad[NUMBER_GROUP_USTAVOK];    //Уставка МТЗP другої ступені (спрямований:назад)

  unsigned int setpoint_mtzr_2_po_napruzi[NUMBER_GROUP_USTAVOK]; //Уставка МТЗP другої ступені (по напрузі)
  unsigned int setpoint_mtzr_2_U[NUMBER_GROUP_USTAVOK];          //Уставка МТЗP другої ступені (напруга пуску)

*/
    //ДЗ
  uint32_t pickup_dzo_Io3g_Io1g[NUMBER_GROUP_USTAVOK];                   //Уставка блокування ДЗО при ожеледі п.5.24.26  0.05 до 0.95 з кроком зміни 0.001.
  
  uint32_t pickup_dzo1[NUMBER_GROUP_USTAVOK];                    //Уставка ДЗO1 за опором п.5.24.8  [0.01; 300] крок 0,01 Ом
  uint32_t pickup_dzo1_amtz[NUMBER_GROUP_USTAVOK];               //Уставка ДЗO1 для АМСЗ за струмом п.5.24.34.3  [2; 150] крок 0,01А
  uint32_t pickup_dzo1_blkI[NUMBER_GROUP_USTAVOK];               //Уставка ДЗO1  струму бокування  п.5.24.10   [2; 150] крок 0,01А

  int32_t pickup_dzo2_angle[NUMBER_GROUP_USTAVOK];               //Кут нижньої межі сектора для ДЗO2 п.5.24.14  [ 0 до 60 ] крок 1
  int32_t pickup_dzo2_angle_cos1[NUMBER_GROUP_USTAVOK];           //Косинус кута нижньої межі сектора для ДЗO2 (сектор спрацювання)
  int32_t pickup_dzo2_angle_sin1[NUMBER_GROUP_USTAVOK];           //Синус кута нижньої межі сектора для ДЗO2 (сектор спрацювання)
  int32_t pickup_dzo2_angle_cos2[NUMBER_GROUP_USTAVOK];           //Косинус кута нижньої межі сектора для ДЗO2 (сектор відпускання)
  int32_t pickup_dzo2_angle_sin2[NUMBER_GROUP_USTAVOK];           //Синус кута нижньої межі сектора для ДЗO2 (сектор відпускання)
  uint32_t pickup_dzo2_dir[NUMBER_GROUP_USTAVOK];                //Уставка ДЗO2 за опором п.5.24.13 [0.01; 300] крок 0,01 Ом
  uint32_t pickup_dzo2_inv[NUMBER_GROUP_USTAVOK];                //Уставка ДЗO2 за опором п.5.24.13 [0.01; 300] крок 0,01 Ом
  uint32_t pickup_dzo2_amtz[NUMBER_GROUP_USTAVOK];               //Уставка ДЗO2 для АМСЗ за струмом п.5.24.34.3  [2; 150] крок 0,01А

  int32_t pickup_dzo3_angle_h[NUMBER_GROUP_USTAVOK];               //Кут верхньої межі сектора для ДЗO3 п.5.24.15  [ 179 ° до 180 ] крок 1
  int32_t pickup_dzo3_angle_l[NUMBER_GROUP_USTAVOK];               //Кут нижньої межі сектора для ДЗO3  п.5.24.15  [ 179 ° до 180 ] крок 1
  //int32_t pickup_dzo3_angle_d[NUMBER_GROUP_USTAVOK];               //Кут різниці меж секторів для ДЗO3  п.5.24.16  [ 5 °до 110 °. ] крок 1
  int32_t pickup_dzo3_angle_cos1_l[NUMBER_GROUP_USTAVOK];           //Косинус кута нижньої межі сектора для ДЗO3 (сектор спрацювання) 
  int32_t pickup_dzo3_angle_sin1_l[NUMBER_GROUP_USTAVOK];           //Синус кута нижньої межі сектора для ДЗ3O (сектор спрацювання)
  int32_t pickup_dzo3_angle_cos2_l[NUMBER_GROUP_USTAVOK];           //Косинус кута нижньої межі сектора для ДЗO2 (сектор відпускання)
  int32_t pickup_dzo3_angle_sin2_l[NUMBER_GROUP_USTAVOK];           //Синус кута нижньої межі сектора для ДЗO2 (сектор відпускання)
  int32_t pickup_dzo3_angle_cos1_h[NUMBER_GROUP_USTAVOK];           //Косинус кута нижньої межі сектора для ДЗO3 (сектор спрацювання) 
  int32_t pickup_dzo3_angle_sin1_h[NUMBER_GROUP_USTAVOK];           //Синус кута нижньої межі сектора для ДЗ3O (сектор спрацювання)
  int32_t pickup_dzo3_angle_cos2_h[NUMBER_GROUP_USTAVOK];           //Косинус кута нижньої межі сектора для ДЗO2 (сектор відпускання)
  int32_t pickup_dzo3_angle_sin2_h[NUMBER_GROUP_USTAVOK];           //Синус кута нижньої межі сектора для ДЗO2 (сектор відпускання)
  
  uint32_t pickup_dzo3_dir[NUMBER_GROUP_USTAVOK];                //Уставка ДЗO3 за опором п.5.24.13 [0.01; 300] крок 0,01 Ом
  uint32_t pickup_dzo3_inv[NUMBER_GROUP_USTAVOK];                //Уставка ДЗO3 за опором п.5.24.13 [0.01; 300] крок 0,01 Ом
  uint32_t pickup_dzo3_amtz[NUMBER_GROUP_USTAVOK];               //Уставка ДЗO3 для АМСЗ за струмом п.5.24.34.3 [2; 150] крок 0,01А


  uint32_t pickup_dzo4_Zo_dir[NUMBER_GROUP_USTAVOK];                //Уставка ДЗО4 за опором п.5.24.21  [0.01; 300] крок 0,01 Ом
  uint32_t pickup_dzo4_Xo_dir[NUMBER_GROUP_USTAVOK];                //Уставка ДЗО4 за опором п.5.24.21  [0.01; 300] крок 0,01 Ом
  uint32_t pickup_dzo4_Zo_inv[NUMBER_GROUP_USTAVOK];                //Уставка ДЗО4 за опором п.5.24.21  [0.01; 300] крок 0,01 Ом
  uint32_t pickup_dzo4_Xo_inv[NUMBER_GROUP_USTAVOK];                //Уставка ДЗО4 за опором п.5.24.21  [0.01; 300] крок 0,01 Ом
  uint32_t pickup_dzo4_amtz[NUMBER_GROUP_USTAVOK];               //Уставка ДЗО4 для АМСЗ за струмом п.5.27.18 [2; 150] крок 0,01А

  
  int32_t timeout_dzo1[NUMBER_GROUP_USTAVOK];                    //Витримка ДЗO1 п.5.24.8  [0.0; 32] крок 0,01с
  int32_t timeout_dzo1_amtz[NUMBER_GROUP_USTAVOK];               //Витримка ДЗO1 для АМСЗO п.5.24.34.3  [0.05; 32] крок 0,01с

  int32_t timeout_dzo2_dir[NUMBER_GROUP_USTAVOK];                //Витримка ДЗO2 ВПЕРЕД п.5.24.13  [0.0; 32] крок 0,01с
  int32_t timeout_dzo2_dir_pr[NUMBER_GROUP_USTAVOK];             //Витримка ДЗO2 ВПЕРЕД  прискорений п.5.24.49.4  [0; 5] крок 0,01с
  int32_t timeout_dzo2_inv[NUMBER_GROUP_USTAVOK];                //Витримка ДЗO2 НАЗАД п.5.24.13  [0.0; 32] крок 0,01с
  int32_t timeout_dzo2_inv_pr[NUMBER_GROUP_USTAVOK];             //Витримка ДЗO2 НАЗАД  прискорений п.5.24.49.4  [0; 5] крок 0,01с
  int32_t timeout_dzo2_amtz[NUMBER_GROUP_USTAVOK];               //Витримка ДЗO2 для АМСЗ п.5.24.34.3  [0.05; 32] крок 0,01с
  int32_t timeout_dzo2_amtz_pr[NUMBER_GROUP_USTAVOK];            //Витримка ДЗO2 прискорений для АМСЗ п.5.24.50.4 [0; 5] крок 0,01с
  int32_t timeout_dzo2_vvid_pr[NUMBER_GROUP_USTAVOK];            //Витримка вводу прискорення ДЗ2 п.5.24.49.2   [0,1; 5] крок 0,01с
  int32_t timeout_dzo2_amtz_vvid_pr[NUMBER_GROUP_USTAVOK];       //Витримка вводу прискорення ДЗ2 для АМСЗ п.5.24.50.2  [0,1; 5] крок 0,01с

  int32_t timeout_dzo3_dir[NUMBER_GROUP_USTAVOK];                //Витримка ДЗO3 ВПЕРЕД п.5.24.13  [0.0; 32] крок 0,01с
  int32_t timeout_dzo3_dir_pr[NUMBER_GROUP_USTAVOK];             //Витримка ДЗO3 ВПЕРЕД  прискорений п.5.24.49.4 [0; 5] крок 0,01с
  int32_t timeout_dzo3_inv[NUMBER_GROUP_USTAVOK];                //Витримка ДЗO3 НАЗАД п.5.24.13  [0.0; 32] крок 0,01с
  int32_t timeout_dzo3_inv_pr[NUMBER_GROUP_USTAVOK];             //Витримка ДЗO3 НАЗАД  прискорений п.5.24.49.4 [0; 5] крок 0,01с
  int32_t timeout_dzo3_amtz[NUMBER_GROUP_USTAVOK];               //Витримка ДЗO3 для АМСЗ п.5.24.34.3 [0.05; 32] крок 0,01с
  int32_t timeout_dzo3_amtz_pr[NUMBER_GROUP_USTAVOK];            //Витримка ДЗO3 прискорений для АМСЗ п.5.24.50.4   [0; 5] крок 0,01с
  int32_t timeout_dzo3_vvid_pr[NUMBER_GROUP_USTAVOK];            //Витримка вводу прискорення ДЗ3 п.5.24.49.2 [0,1; 5] крок 0,01с
  int32_t timeout_dzo3_amtz_vvid_pr[NUMBER_GROUP_USTAVOK];       //Витримка вводу прискорення ДЗ3 для АМСЗ для АМСЗ п.5.24.50.2  [0,1; 5] крок 0,01с

  int32_t timeout_dzo4_dir[NUMBER_GROUP_USTAVOK];                //Витримка ДЗO4 ВПЕРЕД п.5.24.21  [0.0; 32] крок 0,01с
  int32_t timeout_dzo4_inv[NUMBER_GROUP_USTAVOK];                //Витримка ДЗO4 НАЗАД п.5.24.21  [0.0; 32] крок 0,01с
  int32_t timeout_dzo4_amtz[NUMBER_GROUP_USTAVOK];               //Витримка ДЗO4 для АМСЗ 5.24.34.3  [0.05; 32] крок 0,01с
  
  int32_t timeout_nkn_dzo[NUMBER_GROUP_USTAVOK];                 //Витримка ДЗ "Т НКН ДЗO" п.5.24.41  [0; 1] крок 0,01с

  
  uint32_t control_dzo;
  uint32_t control_dzr;
  uint32_t pickup_dzr_Io3g_Io1g[NUMBER_GROUP_USTAVOK];           //Уставка блокування ДЗP при ожеледі п.5.25.20   0.05 до 0.95 з кроком зміни 0.001.
  
  uint32_t pickup_dzr1[NUMBER_GROUP_USTAVOK];                    //Уставка ДЗP1 за опором п.5.25.6  [0.01; 300] крок 0,01 Ом
  uint32_t pickup_dzr1_amtz[NUMBER_GROUP_USTAVOK];               //Уставка ДЗP1 для АМСЗ за струмом п.5.25.27.3   [2; 150] крок 0,01А
  uint32_t pickup_dzr1_blkI[NUMBER_GROUP_USTAVOK];               //Уставка ДЗP1  струму бокування  п.5.25.8   [2; 150] крок 0,01А

  int32_t pickup_dzr2_angle[NUMBER_GROUP_USTAVOK];               //Кут нижньої межі сектора для ДЗP2 п.5.25.12   [ 0 до 60 ] крок 1
  int32_t pickup_dzr2_angle_cos1[NUMBER_GROUP_USTAVOK];           //Косинус кута нижньої межі сектора для ДЗP2 (сектор спрацювання)
  int32_t pickup_dzr2_angle_sin1[NUMBER_GROUP_USTAVOK];           //Синус кута нижньої межі сектора для ДЗP2 (сектор спрацювання)
  int32_t pickup_dzr2_angle_cos2[NUMBER_GROUP_USTAVOK];           //Косинус кута нижньої межі сектора для ДЗP2 (сектор відпускання)
  int32_t pickup_dzr2_angle_sin2[NUMBER_GROUP_USTAVOK];           //Синус кута нижньої межі сектора для ДЗP2 (сектор відпускання)
  
  uint32_t pickup_dzr2_dir[NUMBER_GROUP_USTAVOK];                //Уставка ДЗP2 за опором п.5.25.11 [0.01; 300] крок 0,01 Ом
  uint32_t pickup_dzr2_inv[NUMBER_GROUP_USTAVOK];                //Уставка ДЗP2 за опором п.5.25.11 [0.01; 300] крок 0,01 Ом
  uint32_t pickup_dzr2_amtz[NUMBER_GROUP_USTAVOK];               //Уставка ДЗP2 для АМСЗ за струмом п.5.25.8  [2; 150] крок 0,01А

  int32_t pickup_dzr3_angle_h[NUMBER_GROUP_USTAVOK];               //Кут верхньої межі сектора для ДЗP3 п.5.25.13  [ 179 ° до 180 ] крок 1
  int32_t pickup_dzr3_angle_l[NUMBER_GROUP_USTAVOK];               //Кут нижньої межі сектора для ДЗP3  п.5.25.13  [ 179 ° до 180 ] крок 1
  //int32_t pickup_dzr3_angle_d[NUMBER_GROUP_USTAVOK];               //Кут різниці меж секторів для ДЗP3  п.5.25.16  [ 5 °до 110 °. ] крок 1
  int32_t pickup_dzr3_angle_cos1_l[NUMBER_GROUP_USTAVOK];           //Косинус кута нижньої межі сектора для ДЗP3 (сектор спрацювання) 
  int32_t pickup_dzr3_angle_sin1_l[NUMBER_GROUP_USTAVOK];           //Синус кута нижньої межі сектора для ДЗ3P3 (сектор спрацювання)
  int32_t pickup_dzr3_angle_cos2_l[NUMBER_GROUP_USTAVOK];           //Косинус кута нижньої межі сектора для ДЗP3 (сектор відпускання)
  int32_t pickup_dzr3_angle_sin2_l[NUMBER_GROUP_USTAVOK];           //Синус кута нижньої межі сектора для ДЗP3 (сектор відпускання)
  int32_t pickup_dzr3_angle_cos1_h[NUMBER_GROUP_USTAVOK];           //Косинус кута нижньої межі сектора для ДЗP3 (сектор спрацювання) 
  int32_t pickup_dzr3_angle_sin1_h[NUMBER_GROUP_USTAVOK];           //Синус кута нижньої межі сектора для ДЗ3P (сектор спрацювання)
  int32_t pickup_dzr3_angle_cos2_h[NUMBER_GROUP_USTAVOK];           //Косинус кута нижньої межі сектора для ДЗP3 (сектор відпускання)
  int32_t pickup_dzr3_angle_sin2_h[NUMBER_GROUP_USTAVOK];           //Синус кута нижньої межі сектора для ДЗP3 (сектор відпускання)
  
  uint32_t pickup_dzr3_dir[NUMBER_GROUP_USTAVOK];                //Уставка ДЗP3 за опором п.5.25.11 [0.01; 300] крок 0,01 Ом
  uint32_t pickup_dzr3_inv[NUMBER_GROUP_USTAVOK];                //Уставка ДЗP3 за опором п.5.25.11 [0.01; 300] крок 0,01 Ом
  uint32_t pickup_dzr3_amtz[NUMBER_GROUP_USTAVOK];               //Уставка ДЗP3 для АМСЗ за струмом п.5.25.8 [2; 150] крок 0,01А
  
  int32_t timeout_dzr1[NUMBER_GROUP_USTAVOK];                    //Витримка ДЗP1 п.5.25.6   [0.05; 32] крок 0,01с
  int32_t timeout_dzr1_amtz[NUMBER_GROUP_USTAVOK];               //Витримка ДЗP1 для АМСЗP п.5.25.27.3   [0.05; 32] крок 0,01с

  int32_t timeout_dzr2_dir[NUMBER_GROUP_USTAVOK];                //Витримка ДЗP2 ВПЕРЕД п.5.25.11   [0.05; 32] крок 0,01с
  int32_t timeout_dzr2_dir_pr[NUMBER_GROUP_USTAVOK];             //Витримка ДЗP2 ВПЕРЕД  прискорений п.5.25.41.4   [0; 5] крок 0,01с
  int32_t timeout_dzr2_inv[NUMBER_GROUP_USTAVOK];                //Витримка ДЗP2 НАЗАД п.5.25.11   [0.05; 32] крок 0,01с
  int32_t timeout_dzr2_inv_pr[NUMBER_GROUP_USTAVOK];             //Витримка ДЗP2 НАЗАД  прискорений п.5.25.41.4   [0; 5] крок 0,01с
  int32_t timeout_dzr2_amtz[NUMBER_GROUP_USTAVOK];               //Витримка ДЗP2 для АМСЗ п.5.25.27.3   [0.05; 32] крок 0,01с
  int32_t timeout_dzr2_amtz_pr[NUMBER_GROUP_USTAVOK];            //Витримка ДЗP2 прискорений для АМСЗ п.5.25.42.4  [0; 5] крок 0,01с
  int32_t timeout_dzr2_vvid_pr[NUMBER_GROUP_USTAVOK];            //Витримка вводу прискорення ДЗP2 п.5.25.41.2    [0,1; 5] крок 0,01с
  int32_t timeout_dzr2_amtz_vvid_pr[NUMBER_GROUP_USTAVOK];       //Витримка вводу прискорення ДЗP2 для АМСЗ п.5.25.42.2 [0,1; 5] крок 0,01с

  int32_t timeout_dzr3_dir[NUMBER_GROUP_USTAVOK];                //Витримка ДЗP3 ВПЕРЕД п.5.25.11  [0.05; 32] крок 0,01с
  int32_t timeout_dzr3_dir_pr[NUMBER_GROUP_USTAVOK];             //Витримка ДЗP3 ВПЕРЕД  прискорений п.5.25.41.4  [0; 5] крок 0,01с
  int32_t timeout_dzr3_inv[NUMBER_GROUP_USTAVOK];                //Витримка ДЗP3 НАЗАД п.5.25.11  [0.05; 32] крок 0,01с
  int32_t timeout_dzr3_inv_pr[NUMBER_GROUP_USTAVOK];             //Витримка ДЗP3 НАЗАД  прискорений п.5.25.41.4  [0; 5] крок 0,01с
  int32_t timeout_dzr3_amtz[NUMBER_GROUP_USTAVOK];               //Витримка ДЗP3 для АМСЗP п.5.25.27.3  [0.05; 32] крок 0,01с
  int32_t timeout_dzr3_amtz_pr[NUMBER_GROUP_USTAVOK];            //Витримка ДЗP3 прискорений для АМСЗP п.5.25.42.4    [0; 5] крок 0,01с
  int32_t timeout_dzr3_vvid_pr[NUMBER_GROUP_USTAVOK];            //Витримка вводу прискорення ДЗP3 п.5.25.41.2  [0,1; 5] крок 0,01с
  int32_t timeout_dzr3_amtz_vvid_pr[NUMBER_GROUP_USTAVOK];       //Витримка вводу прискорення ДЗP3 для АМСЗ для АМСЗ п.5.25.42.2 [0,1; 5] крок 0,01с
 
  int32_t timeout_nkn_dzr[NUMBER_GROUP_USTAVOK];                 //Витримка ДЗ "Т НКН ДЗP" п.5.25.33  [0; 1] крок 0,01с
 

  
  unsigned int control_mtzo;                                 //Поле для управління МТЗO
  unsigned int control_mtzr;                                 //Поле для управління МТЗP
  
   int type_mtzo1;  
                                              //Тип МТЗO1 (0 - Простий, 1 - Спрямований, 2 -  З пуском по напрузі)
  unsigned int setpoint_mtzo_1[NUMBER_GROUP_USTAVOK];            //Уставка МТЗO першої ступені (простий)МСЗ за струмом п.5.3.6   [0,5; 150 А] крок 0,01А
  unsigned int setpoint_mtzo_1_n_vpered[NUMBER_GROUP_USTAVOK];   //Уставка МТЗO 1 ступені (спрямований:вперед)
  unsigned int setpoint_mtzo_1_n_nazad[NUMBER_GROUP_USTAVOK];    //Уставка МТЗO 1 ступені (спрямований:назад)
  unsigned int setpoint_mtzo_1_angle[NUMBER_GROUP_USTAVOK];      //Уставка МТЗ першої ступені (кут довороту) п.5.3.12
           int setpoint_mtzo_1_angle_cos[NUMBER_GROUP_USTAVOK];  //Уставка МТЗ першої ступені (косинус кута довороту)
           int setpoint_mtzo_1_angle_sin[NUMBER_GROUP_USTAVOK];  //Уставка МТЗ першої ступені (синус кута довороту)
  
  unsigned int setpoint_mtzo_1_po_napruzi[NUMBER_GROUP_USTAVOK]; //Уставка МТЗO 1 ступені (по напрузі)
  unsigned int setpoint_mtzo_1_U[NUMBER_GROUP_USTAVOK];          //Уставка МТЗO 1 ступені (напруга пуску)[2; 150 В] крок 0,01В
  int type_mtzo2;                                                //Тип МТЗO2 (0 - Простий, 1 - Спрямований, 2 -  З пуском по напрузі, 3 - Залежний А, 4 - Залежний В, 5 - Залежний С)
  unsigned int setpoint_mtzo_2[NUMBER_GROUP_USTAVOK];            //Уставка МТЗO 2 ступені за струмом п.5.3.6 [0,5; 150 А] крок 0,01А
  unsigned int setpoint_mtzo_2_n_vpered[NUMBER_GROUP_USTAVOK];   //Уставка МТЗO 2 ступені (спрямований:вперед)
  unsigned int setpoint_mtzo_2_n_nazad[NUMBER_GROUP_USTAVOK];    //Уставка МТЗO 2 ступені (спрямований:назад)
  unsigned int setpoint_mtzo_2_angle[NUMBER_GROUP_USTAVOK];      //Уставка МТЗ другої ступені (кут довороту) п.5.3.6  
           int setpoint_mtzo_2_angle_cos[NUMBER_GROUP_USTAVOK];  //Уставка МТЗ другої ступені (косинус кута довороту)
           int setpoint_mtzo_2_angle_sin[NUMBER_GROUP_USTAVOK];  //Уставка МТЗ другої ступені (синус кута довороту)
  
  unsigned int setpoint_mtzo_2_po_napruzi[NUMBER_GROUP_USTAVOK]; //Уставка МТЗO 2 ступені (по напрузі)
  unsigned int setpoint_mtzo_2_U[NUMBER_GROUP_USTAVOK];          //Уставка МТЗO 2 ступені (напруга пуску)[2; 150 В] крок 0,01В
  int type_mtzo3;                                                //Тип МТЗO3 (0 - Простий, 1 - Спрямований, 2 -  З пуском по напрузі)
  unsigned int setpoint_mtzo_3[NUMBER_GROUP_USTAVOK];            //Уставка МТЗO 3 ступені за струмом п.5.3.6 [0,5; 150 А] крок 0,01А
  unsigned int setpoint_mtzo_3_n_vpered[NUMBER_GROUP_USTAVOK];   //Уставка МТЗO 3 ступені (спрямований:вперед)
  unsigned int setpoint_mtzo_3_n_nazad[NUMBER_GROUP_USTAVOK];    //Уставка МТЗO 3 ступені (спрямований:назад)
  unsigned int setpoint_mtzo_3_angle[NUMBER_GROUP_USTAVOK];      //Уставка МТЗ третьої ступені (кут довороту) п.5.3.12
           int setpoint_mtzo_3_angle_cos[NUMBER_GROUP_USTAVOK];  //Уставка МТЗ третьої ступені (косинус кута довороту)
           int setpoint_mtzo_3_angle_sin[NUMBER_GROUP_USTAVOK];  //Уставка МТЗ третьої ступені (синус кута довороту)
  
  unsigned int setpoint_mtzo_3_po_napruzi[NUMBER_GROUP_USTAVOK]; //Уставка МТЗO 3 ступені (по напрузі)
  unsigned int setpoint_mtzo_3_U[NUMBER_GROUP_USTAVOK];          //Уставка МТЗO 3 ступені (напруга пуску)[2; 150 В] крок 0,01В
  int type_mtzo4;                                                //Тип МТЗO4 (0 - Простий, 1 - Спрямований, 2 -  З пуском по напрузі)
  unsigned int setpoint_mtzo_4[NUMBER_GROUP_USTAVOK];            //Уставка МТЗO 4 ступені за струмом п.5.3.6 [0,5; 150 А] крок 0,01А
  unsigned int setpoint_mtzo_4_n_vpered[NUMBER_GROUP_USTAVOK];   //Уставка МТЗO 4 ступені (спрямований:вперед)
  unsigned int setpoint_mtzo_4_n_nazad[NUMBER_GROUP_USTAVOK];    //Уставка МТЗO 4 ступені (спрямований:назад)
  unsigned int setpoint_mtzo_4_angle[NUMBER_GROUP_USTAVOK];      //Уставка МТЗ четвертої ступені (кут довороту) п.5.3.12
           int setpoint_mtzo_4_angle_cos[NUMBER_GROUP_USTAVOK];  //Уставка МТЗ четвертої ступені (косинус кута довороту)
           int setpoint_mtzo_4_angle_sin[NUMBER_GROUP_USTAVOK];  //Уставка МТЗ четвертої ступені (синус кута довороту)
  
  unsigned int setpoint_mtzo_4_po_napruzi[NUMBER_GROUP_USTAVOK]; //Уставка МТЗO 4 ступені (по напрузі)
  unsigned int setpoint_mtzo_4_U[NUMBER_GROUP_USTAVOK];          //Уставка МТЗO 4 ступені (напруга пуску)[2; 150 В] крок 0,01В

  int timeout_mtzo_1[NUMBER_GROUP_USTAVOK];                      //Витримка МТЗ 1 ступені п.5.3.7 [0.0; 32с] крок 0,01с                        
  int timeout_mtzo_1_n_vpered[NUMBER_GROUP_USTAVOK];             //Витримка МТЗ 1 ступені (спрямований:вперед)
  int timeout_mtzo_1_n_nazad[NUMBER_GROUP_USTAVOK];              //Витримка МТЗ 1 ступені (спрямований:назад)
  int timeout_mtzo_1_po_napruzi[NUMBER_GROUP_USTAVOK];           //Витримка МТЗ 1 ступені (по напрузі)
  int timeout_mtzo_2[NUMBER_GROUP_USTAVOK];                      //Витримка МТЗ 2 ступені п.5.3.7 [0.0; 300с] крок 0,01с
  int timeout_mtzo_2_pr[NUMBER_GROUP_USTAVOK];                   //Витримка прискорення МТЗ 2 ступені п.5.3.33 [0; 5] крок 0,01с
  int timeout_mtzo_2_n_vpered[NUMBER_GROUP_USTAVOK];             //Витримка МТЗ 2 ступені (спрямований:вперед)
  int timeout_mtzo_2_n_vpered_pr[NUMBER_GROUP_USTAVOK];          //Витримка прискорення МТЗ 2 ступені(спрямований:вперед)п.5.3.33[0; 5]крок 0,01с
  int timeout_mtzo_2_n_nazad[NUMBER_GROUP_USTAVOK];              //Витримка МТЗ 2 ступені (спрямований:назад)
  int timeout_mtzo_2_n_nazad_pr[NUMBER_GROUP_USTAVOK];           //Витримка прискорення МТЗ 2 ступені(спрямований:назад)п.5.3.33[0; 5]крок 0,01с
  int timeout_mtzo_2_po_napruzi[NUMBER_GROUP_USTAVOK];           //Витримка МТЗ 2 ступені (по напрузі)
  int timeout_mtzo_2_po_napruzi_pr[NUMBER_GROUP_USTAVOK];        //Витримка прискорення МТЗ 2 ступені (по напрузі)п.5.3.33[0; 5]крок 0,01с
  int timeout_mtzo_2_vvid_pr[NUMBER_GROUP_USTAVOK];              //Витримка вводу присорення МТЗ2  п.5.3.33[0,1; 5] крок 0,01с
  int timeout_mtzo_3[NUMBER_GROUP_USTAVOK];                      //Витримка МТЗ 3 ступені п.5.3.7 [0.0; 300с] крок 0,01с
  int timeout_mtzo_3_n_vpered[NUMBER_GROUP_USTAVOK];             //Витримка МТЗ 3 ступені (спрямований:вперед)
  int timeout_mtzo_3_n_nazad[NUMBER_GROUP_USTAVOK];              //Витримка МТЗ 3 ступені (спрямований:назад)
  int timeout_mtzo_3_po_napruzi[NUMBER_GROUP_USTAVOK];           //Витримка МТЗ 3 ступені (по напрузі)
  int timeout_mtzo_4[NUMBER_GROUP_USTAVOK];                      //Витримка МТЗ 4 ступені п.5.3.7 [0.0; 300с] крок 0,01с
  int timeout_mtzo_4_n_vpered[NUMBER_GROUP_USTAVOK];             //Витримка МТЗ 4 ступені (спрямований:вперед)
  int timeout_mtzo_4_n_nazad[NUMBER_GROUP_USTAVOK];              //Витримка МТЗ 4 ступені (спрямований:назад)
  int timeout_mtzo_4_po_napruzi[NUMBER_GROUP_USTAVOK];           //Витримка МТЗ 4 ступені (по напрузі)
  
  int type_mtzr1;                                                //Тип МТЗO3 (0 - Простий, 1 - Спрямований, 2 -  З пуском по напрузі)
  unsigned int setpoint_mtzr_1[NUMBER_GROUP_USTAVOK];            //Уставка МТЗP першої ступені п.5.4.3.6 [0,5; 150 А] крок 0,01А
  unsigned int setpoint_mtzr_1_n_vpered[NUMBER_GROUP_USTAVOK];   //Уставка МТЗP першої ступені (спрямований:вперед)
  unsigned int setpoint_mtzr_1_n_nazad[NUMBER_GROUP_USTAVOK];    //Уставка МТЗP першої ступені (спрямований:назад)
  unsigned int setpoint_mtzr_1_angle[NUMBER_GROUP_USTAVOK];      //Уставка МТЗ першої ступені (кут довороту)п.5.4.9
           int setpoint_mtzr_1_angle_cos[NUMBER_GROUP_USTAVOK];  //Уставка МТЗ першої ступені (косинус кута довороту)
           int setpoint_mtzr_1_angle_sin[NUMBER_GROUP_USTAVOK];  //Уставка МТЗ першої ступені (синус кута довороту)
  unsigned int setpoint_mtzr_1_po_napruzi[NUMBER_GROUP_USTAVOK]; //Уставка МТЗP першої ступені (по напрузі)
  unsigned int setpoint_mtzr_1_U[NUMBER_GROUP_USTAVOK];          //Уставка МТЗP першої ступені (напруга пуску)п.5.4.6 [2; 150 В] крок 0,01В
  int type_mtzr2;                                                //Тип МТЗO4 (0 - Простий, 1 - Спрямований, 2 -  З пуском по напрузі)
  unsigned int setpoint_mtzr_2[NUMBER_GROUP_USTAVOK];            //Уставка МТЗP другої ступені п.5.4.3.6 [0,5; 150 А] крок 0,01А
  unsigned int setpoint_mtzr_2_n_vpered[NUMBER_GROUP_USTAVOK];   //Уставка МТЗP другої ступені (спрямований:вперед)
  unsigned int setpoint_mtzr_2_n_nazad[NUMBER_GROUP_USTAVOK];    //Уставка МТЗP другої ступені (спрямований:назад)
  unsigned int setpoint_mtzr_2_angle[NUMBER_GROUP_USTAVOK];      //Уставка МТЗ другої ступені (кут довороту)п.5.4.9
           int setpoint_mtzr_2_angle_cos[NUMBER_GROUP_USTAVOK];  //Уставка МТЗ другої ступені (косинус кута довороту)
           int setpoint_mtzr_2_angle_sin[NUMBER_GROUP_USTAVOK];  //Уставка МТЗ другої ступені (синус кута довороту)
  unsigned int setpoint_mtzr_2_po_napruzi[NUMBER_GROUP_USTAVOK]; //Уставка МТЗP другої ступені (по напрузі)
  unsigned int setpoint_mtzr_2_U[NUMBER_GROUP_USTAVOK];          //Уставка МТЗP другої ступені (напруга пуску)п.5.4.6 [2; 150 В] крок 0,01В

  int timeout_mtzr_1[NUMBER_GROUP_USTAVOK];                      //Витримка МТЗP першої ступені п.5.4.4 [0.0; 32с] крок 0,01с    
  int timeout_mtzr_1_n_vpered[NUMBER_GROUP_USTAVOK];             //Витримка МТЗP першої ступені (спрямований:вперед)
  int timeout_mtzr_1_n_nazad[NUMBER_GROUP_USTAVOK];              //Витримка МТЗP першої ступені (спрямований:назад)
  int timeout_mtzr_1_po_napruzi[NUMBER_GROUP_USTAVOK];           //Витримка МТЗP першої ступені (по напрузі)
  int timeout_mtzr_2[NUMBER_GROUP_USTAVOK];                      //Витримка МТЗP другої ступені п.5.4.4 [0.0; 300с] крок 0,01с
  int timeout_mtzr_2_n_vpered[NUMBER_GROUP_USTAVOK];             //Витримка МТЗP другої ступені (спрямований:вперед)
  int timeout_mtzr_2_n_nazad[NUMBER_GROUP_USTAVOK];              //Витримка МТЗP другої ступені (спрямований:назад)
  int timeout_mtzr_2_po_napruzi[NUMBER_GROUP_USTAVOK];           //Витримка МТЗP другоїступені (по напрузі)
  
  
  
  
  //ЗДЗ
  int32_t timeout_zdz[NUMBER_GROUP_USTAVOK];                //Витримка ЗДЗ
  unsigned int control_zdz;                                 //Поле для управління ЗДЗ
#if (                                   \
     (MODYFIKACIA_VERSII_PZ == 0) ||    \
     (MODYFIKACIA_VERSII_PZ == 3)       \
    )   
   int32_t zdz_ovd_porig;                                   //Поріг спрацювання ОВД
#endif
  int32_t ctrl_zdz_type;                                    //Тип контролю ЗДЗ
                                                            /*
                                                            0 - Без контролю
                                                            1 - Контроль по I
                                                            2 - Контроль по U
                                                            3 - Контроль по I або U
                                                            4 - Контроль по I і U
                                                            */
  //"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
  //~~~~~~~~~~~  OBSOLETE	OBSOLETE obsolete This for reference only part                                      ~~~~~~~
  //___________________________________________________________________________________________________________________
  //```````````````````````````````````````````````````````````````````````````````````````````````````````````````````
  //ЗЗ
  unsigned int setpoint_zz_3I0[NUMBER_GROUP_USTAVOK];       //уставка ЗЗ/3I0
  unsigned int setpoint_zz_3U0[NUMBER_GROUP_USTAVOK];       //уставка ЗЗ/3U0

  int timeout_zz_3I0[NUMBER_GROUP_USTAVOK];                 //Витримка ЗЗ/3I0
  int timeout_zz_3U0[NUMBER_GROUP_USTAVOK];                 //Витримка ЗЗ/3I0
  int timeout_nzz[NUMBER_GROUP_USTAVOK];                    //Витримка НЗЗ

   unsigned int control_zz;                                 //Поле для управління ЗЗ

  //ТЗНП
  unsigned int setpoint_tznp_1_3I0_vpered[NUMBER_GROUP_USTAVOK];//Уставка ТЗНП 3I0 першої ступені (спрямований:вперед)
  unsigned int setpoint_tznp_1_3U0_vpered[NUMBER_GROUP_USTAVOK];//Уставка ТЗНП 3U0 першої ступені  (спрямований:вперед)
  unsigned int setpoint_tznp_1_3I0_nazad[NUMBER_GROUP_USTAVOK]; //Уставка ТЗНП 3I0 першої ступені (спрямований:назад)
  unsigned int setpoint_tznp_1_3U0_nazad[NUMBER_GROUP_USTAVOK]; //Уставка ТЗНП 3U0 першої ступені  (спрямований:назад)
  unsigned int setpoint_tznp_1_angle[NUMBER_GROUP_USTAVOK];     //Уставка ТЗНП першої ступені (кут довороту)
           int setpoint_tznp_1_angle_cos[NUMBER_GROUP_USTAVOK]; //Уставка ТЗНП першої ступені (косинус кута довороту)
           int setpoint_tznp_1_angle_sin[NUMBER_GROUP_USTAVOK]; //Уставка ТЗНП першої ступені (синус кута довороту)
  unsigned int setpoint_tznp_2_3I0_vpered[NUMBER_GROUP_USTAVOK];//Уставка ТЗНП 3I0 другої ступені (спрямований:вперед)
  unsigned int setpoint_tznp_2_3U0_vpered[NUMBER_GROUP_USTAVOK];//Уставка ТЗНП 3U0 другої ступені  (спрямований:вперед)
  unsigned int setpoint_tznp_2_3I0_nazad[NUMBER_GROUP_USTAVOK]; //Уставка ТЗНП 3I0 другої ступені (спрямований:назад)
  unsigned int setpoint_tznp_2_3U0_nazad[NUMBER_GROUP_USTAVOK]; //Уставка ТЗНП 3U0 другої ступені  (спрямований:назад)
  unsigned int setpoint_tznp_2_angle[NUMBER_GROUP_USTAVOK];     //Уставка ТЗНП другої ступені (кут довороту)
           int setpoint_tznp_2_angle_cos[NUMBER_GROUP_USTAVOK]; //Уставка ТЗНП другої ступені (косинус кута довороту)
           int setpoint_tznp_2_angle_sin[NUMBER_GROUP_USTAVOK]; //Уставка ТЗНП другої ступені (синус кута довороту)
  unsigned int setpoint_tznp_3_3I0_vpered[NUMBER_GROUP_USTAVOK];//Уставка ТЗНП 3I0 третьої ступені (спрямований:вперед)
  unsigned int setpoint_tznp_3_3U0_vpered[NUMBER_GROUP_USTAVOK];//Уставка ТЗНП 3U0 третьої ступені  (спрямований:вперед)
  unsigned int setpoint_tznp_3_3I0_nazad[NUMBER_GROUP_USTAVOK]; //Уставка ТЗНП 3I0 третьої ступені (спрямований:назад)
  unsigned int setpoint_tznp_3_3U0_nazad[NUMBER_GROUP_USTAVOK]; //Уставка ТЗНП 3U0 третьої ступені  (спрямований:назад)
  unsigned int setpoint_tznp_3_angle[NUMBER_GROUP_USTAVOK];     //Уставка ТЗНП першої третьої (кут довороту)
           int setpoint_tznp_3_angle_cos[NUMBER_GROUP_USTAVOK]; //Уставка ТЗНП першої третьої (косинус кута довороту)
           int setpoint_tznp_3_angle_sin[NUMBER_GROUP_USTAVOK]; //Уставка ТЗНП першої третьої (синус кута довороту)

  int timeout_tznp_1_vpered[NUMBER_GROUP_USTAVOK];              //Витримка ТЗНП першої ступені (спрямований:вперед)
  int timeout_tznp_1_nazad[NUMBER_GROUP_USTAVOK];               //Витримка ТЗНП першої ступені (спрямований:назад)
  int timeout_tznp_2_vpered[NUMBER_GROUP_USTAVOK];              //Витримка ТЗНП першої ступені (спрямований:вперед)
  int timeout_tznp_2_nazad[NUMBER_GROUP_USTAVOK];               //Витримка ТЗНП першої ступені (спрямований:назад)
  int timeout_tznp_3_vpered[NUMBER_GROUP_USTAVOK];              //Витримка ТЗНП першої ступені (спрямований:вперед)
  int timeout_tznp_3_nazad[NUMBER_GROUP_USTAVOK];               //Витримка ТЗНП першої ступені (спрямований:назад)

   unsigned int control_tznp;                                   //Поле для управління ТЗНП
  
  //ЗОП(КОФ)
  unsigned int setpoint_zop[NUMBER_GROUP_USTAVOK];          //уставка ЗОП(КОФ)
  int timeout_zop[NUMBER_GROUP_USTAVOK];                    //Витримка  ЗОП(КОФ)
  unsigned int control_zop;                                 //Поле для управління ЗОП(КОФ)

  //`````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
  //~~~~~~~~~~              End of obsolete                                                                            ~~~~~~~~~~~~~~
  //_________________________________________________________________________________________________________________________________
  //.................................................................................................................................
  //АПВ
  int timeout_apv_1[NUMBER_GROUP_USTAVOK];                    //Витримка 1 Циклу АПВ п.5.8.18 [0.1; 200с] крок 0,01с 
  int timeout_apv_2[NUMBER_GROUP_USTAVOK];                    //Витримка 2 Циклу АПВ п.5.8.19 [0.1; 200с] крок 0,01с
  int timeout_apv_3[NUMBER_GROUP_USTAVOK];                    //Витримка 3 Циклу АПВ п.5.8.20 [0.1; 200с] крок 0,01с
  int timeout_apv_4[NUMBER_GROUP_USTAVOK];                    //Витримка 4 Циклу АПВ п.5.8.21 [0.1; 200с] крок 0,01с
  int timeout_apv_block_vid_apv1[NUMBER_GROUP_USTAVOK];       //Блокування АПВ від роботи АПВ1 п.5.8.26 [0.2; 200с] крок 0,01с
  int timeout_apv_block_vid_apv2[NUMBER_GROUP_USTAVOK];       //Блокування АПВ від роботи АПВ2 п.5.8.28 [0.2; 200с] крок 0,01с
  int timeout_apv_block_vid_apv3[NUMBER_GROUP_USTAVOK];       //Блокування АПВ від роботи АПВ3 п.5.8.30 [0.2; 200с] крок 0,01с
  int timeout_apv_block_vid_apv4[NUMBER_GROUP_USTAVOK];       //Блокування АПВ від роботи АПВ4 п.5.8.32 [0.2; 200с] крок 0,01с
  int timeout_apv_block_vid_VV[NUMBER_GROUP_USTAVOK];         //Витримка блокування АПВ в момекнт включення вимикача п.5.8.18 [0.2; 200с] крок 0,01с
  unsigned int control_apv;             //Поле для управління АПВ
  
  //АЧР-ЧАПВ
  unsigned int setpoint_achr_chapv_uf[NUMBER_GROUP_USTAVOK]; //уставка АЧР ЧАПВ UF1 п.5.9.12 [14; 140 В] крок 0,01
  unsigned int setpoint_achr1_f_rab[NUMBER_GROUP_USTAVOK];    //уставка FРаб АЧР1 частоти F     п.5.9.5 [45; 55 Гц] крок 0,01
  unsigned int setpoint_chapv1_f_rab[NUMBER_GROUP_USTAVOK];   //уставка FРаб ЧАПВ1 частотм F   п.5.9.6 [45; 55 Гц] крок 0,01
  unsigned int setpoint_achr2_f_rab[NUMBER_GROUP_USTAVOK];    //уставка FРаб АЧР2 частотм F     п.5.9.5 [45; 55 Гц] крок 0,01
  unsigned int setpoint_chapv2_f_rab[NUMBER_GROUP_USTAVOK];   //уставка FРаб ЧАПВ2 частотм F   п.5.9.6 [45; 55 Гц] крок 0,01

  int timeout_achr_1[NUMBER_GROUP_USTAVOK];                   //Витримка Циклу АЧР1   п.5.9.7 [0; 32с] крок 0,01с
  int timeout_chapv_1[NUMBER_GROUP_USTAVOK];                  //Витримка Циклу ЧАПВ1  п.5.9.9 [0.1; 32с] крок 0,01с
  int timeout_achr_2[NUMBER_GROUP_USTAVOK];                   //Витримка Циклу АЧР2   п.5.9.10 [0; 200с] крок 0,01с
  int timeout_chapv_2[NUMBER_GROUP_USTAVOK];                  //Витримка Циклу ЧАПВ2   п.5.9.10 [0.1; 200с] крок 0,01с

  unsigned int control_achr_chapv;      //Поле для управління АЧР-ЧАПВ
  
  //УРОВ
  unsigned int setpoint_urov[NUMBER_GROUP_USTAVOK];         //уставка УРОВ   п.5.7.4 [0,25; 155 А] крок 0,01А
  int timeout_urov_1[NUMBER_GROUP_USTAVOK];                 //Витримка УРОВ першої ступені  п.5.7.5 [0; 32с] крок 0,01с
  int timeout_urov_2[NUMBER_GROUP_USTAVOK];                 //Витримка УРОВ другої ступені  п.5.7.5 [0; 32с] крок 0,01с
  uint64_t control_urov;                                    //Поле для управління УРОВ

  //Umin
  unsigned int setpoint_Umin1[NUMBER_GROUP_USTAVOK];        //уставка Umin1  п.5.5.7 [5; 110 В] крок 0,01
  unsigned int setpoint_Umin1_Iblk[NUMBER_GROUP_USTAVOK];   //уставка блокування по струму Umin1  п.5.5.8 [0,25; 5 А] крок 0,01А
  unsigned int setpoint_Umin2[NUMBER_GROUP_USTAVOK];        //уставка Umin2  Umin2 п.5.5.7 [5; 110 В] крок 0,01
  unsigned int setpoint_Umin2_Iblk[NUMBER_GROUP_USTAVOK];   //уставка блокування по струму Umin2  Umin2 п.5.5.8 [0,25; 5 А] крок 0,01А
  int timeout_Umin1[NUMBER_GROUP_USTAVOK];                    //Витримка  Umin1  п.5.5.9 [0.1; 32с] крок 0,01с   
  int timeout_Umin2[NUMBER_GROUP_USTAVOK];                    //Витримка  Umin2 п.5.5.9 [0.1; 32с] крок 0,01с 
  unsigned int control_Umin;                                 //Поле для управління Umin
  
  //Umax
  unsigned int setpoint_Umax1[NUMBER_GROUP_USTAVOK];        //уставка Umax1  п.5.6.5 [23; 140 В] крок 0,01 
  unsigned int setpoint_Umax2[NUMBER_GROUP_USTAVOK];        //уставка Umax2  п.5.6.5 [23; 140 В] крок 0,01
  uint32_t setpoint_kp_Umax[NUMBER_GROUP_USTAVOK];          //Уставка коефіцієнт повернення ЗНмакс  п.5.6.8 [0.5; 0.96 ] крок 0,01
  int timeout_Umax1[NUMBER_GROUP_USTAVOK];                  //Витримка  Umax1   Umax1 п.5.6.6 [0; 600с] крок 0,01с 
  int timeout_Umax2[NUMBER_GROUP_USTAVOK];                  //Витримка  Umax2   Umax2 п.5.6.6 [0; 600с] крок 0,01с 
  unsigned int control_Umax;                                //Поле для управління Umax
  
  //Універсальний захист
  int32_t setpoint_UP[NUMBER_UP][1][NUMBER_GROUP_USTAVOK];      //Уставка для всіх ступенів
  uint32_t setpoint_UP_KP[NUMBER_UP][1][NUMBER_GROUP_USTAVOK];  //Уставка для "Коефіцієнта повернення" всіх ступенів
  int32_t timeout_UP[NUMBER_UP][1][NUMBER_GROUP_USTAVOK];       //Витримка для Універсального захисту
  uint32_t control_UP;                                          //Поля для управління
  int32_t ctrl_UP_input[NUMBER_UP];                             //Вибір входу Універсального захисту

  unsigned int Tbp;                      //Коефіцієнт трансформації для трансформатора Ip
  unsigned int Tmn;                      //Коефіцієнт трансформації для трансформатора струм Io
  unsigned int TVoltage;                //Коефіцієнт трансформації для трансформатора напруг
  unsigned int control_transformator;   //налаштування для меню "Трансформатор"
  
  unsigned int password1;                                       //Пароль для редагування з меню
  unsigned int password2;                                       //Пароль для очистки лічилчників енегії і ресурсу вимикача
  unsigned int password3;                                       //Пароль для переходу у режим програмування
  unsigned int timeout_deactivation_password_interface_USB;     //Час деактивації паролю для редагування з інтерфейсу USB
  unsigned int password_interface_USB;                          //Пароль для редагування з інтерфейсу USB
  unsigned int timeout_deactivation_password_interface_RS485;   //Час деактивації паролю для редагування з інтерфейсу RS485
  unsigned int password_interface_RS485;                        //Пароль для редагування з інтерфейсу RS485
  
  unsigned int timeout_idle_new_settings;

  //Вимикач
  unsigned int setpoint_Inom;                   //Номінальний струм вимикача
  unsigned int setpoint_r_kom_st_Inom;          //Ресурс комунікаційної стійкості при номінальному струмі вимикача
  unsigned int setpoint_Inom_vymk;              //Номінальний струм вимкнення вимикача
  unsigned int setpoint_r_kom_st_Inom_vymk;     //Ресурс комунікаційної стійкості при номінальному струмі вимкнення вимикача
  unsigned int setpoint_pochatkovyj_resurs;     //Початковий ресурс вимикача
  unsigned int setpoint_krytychnyj_resurs;      //Критичний ресурс вимикача
  unsigned int setpoint_pochatkova_k_vymk;      //Початкова кількість вимкнень
  //-Obs
  int timeout_swch_on;                          //Витримка T вкл.
  int timeout_swch_off;                         //Витримка T відкл.
  int timeout_swch_udl_blk_on;                  //Витримка T "удлинение сигнала блокировки включения"
  int timeout_pryvoda_VV;                       //Витримка T "Привіода ВВ"
  unsigned int control_switch;                  //Поле для управління вимикачем
  //--end OBSOLETE
    //Вимикач
  int timeout_swch_on_[NUMBER_OFF_ON];                          //Витримка T вкл.
  int timeout_swch_off_[NUMBER_OFF_ON];                         //Витримка T відкл.
  int timeout_swch_udl_blk_on_[NUMBER_OFF_ON];                  //Витримка T "удлинение сигнала блокировки включения"
  int timeout_pryvoda_VV_[NUMBER_OFF_ON];                       //Витримка T "Привіода ВВ"
  unsigned int control_switch_[NUMBER_OFF_ON];                  //Поле для управління вимикачем
  //Визначення місця пошкодження
  unsigned int lines[2];                        //Кількість ділянок
  unsigned int dovgyna[2][MAX_NUMBER_LINES_VMP];//Довжина ліній
  unsigned int opir[2][MAX_NUMBER_LINES_VMP];   //Питомий опір ліній
  unsigned int control_vmp;                     //Поле для управління ВМП
  
  //Аналоговий реєстратор
  unsigned int prefault_number_periods; //Час доаварійного масиву (кількість періодів промислової частоти)
  unsigned int postfault_number_periods;//Час післяарійного масиву (кількість періодів промислової частоти)
  unsigned int control_ar;              //Поля для управління аналоговим реєстратором

  //Комунікація
  unsigned int name_of_cell[MAX_CHAR_IN_NAME_OF_CELL];//І'мя ячейки
  unsigned short int user_register[(M_ADDRESS_LAST_USER_REGISTER_DATA - M_ADDRESS_FIRST_USER_REGISTER_DATA) + 1]; //Регістри користувача
  unsigned int address;                                //Адреса
  int speed_RS485;                                    //швидкість обміну
                                                        // 0 - 9600
                                                        // 1 - 14400
                                                        // 2 - 19200
                                                        // 3 - 28800
                                                        // 4 - 38400
                                                        // 5 - 57600
                                                        // 6 - 115200
  int pare_bit_RS485;                                 //паритет
                                                        // 0 - NONE
                                                        // 1 - ODD
                                                        // 2 - EVEN
  int number_stop_bit_RS485;                          //кількість стоп-біт
                                                        // 0 - 1 stop-bit
                                                        // 1 - 2 stop-bits
  unsigned int time_out_1_RS485;                        //time-out наступного символу = X/10 символу
  
  int language;                                         //мова меню  0= змінна мов не підтримується; 1=RU; 2=UA; 3=EN; 4=KZ; 5=др.
  
  unsigned int control_extra_settings_1;                //Поле для додаткових налаштувань

  int32_t time_zone;                                    //Часова зона
  uint32_t dst;                                         //Перехід на літній час
  uint32_t dst_on_rule;                                 //Правило переходу на Літній час
  uint32_t dst_off_rule;                                //Правило переходу на стандартний час
  
  
  time_t time_setpoints;                                    //Час останніх змін уставок-витримок-управління
  unsigned char source_setpoints;                           //0 - мінімальні параметри
                                                            //1 - клавіатура
                                                            //2 - USB
                                                            //3 - RS-485
  
  time_t time_ranguvannja;                                  //Час останніх змін ранжування
  unsigned char source_ranguvannja;                         //0 - мінімальні параметри
                                                            //1 - клавіатура
                                                            //2 - USB
                                                            //3 - RS-485
} __SETTINGS;

typedef struct _info_vymk
{
  time_t time_dat;
  int32_t time_ms;
} __info_vymk;


typedef struct
{
  //Стан обміну
  int state_execution;        //-1 - драйвер готовий до початку нових транзакцій
                              // 0 - відбувається обмін
                              // 1 - обмін завершений без помилок
                              // 2 - обмін завершений з помилками
  
  
  //Ідентифікатор пристрою, з яким ведетьсяобмін
  int device_id;              //-1 - пристрій не визначений
                              // EEPROM_ADDRESS - EEPROM
                              // RTC_ADDRESS - RTC
  //Код операції
  int action;                 //-1 - не визначений
                              // 0 - запис адреси для подальшого зчитування
                              // 1 - зчитування
                              // 2 - запис адреси і запис даних
  

  //Внутрішня адреса по якій буде іти звертання
  unsigned int internal_address;

  //Кількість байт для читання/запису (корисних)
  unsigned int number_bytes;
  
  //Вказівник на буфер (корисний)
  uint8_t *point_buffer;

} __DRIVER_I2C;

typedef struct
{
  unsigned int next_address;
  unsigned int saving_execution;
  unsigned int number_records;
} __INFO_REJESTRATOR;

typedef struct
{
  int first_number;
  int last_number;
} __INFO_AR_REJESTRATOR;

typedef struct _FIL_FATFS
{
  unsigned int opened;
  FIL fil;
  
} __FIL_FATFS;

typedef struct
{
  unsigned int state_execution;     //стан виконуваної заразоперації
  
  unsigned int code_operation;      //Код виконуваної операції

} __DRIVER_SPI_DF;

typedef struct
{
  unsigned char label_start_record;
  time_t time_dat; 
  int32_t time_ms;
  unsigned int TCurrent_o;
  unsigned int TCurrent_r;
  unsigned int TVoltage;
  unsigned int prefault_number_periods;
  unsigned char name_of_cell[MAX_CHAR_IN_NAME_OF_CELL];
  unsigned int cur_active_sources[N_BIG];
} __HEADER_AR;

typedef enum __STATE_READING_ADCs {
STATE_READING_ADCs_NONE = 0,
STATE_READING_WRITE,
STATE_READING_WRITE_READ,
STATE_READING_READ
} STATE_READING_ADCs;

typedef enum _full_ort_index __full_ort_index;
typedef enum _index_energy __index_energy;

typedef struct
{
  uint32_t tick;
  unsigned int value;

} EXTENDED_OUTPUT_DATA;

typedef struct
{
  uint32_t tick;
  int value;
} EXTENDED_SAMPLE;

typedef struct
{
  unsigned int time_p;
  int data_p[NUMBER_ANALOG_CANALES];
  float frequency_p;

  unsigned int time_c;
  int data_c[NUMBER_ANALOG_CANALES];
  float frequency_c;
} ROZSHYRENA_VYBORKA;

typedef struct
{
  unsigned int time_stemp;
  unsigned int DATA_fix;
  int data [AR_NUMBER_ANALOG_CANALES];
  unsigned int active_functions[N_BIG];
  int state_ar_record;
  
} DATA_FOR_OSCYLOGRAPH;


typedef struct 
{
  unsigned int x1;
  int y1;

  unsigned int x2;
  int y2;

} VYBORKA_XY;

typedef struct
{
  unsigned int Umn_x1;
  int Umn_y1;
  unsigned int Umn_x2;
  int Umn_y2;

  unsigned int Ubp_x1;
  int Ubp_y1;
  unsigned int Ubp_x2;
  int Ubp_y2;
} POPEREDNJY_PERECHID;

//typedef struct
//{
//  unsigned int present;
//  int start_index;
//  int stop_index;
//  int number_per_index;
//  int real_number;
//} EL_FILTER_STRUCT;

typedef enum _getting_data
{
  GET_DATA_FOR_EDITING = 0,
  GET_DATA_IMMEDITATE
} __getting_data;

typedef enum _setting_data
{
  SET_DATA_INTO_EDIT_TABLE = 0,
  SET_DATA_IMMEDITATE
} __settings_data;

typedef struct _vd
{
           int sign;
  unsigned int begin;
  unsigned int comma;
  unsigned int end;
  unsigned int u_begin;
  unsigned int u_end;
  const unsigned char *p_unit;
} __vd;

typedef struct _ctrl_info
{
  const uint8_t *information;
  unsigned int cursor_x;
} __ctrl_info;

typedef enum _index_I_U
{
  INDEX_I = 0,
  INDEX_U,
  
  _NUMBER_FOR_I_U
} __index_I_U;

typedef enum _id_input_output
{
  ID_INPUT = 0,
  ID_OUTPUT,
  ID_LED,
  ID_DF,
  ID_DB,
  ID_DT,
  ID_AND,
  ID_OR,
  ID_XOR,
  ID_NOT,
  ID_TF,
  ID_OFF_ON,

#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
  
  ID_IN_GOOSE,
  ID_IN_MMS,
  ID_OUT_LAN,
#endif
  
  _MAX_ID_INPUT_OUPUT
  
} __id_input_output;

typedef enum _sector_dz
{
  SECTOR_DZ_NONE = 0,
  SECTOR_DZ_FORWARD,
  SECTOR_DZ_BACKWARD
  
} __sector_dz;

typedef struct _meas_to_d_meas
{
  void const * const arr;
  size_t const ind;
  
} __meas_to_d_meas;


#endif

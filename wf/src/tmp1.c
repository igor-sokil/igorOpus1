#define NUMBER_UP 8
long ctrl_UP_input[NUMBER_UP ] = {1,2,3,4, 0,0,0,0};
long control_UP = 0xf;
enum _index_ml_ctrl_UP
{
  _CTR_UP_PART_I = 0, 
  
  CTR_UP_CTRL_INPUT = _CTR_UP_PART_I,
  
  _CTR_UP_PART_II,
  CTR_UP_STATE_BIT = _CTR_UP_PART_II,
  CTR_UP_OR_AND_BIT,
  CTR_UP_MORE_LESS_BIT,
  
  _CTR_UP_NEXT_BIT,
  MAX_ROW_FOR_CONTROL_UP = _CTR_UP_NEXT_BIT
};
void make_ekran_control_UP()
{
  

  //__SETTINGS *point = (current_ekran.edition == 0) ? &current_settings : &edition_settings;
  
  //__ctrl_info ctrl_info[NUMBER_UP*MAX_ROW_FOR_CONTROL_UP];
  for (long i = 0; i < (NUMBER_UP*MAX_ROW_FOR_CONTROL_UP); i++)
  {
    switch (i)
    {
    case 0:
    case 4:
    case 8:
    case 12:
    case 16:
    case 20:
    case 24:
    case 28:
      {
        long index = ctrl_UP_input[i / MAX_ROW_FOR_CONTROL_UP];

        break;
      }
    case 1:
    case 5:
    case 9:
    case 13:
    case 17:
    case 21:
    case 25:
    case 29:
      {
        long index = control_UP >> ((i / MAX_ROW_FOR_CONTROL_UP)*(_CTR_UP_NEXT_BIT - (_CTR_UP_PART_II - _CTR_UP_PART_I) - _CTR_UP_PART_I) + CTR_UP_STATE_BIT - (_CTR_UP_PART_II - _CTR_UP_PART_I));
        char a__CTR_UP_PART_II__CTR_UP_PART_I = (_CTR_UP_PART_II - _CTR_UP_PART_I);
        char b = (i / MAX_ROW_FOR_CONTROL_UP);
        char c = (_CTR_UP_NEXT_BIT - (_CTR_UP_PART_II - _CTR_UP_PART_I) - _CTR_UP_PART_I);
        char e = b*c + CTR_UP_STATE_BIT - a__CTR_UP_PART_II__CTR_UP_PART_I;

        long index_n = control_UP >> e;

        break;
      }
    case 2:
    case 6:
    case 10:
    case 14:
    case 18:
    case 22:
    case 26:
    case 30:
      {
        long index = (control_UP >> ((i / MAX_ROW_FOR_CONTROL_UP)*(_CTR_UP_NEXT_BIT - (_CTR_UP_PART_II - _CTR_UP_PART_I) - _CTR_UP_PART_I) + CTR_UP_OR_AND_BIT - (_CTR_UP_PART_II - _CTR_UP_PART_I))) & 0x1;

        break;
      }
    case 3:
    case 7:
    case 11:
    case 15:
    case 19:
    case 23:
    case 27:
    case 31:
      {
        long index = (control_UP >> ((i / MAX_ROW_FOR_CONTROL_UP)*(_CTR_UP_NEXT_BIT - (_CTR_UP_PART_II - _CTR_UP_PART_I) - _CTR_UP_PART_I) + CTR_UP_MORE_LESS_BIT - (_CTR_UP_PART_II - _CTR_UP_PART_I))) & 0x1;

        break;
      }
    default:
      {
        //Теоретично цього ніколи не мало б бути
        //total_error_sw_fixed(90);
        
      }
    }
  }
}
int main()
{
    make_ekran_control_UP();
    printf("Hello World");

    return 0;
}

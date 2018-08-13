#include "cards.h"
#include <stdio.h>

int main(void) {
  card_t c;
  c.value = 14;
  c.suit = 3;
  assert_card_valid(c);
  //test value asserts
  c.value = 13; //-1, 0, 1, 2, 3, 13, 14, 15, 100
  assert_card_valid(c);
  //test suit asserts
  c.suit = 1; //-1, 0, 1, 3, 4, 5, 101
  assert_card_valid(c);

  hand_ranking_t r = 0;//0, 1, 7 , 8, -1, 9, 1000
  printf("%s\n", ranking_to_string(r));
  
  //c.value = 102;//1,2,8,9,10,11,12,13,14,15
  //printf("%c\n", value_letter(c));

  //c.suit = 99; //-1, 0, 1, 3, 4, 5, 99
  //printf("%c\n", suit_letter(c));

  //c.value = 16; //14,10,13,-1,11,16
  //c.suit = -1; // 0,2,3,5,-1
  // print_card(c);

  //card_t temp = card_from_letters('A','h');//4s, Ah, 0d, Kc, 10,20,2s, 45, 6d, 1d
  //print_card(temp);

  //card_t c = card_from_num(0);//-1,0,5,51, 52,
  //print_card(c);

}

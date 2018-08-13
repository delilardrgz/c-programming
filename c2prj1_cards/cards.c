#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"

typedef struct deck_tag{
  unsigned card_num;
  card_t card;
} deck_t;


void assert_card_valid(card_t c) {
  //print the value of c
  // printf("The value of c: %d\n", c.value);
  //print the suit of c
  //printf("The suit of c: %d\n", c.suit);
  assert(c.value >= 2);
  assert(c.value <= 14);
  assert(c.suit >= 0);
  assert(c.suit <= 4);
}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r){
  case 0:
    return "STRAIGHT FLUSH";
    break;
  case 1:
    return "FOUR OF A KIND";
    break;
  case 2:
    return "FULL HOUSE";
    break;
  case 3:
    return "FLUSH";
    break;
  case 4:
    return "STRAIGHT";
    break;
  case 5:
    return "THREE OF A KIND";
    break;
  case 6:
    return "TWO PAIR";
    break;
  case 7:
    return "PAIR";
    break;
  case 8:
    return "NOTHING";
    break;
  default:
    return "invalid rank";
    exit(2);
  }
  return "";
}

char value_letter(card_t c) {
  if ((c.value >= 2) && (c.value <= 9)){
   return '0' + c.value;
  }
  else{
    switch(c.value){
    case 10:
      return '0';
      break;
    case 11:
      return 'J';
      break;
    case 12:
      return 'Q';
      break;
    case 13:
      return 'K';
      break;
    case 14:
      return 'A';
      break;
    default:
      printf("invalid value\n");
      exit(2);
    }
  }
  return 'x';
}


char suit_letter(card_t c) {
  switch (c.suit){
  case 0:
    return 's';
    break;
  case 1:
    return 'h';
    break;
  case 2:
    return 'd';
    break;
  case 3:
    return 'c';
    break;
  default:
    printf("invalid suit\n");
    exit(2);
  }
  return 'x';
}

void print_card(card_t c) {
  printf("%c", value_letter(c));
  printf("%c", suit_letter(c));
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  if ((value_let >= 50) && (value_let <= 57)){
    temp.value = value_let - '0';
  }
  else{
    switch (value_let){
    case '0':
      temp.value = 10;
      break;
    case 'J':
      temp.value = 11;
      break;
    case 'Q':
      temp.value = 12;
      break;
    case 'K':
      temp.value = 13;
      break;
    case 'A':
      temp.value = 14;
      break;
      /*default:
      printf("invalid letter value\n");
      exit(2);*/
    }
  }

  switch (suit_let){
  case 's':
    temp.suit = 0;
    break;
  case 'h':
    temp.suit = 1;
    break;
  case 'd':
    temp.suit = 2;
    break;
  case 'c':
    temp.suit = 3;
    break;
    /*default:
    printf("invalid suit value");
    exit(2);*/
  }
  assert_card_valid(temp);
  return temp;
}

card_t card_from_num(unsigned c) {
  
  deck_t deck[52];
  int index;
  //card_t card;
  for (index = 0; index < 52; index++){
    //printf("index: %d\n", index);
    deck[index].card_num = index;
    if (deck[index].card_num % 4 == 0){
      deck[index].card.suit = SPADES;
    }
    else if(deck[index].card_num % 4 == 1){
      deck[index].card.suit = HEARTS;
    }
    else if (deck[index].card_num % 4 == 2){
      deck[index].card.suit = DIAMONDS;
    }
    else{
      deck[index].card.suit = CLUBS;
    }

    
    if (deck[index].card_num % 13 == 0){
      deck[index].card.value = 2;
    }
    else if (deck[index].card_num % 13 ==1){
      deck[index].card.value = 3;
    }
    else if (deck[index].card_num %13 == 2){
      deck[index].card.value= 4;
    }
    else if (deck[index].card_num % 13 == 3){
      deck[index].card.value = 5;
    }
    else if(deck[index].card_num %13 == 4){
      deck[index].card.value=6;
    }
    else if(deck[index].card_num % 13 == 5){
      deck[index].card.value = 7;
    }
    else if(deck[index].card_num % 13 == 6){
      deck[index].card.value = 8;
    }
    else if(deck[index].card_num % 13 == 7){
      deck[index].card.value = 9;
    }
    else if(deck[index].card_num % 13 ==8){
      deck[index].card.value = 10;
    }
    else if(deck[index].card_num % 13 == 9){
      deck[index].card.value = VALUE_JACK;
    }
    else if(deck[index].card_num % 13 == 10){
      deck[index].card.value = VALUE_QUEEN;
    }
    else if(deck[index].card_num % 13 == 11){
      deck[index].card.value = VALUE_KING;
    }
    else{
      deck[index].card.value = VALUE_ACE;
    }
    //printf("deck[%d]: suit = %d, value = %d\n", deck[index].card_num, deck[index].card.suit, deck[index].card.value);
  }
  
  /*for (int suit = SPADES; suit < NUM_SUITS; suit++){
      deck[index].card.suit = suit;
      printf("suit variable = %d\n", suit);
      for (int val = 2; val <= 14; val++){
	printf("value variable = %d\n", val);
        deck[index].card.value = val;
	//printf("deck[%d]: suit = %d, value = %d\n", deck[index].card_num, deck[index].card.suit, deck[index].card.value);
	//exit(0);
      }
      }*/
 
  //printf("deck[%d]: suit = %d, value = %d\n", deck[c].card_num, deck[c].card.suit, deck[c].card.value);
  
  assert_card_valid(deck[c].card);
  return deck[c].card;
}

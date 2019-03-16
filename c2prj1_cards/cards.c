#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c)
{
  assert (c.value >= 2 && c.value <= VALUE_ACE);
  assert (c.suit >= SPADES && c.suit <= CLUBS);
}

const char * ranking_to_string(hand_ranking_t r)
{ 
  switch (r)
    {
    case STRAIGHT_FLUSH: return "STRAIGHT_FLUSH"; break;
    case FOUR_OF_A_KIND: return "FOUR_OF_A_KIND"; break;
    case FULL_HOUSE: return "FULL_HOUSE"; break;
    case FLUSH: return "FLUSH"; break;
    case STRAIGHT: return "STRAIGHT"; break;
    case THREE_OF_A_KIND: return "THREE_OF_A_KIND"; break;
    case TWO_PAIR: return "TWO_PAIR"; break;
    case PAIR: return "PAIR"; break;
    case NOTHING: return "NOTHING"; break;
    default: return "Invalid";
    }
}

char value_letter(card_t c)
{
  char ans = '0';
  if (c.value >= 2 && c.value <= 9)
    {
      ans = '0' + c.value;
    }
  else if (c.value == 10)
    {
      ans = '0';
    }
  else if (c.value == VALUE_JACK)
    {
      ans = 'J';
    }
  else if (c.value == VALUE_QUEEN)
    {
      ans = 'Q';
    }
  else if (c.value == VALUE_KING)
    {
      ans = 'K';
    }
  else if (c.value == VALUE_ACE)
    {
      ans = 'A';
    }

  return ans;
  
}


char suit_letter(card_t c)
{  char abc = '0';
   switch (c.suit)
    {
    case SPADES: abc = 's'; break;
    case HEARTS: abc = 'h'; break;
    case DIAMONDS: abc = 'd'; break;
    case CLUBS: abc = 'c'; break;
    case NUM_SUITS: abc = '4'; break;
    }
    return abc;
}

void print_card(card_t c)
{
  printf("%c", value_letter(c));
  printf("%c", suit_letter(c));
}

card_t card_from_letters(char value_let, char suit_let)
{
  assert((value_let >= '0'+2 &&
	  value_let <= '0'+9 ) ||
	  value_let == '0' ||
	  value_let == 'J' ||
	  value_let == 'Q' ||
	  value_let == 'K' ||
	  value_let == 'A' );
  assert( suit_let == 's' || suit_let == 'h' || suit_let == 'd' || suit_let == 'c' );

  card_t temp;
  switch(value_let)
    {
    case '2': temp.value = 2; break;
    case '3': temp.value = 3; break;
    case '4': temp.value = 4; break;
    case '5': temp.value = 5; break;
    case '6': temp.value = 6; break;
    case '7': temp.value = 7; break;
    case '8': temp.value = 8; break;
    case '9': temp.value = 9; break;
    case '0': temp.value = 10; break;
    case 'J': temp.value = VALUE_JACK; break;
    case 'Q': temp.value = VALUE_QUEEN; break;
    case 'K': temp.value = VALUE_KING; break;
    case 'A': temp.value = VALUE_ACE; break;
    }
  switch (suit_let)
    {
    case 's': temp.suit = SPADES; break;
    case 'h': temp.suit = HEARTS; break;
    case 'd': temp.suit = DIAMONDS; break;
    case 'c': temp.suit = CLUBS; break;
    }
  
  return temp;
}

card_t card_from_num(unsigned c)
{
  assert (c >= 0 && c < 52);
  card_t temp;
  unsigned values = c%13 + 2;
  temp.value = values;
  int suits = c/13;
  if(suits == 0)
    {
      temp.suit = SPADES;
    }
  else if (suits == 1)
    {
      temp.suit = HEARTS;
    }
  else if (suits == 2)
    {
      temp.suit = DIAMONDS;
    }
  else if (suits == 3)
    {
      temp.suit = CLUBS;
    }
  return temp;
}


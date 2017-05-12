#include <string.h>
int count_mars_bars_cargo(struct cargo *cargo) {
  // NULL -> 0
  if (cargo == NULL) {
    return 0;
  }
  // curr != 'marsbar' -> count(cargo->next)
  if (strcmp(cargo->commodity->name, "Mars Bar") != 0) {
    return count_mars_bars_cargo(cargo->next);
  }
  // curr == 'Marsbar' -> quantity + count(cargo->next)
  return cargo->quantity + count_mars_bars_cargo(cargo->next);
}

int cargo_mars_bars(struct bot *b) {
  struct cargo *cargo = b->cargo;
  return count_mars_bars_cargo(cargo);
}














int mars_bars_for_sale(struct bot *b) {
  struct location *curr_location = b->location;
  if (curr_location->type != LOCATION_SELLER) {
    return 0;
  }
  if ((curr_location->commodity->name, "Marsbar") != 0){
    return 0;
  }
  return curr_location->quantity;
}






curr = l;
while (curr != NULL) {
  // do sth
  curr = curr->next;
}

curr = l;
do {
  // do sth
  curr = curr->next;
} while (curr != l);

int v; -> 4/
sturct node *next;

struct node *a, *b, *c, *d;
a = NULL:
b = malloc(sizeof b);
c = malloc(sizeof struct node);
d = malloc(8);
c = a;
d.data = 42;
c->data = 42;


int member(int value, struct node *list) {
  if (list == NULL) {
    return 0;
  }
  if (list->value == value) {
    return 1;
  }
  return member(value, list->next);
}


int member(int value, struct node *list) {
  int result = 0;
  while(list != NULL) {
    if (list->value == value) {
      result = 1;
    }
    list = list->next;
  }
  return result;
}

int member(int value, struct node *list) {
  for(;list != NULL;list = list->next) {
    if (list->value == value) {
      return 1;
    }
  }
  return 0;
}

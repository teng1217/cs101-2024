#include <stdio.h>
#include <string.h>

typedef struct Books {
  int id; 
  int price;
  char title[100];
} book_t;

void total_price(book_t booklist[], int num) {
  int sum = 0;
  for(int i = 0; i <= 5; i ++){
    sum = sum + booklist[i].price;
  }
  printf("%d\n", sum);
}

void list_books(book_t booklist[], int num){
  
  printf("%d ",booklist[num].price);
  
}

int main() {
book_t book[6];
 book[0].id=1;
 book[0].price=1000;
 strcpy(book[0].title,"All the Light We Cannot See");
 
 book[1].id=2;
 book[1].price=300;
 strcpy(book[1].title,"The 38 Letters from J.D.Rockefeller to his son");
 
 book[2].id=3;
 book[2].price=1000;
 strcpy(book[2].title,"The Ballad of Songbirds and Snakes");
 
 book[3].id=4;
 book[3].price=550;
 strcpy(book[3].title,"Killers of the Flower Moon");
 
 book[4].id=5;
 book[4].price=870;
 strcpy(book[4].title,"Elon Musk");
 
 book[5].id=6;
 book[5].price=1344;
 strcpy(book[5].title,"Milk and Honey 12-Month 2024");

 int num;
 printf("½Ð¿é¤J¡G");
 scanf("%d", &num);
  

list_books(book, num);
total_price(book, num);
  return 0;
}


#include <stdio.h>
#include <math.h>

// Declare a new type for holding two decimal x, y cartesian coordinates
typedef struct {
  float x, y;
} point;

// Declare a function that outputs Hello World! n number of times. Call this from main.
void baconator(int n) {
  for (int i = 0; i < n; i++) { puts(".:Chunkyus Baconius:."); }
}

////////////////////////////////////////////////////////////////

int main(int argc, char** argv) {
  // Use a for loop to print out Hello World! five times.
  for (int i = 0; i < 5; i++) {
    puts("chunky bacon");
  }

  //  Use a while loop to print out Hello World! five times.
  int i = 0;
  while(i < 5) {
    i++;
    if (i % 2 == 0) {
      puts("¡ChUnKy bAcOn!");
    } else {
      puts("Not so chunky...");
    }
  }

  // Engage the baconator
  int chunk_quantity = 3;
  baconator(chunk_quantity);

  point p;
  p.x = 6.9;
  p.y = 42.0;
  float length = sqrt(p.x * p.x + p.y * p.y);
}

// What built in types are there other than the ones listed?
signed char a;
unsigned char b;
short int c;
short unsigned int d;
unsigned int e;
unsigned long int f;
long long int g;
unsigned long long int h;
long double i;

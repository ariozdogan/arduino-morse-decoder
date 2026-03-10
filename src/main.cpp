#include <Arduino.h>


const int buttonPin = 8;
const int lightPin = 7;

String pattern = "";

struct node {
  int data;
  node* left;
  node* right;
};

node* newNode(int value){
  node* n = new node;
  n -> data = value;
  n -> left = NULL;
  n -> right = NULL;
  return n;
}

void addMorseInput(){
  node* root = newNode(1);
}

char morseLetter(){
  if (pattern == ".-")    return 'A';
  if (pattern == "-...")  return 'B';
  if (pattern == "-.-.")  return 'C';
  if (pattern == "-..")   return 'D';
  if (pattern == ".")     return 'E';
  if (pattern == "..-.")  return 'F';
  if (pattern == "--.")   return 'G';
  if (pattern == "....")  return 'H';
  if (pattern == "..")    return 'I';
  if (pattern == ".---")  return 'J';
  if (pattern == "-.-")   return 'K';
  if (pattern == ".-..")  return 'L';
  if (pattern == "--")    return 'M';
  if (pattern == "-.")    return 'N';
  if (pattern == "---")   return 'O';
  if (pattern == ".--.")  return 'P';
  if (pattern == "--.-")  return 'Q';
  if (pattern == ".-.")   return 'R';
  if (pattern == "...")   return 'S';
  if (pattern == "-")     return 'T';
  if (pattern == "..-")   return 'U';
  if (pattern == "...-")  return 'V';
  if (pattern == ".--")   return 'W';
  if (pattern == "-..-")  return 'X';
  if (pattern == "-.--")  return 'Y';
  if (pattern == "--..")  return 'Z';
  return '?';                     
}



void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(lightPin, OUTPUT);
  Serial.println("Morse Code Decoder");
  Serial.println("Short press = dot || Long press = line");
  Serial.println("1 second pause = new letter || 3 second pause = new word");
  Serial.println("========================================================");
}

void loop() {
    

}
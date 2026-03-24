#include <Arduino.h>


const int buttonPin = 8;
const int lightPin = 7;

const int buttonDotPress = 100;
const int buttonDashPress = 300;

bool buttonPressed = false;

unsigned long buttonPressStartTime;
unsigned long buttonPressDuration;

String morsePattern = "";

String pattern = "";

struct node {
  char data;
  node* left;
  node* right;
};

node* newNode(char value){
  node* n = new node;
  n->data = value;
  n->left = NULL;
  n->right = NULL;
  return n;
}

node* root;

void morseBinaryTree(){
  root = newNode('\0');

  root->left = newNode('E');
  root->right = newNode('T');

  root->left->left = newNode('I');
  root->left->right = newNode('A');

  root->right->left = newNode('N');
  root->right->right = newNode('M');

  root->left->left->left = newNode('S');
  root->left->left->right = newNode('U');

  root->left->right->left = newNode('R');
  root->left->right->right = newNode('W');

  root->right->left->left = newNode('D');
  root->right->left->right = newNode('K');

  root->right->right->left = newNode('G');
  root->right->right->right = newNode('O');

  root->left->left->left->left = newNode('H');
  root->left->left->left->right = newNode('V');

  root->left->left->right->left = newNode('F'); 

  root->left->right->left->left = newNode('L');

  root->left->right->right->left = newNode('P');
  root->left->right->right->right = newNode('J');

  root->right->left->left->left = newNode('B');
  root->right->left->left->right = newNode('X');

  root->right->left->right->left = newNode('C');
  root->right->left->right->right = newNode('Y');

  root->right->right->left->left = newNode('Z');
  root->right->right->left->right = newNode('Q');


}

void buttonPressTime(){
  int buttonState = digitalRead(buttonPin);

  if(buttonState == LOW && !buttonPressed){
    buttonPressed = true;
    buttonPressStartTime = millis();
  }

  if(buttonState == HIGH && buttonPressed){
    buttonPressed = false;
    buttonPressDuration = millis() - buttonPressStartTime;
  }
}

void userMorseInput(){
  if(buttonDotPress >= buttonPressDuration && buttonPressDuration <= buttonDashPress ){
    morsePattern += ".";
  }
  else if(buttonPressDuration >= buttonDashPress){
    morsePattern += "-";
  }
}

void newLetter(){
  morsePattern = "";
}

void newWord(){
  Serial.print(" ");
}

void decodeMorse(){
  node* current = root;
  
  for(int i = 0; i < morsePattern.length(); i++){
    if(current == NULL){
      return;
    }
    if(morsePattern[i] == '.'){
      current = current->left;
    }
    else{
      current = current->right;
    }
  }
  if(current != NULL && current->data != '\0'){
    Serial.print(current->data);
  }
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
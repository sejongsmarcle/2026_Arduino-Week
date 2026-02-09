#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2);
const int BUTTON_PIN = 2;
const int JUMP_DURATION = 5; 
byte dino[8] = { B00000, B00111, B00101, B10111, B10100, B01110, B01100, B01010 };
byte tree[8] = { B00000, B00100, B00101, B10101, B10110, B01100, B10100, B00000 };
int dinoPos = 1;      
int treePos = 15;     
int score = 0;        
int jumpTimer = 0; 

void setup() {
  lcd.init();           
  lcd.backlight();      
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  lcd.createChar(0, dino);
  lcd.createChar(1, tree);

  lcd.setCursor(0, 0);
  lcd.print("Dino Game Start!");
  delay(2000);
  lcd.clear();
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW && jumpTimer == 0) {
    jumpTimer = JUMP_DURATION;
  }

  if (jumpTimer > 0) {
    dinoPos = 0;
    jumpTimer--;
  } 
  else {
    dinoPos = 1;
  }
  lcd.clear();
  lcd.setCursor(1, dinoPos);
  lcd.write(0); 
  lcd.setCursor(treePos, 1); 
  lcd.write(1); 
  lcd.setCursor(10, 0);
  lcd.print(score);

  if (treePos == 1 && dinoPos == 1) {
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("GAME OVER");
    lcd.setCursor(3, 1);
    lcd.print("Score: ");
    lcd.print(score);
    while(1); 
  }

  treePos--; 
  if (treePos < 0) {
    treePos = 15; 
    score++;      
  }
  delay(200); 
}
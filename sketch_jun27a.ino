long bha;
long san;

const int w1_Pul = 4;
const int w1_dir  = 5;

const int w2_Pul = 6;
const int w2_dir  = 7;

const int w4_Pul = 8;
const int w4_dir  = 9;

const int w3_Pul = 10;
const int w3_dir  = 11;



// ************************************ pin enabling *****************//
int w1_enb = 51;
int w2_enb = 49;
int w3_enb = 47;
int w4_enb = 45;

char x ; // x cordinate
char y ; // x cordinate
char command; // case vari.
char com;

String inString = "";

// automatic cons. //
char dat1;
char dat2 ;
char dat3 ;

long i;
int vh;

char ch;
int value = 0;
int sign = 1;

int number = 0;
// PWM config//
int pd = 500;       // Pulse Delay period
boolean setdir = LOW; // Set Direction

void revmotor () {

  setdir = !setdir;
}

void setup() {

  // Motor Pin Configuration //
  pinMode(w1_Pul, OUTPUT);
  pinMode(w1_dir, OUTPUT);

  pinMode(w2_Pul, OUTPUT);
  pinMode(w2_dir, OUTPUT);

  pinMode(w3_Pul, OUTPUT);
  pinMode(w3_dir, OUTPUT);

  pinMode(w4_Pul, OUTPUT);
  pinMode(w4_dir, OUTPUT);




  //------------------------------------------ //
  digitalWrite(w1_enb, LOW);
  digitalWrite(w2_enb, LOW);
  digitalWrite(w3_enb, LOW);
  digitalWrite(w4_enb, LOW);

  //-------------------------------------//

  /* User input and other parameter declearting   */
  char command;

  Serial.begin(9600);

  Serial.println("input m for control manually");
  Serial.println("input a for control manually");
  Serial.println("input x  for exsit in any mode");
}

void loop() {

  if (Serial.available() > 0) {

    command = Serial.read(); // for manual ( test purpose ) and automatic ( to move to coordiantes)


    switch (command) {
      case 'm':            // manual mode
        manual();
        break;
      case 'a':            // automated mode
        automatic();


    }

  }

}


//------------------- manual movement --------------------//
void manual() {

  while (com != 'h') {     // h for excit
    com = Serial.read();

    switch (com) {
      case 'u': // Forward
        mfor();

        break;

      case 'd': //Backward
        mback();
        break;

      case 'l': // left
        mleft();
        break;

      case 'r': //  right
        mRIGHT();
        break;
    }
  }
}



// ------------- automatic movement control ------------------- //

void automatic() {

  Serial.write("automatic");
  usersetupx();
  usersetupy();

}
void xxmovecontroller() {
  xxmove();

}

void yymovecontroller() {
  Serial.print('\n');
  Serial.print ("YYcontroller");
  yymove();

}




//----------------------------------------------------------------*******    // work all motors in same time // ***--------------------------------------------------//

void mfor() {

  digitalWrite(w1_dir, LOW); //   low for positive direction
  digitalWrite(w2_dir, LOW);
  digitalWrite(w3_dir, HIGH);
  digitalWrite(w4_dir, HIGH);


  for (int x = 0; x < 8000; x++) {
    digitalWrite(w1_Pul, HIGH);
    digitalWrite(w2_Pul, HIGH);
    digitalWrite(w3_Pul, HIGH);
    digitalWrite(w4_Pul, HIGH);

    delayMicroseconds(800);
    digitalWrite(w1_Pul, LOW);
    digitalWrite(w2_Pul, LOW);
    digitalWrite(w3_Pul, LOW);
    digitalWrite(w4_Pul, LOW);
    delayMicroseconds(500);

  }

}


void mback() {
  digitalWrite(w1_dir, HIGH);  //   low for positive direction
  digitalWrite(w2_dir, HIGH);
  digitalWrite(w3_dir, LOW);
  digitalWrite(w4_dir, LOW);

  for (int x = 0; x < 8000; x++) {


    digitalWrite(w1_Pul, HIGH);
    digitalWrite(w2_Pul, HIGH);
    digitalWrite(w3_Pul, HIGH);
    digitalWrite(w4_Pul, HIGH);
    delayMicroseconds(800);
    digitalWrite(w1_Pul, LOW);
    digitalWrite(w2_Pul, LOW);
    digitalWrite(w3_Pul, LOW);
    digitalWrite(w4_Pul, LOW);
    delayMicroseconds(500);


  }
}


void mleft() {
  digitalWrite(w1_dir, HIGH);
  digitalWrite(w2_dir, LOW);
  digitalWrite(w3_dir, LOW);
  digitalWrite(w4_dir, HIGH);

  for (int x = 0; x < 8000; x++) {


    digitalWrite(w1_Pul, HIGH);
    digitalWrite(w2_Pul, HIGH);
    digitalWrite(w3_Pul, HIGH);
    digitalWrite(w4_Pul, HIGH);
    delayMicroseconds(800);
    digitalWrite(w1_Pul, LOW);
    digitalWrite(w2_Pul, LOW);
    digitalWrite(w3_Pul, LOW);
    digitalWrite(w4_Pul, LOW);
    delayMicroseconds(500);


  }

}

void mRIGHT() {
  digitalWrite(w1_dir, LOW);
  digitalWrite(w2_dir, HIGH);
  digitalWrite(w3_dir, HIGH);
  digitalWrite(w4_dir, LOW);


  for (int x = 0; x < 8000; x++) {


    digitalWrite(w1_Pul, HIGH);
    digitalWrite(w2_Pul, HIGH);
    digitalWrite(w3_Pul, HIGH);
    digitalWrite(w4_Pul, HIGH);
    delayMicroseconds(800);
    digitalWrite(w1_Pul, LOW);
    digitalWrite(w2_Pul, LOW);
    digitalWrite(w3_Pul, LOW);
    digitalWrite(w4_Pul, LOW);
    delayMicroseconds(500);


  }

}






void yhome() {};  // collecting y co-ordinates



void ypostive() {
  Serial.write('\n');
  Serial.write(" Y positive");


  digitalWrite(w1_dir, LOW); //   low for positive direction
  digitalWrite(w2_dir, LOW);
  digitalWrite(w3_dir, HIGH);
  digitalWrite(w4_dir, HIGH);


  for (int x = 0; x < (266 * (san)); x++) {
    digitalWrite(w1_Pul, HIGH);
    digitalWrite(w2_Pul, HIGH);
    digitalWrite(w3_Pul, HIGH);
    digitalWrite(w4_Pul, HIGH);

    delayMicroseconds(308);
    digitalWrite(w1_Pul, LOW);
    digitalWrite(w2_Pul, LOW);
    digitalWrite(w3_Pul, LOW);
    digitalWrite(w4_Pul, LOW);
    delayMicroseconds(500);
  }

  loop();
}; // motor forward

void ynegative() {
  Serial.write('\n');
  Serial.write(" Y negative");
  digitalWrite(w1_dir, HIGH);  //   low for positive direction
  digitalWrite(w2_dir, HIGH);
  digitalWrite(w3_dir, LOW);
  digitalWrite(w4_dir, LOW);

  for (int x = 0; (x < (266) * (-1) * (san)   ); x++) {


    digitalWrite(w1_Pul, HIGH);
    digitalWrite(w2_Pul, HIGH);
    digitalWrite(w3_Pul, HIGH);
    digitalWrite(w4_Pul, HIGH);
    delayMicroseconds(308);
    digitalWrite(w1_Pul, LOW);
    digitalWrite(w2_Pul, LOW);
    digitalWrite(w3_Pul, LOW);
    digitalWrite(w4_Pul, LOW);
    delayMicroseconds(500);


  }
  loop();

}; // motor backward

void xpositive() {   // motirright
  Serial.write('\n');
  Serial.write("Xpoistive");

  digitalWrite(w1_dir, LOW);
  digitalWrite(w2_dir, HIGH);
  digitalWrite(w3_dir, HIGH);
  digitalWrite(w4_dir, LOW);


  for (int x = 0; x < ( 308 * (bha)  ); x++) {


    digitalWrite(w1_Pul, HIGH);
    digitalWrite(w2_Pul, HIGH);
    digitalWrite(w3_Pul, HIGH);
    digitalWrite(w4_Pul, HIGH);
    delayMicroseconds(800);
    digitalWrite(w1_Pul, LOW);
    digitalWrite(w2_Pul, LOW);
    digitalWrite(w3_Pul, LOW);
    digitalWrite(w4_Pul, LOW);
    delayMicroseconds(500);


  }
  yymovecontroller();


};

void xnegative() { // motir left
  Serial.write('\n');
  Serial.write(" X negative");
  digitalWrite(w1_dir, HIGH);
  digitalWrite(w2_dir, LOW);
  digitalWrite(w3_dir, LOW);
  digitalWrite(w4_dir, HIGH);

  for (int x = 0; x < ( 308 * (bha)*(-1) ); x++) {


    digitalWrite(w1_Pul, HIGH);
    digitalWrite(w2_Pul, HIGH);
    digitalWrite(w3_Pul, HIGH);
    digitalWrite(w4_Pul, HIGH);
    delayMicroseconds(800);
    digitalWrite(w1_Pul, LOW);
    digitalWrite(w2_Pul, LOW);
    digitalWrite(w3_Pul, LOW);
    digitalWrite(w4_Pul, LOW);
    delayMicroseconds(500);


  }
  yymovecontroller();
}

void backtohome() {

}



/////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------- user input ----------------------------------------------------//

void usersetupx() {

  Serial.println("Enter X co-ordinate");



  bha = Serial.read();
  bha = bha - bha;

  while ( ((bha) > (-500 ) && (bha) > (500)) || ( (bha) == 0 ) ) {

    bha = Serial.parseInt();
    // bha = bha - '0';
    Serial.print (bha);
    Serial.print ('\n');
  }
  Serial.print ("X has assigned  =");
  Serial.print (bha);
}


void usersetupy() {

  Serial.println("Enter Y co-ordinate");


  
  san = Serial.read();
  san = san - san;

  while ( ((san) > (-500 ) && (san) > (500)) || ( (san) == 0 ) ) {

    san = Serial.parseInt();
    // bha = bha - '0';
    Serial.print (san);
    Serial.print ('\n');
  }
  Serial.print ("Y has assigned =");
  Serial.print (san);
  xxmovecontroller();

}


void xxmove()
{
  if ( (bha > 0) ) {
    xpositive();
  }

  else if ( (bha) < 0)  {
    xnegative();
  }


}


void yymove() {
  Serial.print('\n');
  Serial.print ("YYmove");
  if ((san) > 0) {
    Serial.print('\n');
    Serial.print ("Ypositive");
    ypostive();


  }

  else if ((san) < 0)
  {
    Serial.print('\n');
    Serial.print ("Ynegative");
    ynegative();


  }
}

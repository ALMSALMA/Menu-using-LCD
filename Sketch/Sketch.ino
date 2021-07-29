// include the library code: 
#include <LiquidCrystal.h> 
 

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

/*---------- Variables ----------*/
int button, menuNO1, menuNO2; 
int  optionNO=0,  menu=0,  edge=0;
char **submenu;

/*---------- Matrices ----------*/

char *options[] = {"ECG Waveform   ", "Cardiac Output", "Arrhythmias   ",
                     "PERF Wave       ", "Blood Pressure    ", "                ", 
                    };
char *suboptions1[] = {"ECG Rate        ","Amplitude       ", "PT Type    ","ST              ","Artf            ","                ", 
                    };

char *suboptions2[] = {"Wave            ", "INJ Temp       ","BL Temp      ","CC              ", "                ", 
                    };

char *suboptions3[] = {"SV              ", "PREM            ","VENT            ","COND            ", "                ", 
                    };

char *suboptions4[] = {"set frequency     ", "set shape      ","set amplitude     ", "                ", 
                    };

char *suboptions5[] = {"ZERO            ", "Channel 1       ", "Channel 2       ", "Channel 3       ", "                ", 
                    };



/*---------- THE CODE ----------*/
 
void setup() {
  lcd.begin(16, 2);  
  edge = sizeof(options)/2-2;   
  } 

 
void loop() {   

  button = analogRead (0); 
  ReadButton(button);
  PrintToLCD();
  delay(5);
  }

//  define which button has pushed  //
void ReadButton(int x){
  
  if (x > 60 && x < 200) {        //UP button
    optionNO = optionNO-1; 
      if (optionNO < 0){
        optionNO = edge;
   }

  }else if (x < 400){              //Down button
    optionNO = optionNO+1;   
    
    if (optionNO > edge){
        optionNO = 0;
      }}
      
  else if (x > 600 && x < 800){    //Select button
    
    if(menu==0){         // first menu
      lcd.clear();
      menu++;
      menuNO1 = optionNO+1;
      
    switch (optionNO){
      case 0:
      submenu = suboptions1;
      edge = sizeof(suboptions1)/2-2; 
      break;

      case 1:
      submenu = suboptions2;
      edge = sizeof(suboptions2)/2-2; 
      break;

      case 2:
      submenu = suboptions3;
      edge = sizeof(suboptions3)/2-2; 
      break;

      case 3:
      submenu = suboptions4; 
      edge = sizeof(suboptions4)/2-2;
      break;

      case 4:
      submenu = suboptions5; 
      edge = sizeof(suboptions5)/2-2;
      break;


      }
    optionNO=0;
  } 
  else if(menu==1){       //  second menu
    menu++; 
    menuNO2=optionNO+1; 
    lcd.clear(); }
  }
  }

//  print to LCD  //
void PrintToLCD(){

//  first line of LCD  //
  lcd.setCursor(0,0);
  lcd.print("> "); 
  if(menu==0){
    lcd.print(options[optionNO]);
  }else if(menu==1){
    lcd.print(submenu[optionNO]);
  }else{
    lcd.print(menuNO1); 
    lcd.print(menuNO2);
    delay(5000);
    menu = optionNO = 0;
    return 0;
  }

//  second line of LCD  //
  lcd.setCursor(2,1); 
  if(menu==0){
    lcd.print(options[optionNO+1]);
  }else if(menu==1){
    lcd.print(submenu[optionNO+1]);
  }
}

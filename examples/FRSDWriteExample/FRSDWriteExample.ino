#include "FS.h"
#include "SD.h"
File myFile;  // Object for the file
const String MYFILENAME = "/hello.txt";
bool isOpen = false;

void openFile() {
  Serial.println("Open file for writing");
  Serial.println(MYFILENAME);
  myFile = SD.open(MYFILENAME, FILE_APPEND);
  if (!myFile) {
    Serial.println("Failed to open file for writing");
    return;
  }
}

void writeLineFile(const char *message) {
  if (!myFile.println(message)) {
    Serial.println("Write failed");
    return;
  }
}

void closeFile() {
  myFile.close();
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  if (!SD.begin()) {
    Serial.println("Card Mount Failed");
    return;
  }

  // Some test code to see if the writing works 
  openFile();
  writeLineFile("Test Message 2");
  writeLineFile("Another line 2");
  closeFile();
}

void loop() {
  // put your main code here, to run repeatedly:
  
  // Read the button
  // if button pressed and isOpen = false, then open file and make isOpen true;
  // if button pressed and isOpen = true, then close file and make isOpen false;

  // read the potmeter and if isOpen, then write to the file

}

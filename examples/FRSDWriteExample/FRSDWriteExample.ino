#include "FS.h"
#include "SD.h"
File myFile;  // Object for the file
const String MYFILENAME = "/hello.txt";

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
  if(!myFile.close()){
    Serial.println("Closing file failed");
  };
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  if (!SD.begin()) {
    Serial.println("Card Mount Failed");
    return;
  }


  openFile();
  writeLineFile("Test Message 2");
  writeLineFile("Another line 2");
  closeFile();
}

void loop() {
  // put your main code here, to run repeatedly:
}

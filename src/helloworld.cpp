// ------------------
//   helloworld.cpp
// ------------------
// © James Rennie 2026

#include <map>
#include <string>
#include <iostream>

class Printer {
public:

  void printText(std::string printSpool) {
      std::cout << printSpool;
  }
};

class Screen {
private:

  Printer printer;

  std::map<std::string, std::string> colourMap;

public:

  Screen() {
    colourMap.insert( {"Black"   ,"\033[30m"} );
    colourMap.insert( {"Red"     ,"\033[31m"} );
    colourMap.insert( {"Green"   ,"\033[32m"} );
    colourMap.insert( {"Yellow"  ,"\033[33m"} );
    colourMap.insert( {"Blue"    ,"\033[34m"} );
    colourMap.insert( {"Magenta" ,"\033[35m"} );
    colourMap.insert( {"Cyan"    ,"\033[36m"} );
    colourMap.insert( {"White"   ,"\033[37m"} );
    colourMap.insert( {"Default" ,"\033[0m" } );
  }

  // This combination of control characters will clear the console.
  void clear() {
    printer.printText("\033[H\033[J");
  }

  void setTextColour(std::string textColour) {
    printer.printText(colourMap.at(textColour.data()));
  }

  void toast(std::string bread) {
    printer.printText(bread);
  }

  void newline() {
    printer.printText("\n");
  }
};

class Application {
private:

  Screen screen;

public:

  void run() {
    screen.clear();
    screen.setTextColour("Green");
    screen.toast("Hello World!");
    screen.newline();
  }

  void quit() {
    screen.setTextColour("Default");
    screen.newline();
    screen.toast("Press any key to exit...");
    std::cin.get();
    screen.clear();
  }
};

class ErrorHandler {
private:

  // An ERROR_LEVEL of zero means there are no errors to report.
  int ERROR_LEVEL = 0;

public:

  void setErrorLevel(int errorLevel) {
    ERROR_LEVEL = errorLevel;
  }

  int getErrorLevel() {
    return ERROR_LEVEL;
  }
};

int main() {

  Application app;
  ErrorHandler errHandler;

  try {
    app.run();
  }
  catch( ... ) {
    errHandler.setErrorLevel(1);
  }

  app.quit();
  return errHandler.getErrorLevel();
}

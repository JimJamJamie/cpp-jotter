#include <map>
#include <string>
#include <iostream>
#include <fmt/core.h>

// An ERROR_LEVEL of zero means there are no errors to report.
int ERROR_LEVEL = 0;

class Printer {
public:

  // Defaults to printing a newline when called with no args.
  void printText(std::string printSpool = "\n") {
      fmt::print(printSpool);
  }
};

class Screen {
public:

  Printer printer;

  std::map<std::string, std::string> colourMap;

  void createColourMap() {
    colourMap.insert( {"Black"   ,"\033[30m"} );
    colourMap.insert( {"Red"     ,"\033[31m"} );
    colourMap.insert( {"Green"   ,"\033[32m"} );
    colourMap.insert( {"Yellow"  ,"\033[33m"} );
    colourMap.insert( {"Blue"    ,"\033[34m"} );
    colourMap.insert( {"Magenta" ,"\033[35m"} );
    colourMap.insert( {"Cyan"    ,"\033[36m"} );
    colourMap.insert( {"White"   ,"\033[37m"} );
    colourMap.insert( {"Reset"   ,"\033[0m" } );
  }

  // This combination of control characters will clear the console.
  void clear() {
    printer.printText("\033[H\033[J");
  }

  void setColour(std::string textColour) {
    createColourMap();
    printer.printText(colourMap.at(textColour));
  }
};

class ErrorHandler {
public:

  static void setErrorLevel(int errorLevel) {
    ERROR_LEVEL = errorLevel;
  }
};

class Application {
public:

  Printer printer;
  Screen screen;

  void run() {
    screen.clear();
    screen.setColour("Green");
    printer.printText("Hello World!");
    screen.setColour("Reset");
    printer.printText();
  }

  void quit() {
    printer.printText("Press any key to exit...");
    std::cin.get();
    screen.clear();
  }
};

int main() {

  Application app;

  try {
    app.run();
  }
  catch( ... ) {
    ErrorHandler::setErrorLevel(1);
  }

  app.quit();
  return ERROR_LEVEL;
}

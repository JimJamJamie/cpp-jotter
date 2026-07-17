#include <string>
#include <iostream>
#include <fmt/core.h>

int ERROR_LEVEL = 0;

class Printer {
public:

  static void print(std::string printSpool = "\n") {
    fmt::print(printSpool);
  }
};

class Screen: public Printer {
public:

  static void clear() {
    print("\033[H\033[J");
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
    printer.print("Hello World!");
    printer.print();
  }
};

int main() {

  try {
    Application app;
    app.run();
  }
  catch( ... ) {
    ErrorHandler::setErrorLevel(1);
  }

  Printer::print("Press any key to exit...");
  std::cin.get();
  return ERROR_LEVEL;
}

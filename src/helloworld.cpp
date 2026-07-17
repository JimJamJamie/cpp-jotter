#include <string>
#include <iostream>
#include <fmt/core.h>

// An ERROR_LEVEL of zero means there are no errors to report.
int ERROR_LEVEL = 0;


class Printer {
public:

  // Defaults to printing a newline when called with no args.
  static void print(std::string printSpool = "\n") {
    fmt::print(printSpool);
  }
};

class Screen: public Printer {
public:

  // This combination of control characters will clear the console.
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

  void quit() {
    Printer::print("Press any key to exit...");
    std::cin.get();
    Screen::clear();
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

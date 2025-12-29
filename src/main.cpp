#include <chrono>
#include <thread>

#include "terminal.h"

using namespace terminal;

int main() {
  terminal::Field mainField;
  terminal::utils::clear();
  int col = terminal::utils::GetTerminalColumns();
  int row = terminal::utils::GetTerminalRows();
  terminal::Object obj0("", "", 0, 0, 3, col, 1);
  terminal::Object obj1("", "", 3, 0, row, col, 1);
  mainField[obj1][obj0];
  Terminal::init();
  obj0.show();
  obj1.show();
  terminal::input::Key key;
  while (true) {
    if (key.read()) {
      if (key.getCurrentChar() == 'q') {
        Terminal::shutdown();
      }
    }
    return 0;
  }
}

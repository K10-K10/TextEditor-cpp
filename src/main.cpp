#include <chrono>
#include <string>
#include <thread>

#include "terminal.h"

using namespace terminal;

int main() {
  terminal::Field mainField;
  Terminal::init();
  terminal::Object obj0("", "", 0, 0, 3, FULL, 1);
  terminal::Object obj1("", "", 3, 0, FULL, FULL, 1);
  terminal::Object popup("", ":", 4, 4, 3, 10, 1);
  // mainField[obj1][obj0];
  obj0.show();
  obj1.show();
  terminal::input::Key key;
  std::string s, s1;
  std::string v;
  key.hide();
  int selected_id = 0;
  while (true) {
    if (key.read()) {
      switch (key.getKeyCode()) {
        case terminal::input::KeyCode::UP:
          selected_id =
              (selected_id - 1 + 2) % 2;  // Assuming there are 2 objects
          break;
        case terminal::input::KeyCode::DOWN:
          selected_id = (selected_id + 1) % 2;  // Assuming there are 2 objects
          break;
        case terminal::input::KeyCode::ENTER:
          if (selected_id == 0) {
            s += "You selected Object 0\n";
          } else if (selected_id == 1) {
            s += "You selected Object 1\n";
          }
          break;
        case terminal::input::KeyCode::ESCAPE:
          Terminal::shutdown();
          return 0;
        default:
          break;
      }
      popup.text(s);
      popup.show();
    }
  }
  Terminal::shutdown();
  return 0;
}

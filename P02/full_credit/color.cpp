#include "color.h"

std::string Color::to_string() {
  rainbow = std::to_string(red) + ";" + std::to_string(green) + ";" + std::to_string(blue);
  return rainbow;
};

//function takes colors and seperates with semicolons, returns rainbow

void Color::colorize(std::string rainbow2, std::string text) {
  std::cout << "\033[38;2;" + rainbow2 + ";177m" << text << "\033[0m" << std::endl;
};

//no return, passes rainbowr and text as it is used in function

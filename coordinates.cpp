#include "coordinates.hpp"
#include <fstream>
#include <utility>
#include <iostream>

extern std::ofstream coordinate_file;
std::pair<int, int> coordinate = {0, 0};

void export_coordinates() {
  if (coordinate_file.is_open()) {
    coordinate_file << coordinate.first << "," << coordinate.second << "\n";
    coordinate_file.flush();
  }
}

void cordinates(uint8_t Dir, uint8_t Speed) {
  switch (Dir) {
  case Forward:
    coordinate.second += Speed / 10; // Move forward (increase Y)
    break;
  case Backward:
    coordinate.second -= Speed / 10; // Move backward (decrease Y)
    break;
  case Turn_Left:
    coordinate.first -= Speed / 10; // Turn left (decrease X)
    break;
  case Turn_Right:
    coordinate.first += Speed / 10; // Turn right (increase X)
    break;
  case StearRightt:
    coordinate.first += Speed / 20; //  increase X
    coordinate.second += Speed / 20; //  increase Y
    break;
  case StearLeft:
    coordinate.first -= Speed / 20; // decrease X
    coordinate.second += Speed / 20; // increase Y
    break;
  case Top_Left:
    coordinate.first -= Speed / 20; // Diagonal top-left
    coordinate.second += Speed / 20;
    break;
  case Top_Right:
    coordinate.first += Speed / 20; // Diagonal top-right
    coordinate.second += Speed / 20;
    break;
  case Bottom_Left:
    coordinate.first -= Speed / 20; // Diagonal bottom-left
    coordinate.second -= Speed / 20;
    break;
  case Bottom_Right:
    coordinate.first += Speed / 20; // Diagonal bottom-right
    coordinate.second -= Speed / 20;
    break;
  default:
    break; 
  }
  printf("Updated Coordinates: (%d, %d)\n", coordinate.first, coordinate.second);
  export_coordinates(); // Write updated coordinates to file
}
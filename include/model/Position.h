#ifndef MICROMOUSE_INCLUDE_MODEL_POSITION_H_
#define MICROMOUSE_INCLUDE_MODEL_POSITION_H_

class Position {
 public:
  Position(int x, int y) : x(x), y(y) {}
  [[nodiscard]] int getX() const { return x; }
  [[nodiscard]] int getY() const { return y; }

 private:
  int x, y;
};

#endif //MICROMOUSE_INCLUDE_MODEL_POSITION_H_

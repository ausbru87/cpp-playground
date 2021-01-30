#include <cassert>
#include <cmath>
#include <stdexcept>

class Sphere {
 public:
   static float GetVolume(float radius) {
      if (radius > 0) {
          return 4.0 / 3.0 * pi_ * std::pow(radius, 3);
      }else {
          std::invalid_argument("radius must be positive");
      }
    }
 private:
   static float constexpr pi_{3.14159};
};

// Test
int main(void) {
  assert(abs(Sphere::GetVolume(5) - 523.6) < 1);
}
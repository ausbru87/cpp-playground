#include <cassert>
#include <cmath>
#include <stdexcept>
#include <iostream>

// TODO: Define class Sphere
class Sphere {
 public:
  // Constructor
  Sphere(float radius);
  // Sets the Radius after checking validity
  void SetRadius(float radius);
  // returns the private radius_ member
  float GetRadius() const;
  // returns the private volume_ member
  float GetVolume() const;

  // Mutators
  void SetRadius();

 private:
  // Private members
  // Checks if the Radius value is valid
  bool CheckRadius(float radius);
  // Sets the volume using volume formula
  void SetVolume(float radius);
  float radius_;
  float volume_;
};
// Define Constructor
Sphere::Sphere(float radius) {
  SetRadius(radius);
}

// Helper to check validity of radius before setting
bool Sphere::CheckRadius(float radius) {
  if (radius < 0 ) {
    return false;
  }else {
    return true;
  }
}

// Private: used to set the volume after radius is updated
void Sphere::SetVolume(float radius) {
  // v = 4/3*pi*r^3 volume formula
  volume_ = 4.0 / 3.0 * M_PI * std::pow(radius, 3);
}

// Mutator to set radius of sphere and update volume
void Sphere::SetRadius(float radius) {
  if (CheckRadius(radius)) {
    radius_ = radius;
    // Update Volume since radius has changed
    SetVolume(radius_);
  }else {
    // if there radius is invalid throw error
    throw std::invalid_argument("radius must be positive");
  }
}

// Accessor to get radius of sphere
float Sphere::GetRadius() const {
  return radius_;
}

// Accessor to get radius of sphere
float Sphere::GetVolume() const {
  return volume_; 
}

int main(void) {
  // Test 1: create new sphere obj instance
  Sphere sphere(5);
  assert(sphere.GetRadius() == 5);
  assert(abs(sphere.GetVolume() - 523.6) < 1);

  //Test 2: update the existing sphere
  sphere.SetRadius(3);
  assert(sphere.GetRadius() == 3);
  assert(abs(sphere.GetVolume() - 113.1) < 1);

  // test invariant and CheckRadius function
  bool caught{false};
  try {
    sphere.SetRadius(-1);
  } catch (...) {
    caught = true;
  }
  assert(caught);
}
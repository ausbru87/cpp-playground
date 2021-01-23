#include <cassert>
#include <stdexcept>
#include <iostream>

// TODO: Define class Pyramid
class Pyramid {
    private:
      float length_;
      float width_;
      float height_;
      bool CheckValid(float dim);
    
    public:
      // constructor
      Pyramid(float l, float w, float h);
      // Accessors Declarations
      float GetLength() const;
      float GetWidth() const;
      float GetHeight() const;
      // Mutators Declarations
      void SetLength(float l);
      void SetWidth(float w);
      void SetHeight(float h);
      // Declare Volume
      float GetVolume() const;
      float GetSurfaceArea() const;
};

// public class members

// constructor
Pyramid::Pyramid(float l, float w, float h) {
    SetLength(l);
    SetWidth(w);
    SetHeight(h);
}

// accessors
float Pyramid::GetLength() const { return length_; }
float Pyramid::GetWidth() const { return width_; }
float Pyramid::GetHeight() const { return height_; }
// mutators
void Pyramid::SetLength(float l) {
    if (l > 0) {
        length_ = l;
    }else {
        throw "Length needs to be greater than 0.";
    }
}
void Pyramid::SetWidth(float w) {
    if (w > 0) {
        width_ = w;
    }else {
        throw "Width needs to be greater than 0.";
    }
}
void Pyramid::SetHeight(float h) {
    if (h > 0) {
        height_ = h;
    }else {
        throw "Height needs to be greater than 0.";
    }
}
// public GetVolume()
float Pyramid::GetVolume() const {
    return length_ * width_ * height_ / 3;
}
// public GetSurfaceArea()
//float Pyramid::GetSurfaceArea() {
//
//}

// private class members
bool Pyramid::CheckValid(float dim) {
    if (dim > 0) {
        return true;
    }else {
        return false;
    }
}
// Test
int main() {
  Pyramid pyramid(4, 5, 6);
  std::cout << "l: " << pyramid.GetLength() << " w: " << pyramid.GetWidth() << " h: " << pyramid.GetHeight() << "\n";

  assert(pyramid.GetLength() == 4);
  assert(pyramid.GetWidth() == 5);
  assert(pyramid.GetHeight() == 6);
  assert(pyramid.GetVolume() == 40);
  
  try {
     Pyramid pyr2(2, -2, 4); 
  } catch (const char* msg) {
      std::cerr << msg << std::endl;
  }
  // assert(pyramid.GetSurfaceArea() == 
  bool caught{false};
  try {
    Pyramid invalid(-1, 2, 3);
  } catch (...) {
    caught = true;
  }
  assert(caught);
}
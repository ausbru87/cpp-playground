#include <string>
#include <cstring>
#include <iostream>

class Car {
    // TODO: Declare private attributes
    private:
      float weight_;
      int horsepower_;
      char* brand_;
      
    // TODO: Declare getter and setter for brand
    public:
      void SetWeight(float weight);
      float GetWeight();
      void SetHorsepower(int horsepower);
      int GetHorsepower();
      void SetBrand(std::string brand);
      char* GetBrand();
        
};

// Define setters
void Car::SetWeight(float weight) { weight_ = weight; }
void Car::SetHorsepower(int horsepower) { horsepower_ = horsepower; }
void Car::SetBrand(std::string brand) {
    // initialize char array, needs enough buffer for null terminator and allocate memory on heap
    brand_ = new char[brand.length() + 1];
    // copy converted cstring to char array
    strcpy(brand_, brand.c_str());
}

// Define getters
char* Car::GetBrand() { return brand_; }

// Test in main()
int main() 
{
    Car car;
    car.SetBrand("Peugeot");
    std::cout << car.GetBrand() << "\n";   
}
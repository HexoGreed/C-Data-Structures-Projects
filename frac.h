class FractionType
{
public:
  void Initialize(int numerator, int denominator);
  // Function: Initialize the fraction
  // 

  // 
  // Pre:  None
  // Post: Fraction is initialized



  int NumeratorIs();
  // Function: Returns the value of the numerator
  // Pre:  Fraction has been initialized
  // Post: numerator is returned
  int DenominatorIs();
  // Function: Returns the value of the denominator
  // Pre:  Reaction has been initialized 
  // Post: denominator is returned
  bool IsZero();
  // Function: Determines if fraction is zero
  // Pre:  Fraction has been initialized
  // Post: Returns true if numerator is zero
  bool IsNotProper();
  // Function: Determines if fraction is a proper fraction
  // Pre:  Fraction has been initialized
  // Post: Returns true if fraction is greater than one
  int ConvertToProper();
  // Function: Converts the fraction to a whole number and a 
  //       fractional part
  // Pre:  Fraction has been initialized, is in reduced form, and  
  //       is not a proper fraction
  // Post: Returns whole number
  //       Remaining fraction is original fraction minus the
  //       whole number; fraction is in reduced form 

  void print();
  //prints



  FractionType operator+(const FractionType& addend) {
	  FractionType sum;
	  sum.num = num * addend.denom + addend.num * denom;
	  //finds the sum of the numerators
	  sum.denom = denom * addend.denom;
	  //finds the sum of the denominators or gcd

	  return sum;

  }
  FractionType operator-(const FractionType& subtractor) {
      FractionType result;
	  result.num = num * subtractor.denom - subtractor.num * denom;
	  result.denom = denom * subtractor.denom;
	  return result;
	  //copy paste from above but with subtraction
  }
  FractionType operator*(const FractionType& multiplier) {
	  FractionType result;
	  result.num = num * multiplier.num;
	  result.denom = denom * multiplier.denom;
	  return result;
	  //copy paste from above but with multiplication
  }

  FractionType operator/(const FractionType& divisor) {
	  FractionType result;
	  result.num = num * divisor.num;
	  result.denom = denom * divisor.denom;
	  return result;
	  //copy paste from above but with division
	 
  }




private:
  int num;
  int denom;
};


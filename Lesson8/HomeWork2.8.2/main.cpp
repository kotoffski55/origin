#include <iostream>
using namespace std;

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:

	

	Fraction(int& numerator, int& denominator)
	{

		if ((numerator >= denominator) && (numerator % denominator) == 0)
		{
			numerator = numerator / denominator;
			denominator = denominator / denominator;
		}
		else if ((numerator <= denominator) && (denominator % numerator) == 0)
		{
			denominator = denominator / numerator;
			numerator = numerator / numerator;
		}
		numerator_ = numerator;
		denominator_ = denominator;
	}
	
	Fraction operator + (const Fraction& other)
	{
		int sum_num = ((this->numerator_ * other.denominator_) + (this->denominator_ * other.numerator_));
		int sum_den = ((this->denominator_ * other.denominator_));
		return Fraction(sum_num, sum_den);
	}
	Fraction operator - (const Fraction& other)
	{
		int sum_num = ((this->numerator_ * other.denominator_) - (this->denominator_ * other.numerator_));
		int sum_den = ((this->denominator_ * other.denominator_));
		return Fraction(sum_num, sum_den);
	}
	Fraction operator * (const Fraction& other)
	{
		int sum_num = ((this->numerator_ *  other.numerator_));
		int sum_den = ((this->denominator_ * other.denominator_));
		return Fraction(sum_num, sum_den);
	}
	Fraction operator / (const Fraction& other)
	{
		int sum_num = ((this->numerator_ * other.denominator_));
		int sum_den = ((this->denominator_ * other.numerator_));
		return Fraction(sum_num, sum_den);
	}
	Fraction operator ++()
	{
		this->numerator_ = ((numerator_ + denominator_));
		this->denominator_ = (denominator_);
		return Fraction(numerator_,denominator_);
	}
	Fraction operator ++(int)

	{
		int temp_numerator = numerator_;
		int temp_denominator = denominator_;
		this->numerator_ = ((numerator_ + denominator_));
		this->denominator_ = denominator_;
		return Fraction(temp_numerator, temp_denominator);
	}
	
	int getNumerator()
	{
		return this->numerator_;
	}
	int getDenominator()
	{
		return this->denominator_;
	}

};

int main()
{
	int numerator_1;
	int numerator_2;
	int denominator_1;
	int denominator_2;

	
	cout << "Enter the numerator of the fraction 1 : " ;
	cin >> numerator_1;
	cout << "Enter the denominator of the fraction 1 : " ;
	cin >> denominator_1;
	cout << "Enter the numerator of the fraction 2 : " ;
	cin >> numerator_2;
	cout << "Enter the denominator of the fraction 2 : " ;
	cin >> denominator_2; 

	Fraction f1(numerator_1, denominator_1);
	Fraction f2(numerator_2, denominator_2);

	Fraction sum = f1 + f2;
	std::cout << f1.getNumerator() << "/" << f1.getDenominator() << " + " << f2.getNumerator() << "/" << f2.getDenominator() << " = " << sum.getNumerator() << " / " << sum.getDenominator() << '\n';

	Fraction sub = f1 - f2;
	std::cout << f1.getNumerator() << "/" << f1.getDenominator() << " - " << f2.getNumerator() << "/" << f2.getDenominator() << " = " << sub.getNumerator() << " / " << sub.getDenominator() << '\n';

	Fraction multiply = f1 * f2;
	std::cout << f1.getNumerator() << "/" << f1.getDenominator() << " * " << f2.getNumerator() << "/" << f2.getDenominator() << " = " << multiply.getNumerator() << " / " << multiply.getDenominator() << '\n';

	Fraction div = f1 / f2;
	std::cout << f1.getNumerator() << "/" << f1.getDenominator() << " / " << f2.getNumerator() << "/" << f2.getDenominator() << " = " << div.getNumerator() << " / " << div.getDenominator() << '\n';

	f2 = ++f1;
	std::cout << "Prefix increment 1-st fraction : " << f1.getNumerator() << "/" << f1.getDenominator() << std::endl;
	std::cout << "Prefix increment 2-st fraction : " << f2.getNumerator() << "/" << f2.getDenominator() << std::endl;

	f2 = f1++;
	std::cout << "Postfix increment 1-st fraction : " << f1.getNumerator () << "/" << f1.getDenominator() << std::endl;
	std::cout << "Postfix increment 2-st fraction : " << f2.getNumerator() << "/" << f2.getDenominator() << std::endl;
	
	return 0;
}

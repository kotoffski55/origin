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
		int sum_num = ((numerator_ + denominator_));
		int sum_den = (denominator_);
		return Fraction(sum_num, sum_den);
	}
	Fraction operator ++(int)
	{
		int sum_num = ((numerator_ + denominator_));
		int sum_den = (denominator_);
		return Fraction(sum_num, sum_den);
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
	Fraction sub = f1 - f2;
	Fraction multiply = f1 * f2;
	Fraction div = f1 / f2;
	Fraction pre_inc = ++f1;
	Fraction post_inc = f1++;
	

	std::cout << f1.getNumerator() << "/" << f1.getDenominator() << " + " << f2.getNumerator() << "/" << f2.getDenominator() << " = "  <<  sum.getNumerator() << " / " << sum.getDenominator() << '\n';
	std::cout << f1.getNumerator() << "/" << f1.getDenominator() << " - " << f2.getNumerator() << "/" << f2.getDenominator() << " = " << sub.getNumerator() << " / " << sub.getDenominator() << '\n';
	std::cout << f1.getNumerator() << "/" << f1.getDenominator() << " * " << f2.getNumerator() << "/" << f2.getDenominator() << " = " << multiply.getNumerator() << " / " << multiply.getDenominator() << '\n';
	std::cout << f1.getNumerator() << "/" << f1.getDenominator() << " / " << f2.getNumerator() << "/" << f2.getDenominator() << " = " << div.getNumerator() << " / " << div.getDenominator() << '\n';
	std::cout << "Prefix increment 1-st fraction : " << pre_inc.getNumerator() << "/" << pre_inc.getDenominator() << std::endl;
	std::cout << "Postfix increment 1-st fraction : " << post_inc.getNumerator() << "/" << post_inc.getDenominator() << std::endl;
	return 0;
}

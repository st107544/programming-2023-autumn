#include <iostream>

class Mod239 {
public:
	int el;

	Mod239(int el = 0) : el(el % 239) {}
	~Mod239() {}

	int mod(int el)
	{
		while (el < 0)
		{
			el += 239;
		}
		return el % 239;
	}
	int inversed(int el)
	{
		if (el == 0) { return -1; }
		if (el == 1) { return 1; }
		int i = 2;
		while ((el * i) % 239 != 1) ++i;
		return i;
	}
	Mod239 operator+= (Mod239 num)
	{
		el = mod(el + num.el);
		return *this;
	}
	Mod239 operator-= (Mod239 num)
	{
		el = mod(el - num.el);
		return *this;
	}
	Mod239 operator*= (Mod239 num)
	{
		el = mod(el * num.el);
		return *this;
	}
	Mod239 operator/= (Mod239 num)
	{
		if (num.el != 0) el = mod(el * inversed(num.el));
		else el = -1;
		return *this;
	}
	Mod239 operator%= (Mod239 num)
	{
		if (num.el != 0) el = mod(el % num.el);
		else el = -1;
		return *this;
	}

	Mod239 operator=(const Mod239& e)
	{
		return Mod239(e.el % 239);
	};
	bool operator == (const Mod239& e) const
	{
		return el == e.el;
	}
	bool operator != (const Mod239& e) const
	{
		return el != e.el;
	}
	bool operator > (const Mod239& e) const
	{
		return el > e.el;
	}
	bool operator < (const Mod239& e) const
	{
		return el < e.el;
	}
	bool operator >= (const Mod239& e) const
	{
		return el >= e.el;
	}
	bool operator <= (const Mod239& e) const
	{
		return el <= e.el;
	}

	int binpow(int a, int n)
	{
		int res = 1;

		while ( n != 0)
		{
			if ((n & 1) != 0)
			{
				res = ( res * a) % 239;
			}

			a = (a * a) % 239;
			n >>= 1;
		}

		return res;
	}

	friend std::ostream& operator<<(std::ostream& stream, const Mod239& e);
	friend std::istream& operator >> (std::istream& in, Mod239& num);

	friend const Mod239 operator+ (const Mod239& num,const Mod239& num2);
	friend const Mod239 operator- (const Mod239& num, const Mod239& num2);
	friend const Mod239 operator* (const Mod239& num, const Mod239& num2);
	friend Mod239 operator/ (Mod239 num, Mod239 num2);
};

std::ostream& operator<<(std::ostream& stream, const Mod239& e)
{
	stream << e.el << "(239)";
	return stream;
};

std::istream& operator >> (std::istream& in, Mod239& num)
{
	int el;
	in >> el;
	num.el = el % 239;
	return in;
}


const Mod239 operator+ (const Mod239& num,const Mod239& num2)
{
	Mod239 k = num.el + num2.el;
	return k.mod(k.el);
}
const Mod239 operator- (const Mod239& num, const Mod239& num2)
{
	Mod239 k = num.el - num2.el;
	return k.mod(k.el);

}
const Mod239 operator* (const Mod239& num, const Mod239& num2)
{
	Mod239 k = num.el * num2.el;
	return k.mod(k.el);
}
 Mod239 operator/ (Mod239 num, Mod239 num2)
{
	if (num.el != 0)
	{
		Mod239 k = num2.inversed(num2.el) * num.el;
		return k.mod(k.el);
	}
}

int main(int argc, char* argv[])
{
	Mod239 a;
	Mod239 b = 14;
	std::cin >> a;
	std::cout << a << std::endl;
	std::cout << a - 500 << std::endl;
	std::cout << a + 100 << std::endl;
	std::cout << a * 56 << std::endl;
	std::cout << a / 48 << std::endl; //a * 5
	a += 1;
	std::cout << a << std::endl;
	a -= 9;
	std::cout << a << std::endl;
	a *= 100;
	std::cout << a << std::endl;
	a /= 10;
	std::cout << a << std::endl;
	std::cout << "a == 134 - " << (a == 134) << std::endl;
	std::cout << "a >= 0 - " << (a >= 0) << std::endl;
	std::cout << "a <= 134 - " << (a <= 0) << std::endl;
	std::cout << "a != 134 - " << (a != 134) << std::endl;
	std::cout << "a > 0 - " << (a > 0) << std::endl;
	std::cout << "a < 0 - " << (a < 0) << std::endl;
	std::cout << a.binpow(a.el, 4);
	return EXIT_SUCCESS;
}
 
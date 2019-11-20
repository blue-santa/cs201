
#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::to_string;


class MyClass {

	private:
		int _age;
		string _name;

	public:
		void setName(string name) {
			_name = name;
		}

		string getName() const {
			return _name;
		}

		void setAge(int age) {
			_age = age;
		}

		int getAge() const {
			return _age;
		}

		string toString() {
			return "{ " + getName() + ", " + to_string(getAge()) + " }";
		}
};

int main()
{

	MyClass objA;
	MyClass objB;

	objA.setName("Bob");
	objB.setName("Alice");

	objA.setAge(1);
	objB.setAge(2);

	MyClass objC = objB;

	cout << objA.toString() << endl;
	cout << objB.toString() << endl;
	cout << objC.toString() << endl;

    return 0;
}


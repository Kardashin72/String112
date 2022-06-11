#include <iostream>

using namespace std;

class String112 {
	char* str = nullptr;
	int len = 0;
public:
	String112() = default;
	String112(const char* str) {
		this->len = strlen(str);
		this->str = new char[this->len + 1];
		strcpy_s(this->str, this->len + 1, str);
	}
	String112(int cnt, char s) {
		this->len = cnt;
		this->str = new char[len + 1];
		for (int i = 0; i < len; i++) {
			this->str[i] = s;
		}
		this->str[len] = '\0';
	}
	String112(const char* str, int index) {
		this->len = index;
		this->str = new char[this->len + 1];
		for (int i = 0; i < this->len; i++) {
			this->str[i] = str[i];
		}
	}
	String112(const String112& str) {
		if (str.str != nullptr) {
			this->len = str.len;
			this->str = new char[this->len + 1];
			strcpy_s(this->str, this->len + 1, str.str);
		}

	}
	String112(String112&& str) {
		swap(this->str, str.str);
		swap(this->len, str.len);
	}
	void setString(const char* str) {
		this->clear();
		if (str != nullptr) {
			this->len = strlen(str);
			char* n_str = new char[this->len + 1];
			strcpy_s(n_str, this->len + 1, str);
			this->str = n_str;
		}
	}

	String112& setString(const String112& right) {
		//s2.setString(s);
		this->clear();
		if (right.str != nullptr) {
			this->len = right.len;
			this->str = new char[this->len + 1];
			strcpy_s(this->str, this->len + 1, right.str);
		}

		return *this;
	}

	String112& operator=(String112&& str) {
		if (this == &str)
			return *this;
		swap(this->str, str.str);
		swap(this->len, str.len);
		str.clear();
		return *this;
	}

	char& operator[](int index) {
		return this->str[index];
	}
	const char& operator[](int index) const {
		return this->str[index];
	}

	void addString(const String112& right) {
		//s.addString(s2);
		if (right.str == nullptr)
			return;
		if (this->str == nullptr) {
			this->setString(right);
			return;
		}
		this->len += right.len;
		char* n_str = new char[this->len + 1];
		strcpy_s(n_str, this->len + 1, this->str);
		strcat_s(n_str, this->len + 1, right.str); //копирует right.str в конец строки n_str
		delete[] this->str;
		this->str = n_str;
	}

	void clear() {
		if (this->str != nullptr) {
			delete[] this->str;
			this->str = nullptr;
			this->len = 0;
		}
	}
	void printStr() const {
		if (this->str != nullptr)
			cout << this->str;

	}

	int lenght() const {
		return this->len;
	}

	String112& operator+= (const String112& right) {
		this->addString(right);
		return *this;
	}

	String112& operator= (const String112& right) {
		if (this == &right)
			return *this;
		this->~String112();
		if (right.str != nullptr) {
			this->len = right.len;
			this->str = new char[this->len + 1];
			strcpy_s(this->str, this->len + 1, right.str);
		}

		return *this;
	}

	void reverse() {
		for (int i = 0; i < this->len / 2; i++) {
			swap(this->str[i], this->str[this->len - i - 1]);
		}
	}

	bool empty() const {
		return this->str == nullptr;
	}

	void replace(char from, char to) {
		for (int i = 0; i < this->len; i++) {
			if (this->str[i] == from)
				this->str[i] = to;
		}
	}
	int find(char ch) {
		int index = -1;
		for (int i = 0; i < this->len + 1; i++) {
			if (this->str[i] == ch)
				index = i;
		}
		return index;
	}

	void remove(char a) {
		int count = 0;
		for (int i = 0; i < this->len; i++) {
			if (this->str[i] == a)
				count++;
		}
		char* n_str = new char[this->len - count + 1];
		for (int i = 0, k = 0; i < this->len + 1; i++) {
			if (this->str[i] != a) {
				n_str[k] = this->str[i];
				k++;
			}
		}
		this->len -= count;
		delete[] this->str;
		this->str = n_str;
	}

	void erase(int index) {
		char* n_str = new char[this->len];
		for (int i = 0, k = 0; i < this->len + 1; i++) {
			if (i != index) {
				n_str[k] = this->str[i];
				k++;
			}
		}
		this->len--;
		delete[] this->str;
		this->str = n_str;
	}

	void insert(int index, const char* str) {
		int k = 0;
		char* n_str = new char[this->len + strlen(str) + 1];
		for (int i = 0; i < this->len + 1; ++i) {
			if (i < index) {
				n_str[k] = this->str[i];
				k++;
			}
			else
				break;
		}
		for (int i = 0; i < strlen(str); i++) {
			n_str[k] = str[i];
			k++;
		}
		for (int i = index; i < this->len + strlen(str) + 1; i++) {
			n_str[k] = this->str[i];
			k++;
		}
		this->len += strlen(str);
		delete[] this->str;
		this->str = n_str;
	}

	~String112() {
		if (this->str != nullptr) {
			delete[] this->str;
			this->str = nullptr;
			this->len = 0;
		}
	}
	friend ostream& operator<< (ostream& out, const String112& str);
	friend istream& operator>> (istream& in, String112& str);
	friend String112 operator+ (const String112& a, const String112& b);
	friend bool operator== (const String112& a, const String112& b);
	friend bool operator!=(const String112& a, const String112& b);
	friend bool operator>(const String112& a, const String112& b);
	friend bool operator<(const String112& a, const String112& b);
};

//сравнение срок++
//find('е'); //индекс первого вхождения символа е ++
//remove('к') //удалить все вхождения символа к ++
//s.empty() проверяет пустая ли строка ++
//s.reverse() перевернет строку ++
//s.replace('e','t'); заменить все буквы е на t ++
//s.erase(index) удалить индекс из строки ++
//s.insert(index,"hello") вставить в индекс строку hello ++



bool operator==(const String112& a, const String112& b) {
	if (a.len != b.len)
		return false;
	for (int i = 0; i < a.len; i++) {
		if (a.str[i] != b.str[i])
			return false;
	}
	return true;
}

bool operator!=(const String112& a, const String112& b) {
	if (a.len != b.len)
		return true;
	for (int i = 0; i < a.len; i++) {
		if (a.str[i] != b.str[i])
			return true;
	}
	return false;
}

bool operator>(const String112& a, const String112& b) {
	return a.len > b.len;
}

bool operator<(const String112& a, const String112& b) {
	return a.len < b.len;
}

String112 operator+ (const String112& a, const String112& b) {
	String112 tmp = a;
	tmp += b;
	return tmp;
}

ostream& operator<< (ostream& out, const String112& str) {
	out << str.str;
	return out;
}

istream& operator>> (istream& in, String112& str) {
	char* tmp = new char[1000000000];
	in >> tmp;
	str.setString(tmp);
	delete[] tmp;
	return in;
}

void main()
{
	String112 s("Hello World");
	String112 s2("Goodbye");
	s.insert(6, "Hello ");
	cout << s << endl;


}
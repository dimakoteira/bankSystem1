#pragma once
#include<iostream>
#include<vector>
using namespace std;
class clsString
{
private:
	string _value;
public:
	clsString()
	{
		_value = " ";
	}
	clsString(string value)
	{
		_value = value;
	}
	void setvalue(string value)
	{
		_value = value;
	}

	string getvalue()
	{
		return _value;
	}


	__declspec(property(get = getvalue, put = setvalue)) string value;

	static void printFirstLetter(string word)
	{
		cout << word[0] << " ";
		for (int i = 0;i < word.length();i++)
		{
			if (word[i] == ' ')
				cout << word[i + 1] << " ";
		}
		cout << endl;
	}


	void printFirstLetter()
	{
		return printFirstLetter(_value);
	}


	 static string upperFirstLetter(string word)
	{
		bool first_letter = true;
		for (int i = 0;i < word.length();i++)
		{
			if (word[i] != ' ' && first_letter == true)
				word[i] = toupper(word[i]);
			first_letter = (word[i] == ' ' ? true : false);
		}
		return word;
	}


	void upperFirstLetter()
	{
		_value=upperFirstLetter(_value);
	}


	static string lowerFirstLetter(string word)
	{
		bool first_letter = true;
		for (int i = 0;i < word.length();i++)
		{
			if (word[i] != ' ' && first_letter == true)
			{
				word[i] = tolower(word[i]);
				first_letter = (word[i] == ' ' ? true : false);
			}
		}
	}


	void lowerFirstLetter()
	{
		_value=lowerFirstLetter(_value);
	}


	static string upperString(string word)
	{
		for (int i = 0;i < word.length();i++)
		{
			word[i] = toupper(word[i]);
		}
		return word;
	}


	static string lowerString(string word)
	{
		for (int i = 0;i < word.length();i++)
		{
			word[i] = tolower(word[i]);
		}
		return word;
	}


	void upperString()
	{
		_value=upperString(_value);
	}


	void lowerString()
	{
		_value= lowerString(_value);
	}


	static char invertCharCase(char c)
	{
		if (isupper(c))
			return tolower(c);
		else return toupper(c);
	}


	 static int count_letters(string word)
	{
		int count = 0;
		for (int i = 0;i < word.length();i++)
		{
			if (word[i] != ' ')
				count++;

		}
		return count;
	}


	 int count_letters()
	 {
		 return count_letters(_value);
	 }

	static int count_capital(string word)
	{
		int upper_c = 0;
		for (int i = 0;i < word.length();i++)
		{
			if (isupper(word[i]))
				upper_c++;

		}
		return upper_c;
	}


	int count_capital()
	{
		return count_capital(_value);
	}


	static int count_small(string word)
	{
		int lower_c = 0;
		for (int i = 0;i < word.length();i++)
		{
			if (islower(word[i]))
				lower_c++;

		}
		return lower_c;
	}


	int count_small()
	{
		return count_small(_value);
	}


	static short countCaseLetter(string word, char l)
	{
		short counter = 0;
		for (int i = 0;i < word.length();i++)
		{
			if(tolower(word[i])==tolower(l))
				counter++;
		}
		return counter;
	}


	short countCaseLetter(char l)
	{
		return countCaseLetter(_value, l);
	}


	static short countNoCaseLetter(string word, char l)
	{
		short counter = 0;
		for (int i = 0;i < word.length();i++)
		{
			if (word[i] == l)
				counter++;
		}
		return counter;
	}


	short countNoCaseLetter(char l)
	{
		return countNoCaseLetter(_value, l);
	}


	static bool is_vowel(char letter)
	{
		letter = tolower(letter);
		if ((letter == 'a') || (letter == 'e') || (letter == 'o') || (letter == 'u') || (letter == 'i'))
			return true;
		else return false;
	}


	static short count_vowels(string word)
	{
		int count = 0;
		for (int i = 0;i < word.length();i++)
		{
			if (is_vowel(word[i]))
				count++;
		}
		return count;
	}


	short count_vowels()
	{
		return count_vowels(_value);
	}


	static void print_vowels(string word)
	{
		for (int i = 0;i < word.length();i++)
		{
			if (is_vowel(word[i]))
				cout << word[i] << " ";
		}
		cout << endl;
	}


	void print_vowels()
	{
		return print_vowels(_value);
	}


	static void print_each_word(string s)
	{
		string space = " ";
		string word;
		int pos;
		while ((pos = s.find(space)) != std::string::npos)
		{
			word = s.substr(0, pos);
			if (word != "")
				cout << word << " ";
			s = s.erase(0, pos + space.length());
		}
		if (s != "")
			cout << s << endl;
	}


	void print_each_word()
	{
		return print_each_word(_value);
	}

	static int count_each_word(string s)
	{
		string space = " ";
		string word;
		int pos,counter=0;
		while ((pos = s.find(space)) != std::string::npos)
		{
			word = s.substr(0, pos);
			if (word != "")
				counter++;
			s = s.erase(0, pos + space.length());
		}
		if (s != "")
			counter++;
		return counter;
	}


	int counter_each_word()
	{
		return count_each_word(_value);
	}

	static vector <string> split_stringInVector(string word, string space)
	{

		vector<string> vword;
		string sword;
		short pos = 0, counter = 0;
		while ((pos = word.find(space)) != std::string::npos)
		{
			sword = word.substr(0, pos);
			//if (sword != "")
			//{
				vword.push_back(sword);
			//}
			word.erase(0, pos + space.length());
		}
		if (word != "")
			vword.push_back(word);

		return vword;

	}


	vector <string> split_stringInVector( string space)
	{
		return split_stringInVector(_value, space);

	}


	template <typename t>
	static void print_vector(vector<t> v)
	{
		for (const t& ele : v)
		{
			cout << ele << " ";
		}
		cout << endl;
	}

	static string join_string(vector<string> v, string space)
	{
		string s;
		for (string& i : v)
		{
			s = s + i + space;
		}
		return s;
	}

	static string reverse_string(string s)
	{
		vector<string>v = split_stringInVector(s, " ");
		string space = " ", s2;
		vector <string>::iterator iter = v.end();
		while (iter != v.begin())
		{
			iter--;
			s2 = s2 + *iter + " ";

		}
		return s2.substr(0, s2.length() - 1);
	}


	string reverse_string()
	{
		return  reverse_string(_value);
	}


	static string replace_word(string& s, string newword, string oldword)
	{
		int pos = s.find(oldword);
		cout << pos << endl;
		while (pos != s.npos)
		{
			s = s.replace(pos, oldword.length(), newword);
			pos = s.find(oldword);

		}
		return s;
		
	}


	string replace_word(string newword,string oldword)
	{
		return replace_word(_value,newword,oldword);
	}
	
	static string remove_punc(string word)
	{
		string s;
		for (int i = 0;i < word.length();i++)
		{
			if (!ispunct(word[i]))
				s = s + word[i] ;
			else
				s = s + " ";
		}
		return s;
	}


	string remove_punc()
	{
		return remove_punc(_value);
	}


	

};


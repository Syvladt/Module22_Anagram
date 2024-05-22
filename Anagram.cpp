// Anagram.cpp: Ничего умнее не пришло в голову, кроме как создать
// две map, в одной map первое слово, во второй - второе слово.
// В цикле поэлементно их сравнить. По идее они должны быть равны.

#include "Anagram.h"
#include <iostream>
#include <string>
#include <map>

// Функция конвертации строки в map, значения получаем по ссылкам
// Сама функция ничего не возвращает
void convertStr2Map(std::string& string, std::map<char, int>& myMap)
{	// Берём последовательно символы из строки и записываем в map
	// Если такой ключ уже есть, то инкрементируем второе поле в map
	for (int i = 0; i < string.length(); ++i)
	{
		if (myMap.count(string[i]) > 0)
		{
			myMap[string[i]]++;
		}
		else
			myMap.insert({string[i], 1});
	}
	// Отладочная печать
	//for (std::map<char, int>::iterator pointer = myMap.begin(); pointer != myMap.end(); ++pointer)
	//	std::cout << pointer->first << " " << pointer->second << '\n';
}

// Функция сравнивает map1 и map2 и возвращает результат сравнения
bool compareWords(std::string& string1, std::string string2)
{
	std::map<char, int> myMap1, myMap2;
	std::map<char, int>::iterator pointer1, pointer2;
	bool result = true;
	// Сравниваем сначала введённые строки, если их длины разные
	// То сразу делаем вывод, что это не анаграммы
	if (string1.length() == string2.length())
	{	// Конвертируем слова в map
		convertStr2Map(string1, myMap1);
		// Отладочная печать
		//std::cout << std::string(10, '=') << '\n';
		convertStr2Map(string2, myMap2);
		pointer2 = myMap2.begin();
		// В цикле сравниваем map1 и map2
		for(pointer1 = myMap1.begin(); pointer1 != myMap1.end() && result; ++pointer1)
		{
			result = (pointer1->first == pointer2->first) && (pointer1->second == pointer2->second);
			if (pointer2 != myMap2.end())
				++pointer2;
		}
	}
	return result;
}

int main()
{	// Главная фунция. Вводим два слова. Вызываем фунцию сравнения
	// И в зависимости от результата выводим соответствующее сообщение.
	// Проверку ввода делать не стал, так даже интереснее, можно не только
	// реальные слова вводить, но и любые последовательности букв и цифр.
	std::string inStr1, inStr2;
	std::cout << "Enter first word: ";
	std::cin >> inStr1;
	std::cout << "Enter second word: ";
	std::cin >> inStr2;
	if (compareWords(inStr1, inStr2))
	{
		std::cout << "\nThese words are anagrams.\n";
	}
	else
		std::cout << "\nThese words are not anagrams.\n";
	return 0;
}

#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;

list<int> complementWith(list<int> listA, list<int> listB)
{
	list<int>::iterator it1;
	list<int>::iterator it2;
	list<int> newList;
	bool flag = false;

	for (it1 = listB.begin(); it1 != listB.end(); ++it1)
	{
		for (it2 = listA.begin(); it2 != listA.end(); ++it2)
		{
			if (*it1 == *it2)
			{
				flag = true;
			}
		}

		if (!flag)
		{
			newList.push_back(*it1);
		}
	}

	return newList;
}

int main()
{
	list<int> listOne = { 10,20,30,10 };
	list<int> listTwo = { 15,25,35,20,15 };

	list<int> listUnion;
	list<int> listIntersection;
	list<int> listComplementWithAB;
	list<int> listComplementWithBA;
	list<int> listComplementSymetric;
	list<int>::iterator iteratorOne;
	list<int>::iterator iteratorTwo;

	cout << "Elements in listOne:" << endl;

	for (iteratorOne = listOne.begin(); iteratorOne != listOne.end(); ++iteratorOne)
	{
		cout << *iteratorOne << " ";
	}

	cout << "\nElements in listTwo:" << endl;

	for (iteratorOne = listTwo.begin(); iteratorOne != listTwo.end(); ++iteratorOne)
	{
		cout << *iteratorOne << " ";
	}

	cout << endl;


	listComplementWithAB = complementWith(listOne, listTwo);
	listComplementWithBA = complementWith(listTwo, listOne);


	for (iteratorOne = listOne.begin(); iteratorOne != listOne.end(); ++iteratorOne)
	{
		listUnion.push_front(*iteratorOne);
	}
	for (iteratorOne = listTwo.begin(); iteratorOne != listTwo.end(); ++iteratorOne)
	{
		listUnion.push_front(*iteratorOne);
	}

	for (iteratorOne = listOne.begin(); iteratorOne != listOne.end(); ++iteratorOne)
	{
		for (iteratorTwo = listTwo.begin(); iteratorTwo != listTwo.end(); ++iteratorTwo)
		{
			if (*iteratorOne == *iteratorTwo)
			{
				listIntersection.push_front(*iteratorOne);
			}
		}
	}



	listUnion.sort();

	listIntersection.sort();

	listUnion.erase(unique(listUnion.begin(), listUnion.end()), listUnion.end());

	cout << "Union between listOne and listTwo:" << endl;

	for (iteratorOne = listUnion.begin(); iteratorOne != listUnion.end(); ++iteratorOne)
	{
		cout << *iteratorOne << " ";
	}

	cout << "\nIntersection between listOne and listTwo:" << endl;

	for (iteratorOne = listIntersection.begin(); iteratorOne != listIntersection.end(); ++iteratorOne)
	{
		cout << *iteratorOne << " ";
	}

	cout << "\nComplement between listOne and listTwo:" << endl;

	for (iteratorOne = listComplementWithAB.begin(); iteratorOne != listComplementWithAB.end(); ++iteratorOne)
	{
		cout << *iteratorOne << " ";
	}

	cout << "\nComplement between listTwo and listOne:" << endl;

	for (iteratorOne = listComplementWithBA.begin(); iteratorOne != listComplementWithBA.end(); ++iteratorOne)
	{
		cout << *iteratorOne << " ";
	}
}
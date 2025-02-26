/*
* file			main.cpp
* description 	binary search trees kullanarak ağaçlar arasında gezinme ve ağaçların üstünde işlem yapma
* course		veri yapıları 1. öğretim B grubu
* assignment 	2. ödev
* date 			25.12.2024
* author		Sude ANDURMAN , sude.andurman@ogr.sakarya.edu.tr
*/

#include <iostream>
#include <cstdlib>

#include "listmanipulator.hpp"

int main() {
	try {
		ListManipulator listManipulator;
		BSTNode* 		root;
		size_t 			node_idx;
		int 			data_count;
		char 			userInput;

		root = nullptr;
		data_count = 0;
		data_count += listManipulator.getDatasFromFile("./src/agaclar.txt", root);
		node_idx = 0;
		listManipulator.DisplayMenu(node_idx);

		while (true)
		{
			cout << "\nSeçiminiz: ";
			cin >> userInput;

			if (userInput == 'Q' || userInput == 'q')
			{
				cout << "Programdan çıkılıyor...\n";
				break;
			} 
			else if (userInput == 'D' || userInput == 'd')
			{
				if (node_idx + 1 < data_count)
					node_idx++;
			} 
			else if (userInput == 'A' || userInput == 'a')
			{
				if (node_idx > 0)
					node_idx--;
            } 
			else if (userInput == 'W' || userInput == 'w')
			{
				listManipulator.FindTreeToReverse(node_idx);
            }
			else if ((userInput == 'S' || userInput == 's'))
			{
				listManipulator.DeleteTree(node_idx);
				data_count--;
				if (node_idx == data_count)
					node_idx--;
			}
			else
			{
				cout << "Geçersiz giriş! Lütfen tekrar deneyin.\n";
				continue;
			}
			//REFRESH MENU
			if (data_count == 0)
			{
				cout << endl<< "*****************************" << endl;
				cout << endl << endl << "Gösterilecek bir veri kalmadı." << endl << endl;
				cout << endl<< "*****************************" << endl;
			}
			else
			{
				cout << endl << endl;
				listManipulator.DisplayMenu(node_idx);
			}
		}
	}catch (const char* e)
	{
		cerr << "Hata: " << e << endl;
		return (1);
	}
	return (0);
}

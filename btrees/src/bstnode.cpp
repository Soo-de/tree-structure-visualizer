/*
* file			bstnode.cpp
* description 	binary search trees kullanarak ağaçlar arasında gezinme ve ağaçların üstünde işlem yapma
* course		veri yapıları 1. öğretim B grubu
* assignment 	2. ödev
* date 			16.12.2024
* author		Sude ANDURMAN , sude.andurman@ogr.sakarya.edu.tr
*/

#include "bstnode.hpp"

BSTNode :: BSTNode (char content)
{
	data = content;
	left = nullptr;
	right = nullptr;
}

BSTNode :: ~BSTNode()
{
	delete left;
	delete right;
}
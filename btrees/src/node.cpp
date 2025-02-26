/*
* file			node.cpp
* description 	binary search trees kullanarak ağaçlar arasında gezinme ve ağaçların üstünde işlem yapma
* course		veri yapıları 1. öğretim B grubu
* assignment 	2. ödev
* date 			25.12.2024
* author		Sude ANDURMAN , sude.andurman@ogr.sakarya.edu.tr
*/

#include "node.hpp"

Node :: Node (BSTNode* root)
{
	top = root;
	next = nullptr;
}

Node :: Node ()
{
	top = nullptr;
	next = nullptr;
}

Node :: ~Node ()
{}

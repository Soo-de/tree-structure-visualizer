/*
* file			node.hpp
* description 	binary search trees kullanarak ağaçlar arasında gezinme ve ağaçların üstünde işlem yapma
* course		veri yapıları 1. öğretim B grubu
* assignment 	2. ödev
* date 			25.12.2024
* author		Sude ANDURMAN , sude.andurman@ogr.sakarya.edu.tr
*/

#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include "bstnode.hpp"

using namespace std;

class	Node
{
	public:
		BSTNode *top;
		Node	*next;
		Node (BSTNode* root);
		Node ();
		~Node ();
};

#endif
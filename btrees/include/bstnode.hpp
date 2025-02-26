/*
* file			bstnode.hpp
* description 	binary search trees kullanarak ağaçlar arasında gezinme ve ağaçların üstünde işlem yapma
* course		veri yapıları 1. öğretim B grubu
* assignment 	2. ödev
* date 			25.12.2024
* author		Sude ANDURMAN , sude.andurman@ogr.sakarya.edu.tr
*/

#ifndef BSTNODE_HPP
#define BSTNODE_HPP

#include <iostream>
using namespace std;

class	BSTNode
{
	public:
		char	data;
		BSTNode	*left;
        BSTNode	*right;
		BSTNode(char data);
		~BSTNode ();
};

#endif
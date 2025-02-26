/*
* file			listmanipulator.hpp
* description 	binary search trees kullanarak ağaçlar arasında gezinme ve ağaçların üstünde işlem yapma
* course		veri yapıları 1. öğretim B grubu
* assignment 	2. ödev
* date 			25.12.2024
* author		Sude ANDURMAN , sude.andurman@ogr.sakarya.edu.tr
*/

#ifndef LISTMANIPULATOR_HPP
#define LISTMANIPULATOR_HPP

#include "node.hpp"
#include "bstnode.hpp"
#include <fstream>
#include <cstdint>

class	ListManipulator
{
	public:
		Node* head;
		
		ListManipulator();
		~ListManipulator();
		BSTNode*	InsertTree(BSTNode* root, char data);
		void		addToLastIndex (BSTNode* root);
		int			getDatasFromFile (const string& filename, BSTNode* root);
		void		DisplayMenu (size_t node_idx);
		void		DisplayNodeAddress(Node* start_node);
		void		DisplayTreeValue(Node* current);
		void		DisplayPointer(int idx);
		void		FindTreeToReverse(size_t node_idx);
		void		ReverseTree(BSTNode* node);
		void		DeleteTree(size_t node_idx);
		int			CalculateTreeValue(BSTNode* node, int start);

};

#endif
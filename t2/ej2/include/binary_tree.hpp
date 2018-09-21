#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

#include <iostream>
#include <cstdlib>
#include "node.h"

#define	LFT		0
#define	RGT		1
#define PRT		2

enum : char node_type
{
	nothing	= 0		,
	root = 1 << 0	,
	father = 1 << 1	,
	son = 1 << 2	,
	leaft = 1 << 3
};

template < class T >
class binary_tree
{
	private :

		//	GLOBAL VARIABLES

		int number_of_nodes ;
		int historic_nodes ;
		node <T> * _root ;

		//	LOCAL VARIABLES

		int level ;
		long int identify * ;
		node <T> * actual ;
		node_type my_type ;

	public :

		binary_tree () ;

		node <T> * root () ;

		T data () ;
		node <T> * left () ;
		node <T> * right () ;
		node <T> * parent () ;

		T set_data ( T & data = T () ) ;
		int add_root ( T & data = T () ) ;
		int add_left ( T & data = T () ) ;
		int add_right ( T & data = T () ) ;
		
		void print () ;

		~binary_tree () ;
} ;

#endif

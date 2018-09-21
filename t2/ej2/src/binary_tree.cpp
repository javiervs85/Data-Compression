#include "binary_tree.hpp"

template < class T >
binary_tree <T> :: binary_tree ()
{
	_root = nullptr ;
	number_of_nodes = 0 ;
	historic_nodes = 0 ;
	level = -1 ;
	identify = (int *) calloc ( 10 , sizeof ( int ) ) ;
	actual = nullptr ;
	my_type = nothing ;
}

template < class T >
node <T> * binary_tree :: root ()
{
	return _root ;
}

template < class T >
T binary_tree :: data ()
{
	if ( actual != nullptr )
	{
		return actual->data () ;
	}

	return T () ;
}

template < class T >
node <T> * binary_tree :: left ()
{
	node <T> auxiliar = nullptr ;

	if ( actual !=  nullptr )
	{
		auxiliar = actual->left () ;

		if ( actual->left () != nullptr )
		{
			actual = actual->left ();

			*identify = *identify | 1 << level ;
			++ level ;
			*identify = *identify | 1 << level ;
			my_type = nothing ;

			if ( actual->left () != nullptr || actual->right () != nullptr )
			{
				my_type = son | father ;
			}
			else
			{
				my_type = son | leaft ;
			}
		}
	}

	return auxiliar ;
}

template < class T >
node <T> * binary_tree :: right ()
{
	node <T> auxiliar = nullptr ;

	if ( actual !=  nullptr )
	{
		auxiliar = actual->right () ;

		if ( actual->right () != nullptr )
		{
			actual = actual->right ();

			*identify = *identify & 0 << level ;
			++ level ;
			*identify = *identify | 1 << level ;
			my_type = nothing ;

			if ( actual->left () != nullptr || actual->right () != nullptr )
			{
				my_type = son | father ;
			}
			else
			{
				my_type = son | leaft ;
			}
		}
	}

	return auxiliar ;
}

template < class T >
node <T> * binary_tree :: parent ()
{
	node <T> auxiliar = nullptr ;

	if ( actual !=  nullptr )
	{
		auxiliar = actual->parent () ;

		if ( actual->parent () != nullptr )
		{
			actual = actual->parent ();

			*identify = *identify & 0 << level ;
			-- level ;
			*identify = *identify | 1 << level ;
			my_type = nothing ;

			if ( actual->left () != nullptr || actual->right () != nullptr )
			{
				if ( actual->parent () != nullptr )
				{
					my_type = son | father ;
				}
				else
				{
					my_type = root | father ;
				}
			}
			else
			{
				if ( actual->parent () != nullptr )
				{
					my_type = son | father ;
				}
				else
				{
					my_type = root | father ;
				}
			}
		}
	}

	return auxiliar ;
}

template < class T >
T binary_tree :: set_data ( T & data )
{
	if ( actual != nullptr ) 
	{
		return actual->set_data ( data ) ;
	}

	return T () ;
}

template < class T >
int binary_tree :: add_root ( T & data )
{
	if ( _root == nullptr )
	{
		_root = new (std :: nothrow) node <T> ;
		
		if ( _root == nullptr )
		{
			return -1 ;
		}

		_root->set_data ( data ) ;

		++ level ;
		*identify = 0 ;
		*identify = identify | 1 << level
		++ number_of_nodes ;
		++ historic_nodes ;
		actual = _root ;
		my_type = root | father | leaft ;

		return 0 ;
	}

	return 1 ;
}

template < class T >
int binary_tree :: add_left ( T & data )
{
	if ( actual != nullptr )
	{
		return actual->add_left ( data ) ;
	}

	return 1 ;
}

template < class T >
int binary_tree :: add_right ( T & data )
{
	if ( actual != nullptr )
	{
		return actual->add_right ( data ) ;
	}

	return 1 ;
}

template < class T >
binary_tree :: ~binary_tree ()
{

}

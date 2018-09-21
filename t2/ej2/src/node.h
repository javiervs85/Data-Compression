#define _NODE_H

#include <new>

template < class T >
class node
{
	private :
	
		node ** _conextions ;
		int _number_of_conextions ;
		T _data;

	public :

		//  BASE

		node () ;																		// Crea nodo sin conexiones inicializado a '$cero'
		node ( node & auxiliar ) ;														// Constructor de nodo por copia
		//	Se incluye un parametro a booleano para evitar coflictos en la declaración con el método 2 si se inicializa con < T = node & >
		node ( bool param , T & data ) ;												// Crea nodo sin conexiones inicializado a '$data'

		//	SIMPLE LINK LIST

		node ( node <T> * next ) ;														// Crea nodo con una conexión apuntando a '$next' e inicializado a '$cero'
		//	Se incluye un parametro a booleano para evitar coflictos en la declaración con el método 6 si se inicializa con < T = node * >
		node ( bool param , node <T> * next , T & data ) ;								// Crea nodo con una conexión apuntando a '$next' e inicializado a '$data'

		//	DOUBLE LINK LIST

		node ( node <T> * next , node <T> * before );									// Crea nodo con dos conexiones apuntando a '$next' y '$before', inicializado a '$cero'
		//	Se incluye un parametro a booleano para evitar coflictos en la declaración con el método 6 si se inicializa con < T = node * >
		node ( bool param , node <T> * next , node <T> * before , T & data );			// Crea nodo con dos conexiones apuntando a '$next' y '$before', inicializado a '$data'
		
		// BINARY TREE

		node ( node <T> * left , node <T> * right , node <T> * parent );			// Crea nodo con tres conexiones apuntando a '$left', '$right' y '$parent', inicializado a '$cero'
		node ( node <T> * left , node <T> * right , node <T> * parent , T & data );			// Crea nodo con dos conexiones apuntando a ''$left', '$right' y '$parent', inicializado a '$data'

		// TREE'S OR GRAPH'S

		node ( int number_of_conextions ) ;												// Crea nodo con '$n' conexiones a '$nullptr' e inicializado a '$cero'
		//	Se incluye un parametro a booleano para evitar coflictos en la declaración con el método 12 si se inicializa con < T = node * >
		node ( bool param , int number_of_conextions , T & data ) ;						// Crea nodo con '$n' conexiones a '$nullptr' e inicializado a '$data'
		node ( int number_of_conextions , node <T> * conextions ) ;						// Crea nodo con '$n' conexiones a '$conextions[1..n]' e inicializado a '$cero'
		node ( int number_of_conextions , node <T> * conextions , T & data ) ;			// Crea nodo con '$n' conexiones a '$conextions[1..n]' e inicializado a '$data'

		//  BASE

		T data () ;

		//  LIST

		node * & next () ;
		node * & before () ;

		//  BINARY TRE

		int add_left ( T & data = T () ) ;
		int add_right ( T & data = T () ) ;

		node * & left () ;
		node * & right () ;
		node * & parent () ;

		//  TREE'S OR GRAPH'S

		T set_data ( T & data ) ;

		int conextions () ;
		int active_conextions () ;

		int new_conextion () ;
		int new_conextion ( node <T> * ptr ) ;

		void clear_conextions () ;
		
		node * & operator [] ( int index ) ;
		T operator * () ;


		~node () ;
} ;

template < class T >
node <T> :: node ()
{
	_conextions = nullptr ;
	_number_of_conextions = 0 ;
	_data = T () ;
}

template < class T >
node <T> :: node ( node & auxiliar )
{
	_conextions = auxiliar._conextions ;
	_number_of_conextions = auxiliar._number_of_conextions ;
	_data = auxiliar._data ;
}

template < class T >
node <T> :: node ( bool param , T & data )
{
	_conextions = nullptr ;
	_number_of_conextions = 0 ;
	_data = data ;
}

template < class T >
node <T> :: node ( node <T> * next )
{
	_conextions = new (std :: nothrow) node <T> * ;

	if ( _conextions == nullptr )
	{
		_number_of_conextions = 0 ;
		_data = T () ;

		return ;
	}

	_conextions [0] = next ;
	_number_of_conextions = 1 ;
	_data = T () ;
}

template < class T >
node <T> :: node ( bool param , node <T> * next , T & data )
{
	_conextions = new (std :: nothrow) node <T> * ;

	if ( _conextions == nullptr )
	{
		_number_of_conextions = 0 ;
		_data = T () ;

		return ;
	}

	_conextions [0] = next ;
	_number_of_conextions = 1 ;
	_data = data ;
}

template < class T >
node <T> :: node ( node <T> * next , node <T> * before )
{
	_conextions = new (std :: nothrow) node <T> * [2] ;

	if ( _conextions == nullptr )
	{
		_number_of_conextions = 0 ;
		_data = T () ;

		return ;
	}

	_conextions [0] = next ;
	_conextions [1] = before ;
	_number_of_conextions = 2 ;
	_data = T () ;
}

template < class T >
node <T> :: node ( bool param , node <T> * next , node <T> * before , T & data )
{
	_conextions = new (std :: nothrow) node <T> * [2] ;

	if ( _conextions == nullptr )
	{
		_number_of_conextions = 0 ;
		_data = T () ;

		return ;
	}

	_conextions [0] = next ;
	_conextions [1] = before ;
	_number_of_conextions = 2 ;
	_data = data ;
}

template < class T >
node <T> :: node ( node <T> * left , node <T> * right , node <T> * parent )
{
	_conextions = new (std :: nothrow) node <T> * [3] ;

	if ( _conextions == nullptr )
	{
		_number_of_conextions = 0 ;
		_data = T () ;

		return ;
	}

	_conextions [0] = left ;
	_conextions [1] = right ;
	_conextions [2] = parent ;
	_number_of_conextions = 3 ;
	_data = T () ;
}

template < class T >
node <T> :: node ( node <T> * left , node <T> * riht , node <T> * parent , T & data )
{
	_conextions = new (std :: nothrow) node <T> * [3] ;

	if ( _conextions == nullptr )
	{
		_number_of_conextions = 0 ;
		_data = T () ;

		return ;
	}

	_conextions [0] = left ;
	_conextions [1] = right ;
	_conextions [2] = parent ;
	_number_of_conextions = 3 ;
	_data = data ;
}

template < class T >
node <T> :: node ( int number_of_conextions )
{
	_conextions = new (std :: nothrow) node <T> * [number_of_conextions] ;

	if ( _conextions == nullptr )
	{
		_number_of_conextions = 0 ;
		_data = T () ;

		return ;
	}

	_number_of_conextions = number_of_conextions ;
	_data = T () ;
}

template < class T >
node <T> :: node ( bool param , int number_of_conextions , T & data )
{
	_conextions = new (std :: nothrow) node <T> * [number_of_conextions] ;
	
	if ( _conextions == nullptr )
	{
		_number_of_conextions = 0 ;
		_data = T () ;

		return ;
	}

	_number_of_conextions = number_of_conextions ;
	_data = data ;
}

template < class T >
node <T> :: node ( int number_of_conextions , node <T> * conextions )
{
	_conextions = new (std :: nothrow) node <T> * [number_of_conextions] ;
	
	if ( _conextions == nullptr )
	{
		_number_of_conextions = 0 ;
		_data = T () ;

		return ;
	}

	_number_of_conextions = number_of_conextions ;

	for ( int iterator = 0 ; iterator < number_of_conextions ; ++ iterator )
	{
		_conextions = conextions [iterator] ;
	}

	_data = T () ;
}

template < class T >
node <T> :: node ( int number_of_conextions , node <T> * conextions , T & data )
{
	_conextions = new (std :: nothrow) node <T> * [number_of_conextions] ;
	
	if ( _conextions == nullptr )
	{
		_number_of_conextions = 0 ;
		_data = T () ;

		return ;
	}

	_number_of_conextions = number_of_conextions ;

	for ( int iterator = 0 ; iterator < number_of_conextions ; ++ iterator )
	{
		_conextions = conextions [iterator] ;
	}

	_data = data ;
}

template < class T >
int node <T> :: conextions ()
{
	return _number_of_conextions ;
}

template < class T >
int node <T> :: active_conextions ()
{
	int _number_of_active_conextions = 0 ;

	for ( int iterator = 0 ; iterator < _number_of_conextions ; ++ iterator )
	{
		if ( _conextions [iterator] != nullptr )
		{
			++ _number_of_active_conextions ;
		}
	}

	return _number_of_active_conextions ;
}

template < class T >
T node <T> :: data ()
{
	return _data ;
}

template < class T >
node <T> * & node <T> :: next ()
{
	if ( _number_of_conextions < 3 && _number_of_conextions > 0 )
	{
		return _conextions [0] ;
	}

	return node <T> ** = new (std :: nothrow) node <T> * ;
}

template < class T >
node <T> * & node <T> :: before ()
{
	if ( _number_of_conextions == 2 )
	{
		return _conextions [1] ;
	}

	return node <T> ** = new (std :: nothrow) node <T> * ;
}

template < class T >
int node <T> ::  add_left ( T & data )
{
	if ( _conextions [0] == nullptr )
	{
		_conextions [0] = new (std :: nothrow) node <T> * ( nullptr , nullptr , _conextions [0] , data ) ;

		if ( _conextions [0] == nullptr )
		{
			return 1 ;
		}
	}
	else
	{
		node <T> * auxiliar = _conextions [0] ;
		
		_conextions [0] = new (std :: nothrow) node <T> ( auxiliar , nullptr , auxiliar->parent () ) ;

		if ( _conextions [0] == nullptr )
		{
			_conextions [0] = auxiliar ;

			return 1 ;
		}

		auxiliar->parent () = _conextions [0] ;
	}
	
	return 0 ;
}

template < class T >
int node <T> :: add_right ( T & data )
{
	if ( _conextions [1] == nullptr )
	{
		_conextions [1] = new (std :: nothrow) node <T> * ( nullptr , nullptr , _conextions [0] , data ) ;

		if ( _conextions [1] == nullptr )
		{
			return 1 ;
		}
	}
	else
	{
		node <T> * auxiliar = _conextions [1] ;
		
		_conextions [1] = new (std :: nothrow) node <T> ( auxiliar , nullptr , auxiliar->parent () ) ;

		if ( _conextions [1] == nullptr )
		{
			_conextions [1] = auxiliar ;

			return 1 ;
		}

		auxiliar->parent () = _conextions [1] ;
	}
	
	return 0 ;
}

template < class T >
node <T> * & node <T> :: left ()
{
	if ( _number_of_conextions == 3 )
	{
		return _conextions [0] ;
	}

	return node <T> ** = new (std :: nothrow) node <T> * ;
}

template < class T >
node <T> * & node <T> :: right ()
{
	if ( _number_of_conextions == 3 )
	{
		return _conextions [1] ;
	}

	return node <T> ** = new (std :: nothrow) node <T> * ;
}

template < class T >
node <T> * & node <T> :: parent ()
{
	if ( _number_of_conextions == 3 )
	{
		return _conextions [2] ;
	}

	return node <T> ** = new (std :: nothrow) node <T> * ;
}

template < class T >
T node <T> :: set_data ( T & data )
{
	_data = data ;

	return data ;
}

template < class T >
int node <T> :: new_conextion ()
{
	node <T> ** _backup = new (std :: nothrow) node <T> * [_number_of_conextions + 1] ;
	
	if ( _backup == nullptr )
	{
		return 1 ;
	}

	for ( int iterator = 0 ; iterator < _number_of_conextions ; ++ iterator )
	{
		_backup [iterator] = _conextions [iterator] ;
	}

	_backup [_number_of_conextions] = nullptr ;

	++ _number_of_conextions ;

	delete [] _conextions ;

	_conextions = _backup ;

	return 0 ;
}

template < class T >
int node <T> :: new_conextion ( node <T> * ptr )
{
	node <T> ** _backup = new (std :: nothrow) node <T> * [_number_of_conextions + 1] ;
	
	if ( _backup == nullptr )
	{
		return 1 ;
	}

	for ( int iterator = 0 ; iterator < _number_of_conextions ; ++ iterator )
	{
		_backup [iterator] = _conextions [iterator] ;
	}

	_backup [_number_of_conextions] = ptr ;

	++ _number_of_conextions ;

	delete [] _conextions ;

	_conextions = _backup ;

	return 0 ;
}

template < class T >
void node <T> :: clear_conextions ()
{
	int iterator_2 = 0 ;
	int _number_of_active_conextions = this->active_conextions () ;

	if ( _number_of_conextions == 0 )
	{
		return ;
	}

	node <T> ** _backup = new (std :: nothrow) node <T> * [_number_of_active_conextions] ;

	if ( _backup == nullptr )
	{
		return ;
	}

	for ( int iterator = 0 ; iterator < _number_of_conextions ; ++ iterator )
	{
		if ( _conextions [iterator] != nullptr )
		{
			_backup [iterator_2] = _conextions [iterator] ;
			++ iterator_2 ;
		}
	}

	delete _conextions ;

	_conextions = _backup ;

	_number_of_conextions = _number_of_active_conextions ;
}

template < class T >
node <T> * & node <T> :: operator [] ( int index )
{
	if ( index > _number_of_conextions || index < 0 )
	{
		node <T> ** ptr = new (std :: nothrow) node <T> * ;
		return * ptr ;
	}
	
	return _conextions [index] ;
}

template < class T >
T node <T> :: operator * ()
{
	return _data ;
}

template < class T >
node <T> :: ~node ()
{
	_number_of_conextions = 0 ;
	delete [] _conextions ;
}

#endif

#ifndef _LIST_H
#define _LIST_H

#include "node.h"

template < class T >
class list
{
	private :
		
		node <T> * first ;
		int size ;

	public :

		list () ;
		list ( int elements ) ;
		list ( int elements , T & fill );

		node <T> * LastNode () ;
		node <T> * FirstNode () ;

		int Lenght () ;
		
		T ReturnN ( int element );
		T ReturnLast () ;
		T ReturnFirst () ;

		int Add_ATB () ;
		int Add_ATB ( T & data ) ;
		int Add_ATE () ;
		int Add_ATE ( T & data ) ;

		void Delete_ATB () ;
		void Delete_ATE () ;
		
		void Delete () ;
} ;

template < class T >
list <T> :: list ()
{
	first = nullptr ;
	size = 0 ;
}

template < class T >
list <T> :: list ( int elements )
{
	if ( elements < 0 )
	{
		return ;
	}

	node <T> * auxiliar = nullptr ;

	for ( int iterator = 0 ; iterator < elements ; ++ iterator )
	{
		auxiliar = new (std :: nothrow) node <T> ( auxiliar ) ;

		if ( auxiliar == nullptr )
		{
			node <T> * temporary ;

			while ( aux->next () != nullptr )
			{
				temporary = auxiliar ;
				auxiliar = auxiliar->next () ;
				delete temporary ;
			}

			delete auxiliar ;

			first = nullptr ;

			size = 0 ;

			return ;
		}
	}

	first = auxiliar ;

	size = elements ; 
}

template < class T >
list <T> :: list ( int elements , T & fill )
{
	if ( elements < 0 )
	{
		return ;
	}

	node <T> * auxiliar = nullptr ;

	for ( int iterator = 0 ; iterator < elements ; ++ iterator )
	{
		auxiliar = new (std :: nothrow) node <T> ( true , auxiliar , fill ) ;

		if ( auxiliar == nullptr )
		{
			node <T> * temporary ;

			while ( aux->next () != nullptr )
			{
				temporary = auxiliar ;
				auxiliar = auxiliar->next () ;
				delete temporary ;
			}

			delete auxiliar ;

			fill = nullptr ;

			size = 0 ;

			return ;
		}
	}

	fill = auxiliar ;

	size = elements ;
}

template < class T >
node <T> * list <T> :: FirstNode ()
{
	return first ;
}

template < class T >
node <T> * list <T> :: LastNode ()
{
	node <T> * auxiliar = first ;

	if ( auxiliar != nullptr )
	{
		for ( ; auxiliar->next () != nullptr ; auxiliar = auxiliar->next () ) ;
	}

	return auxiliar;
}

template < class T >
int list <T> :: Lenght ()
{
	return size ;
}

template < class T >
T list <T> :: ReturnN ( int element )
{
	node <T> * auxiliar = first ;

	if ( auxiliar != nullptr )
	{
		for ( int iterator = 1 ; iterator < element ; ++ iterator )
		{
			if ( auxiliar->next () == nullptr )
			{
				auxiliar = nullptr ;

				break ;
			}

			auxiliar = auxiliar->next ();
		}
	}

	if ( auxiliar == nullptr )
	{
		return T () ;
	}

	return auxiliar->data () ;
}

template < class T >
T list <T> :: ReturnLast ()
{
	node <T> * auxiliar = LastNode () ;

	if ( auxiliar == nullptr )
	{
		return T () ;
	}

	return auxiliar->data () ;
}

template < class T >
T list <T> :: ReturnFirst ()
{
	node <T> * auxiliar = first ;

	if ( auxiliar == nullptr )
	{
		return T () ;
	}

	return auxiliar->data () ;
}

template < class T >
int list <T> :: Add_ATB ()
{
	node <T> * auxiliar = first ;
	first = new (std :: nothrow) node <T> ;

	if ( first == nullptr )
	{
		first = auxiliar ;

		return 1 ;
	}

	first->next () = auxiliar;

	++ size;

	return 0 ; 
}

template < class T >
int list <T> :: Add_ATB ( T & data )
{
	node <T> * auxiliar = first ;
	first = new (std :: nothrow) node <T> ( true , data ) ;

	if ( auxiliar != nullptr )
	{
		first->next () = auxiliar ;

		return 1 ;
	}

	++ size ;

	return 0 ;
}

template < class T >
int list <T> :: Add_ATE ()
{
	node <T> * auxiliar = LastNode () ;
	
	if ( auxiliar == nullptr )
	{
		first = new (std :: nothrow) node <T> ;

		if ( first == nullptr )
		{
			return 1 ;
		}
	}
	else
	{
		auxiliar->next () = new (std :: nothrow) node <T> ;

		if ( auxiliar->next () == nullptr )
		{
			return 1 ;
		}
	}

	++ size ;

	return 0 ;
}

template < class T >
int list <T> :: Add_ATE ( T & data )
{
	node <T> * auxiliar = LastNode () ;

	if ( auxiliar == nullptr )
	{
		first = new (std :: nothrow) node <T> ( true , data ) ;

		if ( first == nullptr )
		{
			return 1 ;
		}
	}
	else
	{
		auxiliar->next () = new (std :: nothrow) node <T> ( true , data ) ;

		if ( auxiliar->next () == nullptr )
		{
			return 1 ;
		}
	}

	++ size ;

	return 0 ;
}

template < class T >
void list <T> :: Delete_ATB ()
{
	node <T> * auxiliar = first ;

	if ( auxiliar != nullptr )
	{
		auxiliar = auxiliar->next () ;
		delete first ;
		first = auxiliar ;
		-- size ;
	}
}

template < class T >
void list <T> :: Delete_ATE ()
{
	node <T> * auxiliar = first ;

	if ( auxiliar != nullptr )
	{
		for ( ; auxiliar->next () != nullptr ; auxiliar = auxiliar->next ()) ;
		delete auxiliar ;
		-- size ;
	}
}

template < class T >
void list <T> :: Delete ()
{
	node <T> * auxiliar = first ;

	while ( first != nullptr )
	{
		auxiliar = auxiliar->next () ;
		delete first ;
		first = auxiliar ;
	}
}

#endif


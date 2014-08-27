From apache@acm.uva.es Sun Feb 20 09:53:47 2005
Received: from acm.localnet (web.localnet [192.168.10.200])
	by acm.uva.es (8.11.6/8.11.6) with ESMTP id j1K8rll10053
	for <judge@juez.localnet>; Sun, 20 Feb 2005 09:53:47 +0100
Received: by acm.localnet (Postfix)
	id E0C9C10B22; Sun, 20 Feb 2005 09:53:46 +0100 (CET)
Delivered-To: judge@acm.uva.es
Received: by acm.localnet (Postfix, from userid 81)
	id DBD1910B11; Sun, 20 Feb 2005 09:53:46 +0100 (CET)
To: judge@acm.uva.es
Subject: Problem 10196
From: nobody@nobody.acm.uva.es
Reply-To: nobody@nobody.acm.uva.es
Message-Id: <20050220085346.DBD1910B11@acm.localnet>
Date: Sun, 20 Feb 2005 09:53:46 +0100 (CET)

/* @JUDGE_ID: 34556CP 10196 C++ "" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 202.80.160.49 - CRC: 218CEA50 **/
/** Date: 2005-02-20 09:53:46 +0100 **/

@BEGIN_OF_SOURCE_CODE
#include <stdio.h>
#include <ctype.h>

char b[8][8];

int check( int x, int y )
{
	if ( x < 0 || x > 7 ) return 0;
	if ( y < 0 || y > 7 ) return 0;
	return 1;
}

int Diagonal( int i, int j, char p, char q, char r )
{
	int x, y;
	for ( x = i - 1, y = j - 1; x > -1 && y > -1; --x, --y )
	{
		if ( islower( b[x][y] ) )
		{
			if ( r == 'k' )
				break;
			if ( b[x][y] == p || b[x][y] == q )
				return 1;
			else
				break;
		}
		if ( isupper( b[x][y] ) )
		{
			if ( r == 'K' )
				break;
			if ( b[x][y] == p || b[x][y] == q )
				return 1;
			else
				break;
		}
	}
	for ( x = i - 1, y = j + 1; x > -1 && y < 8; --x, ++y )
	{
		if ( islower( b[x][y] ) )
		{
			if ( r == 'k' )
				break;
			if ( b[x][y] == p || b[x][y] == q )
				return 1;
			else
				break;
		}
		if ( isupper( b[x][y] ) )
		{
			if ( r == 'K' )
				break;
			if ( b[x][y] == p || b[x][y] == q )
				return 1;
			else
				break;
		}
	}
	for ( x = i + 1, y = j - 1; x < 8 && y > -1; ++x, --y )
	{
		if ( islower( b[x][y] ) )
		{
			if ( r == 'k' )
				break;
			if ( b[x][y] == p || b[x][y] == q )
				return 1;
			else
				break;
		}
		if ( isupper( b[x][y] ) )
		{
			if ( r == 'K' )
				break;
			if ( b[x][y] == p || b[x][y] == q )
				return 1;
			else
				break;
		}
	}
	for ( x = i + 1, y = j + 1; x < 8 && y < 8; ++x, ++y )
	{
		if ( islower( b[x][y] ) )
		{
			if ( r == 'k' )
				break;
			if ( b[x][y] == p || b[x][y] == q )
				return 1;
			else
				break;
		}
		if ( isupper( b[x][y] ) )
		{
			if ( r == 'K' )
				break;
			if ( b[x][y] == p || b[x][y] == q )
				return 1;
			else
				break;
		}
	}
	return 0;
}

int HoVe( int i, int j, char p, char q, char r )
{
	int x, y;
	for ( x = i - 1, y = j; x > -1; --x )
	{
		if ( islower( b[x][y] ) )
		{
			if ( r == 'k' )
				break;
			if ( b[x][y] == p || b[x][y] == q )
				return 1;
			else
				break;
		}
		if ( isupper( b[x][y] ) )
		{
			if ( r == 'K' )
				break;
			if ( b[x][y] == p || b[x][y] == q )
				return 1;
			else
				break;
		}
	}
	for ( x = i + 1, y = j; x < 8; ++x )
	{
		if ( islower( b[x][y] ) )
		{
			if ( r == 'k' )
				break;
			if ( b[x][y] == p || b[x][y] == q )
				return 1;
			else
				break;
		}
		if ( isupper( b[x][y] ) )
		{
			if ( r == 'K' )
				break;
			if ( b[x][y] == p || b[x][y] == q )
				return 1;
			else
				break;
		}
	}
	for ( x = i, y = j - 1; y > -1; --y )
	{
		if ( islower( b[x][y] ) )
		{
			if ( r == 'k' )
				break;
			if ( b[x][y] == p || b[x][y] == q )
				return 1;
			else
				break;
		}
		if ( isupper( b[x][y] ) )
		{
			if ( r == 'K' )
				break;
			if ( b[x][y] == p || b[x][y] == q )
				return 1;
			else
				break;
		}
	}
	for ( x = i, y = j + 1; y < 8; ++y )
	{
		if ( islower( b[x][y] ) )
		{
			if ( r == 'k' )
				break;
			if ( b[x][y] == p || b[x][y] == q )
				return 1;
			else
				break;
		}
		if ( isupper( b[x][y] ) )
		{
			if ( r == 'K' )
				break;
			if ( b[x][y] == p || b[x][y] == q )
				return 1;
			else
				break;
		}
	}
	return 0;
}

int Knight( int i, int j, char p )
{
	if ( check( i - 2, j - 1 ) && b[i - 2][j - 1] == p )
		return 1;
	if ( check( i - 2, j + 1 ) && b[i - 2][j + 1] == p )
		return 1;
	if ( check( i + 2, j - 1 ) && b[i + 2][j - 1] == p )
		return 1;
	if ( check( i + 2, j + 1 ) && b[i + 2][j + 1] == p )
		return 1;
	if ( check( i - 1, j - 2 ) && b[i - 1][j - 2] == p )
		return 1;
	if ( check( i - 1, j + 2 ) && b[i - 1][j + 2] == p )
		return 1;
	if ( check( i + 1, j - 2 ) && b[i + 1][j - 2] == p )
		return 1;
	if ( check( i + 1, j + 2 ) && b[i + 1][j + 2] == p )
		return 1;
	return 0;
}

int Pawn( int i, int j, int a, char p )
{
	if ( check( i + a, j - 1 ) && b[i + a][j - 1] == p )
		return 1;
	if ( check( i + a, j + 1 ) && b[i + a][j + 1] == p )
		return 1;
	return 0;
}

int TakeInput()
{
	int i, j;
	for ( i = 0; i < 8; ++i )
		gets( b[i] );
	for ( i = 0 ; i < 8; ++i )
		for ( j = 0; j < 8; ++j )
			if ( b[i][j] != '.' )
				return 1;
	return 0;
}

void FindKing( int *x, int *y, char c )
{
	int i, j;
	for ( i = 0; i < 8; ++i )
		for ( j = 0; j < 8; ++j )
			if ( b[i][j] == c )
			{
				*x = i;
				*y = j;
				return;
			}
}

int main()
{
	int x, y, f, t = 1;
//	freopen( "a.in", "r", stdin );
	while ( TakeInput() )
	{
		getchar();
		printf( "Game #%d: ", t++ );
		// WHITE
		FindKing( &x, &y, 'K' );
		f = 1;
		if ( Diagonal( x, y, 'b', 'q', 'K' ) ) f = 0;
		if (     HoVe( x, y, 'r', 'q', 'K' ) ) f = 0;
		if (   Knight( x, y, 'n' )           ) f = 0;
		if (     Pawn( x, y, -1, 'p' )       ) f = 0;
		if ( !f )
		{
			printf( "white king is in check.\n" );
			continue;
		}
		// BLACK
		FindKing( &x, &y, 'k' );
		f = 1;
		if ( Diagonal( x, y, 'B', 'Q', 'k' ) ) f = 0;
		if (     HoVe( x, y, 'R', 'Q', 'k' ) ) f = 0;
		if (   Knight( x, y, 'N' )           ) f = 0;
		if (     Pawn( x, y, 1, 'P' )        ) f = 0;
		if ( !f )
		{
		       printf( "black king is in check.\n" );
		       continue;
		}
		printf( "no king is in check.\n" );
	}
	return 0;
}






@END_OF_SOURCE_CODE

#ifndef MESH_H
#define MESH_H




/* #define M_PI    3.14159265358979323846264338327950288 */




static float vertexDigit[] = {
	 0.,  0. ,      0.5,  0. ,      1.,  0. ,
	 0.,  0.5,      0.5,  0.5,      1.,  0.5,
	 0.,  1. ,      0.5,  1. ,      1.,  1. ,
	 0.,  1.5,      0.5,  1.5,      1.,  1.5,
	 0.,  2. ,      0.5,  2. ,      1.,  2. ,
};
static unsigned short elementDigit[12][12] = {
	{  0,  0,  0,     0,  0,  0,     0,  0,  0,     0,  0,  0 },
	{  1,  6,  3,     1,  2,  8,     6, 13, 12,     8, 11, 13 },
	{  1, 11, 10,     9, 11, 13,     0,  0,  0,     0,  0,  0 },
	{  0,  2,  3,     3, 11, 10,     9, 11, 13,     0,  0,  0 },
	{  0,  2,  4,     2,  5,  6,     6, 11, 14,    10, 14, 12 },
	{  2,  8,  7,     6,  8, 11,     6, 14, 13,     0,  0,  0 },
	{  1,  5,  3,     4,  5,  9,     9, 14, 12,     0,  0,  0 },
	{  0,  1,  5,     0,  7,  6,     5,  8,  7,     6, 13, 12 },
	{  0,  1, 14,     9, 14, 12,     0,  0,  0,     0,  0,  0 },
	{  0,  1,  5,     0,  7,  9,     5, 14,  7,     9, 14, 13 },
	{  1,  2,  8,     6,  7,  9,     7,  8, 14,     9, 14, 13 },
	{  1,  5,  3,     0,  0,  0,     0,  0,  0,     0,  0,  0 },
};


static float vertexPrimitive[] = 
	{ -0.5, -0.5,  0. ,      0.5, -0.5,  0. ,      0. ,  0.5,  0.  };
static unsigned short elementPrimitive[] = {0, 1 ,2};


static float vertexCube[] = {
	-1., -1.,  1.,     1., -1.,  1.,    -1.,  1.,  1.,     1.,  1.,  1.,
	-1., -1., -1.,     1., -1., -1.,    -1.,  1., -1.,     1.,  1., -1.,
};
static unsigned short elementCube[] = {
	0, 1, 3,    0, 3, 2,
	1, 5, 7,    1, 7, 3,
	3, 7, 6,    3, 6, 2,
	7, 5, 4,    7, 4, 6,
	6, 4, 0,    6, 0, 2,
	4, 5, 1,    4, 1, 0,
};




#endif
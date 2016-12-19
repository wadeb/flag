#include "GL_vector.h"
#include "Error.h"

#include <cmath>

using std::initializer_list;

//
// Default constructor to make a zero vector.
//
GL_vector::GL_vector()
{
	comps[0] = 0;
	comps[1] = 0;
	comps[2] = 0;
}

//
// Create the vector 3 input floats.
//
GL_vector::GL_vector(GLfloat x, GLfloat y, GLfloat z)
{
	comps[0] = x;
	comps[1] = y;
	comps[2] = z;
}

//
// Create the vector from an initializer_list.
//
GL_vector::GL_vector(initializer_list<GLfloat> list)
{
	int i = 0;
	for (auto it = list.begin(); it != list.end(); ++it) {
		comps[i++] = *it;
	}
}

//
// Read-only [] operator to index into the vector.
//
const GLfloat &GL_vector::operator[](int index) const
{
	index_check(index);
	return comps[index];
}

//
// Write-only [] operator to index into the vector.
//
GLfloat &GL_vector::operator[](int index)
{
	index_check(index);
	return comps[index];
}

//
// Compute and return the cross product of this vector and other.
//
GL_vector GL_vector::cross_product(const GL_vector &other) const
{
	return GL_vector(
		comps[1]*other.comps[2] - comps[2]*other.comps[1],
		comps[2]*other.comps[0] - comps[0]*other.comps[2],
		comps[0]*other.comps[1] - comps[1]*other.comps[0]
	);
}

//
// Compute and return the length of the the vector.
//
GLfloat GL_vector::length() const
{
	return sqrtf(comps[0]*comps[0] + comps[1]*comps[1] + comps[2]*comps[2]);
}

//
// Normalize the length of the vector.
//
void GL_vector::normalize()
{
	// TODO: Make sure to handle length of 0 case.
	GLfloat rlen = 1.0f/length();
	comps[0] *= rlen;
	comps[1] *= rlen;
	comps[2] *= rlen;
}

//
// Return true if both this and other have equal components.
//
bool GL_vector::operator==(const GL_vector &other) const
{
	for (int i = 0; i < 3; i++) {
		if (comps[i] != other.comps[i]) {
			return false;
		}
	}

	return true;
}

//
// Return true if this and other don't have equal components.
//
bool GL_vector::operator!=(const GL_vector &other) const
{
	return !(*this == other);
}

//
// Throws Error if index isn't a valid index into comps.
//
void GL_vector::index_check(int index) const
{
	if (index < 0 || index > 2) {
		throw Error("Error: Invalid index into GL_vector");
	}
}

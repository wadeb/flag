#ifndef GL_VECTOR_H
#define GL_VECTOR_H

#include <GL/glew.h>
#include <initializer_list>

// TODO: Consider implementing operator * and *= for cross product.
// TODO: Implement other common vector operations.

//
// Class that represents a 3D vector of GLfloats.
// Wade Bonkowski - 12/17/2016
//

class GL_vector {
public:
	// Default constructor that initializes the vector to 0.
	GL_vector();

	// Create the vector from 3 floats.
	GL_vector(GLfloat x, GLfloat y, GLfloat z);

	// Initialize the vector from an initializer list.
	GL_vector(std::initializer_list<GLfloat> list);

	// Read-only [] operator to index into the vector.
	const GLfloat &operator[](int index) const;

	// Write access [] operator to index into the vector.
	GLfloat &operator[](int index);

	// Compute and return the cross product of this and the other
	// GL_vector.
	GL_vector cross_product(const GL_vector &other) const;

	// Compute and return the length of the GL_vector.
	GLfloat length() const;

	// Normailize the length of the vector.
	void normalize();

	// Returns whether or not this and other are the same.
	bool operator==(const GL_vector &other) const;

	// Returns whether or not this and other are not the same.
	bool operator!=(const GL_vector &other) const;

	// Return a pointer to the array for use with OpenGL API.
	const GLfloat *array() const
	{ return comps; }

private:
	// Throw Error if index isn't valid index into GL_vector.
	void index_check(int index) const;

	// Represent the vector as an array of floats.
	GLfloat comps[3];

};

#endif // GL_VECTOR_H

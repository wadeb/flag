#include "../GL_vector.h"

#include <cassert>
#include <cmath>

//
// Test basic functionality for all of the GL_vector public functions.
// Wade Bonkowski - 12/18/2016
//

int main()
{
	// Test construction of GL_vector.
	GL_vector zero = GL_vector();
	for (int i = 0; i < 3; i++) {
		assert(zero[i] == 0);
	}

	GL_vector ascend(0, 1, 2);
	for (int i = 0; i < 3; i++) {
		assert(ascend[i] == i);
	}

	GL_vector list_ascend = {0, 1, 2};
	for (int i = 0; i < 3; i++) {
		assert(list_ascend[i] == i);
	}

	// Test cross product and equality operators.
	GL_vector cross_result = ascend.cross_product(ascend);
	assert(cross_result == zero);
	assert(!(cross_result != zero));

	// Test length() and normalize() functions.
	assert(ascend.length() < 2.23608f && ascend.length() > 2.23606f);
	ascend.normalize();
	assert(ascend[0] == 0);
	assert(ascend[1] == (1.0f/sqrtf(5.0f)));
	assert(ascend[2] == (2.0f/sqrtf(5.0f)));

	return 0;
}

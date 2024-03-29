// Author: Muhammad Tayab Soomro
// Student #: 11199539
// NSID: mts066
// Email: tayab.soomro@usask.ca

#ifndef _VECTOR_H
#define _VECTOR_H

// An Elem is single precision floating-point value
typedef float Elem;

// A Vector consists of vector's size and it's elements
typedef struct {
    VecSize size; // Number of elements in the vector
    Elem *elements; // Array of Elem for the vector.
} Vector;
// ... (Vector *v, uint8_t index, ...) {
//   ... v->elements[index] ...
// }



// alloc_vec:
// 	Allocates an empty Vector
// In:
// 	N/a
// Out:
// 	return -- Pointer to newly allocated Vector if successfull, NULL otherwise
// 	effect -- A new Vector is allocted to dynamic memory space.
Vector *alloc_vec(void);


// dealloc_vec:
// 	Deallocates a given Vector
// In:
// 	Vector != NULL
// Out:
// 	No return value
// 	effect -- Vector passed through param is safely deallocated from memory space.
void dealloc_vec(Vector *v);

// extend_vec:
// 	Extend Vector with specified Elem value
// In:
// 	Vector != NULL
// 	Elem
// Out:
// 	return  -- Vector including the new Elem value
//	effect -- Deallocates the given Vector and creates a new one with new Elem value added.
Vector *extend_vec(Vector *v,Elem value);

// print_vec:
// 	Prints the Vector *v  provided in param
// In:
// 	Vector != NULL
// 	v->elements != NULL
// 	v->size > 0
// Out:
// 	Return -- true if successful, false otherwise
// 	effect -- Vector is printed on the stdin
bool print_vec(Vector *v);

#endif _VECTOR_H

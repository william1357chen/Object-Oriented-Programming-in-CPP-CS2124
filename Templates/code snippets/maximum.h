// File: maximum.h

// We need the template header immediately before every
// template function.
template <class T>
// For the function maximum, the return type and the types
// for both the parameters are the same.
// Note that the "greater than" operator (i.e., operator>) *must* be 
// overloaded in any class that you want to use the maximum function on.
T maximum(const T& a, const T& b) {
	if (a > b)
		return a;
	else
		return b;
}
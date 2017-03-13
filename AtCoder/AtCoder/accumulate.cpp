template <class InputIterator, class T, class BinaryOperation>
T accumulate(InputIterator first, InputIterator last, T init,
	BinaryOperation binary_op) {
	while (first != last)
		init = binary_op(init, *first++);
	return init;
}

 #include "Serializer.hpp"

int	main()
{
	cout << sizeof(uintptr_t) << '\n';
	if (sizeof(void*) == 8)
		cout << "64-bit long pointer\n";
	else
		cout << "32-bit long pointer\n";

	Data		data = {0, 0};
	uintptr_t	ptr = reinterpret_cast<uintptr_t>(&data);
	cout << "Data address: " << ptr << "\n";
	// cout << "Data address: " << (unsigned long)&data << "\n";
	Data		*ret = Serializer::deserialize(Serializer::serialize(&data));
	uintptr_t	retptr = reinterpret_cast<uintptr_t>(ret);
	// cout << "Return pointer address: " << (unsigned long)ret << "\n";
	cout << "Return pointer address: " << retptr << "\n";
	return 0;
}

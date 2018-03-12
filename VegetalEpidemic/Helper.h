#ifndef HELPER_H
#define HELPER_H

class Helper {
public:
	Helper();
	template<typename Base, typename T>
	static bool instanceof(const T *ptr) {
		return dynamic_cast<const Base*>(ptr) != nullptr;
	}
};

#endif
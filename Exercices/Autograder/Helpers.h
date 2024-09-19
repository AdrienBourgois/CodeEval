#pragma once

#include <string>

template<typename T>
T ConvertFromString(const std::string& str)
{
	if constexpr (std::is_same_v<T, int>)
	{
		return std::stoi(str);
	}
	else if constexpr (std::is_same_v<T, float>)
	{
		return std::stof(str);
	}
	else if constexpr (std::is_same_v<T, std::string>)
	{
		return str;
	}
	return T();
}

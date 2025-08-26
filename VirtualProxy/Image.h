#pragma once
#include <string>

class Image
{
	std::string m_FileName;
protected:
	void SetFileName(const std::string& fileName);
public:
	Image() = default;
	Image(const std::string& fileName);

	const std::string& GetFileName() const;
	virtual ~Image() = default;
	virtual void Display() = 0;  // const in original example, and in all overriden
	virtual void Load() = 0;
	virtual void Load(const std::string& fileName) = 0;

};


#pragma once
class String
{
private:
	char* str;
	size_t length;

public:
	String();
	String(const String& other);
	String( String&& other) noexcept;
	String(const char* str);
	String(const char arr[], size_t size);

	~String();

	const char* GetString() const { return str ? str : ""; }
	size_t GetLenth() const { return length; }
	bool IsEmpty() const {return length == 0; }

	void SetString(const char* str);
	void SetString(const String& other);
	void SetString(const char arr[], size_t size);
};


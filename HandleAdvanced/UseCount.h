#pragma once

class UseCount
{
private:
	int* p = new int(1);
public:
	UseCount() = default;
	UseCount(UseCount const& u);
	bool Only() const;
	bool Reattach(UseCount const& u);
	bool MakeOnly();
	~UseCount();
};


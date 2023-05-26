struct Foo;
struct Bar;
struct Baz;

// Абстракція відвідувача
struct Visitor
{
	virtual void visit(Foo &ref) = 0;
	virtual void visit(Bar &ref) = 0;
	virtual void visit(Baz &ref) = 0;
	virtual ~Visitor() = default;
};
// Абстракція елемента
struct Element
{
	virtual void accept(Visitor &v) = 0;
	virtual ~Element() = default;
};
// Конкретні елементи
struct Foo : public Element
{
	void accept(Visitor &v) override
	{
		v.visit(*this);
	}
};
struct Bar : public Element
{
	void accept(Visitor &v) override
	{
		v.visit(*this);
	}
};
struct Baz : public Element
{
	void accept(Visitor &v) override
	{
		v.visit(*this);
	}
};
// Конкретний відвідувач
struct GetType : public Visitor
{
	string value;
	void visit(Foo &ref) override
	{
		value = "Foo";
	}
	void visit(Bar &ref) override
	{
		value = "Bar";
	}
	void visit(Baz &ref) override
	{
		value = "Baz";
	}
};
void main()
{
	Foo foo;
	Bar bar;
	Baz baz;
	Element *elements[] = { &foo, &bar, &baz };

	GetType visitor;
	for (auto elem : elements)
	{
		elem->accept(visitor);
		cout << visitor.value << endl;
	}
}

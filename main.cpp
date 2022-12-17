#include <sdk.hpp>

class EmptyComponent final : IComponent
{
private:
	ICore* core_ = nullptr;

public:
	// https://open.mp/uid
	PROVIDE_UID(/* UID GOES HERE */);

	StringView componentName() const override
	{
		return "Empty component";
	}

	SemanticVersion componentVersion() const override
	{
		return SemanticVersion(0, 0, 1, 0);
	}

	void onLoad(ICore* c) override
	{
		// Cache core, player pool here.
		core = c;
		c->printLn("Empty component loaded.");
	}

	void onInit(IComponentList* components) override
	{
	}

	void onReady() override
	{
		// Fire events here at earliest.
	}

	void onFree(IComponent* component) override
	{
	}

	~EmptyComponent()
	{
	}

	void free() override
	{
		delete this;
	}

	void reset() override
	{
	}
};

COMPONENT_ENTRY_POINT()
{
	return new EmptyComponent();
}
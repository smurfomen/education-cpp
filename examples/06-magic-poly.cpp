#include <memory>
#include <vector>
#include <iostream>
#include <string>
struct Drawable;
using document_t = std::vector<Drawable>;

template<typename T> void draw(const T& x);
struct A { };
void draw(const A& s);
void draw(const document_t& doc);

struct Drawable {
	struct iface {
		virtual ~iface() = default;
		virtual std::unique_ptr<iface> copy() const = 0;
		virtual void draw() const = 0;
	};

	template<typename T>
	struct impl_model final : iface {
		T data;
		impl_model(T x) : data(std::move(x))
		{ }

		std::unique_ptr<iface> copy() const override {
			return std::make_unique<impl_model>(*this);
		}

		void draw() const override {
			::draw(data);
		}
	};

	template<typename T>
	Drawable(T x) : self_(std::make_unique<impl_model<T>>(std::move(x)))
	{ }

	Drawable(const Drawable& x) : self_(x.self_->copy())
	{ }

	Drawable(Drawable&& x) noexcept = default;

	Drawable& operator=(Drawable x)
	{
		self_ = std::move(x.self_);
		return *this;
	}

	void draw() const {
		self_->draw();
	}

private:
	std::unique_ptr<iface> self_;
};

template<typename T> void draw(const T& x)
{
	std::cout << x << std::endl;
}

void draw(const document_t& doc)
{
	std::cout << "Begin Document" << std::endl;
	for (const auto& d : doc) {
		d.draw();
	}
	std::cout << "End Document" << std::endl;
}

void draw(const A& a)
{
	std::cout << "struct A {}" << std::endl;
}

int main() {
	document_t doc;
	doc.emplace_back(2);
	doc.emplace_back(5.3);
	doc.emplace_back("Hello");
	doc.emplace_back("World");
	doc.emplace_back(A{});
	doc.emplace_back(doc);

	/* magic */
	Drawable obj(doc);
	obj.draw();

	return 0;
}
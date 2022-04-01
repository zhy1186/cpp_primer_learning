#include <iostream>
#include <string>

class Quote {
 public:
  Quote() = default;
  Quote(const std::string& book, double sales_price)
      : book_no_(book), price_(sales_price) {}

  std::string isbn() const { return book_no_; }
  void debug() const {
    std::cout << "book_no_:" << book_no_ << "\tprice_:" << price_ << std::endl;
  }

  virtual double net_price(std::size_t n) const { return n * price_; }
  virtual ~Quote() = default;

 protected:
  double price_ = 0.0;

 private:
  std::string book_no_;
};

double print_total(std::ostream& os, const Quote item, std::size_t n) {
  double ret = item.net_price(n);
  os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret
     << std::endl;
  return ret;
}

class Bulk_quote : public Quote {
 public:
  Bulk_quote() = default;
  Bulk_quote(const std::string& book, double sales_price, std::size_t min_qty,
             double discount)
      : Quote(book, sales_price), min_qty_(min_qty), discount_(discount) {}

  void debug() const {
    Quote::debug();
    std::cout << "min_qty_: " << min_qty_ << "\tdiscount_: " << discount_
              << std::endl;
  }
  double net_price(std::size_t) const override;

 private:
  std::size_t min_qty_ = 0;
  double discount_ = 0.0;
};

double Bulk_quote::net_price(std::size_t n) const {
  if (n > min_qty_)
    return n * (1 - discount_) * price_;
  else
    return n * price_;
}

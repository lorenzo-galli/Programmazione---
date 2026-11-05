#include <cmath>
#include <iostream>
#include <string>
#include <vector>

class Loss {
public:
    virtual ~Loss() {}
    virtual double forward(double p, double t) const = 0;
    virtual std::string get_type() const = 0;
};

class MSELoss : public Loss {
public:
    double forward(double p, double t) const override {
        return (p - t) * (p - t);
    }
    std::string get_type() const override {
        return "MSELoss";
    }
};
// da completare: la classe AbsLoss, derivata
// pubblicamente da Loss, con due metodi:
// - double forward(double p, double t) const override,
//   che restituisce il valore assoluto di p - t;
// - std::string get_type() const override,
//   che restituisce "AbsLoss".

class AbsLoss : public Loss {

public:
    double forward(double p, double t) const override {
        return std::abs(p - t);
    }

    std::string get_type() const override {
        return "AbsLoss";
    }
};

int main() {
    std::vector<Loss*> losses;
    losses.push_back(new MSELoss());
    // scommentate quando AbsLoss è scritta:
    // losses.push_back(new AbsLoss());
    for (Loss* l : losses) {
        std::cout << l->get_type() << ": "
                  << l->forward(0.5, 1.0) << "\n";
    }
    for (Loss* l : losses) {
        delete l;
    }
    return 0;
}
class AbsLoss : public Loss {
public:
    double forward(double p, double t) const override {
        return std::abs(p - t);
    }
    std::string get_type() const override {
        return "AbsLoss";
    }
};

int main() {
    std::vector<Loss*> losses;
    losses.push_back(new MSELoss());
    losses.push_back(new AbsLoss());
    for (Loss* l : losses) {
        std::cout << l->get_type() << ": "
                  << l->forward(0.5, 1.0) << "\n";
    }
    for (Loss* l : losses) {
        delete l;
    }
    return 0;
}
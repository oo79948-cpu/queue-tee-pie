#include <array>
#include <string>

class Cutie {
  private:
    std::string description;
    int cuteness_rating;

  public:
    Cutie() {}

    Cutie(std::string description, int cuteness_rating) {
      this->description = description;
      this->cuteness_rating = cuteness_rating;
    }

    virtual std::string get_description() {
      return description;
    }
    virtual int get_cuteness_rating() {
      return cuteness_rating;
    }
};

class Puppy: public Cutie {
  public:
    Puppy(): Cutie("Puppy", 1) {}
};

class Kitty: public Cutie {
  public:
    Kitty(): Cutie("Kitty", 2) {}
};

class PygmyMarmoset: public Cutie {
  public:
    PygmyMarmoset(): Cutie("PygmyMarmoset", 3) {}
};

class QueueTees {
  private:
    static const int MAX_SIZE = 10;
    int index = -1;
    std::array<Cutie*, MAX_SIZE> cuties;
  public:
    void enqueue(Cutie *cutie);
    Cutie *dequeue();
    int size();
  int getMaxSize() { return MAX_SIZE; }
};

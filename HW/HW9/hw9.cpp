#include <iostream>
#include <memory>
#include <set>
#include <string>

class newString {
private:
  static std::allocator<char> alloc;
  char *elements;
  char *first_free;
  char *cap;

  void free();
  void reallocate();
  void chk_n_alloc() {
    if (size() == capacity())
      reallocate();
  }

public:
  newString();
  newString(const char *);
  ~newString();

  size_t size() const { return first_free - elements; }
  size_t capacity() const { return cap - elements; }
};

std::allocator<char> newString::alloc;

newString::newString() : elements(nullptr), first_free(nullptr), cap(nullptr) {}

newString::newString(const char *c_str) {
  auto data = alloc.allocate(strlen(c_str));
  elements = data;
  for (size_t i = 0; i < strlen(c_str); ++i) {
    alloc.construct(data++, c_str[i]);
  }
  first_free = cap = data;
}

newString::~newString() { free(); }

void newString::free() {
  if (elements) {
    for (auto p = first_free; p != elements;) {
      alloc.destroy(--p);
    }
    alloc.deallocate(elements, cap - elements);
  }
}

void newString::reallocate() {
  auto newcapacity = size() ? 2 * size() : 1;
  auto newdata = alloc.allocate(newcapacity);
  auto dest = newdata;
  auto elem = elements;
  for (size_t i = 0; i != size(); ++i) {
    alloc.construct(dest++, std::move(*elem++));
  }
  free();
  elements = newdata;
  first_free = dest;
  cap = elements + newcapacity;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Message;

class Folder {
public:
  Folder(const std::string &str = "") : name(str) {}
  void addMsg(Message *);
  void remMsg(Message *);
  void printMessages() const;

private:
  std::string name;
  std::set<Message *> messages;
};

class Message {
public:
  Message(const std::string &str = "") : contents(str) {}
  void save(Folder &);
  void remove(Folder &);
  std::string getContents() const { return contents; }

private:
  std::string contents;
  std::set<Folder *> folders;
};

void Folder::addMsg(Message *msg) { messages.insert(msg); }

void Folder::remMsg(Message *msg) { messages.erase(msg); }

void Folder::printMessages() const {
  std::cout << name << ":\n";
  for (const auto &msg : messages) {
    std::cout << "  Message: " << msg->getContents() << "\n";
  }
}

void Message::save(Folder &f) {
  folders.insert(&f);
  f.addMsg(this);
}

void Message::remove(Folder &f) {
  folders.erase(&f);
  f.remMsg(this);
}

int main() {
  // Creating messages
  Message m1("Hello");
  Message m2("How are you?");

  // Creating folders
  Folder f1("Folder 1");
  Folder f2("Folder 2");

  // Adding messages to folders
  m1.save(f1);
  m2.save(f1);
  m2.save(f2);

  // Printing messages in each folder
  f1.printMessages();
  f2.printMessages();

  printf(
      "\n////////////////////////////////////////////////////////////////////"
      "////////////////////////////\n");

  newString s1;
  newString s2("Hello, world!");

  std::cout << "Size of s1: " << s1.size() << std::endl;
  std::cout << "Capacity of s1: " << s1.capacity() << std::endl;

  std::cout << "Size of s2: " << s2.size() << std::endl;
  std::cout << "Capacity of s2: " << s2.capacity() << std::endl;
  return 0;
}

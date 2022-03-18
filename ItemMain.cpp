#include "Tool.hpp"
#include "NonTool.hpp"
#include <memory>

int main() {
    std::unique_ptr<Item> t = std::make_unique<Tool>(1, "axe", 1000);
    std::unique_ptr<Item> q = std::make_unique<NonTool>(1, "log", ItemType::Plank);
}

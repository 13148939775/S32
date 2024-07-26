
#ifndef HHT_DATAMANAGER_TREE_H
#define HHT_DATAMANAGER_TREE_H

#include <iostream>
#include <memory>
#include <vector>

#include "trigger/LogicToken.h"

namespace hht {
namespace datamanager {

struct LogicNode {
    Token mToken{TokenType::Unknown};

    std::unique_ptr<LogicNode> left{nullptr};
    std::unique_ptr<LogicNode> right{nullptr};

    LogicNode() noexcept = default;

    LogicNode(LogicNode&& rhs) noexcept = default;
    LogicNode(LogicNode const& rhs) noexcept = delete;

    LogicNode(TokenType const type) noexcept : mToken(type) {}
    LogicNode(Token const& t) noexcept : mToken(t) {}

    LogicNode& operator=(LogicNode&& rhs) noexcept = default;
    LogicNode& operator=(LogicNode const& rhs) noexcept = delete;

    ~LogicNode() noexcept = default;

    using Tokens = std::vector<Token>;

    static std::unique_ptr<LogicNode> parseExpression(Tokens const& tokens, std::size_t& current);
    static std::unique_ptr<LogicNode> parseOperation(Tokens const& tokens, std::size_t& current);
    static std::unique_ptr<LogicNode> parseParentheses(Tokens const& tokens, std::size_t& current);
    static std::unique_ptr<LogicNode> parseTerminator(Tokens const& tokens, std::size_t& current);

    static bool hasUnused(Tokens const& tokens, std::size_t const current) noexcept { return current < tokens.size(); }

    static std::unique_ptr<LogicNode> build(const std::string& expression);
};

}  // namespace datamanager
}  // namespace hht

#endif  // BOOLEVAL_TREE_HPP
#include "trigger/LogicNode.h"

#include <iostream>
#include <memory>

#include "glog/logging.h"

namespace hht {
namespace datamanager {

std::unique_ptr<LogicNode> LogicNode::parseExpression(Tokens const& tokens, std::size_t& current) {
    auto left{parseOperation(tokens, current)};

    if (hasUnused(tokens, current) && tokens[current].isNot(TokenType::LogicalOr)) {
        return left;
    }

    while (hasUnused(tokens, current) && tokens[current].is(TokenType::LogicalOr)) {
        ++current;
        auto logical_or{std::make_unique<LogicNode>(TokenType::LogicalOr)};

        auto right{parseOperation(tokens, current)};
        if (right == nullptr) {
            return nullptr;
        }

        logical_or->left = std::move(left);
        logical_or->right = std::move(right);
        left = std::move(logical_or);
    }

    return left;
}

std::unique_ptr<LogicNode> LogicNode::parseOperation(Tokens const& tokens, std::size_t& current) {
    auto left{parseParentheses(tokens, current)};

    if (left == nullptr) {
        left = parseTerminator(tokens, current);
    }

    if (left == nullptr) {
        return nullptr;
    }

    while (hasUnused(tokens, current) && tokens[current].is(TokenType::LogicalAnd)) {
        ++current;

        auto logical_and{std::make_unique<LogicNode>(TokenType::LogicalAnd)};

        auto right{parseParentheses(tokens, current)};

        if (right == nullptr) {
            right = parseTerminator(tokens, current);
        }

        if (right == nullptr) {
            return nullptr;
        }

        logical_and->left = std::move(left);
        logical_and->right = std::move(right);
        left = std::move(logical_and);
    }

    return left;
}

std::unique_ptr<LogicNode> LogicNode::parseParentheses(Tokens const& tokens, std::size_t& current) {
    if (!hasUnused(tokens, current)) {
        return nullptr;
    }

    if (tokens[current].is(TokenType::LP)) {
        ++current;
        auto expression{parseExpression(tokens, current)};
        if (!hasUnused(tokens, current)) {
            return nullptr;
        }

        if (tokens[current++].is(TokenType::RP)) {
            return expression;
        }
    }

    return nullptr;
}

std::unique_ptr<LogicNode> LogicNode::parseTerminator(Tokens const& tokens, std::size_t& current) {
    if (!hasUnused(tokens, current)) {
        return nullptr;
    }

    auto const& token{tokens[current++]};
    if (token.is(TokenType::Field)) {
        return std::make_unique<LogicNode>(token);
    } else {
        return nullptr;
    }
}

/**
 * Builds an expression tree by using a recursive descent parser method.
 */
std::unique_ptr<LogicNode> LogicNode::build(const std::string& expression) {
    auto const tokens{Token::tokenize(expression)};
    if (tokens.empty()) {
        LOG(ERROR) << "[LogicNode::build] tokens empty. Expression: " << expression << ".\n";
        return nullptr;
    }

    std::size_t current{0u};

    return parseExpression(tokens, current);
}

}  // namespace datamanager
}  // namespace hht
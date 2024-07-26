
#ifndef HHT_DATAMANAGER_TOKEN_H
#define HHT_DATAMANAGER_TOKEN_H

#include <algorithm>
#include <array>
#include <cstdint>
#include <string>
#include <vector>

namespace hht {
namespace datamanager {

/**
 * enum class TokenType
 *
 * Represents a token type. Supported types are logical operators, relational operators, parentheses and field.
 */
enum class TokenType : std::uint8_t {
    // Unknown token type
    Unknown,

    // Field key token type
    Field,

    // Logical AND operator token type
    LogicalAnd,

    // Logical OR operator token type
    LogicalOr,

    // Left parenthesis token type
    LP,

    // Right parenthesis token type
    RP
};

using TokenTypePair = std::pair<std::string, TokenType>;

static std::array<TokenTypePair, 10> keywords{
    TokenTypePair{"and", TokenType::LogicalAnd}, TokenTypePair{"AND", TokenType::LogicalAnd},
    TokenTypePair{"or", TokenType::LogicalOr},   TokenTypePair{"OR", TokenType::LogicalOr},
    TokenTypePair{"&&", TokenType::LogicalAnd},  TokenTypePair{"||", TokenType::LogicalOr},
    TokenTypePair{"&", TokenType::LogicalAnd},   TokenTypePair{"|", TokenType::LogicalOr},
    TokenTypePair{"(", TokenType::LP},           TokenTypePair{")", TokenType::RP}};

class Token {
public:
    Token() = default;

    Token(Token&& rhs) = default;
    Token(Token const& rhs) = default;

    Token(TokenType const type) : mType(type), mValue(toTokenKeyword(type)) {}

    Token(const std::string& value) : mType(toTokenType(value)), mValue(value) {}

    Token(TokenType const type, const std::string& value) : mType(type), mValue(value) {}

    Token& operator=(Token&& rhs) = default;
    Token& operator=(Token const& rhs) = default;

    bool operator==(Token const& rhs) const { return mType == rhs.mType && (mValue == rhs.mValue); }

    ~Token() = default;

    static std::string toTokenKeyword(TokenType type) {
        for (auto&& pair : keywords) {
            if (pair.second == type) {
                return pair.first;
            }
        }
        return {};
    };

    static TokenType toTokenType(const std::string& keyword) {
        for (auto&& pair : keywords) {
            if (pair.first == keyword) {
                return pair.second;
            }
        }
        return TokenType::Field;
    };

    /**
     * Sets the token type.
     *
     * @param type Token type
     */
    void type(TokenType const type) {
        if (type != mType) {
            mType = type;
            mValue = toTokenKeyword(type);
        }
    }

    /**
     * Gets the token type.
     *
     * @return Token type
     */
    TokenType type() const { return mType; }

    /**
     * Sets the token value.
     *
     * @param value Token value
     */
    void value(const std::string& value) {
        mType = toTokenType(value);
        mValue = value;
    }

    /**
     * Gets the token value.
     *
     * @return Token value
     */
    std::string value() const { return mValue; }

    /**
     * Checks whether the token is of the specified type.
     *
     * @return True if the token is of the specified type, false otherwise
     */
    bool is(TokenType const type) const { return mType == type; }

    /**
     * Checks whether the token is not of the specified type.
     *
     * @return True if the token is not of the specified type, false otherwise
     */
    bool isNot(TokenType const type) const { return mType != type; }

    /**
     * Checks whether the token is of the first or second specified type.
     *
     * @return True if the token is of the first or second specified type, false otherwise
     */
    bool isOneOf(TokenType const first, TokenType const second) const { return is(first) || is(second); }

    /**
     * Checks whether the token is one of the multiple specified types.
     *
     * @return True if the token is one of the multiple specified types, false otherwise
     */
    template <typename... MoreTokenType>
    bool isOneOf(TokenType const first, TokenType const second, MoreTokenType const... nth) const {
        return is(first) || isOneOf(second, nth...);
    }

    static bool isDelimiter(char c) {
        constexpr char lq = '(';
        constexpr char rq = ')';
        constexpr char ws = ' ';
        constexpr char char_or = '|';
        constexpr char char_and = '&';

        return c == lq || c == rq || c == ws || c == char_or || c == char_and;
    }

    static bool isWhitespace(char c) {
        constexpr char ws = ' ';
        return c == ws;
    }

    static std::vector<Token> tokenize(const std::string& expressions) {
        auto first = expressions.begin();
        auto last = expressions.end();

        auto it = first;

        std::vector<Token> result{};
        while (it != last) {
            it = std::find_if(first, last, isDelimiter);
            if (it == first) {
                if (!isWhitespace(*it)) {
                    result.emplace_back(std::string(it, it + 1));
                }
                it++;
                first++;
            } else if (it != last) {
                result.emplace_back(std::string(first, it));
                first = it;
            }
        }

        return result;
    };

private:
    TokenType mType{TokenType::Unknown};
    std::string mValue{};
};

}  // namespace datamanager
}  // namespace hht

#endif
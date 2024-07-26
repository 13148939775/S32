/*
 * @author 008196
 * @for application log interface, provide action rules
 * @version 0.1
 * @date 2023-02 ~ 2023-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef NODE_LOG_INTERFACE_H
#define NODE_LOG_INTERFACE_H

#include <string>

template <typename T>
class NodeLogInterface {
public:
    virtual std::shared_ptr<T> GetLogger() const = 0;
    virtual const std::string GetLoggerName() const = 0;
};

#endif /* NODE_LOG_INTERFACE_H */

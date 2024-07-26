#ifndef IOX_SOA_INTERFACE_H
#define IOX_SOA_INTERFACE_H

namespace HHT {
template <typename Service, typename T>
class ServerStub {
public:
    void GetServiceList();

    void GetAllMethods(Service& ser);

    bool WaitforConnect(Service);

    ServerStub& GetInstance()
    {
        static ServerStub sb;
        return sb;
    }

    int GetStatus(T&);

    bool SetProp(T&);
};
}

#endif /* IOX_SOA_INTERFACE_H */

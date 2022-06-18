#ifndef TP_FINAL_DUNE_GRUPO_1_REQUEST_H
#define TP_FINAL_DUNE_GRUPO_1_REQUEST_H

#include <vector>
#include <cstdint>

class Request {
protected:
public:
    virtual int getCommand() = 0;
    virtual std::vector<uint16_t> getData() = 0;
};


#endif //TP_FINAL_DUNE_GRUPO_1_REQUEST_H

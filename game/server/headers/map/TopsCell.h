#ifndef TOPSCELL_H_
#define TOPSCELL_H_

#include "ServerCell.h"

class TopsCell : public ServerCell {
public:
    explicit TopsCell(coordenada_t coord);
    int ground() override;
    unsigned int harvest() override;

    ~TopsCell() override = default;
};

#endif  // TOPSCELL_H_

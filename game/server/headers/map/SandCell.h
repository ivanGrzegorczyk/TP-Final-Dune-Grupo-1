#ifndef SANDCELL_H_
#define SANDCELL_H_

#include "ServerCell.h"

class SandCell : public ServerCell {
private:
    unsigned int spice;

public:
    SandCell(coordenada_t coord, unsigned int spice);
    int ground() override;
    bool receiveUnit() override;
};

#endif  // SANDCELL_H_
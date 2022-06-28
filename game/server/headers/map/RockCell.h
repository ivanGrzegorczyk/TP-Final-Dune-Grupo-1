#ifndef ROCKCELL_H_
#define ROCKCELL_H_

#include "ServerCell.h"

class RockCell : public ServerCell {
public:
    RockCell(coordenada_t coord);
    int ground() override;
    unsigned int harvest() override;
};

#endif  // ROCKCELL_H_

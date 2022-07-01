#ifndef CLIFFSCELL_H_
#define CLIFFSCELL_H_

#include "ServerCell.h"

class CliffsCell : public ServerCell {
public:
    explicit CliffsCell(coordenada_t coord);
    int ground() override;
    unsigned int harvest() override;

    ~CliffsCell() override = default;
};

#endif  // CLIFFSCELL_H_

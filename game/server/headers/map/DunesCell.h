#ifndef DUNESCELL_H_
#define DUNESCELL_H_

#include "ServerCell.h"

class DunesCell : public ServerCell {
public:
    explicit DunesCell(coordenada_t coord);
    int ground() override;
    unsigned int harvest() override;

    ~DunesCell() override = default;
};

#endif  // DUNESCELL_H_

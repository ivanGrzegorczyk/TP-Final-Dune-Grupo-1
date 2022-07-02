#ifndef TP_FINAL_DUNE_GRUPO_1_SDLENTITY_H
#define TP_FINAL_DUNE_GRUPO_1_SDLENTITY_H

class SdlEntity {
public:
    virtual void render() = 0;
    virtual void update() = 0;
    virtual bool contains(int x, int y) const = 0;
};

#endif //TP_FINAL_DUNE_GRUPO_1_SDLENTITY_H

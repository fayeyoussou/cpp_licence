//
// Created by youssoupha faye on 08/01/2026.
//

#pragma once

class Vivant {
private:
    int poid;
    public:
    int getPoid() const;
    void setPoid(int poid);
    virtual void bouger();
    Vivant(int poid);

};



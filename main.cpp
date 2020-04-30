//
//  main.cpp
//  TSC_Labo04_00405016
//
//  Created by Mario Muñoz on 4/30/20.
//  Copyright © 2020 Mario Muñoz. All rights reserved.
//

#include <iostream>
#include "math_tools.h"
#include "classes.h"
#include "display_tools.h"
#include "tools.h"
#include "sel.h"


int main()
{
    vector<Matrix> localKs;
    vector<Vector> localbs;
    Matrix K;
    Vector b;
    Vector T;

    mesh m;
    leerMallayCondiciones(m);

    crearSistemasLocales(m,localKs,localbs);
    
    zeroes(K,m.getSize(NODES)*2);
    zeroes(b,m.getSize(NODES)*2);
    ensamblaje(m,localKs,localbs,K,b);
    
    applyDirichlet(m,K,b);

    showMatrix(K);

    return 0;
}

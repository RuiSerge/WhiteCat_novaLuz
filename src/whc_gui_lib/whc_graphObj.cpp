#include "whc_graphObj.h"


//Initialisation des variables de classe
unsigned int whc_graphObj::c_nbr_ggo = 0 ;
unsigned int whc_graphObj::c_last_ggoId = 0 ;
/*
unsigned int graphicalObj::hasfocus_ggo = 0 ;
unsigned int graphicalObj::haskeyfocus_ggo = 0 ;
unsigned int graphicalObj::isflyover_ggo = 0 ;
unsigned int graphicalObj::prev_hasfocus_ggo = 0 ;
unsigned int graphicalObj::prev_haskeyfocus_ggo = 0 ;
unsigned int graphicalObj::prev_isflyover_ggo = 0 ;
*/

whc_graphObj::whc_graphObj( )
{
    ++ c_nbr_ggo;
    ++ c_last_ggoId;
    m_ggoId = c_last_ggoId;

    m_x = -1 ; //!< Member variable "m_x"
    m_y = -1 ; //!< Member variable "m_y"
}

whc_graphObj::whc_graphObj(int x, int y)
{
    ++ c_nbr_ggo;
    ++ c_last_ggoId;
    m_ggoId = c_last_ggoId;

    m_x = x ; //!< Member variable "m_x"
    m_y = y ; //!< Member variable "m_y"
}

whc_graphObj::~whc_graphObj()
{
    --c_nbr_ggo ;
}

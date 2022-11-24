#include "whc_container.h"

whc_container::whc_container()
{
	//ctor
	whc_graphObj();
	m_h = 0 ; //!< Member variable "m_h"
    m_w = 0 ; //!< Member variable "m_w"
    m_hasfocus = false ; //!< Member variable "m_hasfocus"
    m_isvisible = true ; //!< Member variable "m_isvisible"
    m_isflyover = false ; //!< Member variable "m_isflyover"
    m_haskeyfocus = false ; //!< Member variable "m_haskeyfocus")
}

whc_container::whc_container(int x, int y, int h, int w)
{
	//ctor
	whc_graphObj(x,y);
    m_h = h ; //!< Member variable "m_h"
    m_w = w ; //!< Member variable "m_w"
    m_hasfocus = false ; //!< Member variable "m_hasfocus"
    m_isvisible = false ; //!< Member variable "m_isvisible"
    m_isflyover = false ; //!< Member variable "m_isflyover"
    m_haskeyfocus = false ; //!< Member variable "m_haskeyfocus")
}

whc_container::~whc_container()
{
	//dtor
}

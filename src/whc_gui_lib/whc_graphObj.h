#ifndef graphicalObj_H
#define graphicalObj_H

#include <forward_list>
#include <whc_mouse.h>

class whc_graphObj
{
public:

    static unsigned int c_nbr_ggo ; 	//!< Class number of ggo active
    static unsigned int c_last_ggoId ; 	//!< Class number of ggo created : used to assign unique id number

    /** Default constructor */
    whc_graphObj();
    /** constructor */
    whc_graphObj(int x, int y);
    /** Default destructor */
    virtual ~whc_graphObj();

    /** == */
    bool operator==(whc_graphObj const& val) const
    {
        return (val.m_ggoId == m_ggoId) ;
    }
    /** Access name
    * \return The current value m_name
     */
    std::string Name()
    {
        return m_name;
    }
    /** Set name
     * \param val New value to set
     */
    void Name(std::string val)
    {
        m_name = val;
    }


    /** Access relative x position
    * \return The current value m_x
     */
    int x()
    {
        return m_x;
    }
    /** Set relative x position
     * \param val New value to set
     */
    void x(int val)
    {
        m_x = val;
    }
     /** Set  XX parent position
    * param val New value to set
     */
	void XX(int val)
    {
		m_XX=val;
	}
	int XX()
    {
		return m_XX;
	}
    /** Access relative y position
     * \return The current value of m_y
     */
    int y()
    {
        return m_y;
    }
    /** Set relative y position
     * \param val New value to set
     */
    void y(int val)
    {
        m_y = val;
    }
     /** Set  YY parent position
    * param val New value to set
     */
	void YY(int val)
    {
		 m_YY=val;
	}
	int YY()
    {
		 return m_YY;
	}
    /** Get m_ParentObj
     * \return Parent graphicalObj
     */
    void *ParentObj()
    {
        return m_ParentObj ;
    }

    /** Set m_ParentObj
     * \param val New value to set
     */
    void ParentObj(whc_graphObj *val)
    {
        m_ParentObj = val;
    }

    /** Add a child graphicalObj at the list of the childs GraphObjects
     * \param val New graphicalObj
     */
    void AddChild(whc_graphObj &val)
    {
        whc_graphObj* a = this;
        val.ParentObj(a);   //ggo tree hierachy
        m_Child.push_back(val) ;
    }

    /** Remove a child graphicalObj from the list of the childs GraphObjects
     * \param val New graphicalObj
     */
//    void RemoveChild(whc_graphObj &val)
//    {
//        m_Child.remove(val) ;    //on laisse filer m_depth car peut probable que l'on supprime
//    }

    /** Remove a child graphicalObj from the list of the childs GraphObjects
     * \param val New graphicalObj
     */
    bool hasChild()
    {
        return (not m_Child.empty()) ;    //on laisse filer m_depth car peut probable que l'on supprime
    }

	/** Draw
     * \param none
     */
    void Draw(int X, int Y)
    {
    	m_XX=X+m_x; m_YY=Y+m_y;
    };

    /** list of childs in tree of graphical object */
    typedef std::vector<whc_graphObj> type_list_grObj;
    type_list_grObj m_Child;

protected:
	/** parent in tree of graphical object */
	std::string m_name;
    unsigned int m_ggoId ;
    int m_x; //!< Member variable "m_x"
    int m_y; //!< Member variable "m_y"
    int m_XX; //!< Member variable "m_XX"
    int m_YY; //!< Member variable "m_YY"
	whc_graphObj* m_ParentObj;

private:

}
;

#endif // graphicalObj_H

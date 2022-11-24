#ifndef CONTENEUR_H
#define CONTENEUR_H

#include <whc_graphObj.h>
#include <allegro/color.h>
#include <OpenLayer.hpp>

class whc_container : public whc_graphObj
{
	public:

	typedef enum
    {
        Aucun  = 0,
        Cadre  = 1,
        Relief = 2
    } whc_borderStyle ;

	/** Default constructor */
	whc_container();
	whc_container(int x, int y, int h, int w);
	/** Default destructor */
	virtual ~whc_container();

		whc_borderStyle BorderStyle()
		{
			return m_borderStyle;
		}
		void BorderStyle(whc_borderStyle  val)
		{
			m_borderStyle = val;
		}

  		ol::Rgba BackColor()
		{
			return m_backColor;
		}
		void BackColor(ol::Rgba val)
		{
			m_backColor = val;
		}

		ol::Rgba ForeColor()
		{
			return m_foreColor;
		}
		void ForeColor(ol::Rgba val)
		{
			m_foreColor = val;
		}

	/** Access height
     * \return The current value of m_h
     */
    unsigned int h()
    {
        return m_h;
    }
    /** Set height
     * \param val New value to set
     */
    void h(unsigned int val)
    {
        m_h = val;
    }
    /** Access width
     * \return The current value of m_w
     */
    unsigned int w()
    {
        return m_w;
    }
    /** Set width
     * \param val New value to set
     */
    void w(unsigned int val)
    {
        m_w = val;
    }
    /** Access m_hasfocus
     * \return The current value of m_hasfocus
     */
    bool hasfocus()
    {
        return m_hasfocus;
    }
    /** Set m_hasfocus
     * \param val New value to set
     */
    void hasfocus(bool val)
    {
        m_hasfocus = val;
    }
    /** Access m_isvisible
     * \return The current value of m_isvisible
     */
    bool isvisible()
    {
        return m_isvisible;
    }
    /** Set m_isvisible
     * \param val New value to set
     */
    void isvisible(bool val)
    {
        m_isvisible = val;
    }
    /** Access m_isflyover
     * \return The current value of m_isflyover
     */
    bool isflyover()
    {
        return m_isflyover;
    }
    /** Set m_isflyover
     * \param val New value to set
     */
    void isflyover(bool val)
    {
        m_isflyover = val;
    }
    /** Access m_haskeyfocus
     * \return The current value of m_haskeyfocus
     */
    bool haskeyfocus()
    {
        return m_haskeyfocus;
    }
    /** Set m_haskeyfocus
     * \param val New value to set
     */
    void haskeyfocus(bool val)
    {
        m_haskeyfocus = val;
    }
	void Draw(int X, int Y)
	{
		m_XX=X+m_x; m_YY=Y+m_y;
	}
	protected:
		/** */
		void getkeyfocus()
		{
			m_haskeyfocus = true;
		}
		/** lose key focus */
		void losekeyfocus()
		{
			m_haskeyfocus = false;
		}
		/** in case of Get focus  : function to be over */
		void getfocus()
		{
			m_hasfocus = true;
		}
		/** in case of lose focus */
		void losefocus()
		{
			m_hasfocus = false;
		}

		unsigned int m_h; //!< Member variable "m_h"
		unsigned int m_w; //!< Member variable "m_w"

		bool m_hasfocus; //!< Member variable "m_hasfocus"
		bool m_isvisible; //!< Member variable "m_isvisible"
		bool m_isflyover; //!< Member variable "m_isflyover"
		bool m_haskeyfocus; //!< Member variable "m_haskeyfocus"
		whc_borderStyle m_borderStyle; // exemple : Aucun, Cadre, Relief
		ol::Rgba m_backColor; // exemple : Control, Window, ...
		ol::Rgba m_foreColor; // exemple : ControlText, Control, Window, ...

	private:

};

#endif // CONTENEUR_H

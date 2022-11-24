#ifndef ETIQUETTE_H
#define ETIQUETTE_H

#include <whc_container.h>
#include <string.h>

class whc_label : public whc_container
{
	public:

	typedef enum
    {
        Aucun  = 0,
        Left  = 1,
        Center = 2
    } whc_textAlign ;

		/** Default constructor */
		whc_label();
		/** Default destructor */
		virtual ~whc_label();

		bool isUnderline(){return m_underline;}
		void setUnderline(bool val) {m_underline=val;}

		std::string Text()
		{
			return m_text;
		}
		void Text(std::string val)
		{
			m_text = val;
		}

		whc_textAlign TextAlign()
		{
			return m_textAlign;
		}
		void TextAlign(whc_textAlign  val)
		{
			m_textAlign = val;
		}

		ol::TextRenderer Font()
		{
			return m_font;
		}

		void Font(ol::TextRenderer val)
		{
			m_font = val;
		}

		void Font(const char *font, int xx, int yy)
		{
			m_font.Load(font, xx, yy, m_foreColor);
		}

		void Draw(int X, int Y)
		{
			m_XX=X+m_x; m_YY=Y+m_y;
			if( m_font )
			{
				m_font.SetColor(m_foreColor);
				m_font.Print(m_text,X+m_x, Y+m_y);
				if (m_underline)
				{
					ol::Line(ol::Vec2D(X+m_x,Y+m_y+3),ol::Vec2D(X+m_x+m_font.Width(m_text),Y+m_y+3)).Draw(m_foreColor);
				}
			}
		}

	protected:
		std::string m_text;
		whc_textAlign m_textAlign;
		ol::TextRenderer m_font;
		bool m_underline;

	private:
};

#endif // ETIQUETTE_H

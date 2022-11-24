#ifndef WHC_SWITCH_H
#define WHC_SWITCH_H

#include <whc_container.h>
#include <string.h>

class whc_switch : public whc_container
{
	public:

		std::map<int,ol::Bitmap> static map_switch_bmp;
		std::map<int,ol::Bitmap> static map_switch_label;


		/** Default constructor */
		whc_switch();
		/** Default destructor */
		virtual ~whc_switch();

		void init_map_switch_bmp();

	protected:

	private:
};

#endif // WHC_SWITCH_H

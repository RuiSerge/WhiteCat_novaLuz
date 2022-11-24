#ifndef WHC_POINT_H
#define WHC_POINT_H

class whc_point
{
	public:
		/** Default constructor */
		whc_point();
		whc_point(unsigned int xx, unsigned int yy);
		/** Default destructor */
		virtual ~whc_point();
		unsigned int x ;
		unsigned int y;
	protected:
	private:
};

#endif // WHC_POINT_H

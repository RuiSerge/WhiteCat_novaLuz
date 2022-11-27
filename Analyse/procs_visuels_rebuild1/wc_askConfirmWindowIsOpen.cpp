bool wc_askConfirmWindowIsOpen()
{
	bool f_bool = false;
	for(int i=0;i<63;i++)
	{
		if (window_opened[i]==W_ASKCONFIRM)
		{
			f_bool = true;
			break;
		}
	}
	return f_bool;
}

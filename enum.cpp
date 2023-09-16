#include "enum.h"

reg why_check_reg(int value)
{
	switch (value)
	{
	case 1:
		return reg::var_entry;
		break;
	case 2:
		return reg::var_sign_in;
		break;
	case 3:
		return reg::var_cancel;
		break;
	default:
		return reg::var_no_indef;
		break;
	}
}

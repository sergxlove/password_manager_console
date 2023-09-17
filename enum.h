#pragma once
#ifndef _ENUM_H_
#define _ENUM_H_
enum reg
{
	var_no_indef,
	var_entry,
	var_sign_in,
	var_cancel
};
enum pass
{
	var_no_in,
	var_check_pass,
	var_new_pass,
	var_exit
};
reg why_check_reg(int value);
pass why_check_pass(int value);
#endif // !_ENUM_H_


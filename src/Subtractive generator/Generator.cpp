/**
 * Filename: /home/luiscm/Rosetta Code/src/Subtractive generator/Generator.cpp
 * Path: /home/luiscm/Rosetta Code
 * Created Date: Thu Jun 08 2017
 * Author: luiscm
 * 
 * Copyright (c) 2017 Your Company
 */

#include "Generator.h"
#include <iostream>

namespace gen
{
	Generator::Generator(uint seed)
	{
		initialize(seed);
	}

	Generator::~Generator()
	{
		mState = std::vector<uint>();
	}

	void Generator::initialize(uint inSeed)
	{
		uint mod = 1e9;

		std::vector<uint> s, r;

		s.resize(55);
		r.resize(220);

		s[0] = inSeed;
		s[1] = 1;

		for (size_t i = 2; i < s.size(); i++)
		{
			s[i] = s[i-2] - s[i-1] % mod;
		}

		for (size_t i = 0; i < s.size(); i++)
		{
			r[i] = s[(34*i - 1) % 55];
		}


		for (size_t i = 55; i < 220; i++)
		{
			r[i] = r[i-55] - r[i-24] % mod;
		}

		mState.resize(56);

		for (size_t i = 0; i < 165; i++)
		{
			mState[i] = r[55+i];
		}
	}

	uint Generator::generate()
	{
		uint newNum = mState[0] - mState[30];

		for (size_t i = 0; i < 54; i++)
		{
			mState[i] = mState[i+1];
		}

		mState[55] = newNum;

		return newNum;
	}
}

/**
 * Filename: /home/luiscm/Rosetta Code/src/Subtractive generator/Generator.h
 * Path: /home/luiscm/Rosetta Code
 * Created Date: Thu Jun 08 2017
 * Author: luiscm
 * 
 * Copyright (c) 2017 Your Company
 */

#ifndef ROSETTA_CODE_GENERATOR_H
#define ROSETTA_CODE_GENERATOR_H

#include <vector>
#include <cstdlib>
#include <ctime>

namespace gen
{
	class Generator
	{
	public:
		Generator(uint seed);
		virtual ~Generator();

		/*
		 * Generate random numbers via subtractive algorithm
		 */
		uint generate(void);
	
	private:
		std::vector<uint> mState;

		void initialize(uint seed);
	};
}

#endif // ROSETTA_CODE_GENERATOR_H

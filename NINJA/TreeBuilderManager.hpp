/*
 * TreeBuilderManager.hpp
 *
 *  Created on: Feb 7, 2016
 *      Author: michel
 */

#include "ExceptionHandler.hpp"
#include "TreeNode.hpp"
#include "DistanceReader.hpp"
#include "SequenceFileReader.hpp"
#include "TreeBuilderBinHeap.hpp"
#include <stdlib.h>
#include "TreeBuilderExtMem.hpp"
#include "DistanceReaderExtMem.hpp"

class TreeBuilderManager {
	struct Float{
		float* pointer;
		int length;
	};
	public:

		enum InputType {alignment, distance};
		enum AlphabetType {dna, amino, null};
		enum CorrectionType {not_assigned, none, JukesCantor/*DNA*/, Kimura2/*DNA*/, FastTree /*amino*/};
		enum OutputType {dist, tree};

		TreeBuilderManager(std::string method, std::string njTmpDir, std::string inFile, FILE* outfile, InputType inType, OutputType outType, AlphabetType alphType, CorrectionType corrType, int threads, bool useSSE);

		std::string method;
		std::string njTmpDir;
		std::string inFile;
		FILE* outFile;
		std::string** names;
		//Float** inD;
		//int inDsize;
		InputType inType;
		OutputType outType;
		AlphabetType alphType;
		CorrectionType corrType;
		const static int NUM_RAND_DIR_CHARS = 6;
		std::string chars;
		int threads;

		bool newDistanceMethod;

		std::string doJob();
		static std::string getUniqueID();
		static bool deleteDir(FILE* dir);

};

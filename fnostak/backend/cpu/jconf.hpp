#pragma once

#include "fnostak/params.hpp"

#include <stdlib.h>
#include <string>

namespace fnostak
{
namespace cpu
{

class jconf
{
public:
	static jconf* inst()
	{
		if (oInst == nullptr) oInst = new jconf;
		return oInst;
	};

	bool parse_config(const char* sFilename = params::inst().configFileCPU.c_str());

	struct thd_cfg {
		int iMultiway;
		bool bNoPrefetch;
		long long iCpuAff;
	};

	size_t GetThreadCount();
	bool GetThreadConfig(size_t id, thd_cfg &cfg);
	bool NeedsAutoconf();

private:
	jconf();
	static jconf* oInst;

	struct opaque_private;
	opaque_private* prv;
};

} // namespace cpu
} // namepsace fnostak

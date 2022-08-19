#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include "Export.h"

class IBML;

class BML_EXPORT ICommand {
public:
	virtual std::string GetName() = 0;
	virtual std::string GetAlias() = 0;
	virtual std::string GetDescription() = 0;
	virtual bool IsCheat() = 0;

	virtual void Execute(IBML* bml, const std::vector<std::string>& args) = 0;
	virtual const std::vector<std::string> GetTabCompletion(IBML* bml, const std::vector<std::string>& args) = 0;

	static int ParseInteger(const std::string& str, int mn = INT_MIN, int mx = INT_MAX) {
		return 0;
	}

	static float ParseFloat(const std::string& str, float mn = FLT_MIN, float mx = FLT_MAX) {
		return 0.0;
	}

	static bool ParseBoolean(const std::string& str) {
		return false;
	}
};
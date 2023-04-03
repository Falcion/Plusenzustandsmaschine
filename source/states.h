#include <string>

using namespace std;

enum class states {
	unknown,
	failed,
	staged,
	skipped,
	processing,
	successful,
};

const states state_from_string(const string& state_name) {
	for (auto ch : state_name)
		ch = tolower(ch);

	if (state_name == "unknown")
		return states::unknown;
	else if (state_name == "failed")
		return states::failed;
	else if (state_name == "staged")
		return states::staged;
	else if (state_name == "skipped")
		return states::skipped;
	else if (state_name == "processing")
		return states::processing;
	else if (state_name == "successful")
		return states::successful;
	else
		throw exception("unknown given state's name: can't return any state");
}

const std::string to_string(const states& state) {
	switch (state) {
	case states::unknown:
		return "unknown";
	case states::failed:
		return "failed";
	case states::staged:
		return "staged";
	case states::skipped:
		return "skipped";
	case states::processing:
		return "processing";
	case states::successful:
		return "successful";
	}
}
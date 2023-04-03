#include <string>

using namespace std;

enum class shifts {
	begin,
	stage,
	resume,
	exit,
	stop,
};

const shifts shift_from_string(const string& shift_name) {
	for (auto ch : shift_name)
		ch = tolower(ch);

	if (shift_name == "begin")
		return shifts::begin;
	else if (shift_name == "stage")
		return shifts::stage;
	else if (shift_name == "resume")
		return shifts::resume;
	else if (shift_name == "exit")
		return shifts::exit;
	else if (shift_name == "stop")
		return shifts::stop;
	else
		throw exception("unknown given shifts's name: can't return any state");
}

const std::string to_string(const shifts& state) {
	switch (state) {
	case shifts::begin:
		return "begin";
	case shifts::stage:
		return "stage";
	case shifts::resume:
		return "resume";
	case shifts::exit:
		return "exit";
	case shifts::stop:
		return "stop";
	}
}
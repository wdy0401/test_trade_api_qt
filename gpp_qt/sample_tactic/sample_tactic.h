#ifdef SAMPLE_TACTIC
class _declspec(dllexport) tactic //������point
#else
class _declspec(dllimport) tactic //������point
#endif

class tactic
{
		tactic();
		void readquote(std::string);
		
};



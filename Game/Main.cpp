
#include "Core.h"

int main(void)
{
	Core& Core = Core::Instance();

	Core.Startup();
	Core.Run();
	Core.Shutdown();

	return EXIT_SUCCESS;
}

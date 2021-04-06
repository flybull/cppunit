#include <unistd.h>
#include "impl.h"

int main()
{
	impl_step(init);
	impl_step(start);
	sleep(1);
	impl_step(join);
	impl_step(stop);
	impl_step(uninit);

	return 0;
}




/*
 * Copyright (c) 1987 Fujitsu
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
/*
	main.c -- Top level of the Macross assembler.

	Chip Morningstar -- Lucasfilm Ltd.

	5-December-1984
*/

#include "macrossTypes.h"
#include "macrossGlobals.h"
#include "initialize.h"
#include "semanticMisc.h"
#include "y.tab.h"

#include <unistd.h>

int
main(int argc, char **argv)
{
#ifdef __APPLE__
	char end = get_end();
#else
	extern char	 end;
#endif

	fflush(stdout);
	initializeStuff(argc, argv);
	yyparse();
	finishUp();
	/* sbrk() ends up having different signatures depending on compiler
         * flags and system. We cast here out of an abundance of caution.
         * This, and the "end" variable above, are both just for this one
         * diagnostic, so if they're causing your build trouble, they can
         * be safely deleted. --mcm */
	if (emitPrint)
		printf("storage high water mark 0x%x == %d\n", (void *)sbrk(0) - (void *)(&end),
			(void *)sbrk(0) - (void *)(&end));
	if (errorFlag)
		chokePukeAndDie();
	return 0;
}

  void
printVersion(void)
{
	printf("Macross %s version 4.20.\n", TARGET_CPU_STRING);
}


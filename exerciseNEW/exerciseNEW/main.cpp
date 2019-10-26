#include <stdio.h>
#include <stdlib.h>
#include <time.h>



typedef float pnt[3];
void count(pnt const* pnts, const int n, unsigned cnt[8]) {
	for (int i = 0; i < 8; ++i)
		cnt[i] = 0;
	for (int i = 0; i < n; ++i)
		if (pnts[i][0] >= 0.0f && pnts[i][1] >= 0.0f && pnts[i][2] >= 0.0f) ++cnt[7]; else
			if (pnts[i][0] >= 0.0f && pnts[i][1] >= 0.0f && pnts[i][2] < 0.0f) ++cnt[3]; else
				if (pnts[i][0] >= 0.0f && pnts[i][1] < 0.0f && pnts[i][2] >= 0.0f) ++cnt[5]; else
					if (pnts[i][0] >= 0.0f && pnts[i][1] < 0.0f && pnts[i][2] < 0.0f) ++cnt[1]; else
						if (pnts[i][0] < 0.0f && pnts[i][1] >= 0.0f && pnts[i][2] >= 0.0f) ++cnt[6]; else
							if (pnts[i][0] < 0.0f && pnts[i][1] >= 0.0f && pnts[i][2] < 0.0f) ++cnt[2]; else
								if (pnts[i][0] < 0.0f && pnts[i][1] < 0.0f && pnts[i][2] >= 0.0f) ++cnt[4]; else
									++cnt[0];
}

void countWNoIf(pnt const* pnts, const int n, unsigned octs[8]) {
	for (int i = 0; i < 8; ++i)
		octs[i] = 0;			// Sets the number for each binary representation of the octagon. 
	// Most significant bit

	// Go through points individually from the array.
	for (int j = 0; j <= n; j++) {
		int x, y, z;
		size_t binVal = 0;	// Binary placeholder
		x = 0.0f < pnts[j][0]; // Extract x value
		y = 0.0f < pnts[j][1]; // Extract y value
		z = 0.0f < pnts[j][2]; // Extract z value

		binVal = (((x << 2) | (y << 1) | z));
		//printf("%d\n", binVal);	// For debug.
		// We know now what octagon is relevant for the points. 
		octs[binVal] += 1;
	}

}

//Function to populate points to point array.
void populatePoints(pnt* arr, const int points) {
	time_t t;
	srand((unsigned)time(&t));
	for (int i = 0; i <= points; i++) {
		for (int j = 0; j < 3; j++) {
			arr[i][j] = ((float)rand()) / ((float)RAND_MAX/2) - 1.0f;
		}
	}
}




int main() {
	const int n = 20;
	pnt* test = (pnt*)malloc(sizeof(pnt) * n);
	unsigned octs[8];
	populatePoints(test, n);
	count(test, n, octs);
	//countWNoIf(test, n, octs);
	free((void*)test);
	return 0;
}
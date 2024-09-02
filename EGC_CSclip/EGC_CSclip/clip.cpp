#include "clip.h"

namespace egc {

	std::vector<int> computeCSCode(std::vector<vec3> clipWindow, const vec3 p) {
		//TO DO - compute the code for the point given as argument
		
		std::vector<int> code(4, 0); //TBRL
		
		//top
		if (p.y < clipWindow[0].y) {
			code[0] = 1;
		}

		//bottom
		if (p.y > clipWindow[2].y) {
			code[1] = 1;
		}

		//right
		if (p.x > clipWindow[2].x) {
			code[2] = 1;
		}

		//left
		if (p.x < clipWindow[0].x) {
			code[3] = 1;
		}

		return code;
	}

	bool simpleRejection(std::vector<int> cod1, std::vector<int> cod2) {
		//TO DO - write the code to determine if the two input codes represent 
		//points in the SIMPLE REJECTION case

		for (int i = 0; i < cod1.size(); i++) {
			if (cod1[i] == 1 && cod2[i] == 1) {
				return true;
			}
		}

		return false;
	}

	bool simpleAcceptance(std::vector<int> cod1, std::vector<int> cod2) {
		//TO DO - write the code to determine if the two input codes represent 
		//points in the SIMPLE ACCEPTANCE case

		for (int i = 0; i < cod1.size(); i++) {
			if (cod1[i] == 1 || cod2[i] == 1) {
				return false;
			}
		}

		return true;
	}

	bool isInsideClippingArea(std::vector<int> code) {
		for (int i = 0; i < code.size(); i++) {
			if (code[i] == 1) {
				return false;
			}
		}

		return true;
	}

	//function returns -1 if the line segment cannot be clipped
	int lineClip_CohenSutherland(std::vector<vec3> clipWindow, vec3& p1, vec3& p2) {
		//TO DO - implement the Cohen-Sutherland line clipping algorithm - consult the laboratory work
		
		bool finised = true;

		int xMin = clipWindow[0].x;
		int xMax = clipWindow[2].x;
		int yMin = clipWindow[0].y;
		int yMax = clipWindow[2].y;

		while (finised) {
			std::vector<int> codeP1 = computeCSCode(clipWindow, p1);
			std::vector<int> codeP2 = computeCSCode(clipWindow, p2);

			if (simpleRejection(codeP1, codeP2)) {
				finised = false;
			}
			else {
				if (simpleAcceptance(codeP1, codeP2)) {
					finised = false;
				}
				else {
					if (isInsideClippingArea(codeP1)) {
						std::swap(p1, p2);
						std::swap(codeP1, codeP2);
					}
					if (codeP1[0] == 1 && p1.y != p2.y) {
						p1.x = p1.x + (p2.x - p1.x) * (yMin - p1.y) / (p2.y - p1.y);
						p1.y = yMin;
					}
					else if (codeP1[1] == 1 && p1.y != p2.y) {
							p1.x = p1.x + (p2.x - p1.x) * (yMax - p1.y) / (p2.y - p1.y);
							p1.y = yMax;
					}
					else if (codeP1[2] == 1 && p1.x != p2.x) { 
							p1.y = p1.y + (p2.y - p1.y) * (xMax - p1.x) / (p2.x - p1.x);
							p1.x = xMax;
					}
					else if (codeP1[3] == 1 && p1.x != p2.x) {
									p1.y = p1.y + (p2.y - p1.y) * (xMin - p1.x) / (p2.x - p1.x);
									p1.x = xMin;
					}
				}
			}
		}
		return 0;
	}
}
#include "types.h"

bool isValidGesture( tGestureType userGerture ) {
	if( GESTURE_START < userGerture && GESTURE_END > userGerture ) {
		return true;
	}
	else {
		return false;
	}
}
typedef enum gestureType{
	GESTURE_START,
	GESTURE_UP,
	GESTURE_DOWN,
	GESTURE_RIGHT,
	GESTURE_LEFT,
	GESTURE_END
}tGestureType;

bool isValidGesture( tGestureType userGerture );
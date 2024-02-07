import cv2
import dlib
import threading

# Initialize dlib's face detector and facial landmark predictor
detector = dlib.get_frontal_face_detector()
predictor = dlib.shape_predictor('shape_predictor_68_face_landmarks.dat')  # Download this file from http://dlib.net/files/shape_predictor_68_face_landmarks.dat.bz2

# Shared variables between threads
shared_frame = None
shared_adjusted_position = (0, 0)
running = True  # Shared variable to control thread execution

# Set the desired capture screen size
capture_width = 1280  # Set your desired width
capture_height = 720  # Set your desired height

# Open the video capture
cap = cv2.VideoCapture(0)
cap.set(3, capture_width)  # Set the width
cap.set(4, capture_height)  # Set the height

# Function to capture frames
def capture_frames():
    global shared_frame, running
    while running:
        ret, frame = cap.read()
        if not ret:
            break
        shared_frame = frame

# Function to process frames
def process_frames():
    global shared_frame, shared_adjusted_position, running
    while running:
        if shared_frame is not None:
            frame = shared_frame.copy()

            # Convert the frame to grayscale for face detection
            gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

            # Detect faces in the frame using dlib's detector
            faces = detector(gray)

            for face in faces:
                # Get the facial landmarks
                landmarks = predictor(gray, face)

                # Calculate the center of the face
                face_center_x = int((face.left() + face.right()) / 2)
                face_center_y = int((face.top() + face.bottom()) / 2)

                # Adjust coordinates to make the center of the screen (0, 0)
                adjusted_x = face_center_x - capture_width // 2
                adjusted_y = face_center_y - capture_height // 2

                # Update shared adjusted position
                shared_adjusted_position = (adjusted_x, adjusted_y)

                print(f"Adjusted Face Position: X={adjusted_x}, Y={adjusted_y}")

                # Draw a rectangle around the detected face
                cv2.rectangle(frame, (face.left(), face.top()), (face.right(), face.bottom()), (255, 0, 0), 2)

                # Draw facial landmarks
                for i in range(68):  # Assuming 68-point facial landmarks
                    x, y = landmarks.part(i).x, landmarks.part(i).y
                    cv2.circle(frame, (x, y), 1, (0, 255, 0), -1)

            # Display the frame with adjusted face position
            cv2.imshow('Face Tracking', frame)

            # Exit on 'q' key press
            if cv2.waitKey(1) & 0xFF == ord('q'):
                running = False  # Set the running variable to False
                break

# Start threads
capture_thread = threading.Thread(target=capture_frames)
process_thread = threading.Thread(target=process_frames)

capture_thread.start()
process_thread.start()

# Wait for threads to finish
capture_thread.join()
process_thread.join()

# Release the capture and close all windows
cap.release()
cv2.destroyAllWindows()

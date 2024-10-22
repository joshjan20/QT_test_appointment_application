# Qt Appointment Management Application

This project is a **Qt-based Appointment Management System** that allows users to manage bookings, cancellations, available slots, and records of appointments. The application features a graphical user interface (GUI) with buttons to interact with different functionalities, including viewing available slots, booking appointments, canceling appointments, and viewing appointment records.

## Features
- **Booking**: Users can book an appointment through the booking system.
- **Cancellation**: Users can cancel an existing appointment.
- **Available Slots**: Users can view available appointment slots.
- **Records**: Users can view records of all bookings.

## Prerequisites

- **Qt 5.x/6.x**: You will need Qt installed on your system (including `Qt Creator` or another IDE supporting Qt development).
- **C++ Compiler**: A C++ compiler like GCC (Linux), Clang (macOS), or MSVC (Windows).
- **CMake** (optional): If you're using a build system like CMake.

## Getting Started

### 1. Clone the Repository

```bash
git clone <repository-url>
cd <repository-name>
```

### 2. Build and Run the Project

#### Using Qt Creator:
1. Open `Qt Creator`.
2. Click on **Open File or Project** and select the `.pro` or `CMakeLists.txt` file.
3. Configure the project and click on **Build**.
4. Click **Run** to launch the application.

#### Using Command Line:
1. Navigate to the project directory.
2. Run `qmake` or `cmake` depending on your setup.
   ```bash
   qmake && make    # For qmake-based projects
   cmake . && make  # For cmake-based projects
   ```
3. Run the application:
   ```bash
   ./<app-executable>
   ```

## Project Structure

### `mainwindow.h` and `mainwindow.cpp`

The `MainWindow` class handles the main application window and its core functionalities. It contains several buttons that allow users to interact with the following features:
- **Booking**: Handled by `ptrBooking` (instance of `Booking` class).
- **Cancellation**: Handled by `ptrCancellation` (instance of `Cancellation` class).
- **Available Slots**: Handled by `ptrAvailableSlots` (instance of `Availableslots` class).
- **Records**: Handled by `ptrRecords` (instance of `Records` class).

Each of these buttons has an associated slot that is triggered when clicked, as described below.

### Main Functionalities:

#### 1. **Booking**
The `on_btnBooking_clicked()` method is triggered when the "Booking" button is clicked. This method populates booking data and displays the `Booking` window.

```cpp
void MainWindow::on_btnBooking_clicked() {
    ptrBooking->populateData();
    ptrBooking->show();
}
```

#### 2. **Cancellation**
The `on_btnCancellation_clicked()` method is triggered when the "Cancellation" button is clicked. It loads data for cancellations and displays the `Cancellation` window.

```cpp
void MainWindow::on_btnCancellation_clicked() {
    ptrCancellation->populateData();
    ptrCancellation->show();
}
```

#### 3. **Available Slots**
The `on_btnAvailableSlots_clicked()` method is triggered when the "Available Slots" button is clicked. It displays the available appointment slots in the `AvailableSlots` window.

```cpp
void MainWindow::on_btnAvailableSlots_clicked() {
    ptrAvailableSlots->populateData();
    ptrAvailableSlots->show();
}
```

#### 4. **Records**
The `on_btnRecords_clicked()` method is triggered when the "Records" button is clicked. It shows all booking records.

```cpp
void MainWindow::on_btnRecords_clicked() {
    ptrRecords->populateData();
    ptrRecords->show();
}
```

### `MainWindow Destructor`

The `MainWindow` destructor ensures proper cleanup of dynamically allocated objects and sets them to `nullptr` after deletion.

```cpp
MainWindow::~MainWindow() {
    delete ptrAvailableSlots; ptrAvailableSlots = nullptr;
    delete ptrBooking;        ptrBooking = nullptr;
    delete ptrCancellation;   ptrCancellation = nullptr;
    delete ptrRecords;        ptrRecords = nullptr;
    delete ui;
}
```

## How to Use

1. **Booking**: Click on the "Booking" button to book a new appointment.
2. **Cancellation**: Click on "Cancellation" to cancel an existing appointment.
3. **Available Slots**: Click on "Available Slots" to view open time slots for appointments.
4. **Records**: Click on "Records" to view the history of all bookings.

## Future Enhancements

- **Database Integration**: The project can be extended to connect to a database (like SQLite or MySQL) for persisting appointment data.
- **Notifications**: Add email or SMS notifications for appointment confirmation and reminders.
- **User Authentication**: Implement login and authentication features for different users (e.g., administrators and customers).


# Setup of Nginx

https://github.com/kode2go/nginx_webserver

# Setup of esp32

https://github.com/kode2go/esp32_home_power_management/wiki

Original Work:
https://github.com/kode2go/esp32_home_power_management/tree/main

# esp32_cloud_app_flow


This Flask app has several routes and functions for handling and displaying data:

get_csv_file_path(): This function generates the CSV file path based on the current date. It ensures that a directory named "data" exists and returns a path to a CSV file with the current date in its name.

/flask/rec (POST request): The receive_data() function is responsible for receiving data from a POST request. It assumes that data is sent as a form field named 'data' and appends this data along with a timestamp to a CSV file. If the CSV file doesn't exist, it creates one with a header.

/flask/get (GET request): The get_data() function reads data from the CSV file, converts the 'timestamp' column to a datetime data type, and then filters the DataFrame to include only the rows from the last 5 minutes. The filtered data is converted to JSON and returned.

/flask/history (GET and POST requests): The history() function handles both GET and POST requests. When accessed via a GET request, it lists the CSV files in the "data" directory and renders a template named 'history.html', which allows users to select a CSV file for further exploration. When accessed via a POST request, it loads the selected CSV file, filters the data to include every 10th row, converts it to JSON, and renders it in a template named 'show_data.html'.

/flask (GET request): The index() function is the root route of the application and renders an 'index.html' template.

This Flask app appears is designed for receiving, storing, and displaying data, especially for time-series data with timestamps. It provides a web interface for exploring historical data and viewing the most recent data points from the last 5 minutes. Users can access these functionalities through their web browser by visiting the specified routes.

    +----------------------------------+
    |           Flask Web App          |
    +----------------------------------+
                 |
                 |
                 v
       +-----------------------+
       |   API Route Diagram  |
       +-----------------------+
                 |
                 v
    +----------------------+    +----------------------+
    |   /flask/rec         |    |   /flask/get         |
    +----------------------+    +----------------------+
    |   Method: POST       |    |   Method: GET        |
    +----------------------+    +----------------------+
    |   Description:       |    |   Description:       |
    |   Receive data from  |    |   Get data within the|
    |   ESP32 device and   |    |   last 5 minutes.   |
    |   store it in a CSV |    +----------------------+
    |   file.              |    |   Response:          |
    +----------------------+    |   JSON containing   |
    |   Request Body:      |    |   data from the last |
    |   'data' field with  |    |   5 minutes.        |
    |   sensor data.       |    +----------------------+
    +----------------------+    |   Example Response:  |
    |   Response:          |    |   [{               |
    |   Success message.   |    |       "timestamp":  |
    +----------------------+    |       "2023-09-22   |
                               |       12:34:56",     |
                               |       "data": 123   |
                               |   }]                |
                               +----------------------+
                 |
                 v
    +----------------------+
    |   /flask/history     |
    +----------------------+
    |   Methods: GET, POST |
    +----------------------+
    |   Description:       |
    |   View historical    |
    |   data files and     |
    |   display data from |
    |   selected file.    |
    +----------------------+
    |   Request Method:    |
    |   POST              |
    +----------------------+
    |   Request Parameters:|
    |   'csv_file' field   |
    +----------------------+
    |   Response:          |
    |   Render HTML        |
    |   templates for      |
    |   data display.      |
    +----------------------+
                 |
                 v
    +----------------------+
    |   /flask             |
    +----------------------+
    |   Method: GET        |
    +----------------------+
    |   Description:       |
    |   Display the main   |
    |   index page.        |
    +----------------------+
    |   Response:          |
    |   Render HTML        |
    |   template.          |
    +----------------------+

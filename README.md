# esp32_cloud

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

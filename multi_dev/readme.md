# multi device

# Create index.html
created 3 plots now

3 update plots

3x fetch data

each fetch_data requests device name from server route:
/flask/get?device_name=$deviceName = "esp01"

3x fetch interval

# app.py

Create app.py
get_csv_file:
- dev_name with file name

/flask/rec

received_device_name = request.form.get('device_name')

/flask/get:

- now gets request for device name for JS, either esp01, esp02, or esp03

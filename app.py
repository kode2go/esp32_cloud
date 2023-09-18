import requests
import random


# Define the URL where you want to send the POST request
# url = 'http://34.29.140.126/flask/rec'
url = 'http://10.0.0.106:5000/flask/rec'

# Define the data to send in the POST request
# data_to_send = {'data': '4'}
random_number = random.randint(1, 100)
data_to_send = {'data': str(random_number)}
try:
    # Send the POST request
    response = requests.post(url, data=data_to_send)

    # Check the response
    if response.status_code == 200:
        print('POST request was successful!')
        print('Response content:')
        print(response.text)
    else:
        print('POST request failed with status code:', response.status_code)

except Exception as e:
    print('An error occurred:', str(e))

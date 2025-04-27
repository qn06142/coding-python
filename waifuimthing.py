import requests

url = 'https://api.waifu.im/tags'
params = {
}

response = requests.get(url, params=params)

if response.status_code == 200:
    data = response.json()
    print(data)
else:
    print('Request failed with status code:', response.status_code)

import urllib.request

def download_images(image_list):
    for filename, url in image_list:
        urllib.request.urlretrieve(url, filename)


image_list = [
    # ("image1.png", 'https://img.infoprice.by/256/4157/000004157/norm/000004157.n_1.png'),
    # ("image2.png", 'https://img.infoprice.by/256/6560/000006560/norm/000006560.n_1.png'),
    # ...
]

download_images(image_list)

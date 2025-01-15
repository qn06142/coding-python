import datetime
with open("ngiay.inp", "r") as f:
    s = int(f.read())

with open("ngiay.out", "w") as f:
    f.write((str(datetime.timedelta(seconds=s))))
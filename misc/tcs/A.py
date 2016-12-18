import sys
def ip_2_int(ip):
    ip_comp = ip.split('.')
    ip = (int(ip_comp[0]) << 24) | (int(ip_comp[1]) << 16) | (int(ip_comp[2]) << 8) | (int(ip_comp[3]))
    return ip
input = []
for line in sys.stdin:
    input.append(line.strip())
fname = input[0]
t = int(input[1])
ips = []

with open(fname) as f:
    for line in f:
        line = line.strip()
        if len(line) == 0:
            continue
        line = line.strip().split(',')[0]
        ip, subnet = line.split('/')
        subnet = 32 - int(subnet)
        ip = ip_2_int(ip)
        ips.append((ip >> subnet, subnet))

idx = 2
while t > 0:
    ip = ip_2_int(input[idx])
    for _ip,subnet in ips:
        if _ip == (ip >> subnet):
            sys.stdout.write('Yes')
            break
    else:
        sys.stdout.write('No')
    t -= 1
    if t > 0:
        sys.stdout.write('\n')
    idx += 1

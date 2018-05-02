import subprocess as sp

with open('../order', 'r') as of: for ff in of.readlines(): f =
ff.rstrip() print(f) sp.run(\['git', 'add', f\]) sp.run(\['git',
'commit', '-m', f\]) input()

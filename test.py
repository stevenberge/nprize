import os
path="input/training_set/"
bin_path="data/qualify.bin"
qualify_path="input/qualifying.txt"
users_path="data/users"

users={}
for movie in range(NMOVIES):
    if movie % 10==0: print movie
    fp=open(training_path+'mv_'+'%07d'%(movie+1)+'.txt')
    fmovie = None
    trainent=''
    traindat=''
    probeent=''
    probedat=''
    for line in fp:
        line=line.strip()
        if not fmovie:
            assert line.endswith(':')
            fmovie=int(line[:-1])
            assert fmovie-1==movie
            continue
        sline=line.split(',')
        user,rank,date=sline
        iuser=users[user]
        rank=int(rank)-1
        sdate=date.split('-')
        year,month,day=sdate
        year=int(year)-1998
        month=int(month)-1
        day=int(day)-1

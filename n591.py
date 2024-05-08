animal = "屬牛虎兔龍蛇馬羊猴雞狗豬"
try:
    while true:
        year = int(input())
        ind = (year) % 12
        print(animal[ind])
except:
    pass
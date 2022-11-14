import random,pandas
userword=[]
choosen_word_list=[]
mistake=False
Try=0
winner=False
loser=False
def open_csv_file():
    data=pandas.read_csv("all_countries.csv",header=None, names=["country"])
    return data
def get_countries_list():
    data=open_csv_file()
    countries_list=[row.country for (index,row) in data.iterrows()]
    return countries_list
def choose_random_word():
    global word,choosen_word_list
    countries_list=get_countries_list()
    word=random.choice(countries_list)
    return word
def turn_choosen_word_to_list(random_word):
    global choosen_word_list
    for letter in random_word:
        if letter==" ":
            pass
        else:
            choosen_word_list.append(letter)
def determine_the_len_of_userword():
    global choosen_word_list,userword
    for letter in choosen_word_list:
        userword.append("_")
def check_win():
    global choosen_word_list,userword,winner
    if userword==choosen_word_list:
        winner=True
        print("you win")
def check_lost():
    global loser,mistake,Try,choosen_word_list
    if mistake==True: 
        Try+=1
        mistake=False
    if Try==5:
        loser=True
        print("you lost")
        print(f"the word was {choosen_word_list}")
def Play():
    global winner,userword,choosen_word_list,loser,mistake
    random_word=choose_random_word().lower()
    turn_choosen_word_to_list(random_word)
    determine_the_len_of_userword()
    print(userword)
    m=0
    while winner==False and loser==False:
        usersLetter=input("enter a letter\n").lower()
        for x in range(len(choosen_word_list)):
            if usersLetter==choosen_word_list[x]:
                userword[x]=usersLetter
            else:
                m=m+1
                if m==len(choosen_word_list):
                    mistake=True
        m=0
        print(userword)
        check_lost()
        check_win()
        if winner==False and loser==False:
            print(f"you still have {5-Try} attempts")
Play()
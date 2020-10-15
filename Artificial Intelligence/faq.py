data=open("data.txt","r")
questions=data.read()
ques=questions.split('\n')
while 1:
    word=input("Enter your query word:")
    word=word.lower()
    if(word=='quit'):
        break
    for i in ques:
        if word in i:
            print(ques[ques.index(i)+1])
            break
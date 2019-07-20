import pdftotext

with open("testoutput.pdf", "rb") as f :
    pdf = pdftotext.PDF(f)


with open('test.txt', 'w') as f :
    f.write(" ".join(pdf))

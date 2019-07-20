from PyPDF2 import PdfFileMerger, PdfFileReader
import os

receiptdir = '/Users/singiyeol/Desktop/베다니/receiptMOD'
pdfs = os.listdir(receiptdir)

pdfs = [file for file in os.listdir(receiptdir) if file.endswith(".pdf")]

for pdff in pdfs :
    print(pdff)

merger = PdfFileMerger()

for pdf in pdfs :
    merger.append(PdfFileReader(pdf), 'rb')

with open("testoutput.pdf", "wb") as fout:
    merger.write(fout)


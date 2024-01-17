import tkinter as tk
from tkinter import ttk
import csv
import argparse
from enum import Enum



class ShotType(Enum):
        Tee = 1
        Approach = 2
        Pitch = 3
        Chip = 4
        Putt = 5

def process_command_line_arguments():
    parser = argparse.ArgumentParser(description='Description of your script.')

    # Define command-line arguments
    parser.add_argument('course', type=str, help='Course')
    parser.add_argument('gui', type=str, help='Gui')

    # Parse the command-line arguments
    args = parser.parse_args()

    # Access the parsed arguments
    return args.course, args.gui


def createGui(title):
    window = tk.Tk()
    window.title(title)
    return window

def labelFrame(window, text, row, colSpan):
    frame = ttk.LabelFrame(window, text=text)
    frame.grid(row=row, column=0, columnspan=colSpan, padx=10, pady=10, sticky=tk.W)
    return frame

def comboBox(stringList, frame, row, column, default=""):
    combobox = ttk.Combobox(frame, values=stringList, textvariable=tk.StringVar(value=default), state="readonly")
    combobox.grid(row=row, column=column, padx=10, pady=10)
    return combobox

def LabelEntry(frame, text, row):
    label = ttk.Label(frame, text=text)
    label.grid(row=row, column=0, sticky=tk.W)

    entry = ttk.Entry(frame)
    entry.grid(row=row, column=1, padx=10, pady=10)

    return label, entry

def sideCar(frame, row, str1, str2, text):
    _, combobox = labelCombobox(frame, text, row, str1)
    sidecar = comboBox(str2, frame, row, 2, "")
    return combobox, sidecar

      

def labelCheckbox(frame, text, row, col):
    var = tk.IntVar()

    # Create a Checkbutton
    checkbox = tk.Checkbutton(frame, text=text, variable=var)
    checkbox.grid(row = row, column = col, sticky=tk.W)

    return "label", var

def labelCombobox(frame, text, row, stringList, default=""):
    label = ttk.Label(frame, text=text)
    label.grid(row=row, column=0, sticky=tk.W)
    return label, comboBox(stringList, frame, row, 1, default)


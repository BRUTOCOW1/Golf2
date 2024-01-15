import sys
import tkinter as tk
from tkinter import ttk
import csv
import argparse
from enum import Enum


class GUI:
    def __init__(self, gui, course, hole):
        self.window = createGui(course+gui)
        self.hole = hole



class courseBuilder(GUI):
    def __init__(self, gui, course, hole):
        GUI.__init__(self, gui, course, hole)

class ShotType(Enum):
        Tee = 1
        Approach = 2
        Pitch = 3
        Chip = 4
        Putt = 5

class shot(GUI):
    def __init__(self, gui, course, hole, shot, sType):
        super().__init__(gui, course, hole)
        self.shot = shot
        self.sType = ShotType.Approach.value
        loftedShot(self.window)
        self.window.mainloop()

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

def tee(window):
    return 23

def putt(window):
    return 34

def labelFrame(window, text1, text2, row):
    frame = ttk.LabelFrame(window, text=text1)
    frame.grid(row=row, column=0, columnspan=2, padx=10, pady=10, sticky=tk.W)

    label = ttk.Label(frame, text=text2)
    label.grid(row=0, column=0, sticky=tk.W)
    return frame, label

def comboBox(stringList, frame, row):
    combobox = ttk.Combobox(frame, values=stringList, state="readonly")
    combobox.grid(row=row, column=1, padx=10, pady=10)
    return combobox

def LabelEntry(frame, text, row):
    label = ttk.Label(frame, text=text)
    label.grid(row=row, column=0, sticky=tk.W)

    entry = ttk.Entry(frame)
    entry.grid(row=row, column=1, padx=10, pady=10)

    return label, entry

def labelCombobox(frame, text, row, stringList):
    label = ttk.Label(frame, text=text)
    label.grid(row=row, column=0, sticky=tk.W)
    return label, comboBox(stringList, frame, row)


def loftedShot(window):

    shot_number_frame = ttk.LabelFrame(window, text="Shot #: ")
    shot_number_frame.grid(row=0, column=0, columnspan=2, padx=10, pady=10, sticky=tk.W)

    shot_number_label, shot_number_combobox = labelCombobox(shot_number_frame, "Shot #: ", 0, [str(i) for i in range(1, 19)])

    meta_frame = ttk.LabelFrame(window, text="Meta: ")
    meta_frame.grid(row=1, column=0, columnspan=2, padx=10, pady=10, sticky=tk.W)

    meta_high_level_label, high_level_combobox = labelCombobox(meta_frame, "High Level: ", 0, ["Tee", "Approach", "Pitch", "Bunker", "Chip", "Putt"])

    meta_lie_label, meta_lie_entry = LabelEntry(meta_frame, "Lie: ",1)

    meta_aim_label, meta_aim_entry = LabelEntry(meta_frame, "Aim",2)

    # Hist Section
    hist_frame = ttk.LabelFrame(window, text="Hist:")
    hist_frame.grid(row=2, column=0, columnspan=2, padx=10, pady=10, sticky=tk.W)

    hist_club_choice_label, hist_club_choice_entry = LabelEntry(hist_frame, "Club Choice: ", 0)

    hist_desc_label, hist_desc_entry = LabelEntry(hist_frame, "Desc: ", 1)
    
    hist_height_label, hist_height_entry = LabelEntry(hist_frame, "Height: ", 2)

    hist_shape_label, hist_shape_entry = LabelEntry(hist_frame, "Shape: ", 3)

    hist_direction_label, hist_direction_entry = LabelEntry(hist_frame, "Direction: ", 4)

    hist_distance_label, hist_distance_entry = LabelEntry(hist_frame, "Distance: ", 5)

    hist_end_location_label, hist_end_location_entry = LabelEntry(hist_frame, "End Location: ", 6)

    hist_rating_label, hist_rating_entry = LabelEntry(hist_frame, "Rating: ", 7)

    hist_blunders_label, hist_blunders_entry = LabelEntry(hist_frame, "Blunder(s): ", 8)

    # Create and place a submit button
    submitList = [shot_number_combobox, high_level_combobox, meta_lie_entry, meta_aim_entry,
           hist_club_choice_entry, hist_desc_entry, hist_height_entry, hist_shape_entry,
           hist_direction_entry, hist_distance_entry, hist_end_location_entry,
           hist_rating_entry, hist_blunders_entry]

    submit_button = ttk.Button(window, text="Submit", command=lambda: submit_button_clicked(submitList))

    submit_button.grid(row=3, column=0, columnspan=2, pady=20)

def submit_button_clicked(submitList):
    print("Submit button clicked")  # Add this line for debugging

    user_inputs = [submitList[i].get() for i in range(len(submitList))]
  
    print("Row to be written to CSV:", user_inputs)  # Add this line for debugging

    # Append the row to the CSV file
    with open("./arch/beep.csv", "a", newline='') as csvfile:
        csv_writer = csv.writer(csvfile)
        csv_writer.writerow(user_inputs)

    # Add this line for debugging


def main():
    course, gui = process_command_line_arguments()
    
    theShot = shot(gui, course, 1, 1, 1)
    print(theShot.shot)
    return 1
if __name__ == "__main__":
    sys.exit(main())

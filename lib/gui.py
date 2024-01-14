import sys
import tkinter as tk
from tkinter import ttk
import csv


class pop:
    def __init__(self):
        createGui()

        

def submit_button_clicked():
    # Retrieve user inputs

    #shot_number = shot_number_entry.get()
    shot_number = shot_number_combobox.get()

    
    meta_high_level = high_level_combobox.get()
    meta_lie = meta_lie_entry.get()
    meta_aim = meta_aim_entry.get()
    
    hist_club_choice = hist_club_choice_entry.get()
    hist_desc = hist_desc_entry.get()
    hist_height = hist_height_entry.get()
    hist_shape = hist_shape_entry.get()
    hist_direction = hist_direction_entry.get()
    hist_distance = hist_distance_entry.get()
    hist_end_location = hist_end_location_entry.get()
    hist_rating = hist_rating_entry.get()
    hist_blunders = hist_blunders_entry.get()

    # Format the information as a list
    row = [shot_number, meta_high_level, meta_lie, meta_aim,
           hist_club_choice, hist_desc, hist_height, hist_shape,
           hist_direction, hist_distance, hist_end_location,
           hist_rating, hist_blunders]

    # Append the row to the CSV file
    with open("./arch/SG.csv", "a", newline='') as csvfile:
        csv_writer = csv.writer(csvfile)
        csv_writer.writerow(row)


# Create the main window

def createGui(title):
    window = tk.Tk()
    window.title(title)
    return window

# Create and place entry widgets


def loftedShot(window):
    shot_number_frame = ttk.LabelFrame(window, text="Shot #:")
    shot_number_frame.grid(row=0, column=0, columnspan=2, padx=10, pady=10, sticky=tk.W)

    shot_number_label = ttk.Label(shot_number_frame, text="Shot X:")
    shot_number_label.grid(row=0, column=0, sticky=tk.W)

    shot_numbers = [str(i) for i in range(1, 19)]  # Options from 1 to 18
    shot_number_combobox = ttk.Combobox(shot_number_frame, values=shot_numbers, state="readonly")
    shot_number_combobox.grid(row=0, column=1, padx=10, pady=10)
    shot_number_combobox.set("1")  # Set default selection


    # Meta Section
    meta_frame = ttk.LabelFrame(window, text="Meta:")
    meta_frame.grid(row=1, column=0, columnspan=2, padx=10, pady=10, sticky=tk.W)

    meta_high_level_label = ttk.Label(meta_frame, text="High Level:")
    meta_high_level_label.grid(row=0, column=0, sticky=tk.W)

    high_levels = ["Tee", "Approach", "Pitch", "Bunker", "Chip", "Putt"]  # Options from 1 to 18
    high_levels.append("Custom")  # Add a custom option
    high_level_combobox = ttk.Combobox(meta_frame, values=high_levels, state="readonly")
    high_level_combobox.grid(row=0, column=1, padx=10, pady=10)

    meta_lie_label = ttk.Label(meta_frame, text="Lie:")
    meta_lie_label.grid(row=1, column=0, sticky=tk.W)

    meta_lie_entry = ttk.Entry(meta_frame)
    meta_lie_entry.grid(row=1, column=1, padx=10, pady=10)

    meta_aim_label = ttk.Label(meta_frame, text="Aim:")
    meta_aim_label.grid(row=2, column=0, sticky=tk.W)

    meta_aim_entry = ttk.Entry(meta_frame)
    meta_aim_entry.grid(row=2, column=1, padx=10, pady=10)

    # Hist Section
    hist_frame = ttk.LabelFrame(window, text="Hist:")
    hist_frame.grid(row=2, column=0, columnspan=2, padx=10, pady=10, sticky=tk.W)

    hist_club_choice_label = ttk.Label(hist_frame, text="Club Choice:")
    hist_club_choice_label.grid(row=0, column=0, sticky=tk.W)

    hist_club_choice_entry = ttk.Entry(hist_frame)
    hist_club_choice_entry.grid(row=0, column=1, padx=10, pady=10)

    hist_desc_label = ttk.Label(hist_frame, text="Desc:")
    hist_desc_label.grid(row=1, column=0, sticky=tk.W)

    hist_desc_entry = ttk.Entry(hist_frame)
    hist_desc_entry.grid(row=1, column=1, padx=10, pady=10)

    hist_height_label = ttk.Label(hist_frame, text="Height:")
    hist_height_label.grid(row=2, column=0, sticky=tk.W)

    hist_height_entry = ttk.Entry(hist_frame)
    hist_height_entry.grid(row=2, column=1, padx=10, pady=10)

    hist_shape_label = ttk.Label(hist_frame, text="Shape:")
    hist_shape_label.grid(row=3, column=0, sticky=tk.W)

    hist_shape_entry = ttk.Entry(hist_frame)
    hist_shape_entry.grid(row=3, column=1, padx=10, pady=10)

    hist_direction_label = ttk.Label(hist_frame, text="Direction:")
    hist_direction_label.grid(row=4, column=0, sticky=tk.W)

    hist_direction_entry = ttk.Entry(hist_frame)
    hist_direction_entry.grid(row=4, column=1, padx=10, pady=10)

    hist_distance_label = ttk.Label(hist_frame, text="Distance:")
    hist_distance_label.grid(row=5, column=0, sticky=tk.W)

    hist_distance_entry = ttk.Entry(hist_frame)
    hist_distance_entry.grid(row=5, column=1, padx=10, pady=10)

    hist_end_location_label = ttk.Label(hist_frame, text="EndLocation:")
    hist_end_location_label.grid(row=6, column=0, sticky=tk.W)

    hist_end_location_entry = ttk.Entry(hist_frame)
    hist_end_location_entry.grid(row=6, column=1, padx=10, pady=10)

    hist_rating_label = ttk.Label(hist_frame, text="Rating:")
    hist_rating_label.grid(row=7, column=0, sticky=tk.W)

    hist_rating_entry = ttk.Entry(hist_frame)
    hist_rating_entry.grid(row=7, column=1, padx=10, pady=10)

    hist_blunders_label = ttk.Label(hist_frame, text="Blunder(s):")
    hist_blunders_label.grid(row=8, column=0, sticky=tk.W)

    hist_blunders_entry = ttk.Entry(hist_frame)
    hist_blunders_entry.grid(row=8, column=1, padx=10, pady=10)

    # Create and place a submit button
    submit_button = ttk.Button(window, text="Submit", command=submit_button_clicked)
    submit_button.grid(row=3, column=0, columnspan=2, pady=20)


def main():
    window = createGui("Shot Input Information")
    loftedShot(window)
    window.mainloop()

    return 1


if __name__ == "__main__":
    sys.exit(main())

import sys
from tkinter import ttk
from Utils import *

class GUI:
    def __init__(self, winName):
        self.window = createGui(winName)

class courseBuilder(GUI):
    def __init__(self, hole):
        GUI.__init__(self, hole)

class shot(GUI):
    def __init__(self, shot, winName):
        super().__init__(winName)
        self.shot = shot
        self.putting = False
        self.inHole = False

        self.aims = ["Fairway", "Green"]

        self.elevChanges = ["Downhill", "Flat (No elev change)", "Uphill"]

        self.directions = ["Left", "Center", "Right"]

        self.endLocations = self.aims + ["Hazard", "Bunker", "Out of Bounds", "Rough", "Fringe"]

        self.heights = ["Low", "Medium", "High"]

        self.shapes = ["Hook", "Draw", "Straight", "Fade", "Slice"]

        self.severities = ["N/A", "Perceptible", "Mild", "Moderate", "Severe", "Catastrophic"]

        self.blunders = ["Push", "Pull", "Top", "Thin", "Duff", "Flub", "Mystery"]
        
        self.clubs = ["Driver", "4 Wood" ] + [str(i) + " iron" for i in range(2, 11)] + ["46 Degree Wedge", "Pitching Wedge", "Gap Wedge", "Sand Wedge"]

    def hit_submit(self, submitList):
        self.submit_button_clicked(submitList)
        self.window.destroy()

    def submit_button_clicked(self, submitList):

        user_inputs = [submitList[i].get() for i in range(len(submitList))]
        if self.shot == 1:
            row=["T"]
        elif self.putting:
            row =["P"]
        else:
            row = ["A"]
        
        row += user_inputs
    
        print("Row to be written to CSV:", row)  # Add this line for debugging

        if not self.putting and user_inputs[-2]:
            self.putting = True

        if user_inputs[-1]:
            self.inHole = True

        # Append the row to the CSV file
        with open("./arch/beep.csv", "a", newline='') as csvfile:
            csv_writer = csv.writer(csvfile)
            csv_writer.writerow(row)


class Putt(shot):
    def __init__(self, shot):
        super().__init__(shot, "Putt")
        self.onGreen = True
        self.putt()
        self.window.mainloop()
    
    def putt(self):

        lie_frame = labelFrame(self.window, "Putt", 0, 2)

        _, segments = labelCombobox(lie_frame, "Segments: ", 3, [str(i) for i in range(1,5)])
        segments.current(0)

        segs = []
        for x in range(int(segments.get())):
            lie_topography_combobox, lie_topography_severity_combobox = sideCar(lie_frame, x, self.elevChanges, self.severities, "Topography")
            lie_elev_combobox, lie_elev_severity_combobox = sideCar(lie_frame, x+1, ["Straight", "Right To Left", "Left To Right"], self.severities,"Ball Location")
            segs.append(lie_topography_combobox)
            segs.append(lie_topography_severity_combobox)
            segs.append(lie_elev_combobox)
            segs.append(lie_elev_severity_combobox)

        hist_frame = labelFrame(self.window, "Hist", 1, 3)

        _, hist_desc_entry = LabelEntry(hist_frame, "Desc: ", 1)
        
        

        _, hist_direction_entry = LabelEntry(hist_frame, "Direction: ", 4)
        _, hist_distance_entry = LabelEntry(hist_frame, "Distance: ", 5)
        _, hist_end_location_entry = LabelEntry(hist_frame, "End Location: ", 6)
        _, hist_rating_entry = LabelEntry(hist_frame, "Rating: ", 7)
        _, hist_in_hole_entry = labelCheckbox(hist_frame, "In Hole:c", 8, 1)

        submitList = segs + [
            
            lie_topography_combobox, lie_topography_severity_combobox,
            hist_desc_entry, hist_direction_entry, hist_distance_entry, hist_end_location_entry,
            hist_rating_entry, hist_in_hole_entry
        ]


        submit_button = ttk.Button(self.window, text="Submit", command=lambda: self.hit_submit(submitList))

        submit_button.grid(row=2, column=0, columnspan=2, pady=20)



class LoftedShot(shot):
    def __init__(self, shot):
        desc = "Tee" if shot == 1 else "Lofted"
        super().__init__(shot, "Shot #" + str(shot)+ ": " + desc)
        self.approachShot(shot)
        self.window.mainloop()
        
    
    def approachShot(self, shot):

        # Meta Section
        meta_frame = labelFrame(self.window, "Meta", 0, 3)
        _, high_level_combobox = labelCombobox(meta_frame, "High Level: ", 0, ["Tee", "Approach", "Pitch", "Bunker", "Chip", "Putt"])
        meta_aim_entry, meta_aim_direction_combobox = sideCar(meta_frame,1, self.aims, self.directions, "Aim: ")
        
    
        lie_frame = labelFrame(self.window, "Lie", 1, 2)
        lie_topography_combobox, lie_topography_severity_combobox = sideCar(lie_frame, 0, self.elevChanges, self.severities, "Topography")
        lie_elev_combobox, lie_elev_severity_combobox = sideCar(lie_frame, 1, ["Level", "Above Feet", "Below Feet"], self.severities,"Ball Location")
        
        
        # Hist Section
        hist_frame = labelFrame(self.window, "Hist", 2, 3)
        _, hist_club_choice_entry = labelCombobox(hist_frame, "Club Choice: ", 0, self.clubs)
        _, hist_desc_entry = LabelEntry(hist_frame, "Desc: ", 1)
        _, hist_height_combobox = labelCombobox(hist_frame, "Height: ", 2, self.heights)
        hist_shape_combobox,hist_shape_severity_combobox = sideCar(hist_frame, 3, self.shapes, self.severities, "Shape: ")
        _, hist_direction_combobox = labelCombobox(hist_frame, "Vector From Aim: ", 4, self.directions)
        _, hist_distance_combobox = labelCombobox(hist_frame, "Distance: ", 5, [str(x) for x in range(0, 350, 50)])
        _, hist_end_location_combobox = labelCombobox(hist_frame, "End Location: ", 6, self.endLocations)
        _, hist_rating_combobox = labelCombobox(hist_frame, "Rating: ", 7, [str(i) for i in range(1,11)])
        _, hist_blunders_combobox = labelCombobox(hist_frame, "Blunder(s): ", 8, self.blunders)
        _, hist_on_green_entry = labelCheckbox(hist_frame, "Landed on Green", 9, 0)
        _, hist_in_hole_entry = labelCheckbox(hist_frame, "Landed In Hole", 9, 1)

        
        if shot < 3:
            if self.shot == 1:
                lie_topography_combobox.current(1)
                lie_elev_combobox.current(0)
                lie_topography_severity_combobox.current(0)
            high_level_combobox.current(shot-1)

        # Create and place a submit button
        submitList = [
            high_level_combobox, meta_aim_entry, meta_aim_direction_combobox,
            lie_topography_combobox,lie_topography_severity_combobox, lie_elev_combobox, lie_elev_severity_combobox,
            hist_club_choice_entry, hist_desc_entry, hist_height_combobox, hist_shape_combobox, hist_shape_severity_combobox,
            hist_direction_combobox, hist_distance_combobox, hist_end_location_combobox,
            hist_rating_combobox, hist_blunders_combobox, hist_on_green_entry, hist_in_hole_entry, 
        ]
        

        submit_button = ttk.Button(self.window, text="Submit", command=lambda: self.hit_submit(submitList))

        submit_button.grid(row=4, column=0, columnspan=2, pady=20)



    # Add this line for debugging


class Hole():
    def __init__(self, hNum):
        self.num = hNum
        self.shots = []
        self.playHole()

    
    def playHole(self):
        putting = False
        inHole = False
        shotNum = 1
        while not putting:
            lastShot = LoftedShot(shotNum)
            self.shots.append(lastShot)
            if lastShot.putting:
                putting = True
            shotNum += 1

        while not inHole:
            lastShot = Putt(shotNum)
            self.shots.append(lastShot)
            if lastShot.inHole:
                return
                
            shotNum += 1
        


def main():
    course, num_holes = process_command_line_arguments()

    holes = []
    for x in range(1,int(num_holes)+1):
        print(x)
        holes.append(Hole(x))
    
    return 1
if __name__ == "__main__":
    sys.exit(main())

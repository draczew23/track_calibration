class IsBadRun:
    def __init__(self):
        self.badruns = set()
        self.lastrun = -1
        self.lastresult = True
        self.firstrun = True

    def is_bad_run(self, run):
        if self.firstrun:
            with open("badruns_mine.dat", "r") as file:
                for line in file:
                    irun = int(line.strip())
                    if irun > 0:
                        self.badruns.add(irun)
                print("Loaded list of", len(self.badruns), "bad runs")
            self.firstrun = False

        if run == self.lastrun:
            return self.lastresult

        self.lastrun = run
        self.lastresult = False

        if run in self.badruns:
            self.lastresult = True

        return self.lastresult
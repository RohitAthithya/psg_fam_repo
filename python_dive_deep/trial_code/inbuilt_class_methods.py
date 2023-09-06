from collections import namedtuple



amat_getwaf_param = namedtuple('amat_getwaf_param',['RobotID', 'BladeID', 'StationCode', 'SlotNum'])
AMAT_GETWAF = 1
DOES_NOT_COMPLY_STR = "does not comply format rules: check documentation for more details."

present_and_taught_port_list = ["P1", "P2", "4P4", "LLA", "MU1"]

class MotionCommands: # REQUIRES GLOBAL VARIABLES:AMAT_GETWAF

    def __init__(self, motion_param:namedtuple):

        if isinstance(motion_param, amat_getwaf_param):
            self.motion_cmd_type = AMAT_GETWAF
            self.RobotID = motion_param.RobotID
            self.BladeID = motion_param.BladeID
            self.StationCode = motion_param.StationCode
            self.SlotNum = motion_param.SlotNum

    @property
    def RobotID(self):
        return self._RobotID

    @RobotID.setter
    def RobotID(self, RobotID):
        if len(RobotID) != 2:
            raise Exception(f"Expected length of RobotID is 2")
        if "R" != RobotID[0].upper():
            raise Exception(f"MotionCommand:{self.motion_cmd_type}: RobotID needs to start with CAPITAL letter 'R' ")
        try:
            int(RobotID[1])
        except ValueError:
            raise Exception(f"The second letter of RobotID must be a integral value.")
        except Exception:
            raise Exception(f"Unkown error criteria, is the IO broken or something?")

        self._RobotID = RobotID

    @property
    def BladeID(self):
        return self._BladeID

    @BladeID.setter
    def BladeID(self, BladeID):
        if len(BladeID) != 2:
            raise Exception(f"Expected length of BladeID is 2")
        if "B" != BladeID[0].upper():
            raise Exception(f"MotionCommand:{self.motion_cmd_type}: BladeID needs to start with CAPITAL letter 'B' ")
        try:
            int(BladeID[1])
        except ValueError:
            raise Exception(f"The second letter of BladeID must be a integral value.")
        except Exception:
            raise Exception(f"Unkown error criteria, is the IO broken or something?")

        self._BladeID = BladeID


    @property
    def StationCode(self):
        return self._StationCode

    @StationCode.setter
    def StationCode(self, StationCode):
        if StationCode.upper() not in present_and_taught_port_list:
            raise Exception("StationCode not available in the colelcted list of present and taught port list. ")

        self._StationCode = StationCode
    @property
    def SlotNum(self):
        return self._SlotNum

    @SlotNum.setter
    def SlotNum(self, SlotNum):
        try:
            int(SlotNum)
        except ValueError:
            raise Exception(f"SlotNum must be a integral value.")
        except Exception:
            raise Exception(f"Unkown error criteria, is the IO broken or something?")

        self._SlotNum = SlotNum


    def __str__(self) -> str:
        match self.motion_cmd_type:
            case AMAT_GETWAF:
                return f"GETWAF,{self.RobotID}:{self.BladeID},{self.StationCode}:{self.SlotNum}"








get_param = amat_getwaf_param( "R1", "B1", "P1", "1")

get_cmd = MotionCommands(get_param)
# get_cmd.RobotID = "R1"
# get_cmd.BladeID = "B1"
# get_cmd.StationCode = "P1"
# get_cmd.SlotNum = "1"


print(get_param)
print(*get_param)

print(str(get_cmd))
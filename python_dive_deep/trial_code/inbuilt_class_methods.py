from collections import namedtuple



amat_getwaf_param = namedtuple('amat_getwaf_param',['RobotID', 'BladeID', 'StationCode', 'SlotNum'])
AMAT_GETWAF = 1

amat_movtoloc_param = namedtuple('amat_movtoloc_param', ['RobotID', 'BladeID', 'StationCode', 'SlotNum', 'PurposeID'])
AMAT_MOVTOLOC = 3

DOES_NOT_COMPLY_STR = "does not comply format rules: check documentation for more details."

present_and_taught_port_list:list[str] = ["P1", "P2", "4P4", "LLA", "MU1"]
motion_purpose_lst:list[str] = ["TAUGHT", "GET", "GTS", "GTX", "GTR", "PUT", "PTS", "PTX", "PTR", "MAP"]

class MotionCommands: # REQUIRES GLOBAL VARIABLES:AMAT_GETWAF

    def __init__(self, motion_param:namedtuple):

        self._motion_cmd_type:int = -1
        self.command_string:str = ""

        if isinstance(motion_param, amat_getwaf_param):
            self._motion_cmd_type = AMAT_GETWAF
        if isinstance(motion_param, amat_movtoloc_param):
            self._motion_cmd_type = AMAT_MOVTOLOC
        self._input_motion_param = motion_param
        self._populate_params()

    def _populate_params(self):
        if self._motion_cmd_type == AMAT_GETWAF:
            self._populate_getwaf_param()
        elif self._motion_cmd_type == AMAT_MOVTOLOC:
            self._populate_movtoloc_param()
        else:
            raise Exception("The input parameters are not of known parameters type! Check input or if its a new command, implment the corr. checks in this . ")


    def _populate_getwaf_param(self):
        self.RobotID = self._input_motion_param.RobotID
        self.BladeID = self._input_motion_param.BladeID
        self.StationCode = self._input_motion_param.StationCode
        self.SlotNum = self._input_motion_param.SlotNum

        self.command_string = f"GETWAF,{self.RobotID}:{self.BladeID},{self.StationCode}:{self.SlotNum}"

    def _populate_movtoloc_param(self):
        self.RobotID = self._input_motion_param.RobotID
        self.BladeID = self._input_motion_param.BladeID
        self.StationCode = self._input_motion_param.StationCode
        self.SlotNum = self._input_motion_param.SlotNum
        self.PurposeID = self._input_motion_param.PurposeID

        self.command_string = f"MOVTOLOC,{self.RobotID}:{self.BladeID},{self.StationCode}:{self.SlotNum},{self.PurposeID}"

    @property
    def RobotID(self):
        return self._RobotID

    @RobotID.setter
    def RobotID(self, RobotID:str):
        if len(RobotID) != 2:
            raise Exception(f"Expected length of RobotID is 2")
        if "R" != RobotID[0].upper():
            raise Exception(f"MotionCommand:{self._motion_cmd_type}: RobotID needs to start with CAPITAL letter 'R' ")
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
    def BladeID(self, BladeID:str):
        if len(BladeID) != 2:
            raise Exception(f"Expected length of BladeID is 2")
        if "B" != BladeID[0].upper():
            raise Exception(f"MotionCommand:{self._motion_cmd_type}: BladeID needs to start with CAPITAL letter 'B' ")
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
    def StationCode(self, StationCode:str):
        if StationCode.upper() not in present_and_taught_port_list:
            raise Exception("StationCode not available in the colelcted list of present and taught port list. ")

        self._StationCode = StationCode

    @property
    def SlotNum(self):
        return self._SlotNum
    @SlotNum.setter
    def SlotNum(self, SlotNum:str):
        try:
            int(SlotNum)
        except ValueError:
            raise Exception(f"SlotNum must be a integral value.")
        except Exception:
            raise Exception(f"Unkown error criteria, is the IO broken or something?")

        self._SlotNum = SlotNum


    @property
    def PurposeID(self):
        return self._PurposeID

    @PurposeID.setter
    def PurposeID(self, PurposeID:str):
        if PurposeID.upper() not in motion_purpose_lst:
            raise Exception("Purpose not found in the known list of movtoloc purposes. ")

        self._PurposeID = PurposeID



    def __str__(self) -> str:
        return self.command_string




get_param = amat_getwaf_param( "a1", "B11", "P1", "1")
get2_param = amat_getwaf_param(RobotID="sdd", )

get_cmd = MotionCommands(get_param)
# get_cmd.RobotID = "R1"
# get_cmd.BladeID = "B1"
# get_cmd.StationCode = "P1"
# get_cmd.SlotNum = "1"


# print(get_param)
# print(*get_param)

print(str(get_cmd))

movtoloc_param = amat_movtoloc_param("R1", "B1", "P1", "1", "PTS")
movtoloc_cmd = MotionCommands(movtoloc_param)

print(str(movtoloc_cmd))



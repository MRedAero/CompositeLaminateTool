# This file was automatically generated by SWIG (http://www.swig.org).
# Version 3.0.5
#
# Do not make changes to this file unless you know what you are doing--modify
# the SWIG interface file instead.





from sys import version_info
if version_info >= (2, 6, 0):
    def swig_import_helper():
        from os.path import dirname
        import imp
        fp = None
        try:
            fp, pathname, description = imp.find_module('_LaminateOrthotropic', [dirname(__file__)])
        except ImportError:
            import _LaminateOrthotropic
            return _LaminateOrthotropic
        if fp is not None:
            try:
                _mod = imp.load_module('_LaminateOrthotropic', fp, pathname, description)
            finally:
                fp.close()
            return _mod
    _LaminateOrthotropic = swig_import_helper()
    del swig_import_helper
else:
    import _LaminateOrthotropic
del version_info
try:
    _swig_property = property
except NameError:
    pass  # Python < 2.2 doesn't have 'property'.


def _swig_setattr_nondynamic(self, class_type, name, value, static=1):
    if (name == "thisown"):
        return self.this.own(value)
    if (name == "this"):
        if type(value).__name__ == 'SwigPyObject':
            self.__dict__[name] = value
            return
    method = class_type.__swig_setmethods__.get(name, None)
    if method:
        return method(self, value)
    if (not static):
        if _newclass:
            object.__setattr__(self, name, value)
        else:
            self.__dict__[name] = value
    else:
        raise AttributeError("You cannot add attributes to %s" % self)


def _swig_setattr(self, class_type, name, value):
    return _swig_setattr_nondynamic(self, class_type, name, value, 0)


def _swig_getattr_nondynamic(self, class_type, name, static=1):
    if (name == "thisown"):
        return self.this.own()
    method = class_type.__swig_getmethods__.get(name, None)
    if method:
        return method(self)
    if (not static):
        return object.__getattr__(self, name)
    else:
        raise AttributeError(name)

def _swig_getattr(self, class_type, name):
    return _swig_getattr_nondynamic(self, class_type, name, 0)


def _swig_repr(self):
    try:
        strthis = "proxy of " + self.this.__repr__()
    except:
        strthis = ""
    return "<%s.%s; %s >" % (self.__class__.__module__, self.__class__.__name__, strthis,)

try:
    _object = object
    _newclass = 1
except AttributeError:
    class _object:
        pass
    _newclass = 0


class StrainStress_s(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, StrainStress_s, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, StrainStress_s, name)
    __repr__ = _swig_repr
    __swig_setmethods__["data"] = _LaminateOrthotropic.StrainStress_s_data_set
    __swig_getmethods__["data"] = _LaminateOrthotropic.StrainStress_s_data_get
    if _newclass:
        data = _swig_property(_LaminateOrthotropic.StrainStress_s_data_get, _LaminateOrthotropic.StrainStress_s_data_set)

    def __init__(self):
        this = _LaminateOrthotropic.new_StrainStress_s()
        try:
            self.this.append(this)
        except:
            self.this = this
    __swig_destroy__ = _LaminateOrthotropic.delete_StrainStress_s
    __del__ = lambda self: None
StrainStress_s_swigregister = _LaminateOrthotropic.StrainStress_s_swigregister
StrainStress_s_swigregister(StrainStress_s)

class LaminateOrthotropic(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, LaminateOrthotropic, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, LaminateOrthotropic, name)
    __repr__ = _swig_repr
    __swig_setmethods__["stackup"] = _LaminateOrthotropic.LaminateOrthotropic_stackup_set
    __swig_getmethods__["stackup"] = _LaminateOrthotropic.LaminateOrthotropic_stackup_get
    if _newclass:
        stackup = _swig_property(_LaminateOrthotropic.LaminateOrthotropic_stackup_get, _LaminateOrthotropic.LaminateOrthotropic_stackup_set)
    __swig_setmethods__["ABDmat"] = _LaminateOrthotropic.LaminateOrthotropic_ABDmat_set
    __swig_getmethods__["ABDmat"] = _LaminateOrthotropic.LaminateOrthotropic_ABDmat_get
    if _newclass:
        ABDmat = _swig_property(_LaminateOrthotropic.LaminateOrthotropic_ABDmat_get, _LaminateOrthotropic.LaminateOrthotropic_ABDmat_set)
    __swig_setmethods__["ABDinv"] = _LaminateOrthotropic.LaminateOrthotropic_ABDinv_set
    __swig_getmethods__["ABDinv"] = _LaminateOrthotropic.LaminateOrthotropic_ABDinv_get
    if _newclass:
        ABDinv = _swig_property(_LaminateOrthotropic.LaminateOrthotropic_ABDinv_get, _LaminateOrthotropic.LaminateOrthotropic_ABDinv_set)
    __swig_setmethods__["Exx"] = _LaminateOrthotropic.LaminateOrthotropic_Exx_set
    __swig_getmethods__["Exx"] = _LaminateOrthotropic.LaminateOrthotropic_Exx_get
    if _newclass:
        Exx = _swig_property(_LaminateOrthotropic.LaminateOrthotropic_Exx_get, _LaminateOrthotropic.LaminateOrthotropic_Exx_set)
    __swig_setmethods__["Eyy"] = _LaminateOrthotropic.LaminateOrthotropic_Eyy_set
    __swig_getmethods__["Eyy"] = _LaminateOrthotropic.LaminateOrthotropic_Eyy_get
    if _newclass:
        Eyy = _swig_property(_LaminateOrthotropic.LaminateOrthotropic_Eyy_get, _LaminateOrthotropic.LaminateOrthotropic_Eyy_set)
    __swig_setmethods__["Gxy"] = _LaminateOrthotropic.LaminateOrthotropic_Gxy_set
    __swig_getmethods__["Gxy"] = _LaminateOrthotropic.LaminateOrthotropic_Gxy_get
    if _newclass:
        Gxy = _swig_property(_LaminateOrthotropic.LaminateOrthotropic_Gxy_get, _LaminateOrthotropic.LaminateOrthotropic_Gxy_set)
    __swig_setmethods__["nuxy"] = _LaminateOrthotropic.LaminateOrthotropic_nuxy_set
    __swig_getmethods__["nuxy"] = _LaminateOrthotropic.LaminateOrthotropic_nuxy_get
    if _newclass:
        nuxy = _swig_property(_LaminateOrthotropic.LaminateOrthotropic_nuxy_get, _LaminateOrthotropic.LaminateOrthotropic_nuxy_set)
    __swig_setmethods__["nuyx"] = _LaminateOrthotropic.LaminateOrthotropic_nuyx_set
    __swig_getmethods__["nuyx"] = _LaminateOrthotropic.LaminateOrthotropic_nuyx_get
    if _newclass:
        nuyx = _swig_property(_LaminateOrthotropic.LaminateOrthotropic_nuyx_get, _LaminateOrthotropic.LaminateOrthotropic_nuyx_set)
    __swig_setmethods__["thickness"] = _LaminateOrthotropic.LaminateOrthotropic_thickness_set
    __swig_getmethods__["thickness"] = _LaminateOrthotropic.LaminateOrthotropic_thickness_get
    if _newclass:
        thickness = _swig_property(_LaminateOrthotropic.LaminateOrthotropic_thickness_get, _LaminateOrthotropic.LaminateOrthotropic_thickness_set)
    __swig_setmethods__["local_ply_strain"] = _LaminateOrthotropic.LaminateOrthotropic_local_ply_strain_set
    __swig_getmethods__["local_ply_strain"] = _LaminateOrthotropic.LaminateOrthotropic_local_ply_strain_get
    if _newclass:
        local_ply_strain = _swig_property(_LaminateOrthotropic.LaminateOrthotropic_local_ply_strain_get, _LaminateOrthotropic.LaminateOrthotropic_local_ply_strain_set)
    __swig_setmethods__["local_ply_stress"] = _LaminateOrthotropic.LaminateOrthotropic_local_ply_stress_set
    __swig_getmethods__["local_ply_stress"] = _LaminateOrthotropic.LaminateOrthotropic_local_ply_stress_get
    if _newclass:
        local_ply_stress = _swig_property(_LaminateOrthotropic.LaminateOrthotropic_local_ply_stress_get, _LaminateOrthotropic.LaminateOrthotropic_local_ply_stress_set)

    def calculate_laminate_properties(self):
        return _LaminateOrthotropic.LaminateOrthotropic_calculate_laminate_properties(self)

    def set_number_of_plies(self, arg2):
        return _LaminateOrthotropic.LaminateOrthotropic_set_number_of_plies(self, arg2)

    def get_ply(self, arg2):
        return _LaminateOrthotropic.LaminateOrthotropic_get_ply(self, arg2)

    def get_unit_strain(self, arg2, arg3, arg4):
        return _LaminateOrthotropic.LaminateOrthotropic_get_unit_strain(self, arg2, arg3, arg4)

    def get_unit_stress(self, arg2, arg3, arg4):
        return _LaminateOrthotropic.LaminateOrthotropic_get_unit_stress(self, arg2, arg3, arg4)

    def __init__(self):
        this = _LaminateOrthotropic.new_LaminateOrthotropic()
        try:
            self.this.append(this)
        except:
            self.this = this
    __swig_destroy__ = _LaminateOrthotropic.delete_LaminateOrthotropic
    __del__ = lambda self: None
LaminateOrthotropic_swigregister = _LaminateOrthotropic.LaminateOrthotropic_swigregister
LaminateOrthotropic_swigregister(LaminateOrthotropic)

# This file is compatible with both classic and new-style classes.


#pragma once

#include "CommandTable.h"
#include "ParamInfos.h"
#include "ScriptUtils.h"

DEFINE_COMMAND(IsScripted, returns 1 if the object or reference has a script attached to it., 0, 1, kParams_OneOptionalForm);
DEFINE_COMMAND(GetScript, returns the script of the reference or passed object., 0, 1, kParams_OneOptionalForm);
DEFINE_COMMAND(RemoveScript, removes the script of the reference or passed object., 0, 1, kParams_OneOptionalForm);
DEFINE_COMMAND(SetScript, sets the script of the reference or passed object., 0, 2, kParams_OneForm_OneOptionalForm);
DEFINE_COMMAND(IsFormValid, returns 1 if the reference or passed object is valid., 0, 1, kParams_OneOptionalForm);

static ParamInfo kParams_OneReference[1] =
{
	{	"reference",	kParamType_ObjectRef,	0	},
};

DEFINE_COMMAND(IsReference, returns 1 if the passed refVar is a reference., 0, 1, kParams_OneReference);

static ParamInfo kParams_GetVariable[2] =
{
	{	"variable name",	kParamType_String,	0	},
	{	"quest",			kParamType_Quest,	1	},
};

DEFINE_COMMAND(GetVariable, looks up the value of a variable by name, 0, 2, kParams_GetVariable);
DEFINE_COMMAND(HasVariable, returns true if the script has a variable with the specified name, 0, 2, kParams_GetVariable);
DEFINE_COMMAND(GetRefVariable, looks up the value of a ref variable by name, 0, 2, kParams_GetVariable);
DEFINE_CMD_ALT(GetArrayVariable, GetArrayVar, looks up an array variable by name on the calling object or specified quest, 0, 2, kParams_GetVariable);

static ParamInfo kParams_SetNumVariable[3] =
{
	{	"variable name",	kParamType_String,	0	},
	{	"variable value",	kParamType_Float,	0	},
	{	"quest",			kParamType_Quest,	1	},
};

static ParamInfo kParams_SetRefVariable[3] =
{
	{	"variable name",	kParamType_String,	0	},
	{	"variable value",	kParamType_AnyForm,	0	},
	{	"quest",			kParamType_Quest,	1	},
};

DEFINE_COMMAND(SetVariable, sets the value of a variable by name, 0, 3, kParams_SetNumVariable);
DEFINE_COMMAND(SetRefVariable, sets the value of a variable by name, 0, 3, kParams_SetRefVariable);

static ParamInfo kParams_CompareScripts[2] =
{
	{	"script",	kParamType_ObjectID,	0	},
	{	"script",	kParamType_ObjectID,	0	},
};

DEFINE_COMMAND(CompareScripts, returns true if the compiled scripts are identical, 0, 2, kParams_CompareScripts);

DEFINE_COMMAND(ResetAllVariables, sets all variables in a script to zero, 0, 0, NULL);

static ParamInfo kParams_GetFormFromMod[2] =
{
	{	"modName",	kParamType_String,	0	},
	{	"formID",	kParamType_String,	0	},
};

DEFINE_COMMAND(GetNumExplicitRefs, returns the number of literal references in a script, 0, 1, kParams_OneOptionalForm);

DEFINE_COMMAND(GetNthExplicitRef, returns the nth literal reference in a script, 0, 2, kParams_OneInt_OneOptionalForm);

DEFINE_COMMAND(RunScript, debug, 0, 1, kParams_OneForm);

DEFINE_COMMAND(GetCurrentScript, returns the calling script, 0, 0, NULL);
DEFINE_COMMAND(GetCallingScript, returns the script that called the executing function script, 0, 0, NULL);

static ParamInfo kNVSEParams_SetEventHandler[20] =
{
	{ "event name",			kNVSEParamType_String,	0 },
	{ "function script",	kNVSEParamType_Form,	0 },

	{ "filter",				kNVSEParamType_Pair,	1 },
	{ "filter",				kNVSEParamType_Pair,	1 },
	{ "filter",				kNVSEParamType_Pair,	1 },
	{ "filter",				kNVSEParamType_Pair,	1 },
	{ "filter",				kNVSEParamType_Pair,	1 },

	{ "filter",				kNVSEParamType_Pair,	1 },
	{ "filter",				kNVSEParamType_Pair,	1 },
	{ "filter",				kNVSEParamType_Pair,	1 },
	{ "filter",				kNVSEParamType_Pair,	1 },
	{ "filter",				kNVSEParamType_Pair,	1 },

	{ "filter",				kNVSEParamType_Pair,	1 },
	{ "filter",				kNVSEParamType_Pair,	1 },
	{ "filter",				kNVSEParamType_Pair,	1 },
	{ "filter",				kNVSEParamType_Pair,	1 },
	{ "filter",				kNVSEParamType_Pair,	1 },

	{ "filter",				kNVSEParamType_Pair,	1 },
	// 1 filter for thisObj, 15 for the rest.
};

DEFINE_COMMAND_EXP(SetEventHandler, defines a function script to serve as a callback for game events, 0, kNVSEParams_SetEventHandler);
DEFINE_COMMAND_EXP(RemoveEventHandler, "removes event handlers matching the event, script, and optional filters specified", 0, kNVSEParams_SetEventHandler);
DEFINE_CMD(GetCurrentEventName, returns the name of the event currently being processed by an event handler, 0, NULL);

static ParamInfo kNVSEParams_DispatchEvent[3] =
{
	{	"eventName",			kNVSEParamType_String,	0	},
	{	"args",					kNVSEParamType_Array,	1	},
	{	"sender",				kNVSEParamType_String,	1	}
};
static ParamInfo kNVSEParams_DispatchEventAlt[16] =
{
	{	"eventName",			kNVSEParamType_String,	0	},

	{ "arg1",				kNVSEParamType_BasicType,	1 },
	{ "arg2",				kNVSEParamType_BasicType,	1 },
	{ "arg3",				kNVSEParamType_BasicType,	1 },
	{ "arg4",				kNVSEParamType_BasicType,	1 },
	{ "arg5",				kNVSEParamType_BasicType,	1 },

	{ "arg6",				kNVSEParamType_BasicType,	1 },
	{ "arg7",				kNVSEParamType_BasicType,	1 },
	{ "arg8",				kNVSEParamType_BasicType,	1 },
	{ "arg9",				kNVSEParamType_BasicType,	1 },
	{ "arg10",				kNVSEParamType_BasicType,	1 },

	{ "arg11",				kNVSEParamType_BasicType,	1 },
	{ "arg12",				kNVSEParamType_BasicType,	1 },
	{ "arg13",				kNVSEParamType_BasicType,	1 },
	{ "arg14",				kNVSEParamType_BasicType,	1 },
	{ "arg15",				kNVSEParamType_BasicType,	1 }
};

DEFINE_COMMAND_EXP(DispatchEvent, dispatches a user-defined event to any registered listeners, 0, kNVSEParams_DispatchEvent);
DEFINE_COMMAND_EXP(DispatchEventAlt, dispatches a user-defined event to any registered listeners, 0, kNVSEParams_DispatchEventAlt);

static ParamInfo kNVSEParams_DumpEventHandlers[17] =
{
	{	"eventName",		kNVSEParamType_String,	1	},
	{	"script",			kNVSEParamType_Form,	1	},

	{ "arg1",				kNVSEParamType_BasicType,	1 },
	{ "arg2",				kNVSEParamType_BasicType,	1 },
	{ "arg3",				kNVSEParamType_BasicType,	1 },
	{ "arg4",				kNVSEParamType_BasicType,	1 },
	{ "arg5",				kNVSEParamType_BasicType,	1 },

	{ "arg6",				kNVSEParamType_BasicType,	1 },
	{ "arg7",				kNVSEParamType_BasicType,	1 },
	{ "arg8",				kNVSEParamType_BasicType,	1 },
	{ "arg9",				kNVSEParamType_BasicType,	1 },
	{ "arg10",				kNVSEParamType_BasicType,	1 },

	{ "arg11",				kNVSEParamType_BasicType,	1 },
	{ "arg12",				kNVSEParamType_BasicType,	1 },
	{ "arg13",				kNVSEParamType_BasicType,	1 },
	{ "arg14",				kNVSEParamType_BasicType,	1 },
	{ "arg15",				kNVSEParamType_BasicType,	1 }
};

DEFINE_COMMAND_EXP(DumpEventHandlers, "dumps event handlers, optionally filtered by eventName, script and args.", 0, kNVSEParams_DumpEventHandlers);
DEFINE_COMMAND_EXP(GetEventHandlers, "returns a multi-dimensional array of event handlers, optionally filtered by eventName, script and args.", 0, kNVSEParams_DumpEventHandlers);

static ParamInfo kParams_CallAfter_OLD[3] =
{
	{	"seconds",	kParamType_Float,	0	},
	{	"function",	kParamType_AnyForm,0	},
	{ "runs in menumode", kParamType_Integer, 1}
};

static ParamInfo kNVSEParams_CallAfter[18] =
{
	{	"seconds",	kNVSEParamType_Number,	0	},
	{	"function",	kNVSEParamType_Form,0	},
	{ "flags", kNVSEParamType_Number, 1},

	{	"element",	kNVSEParamType_BasicType,	1	},
	{	"element",	kNVSEParamType_BasicType,	1	},
	{	"element",	kNVSEParamType_BasicType,	1	},
	{	"element",	kNVSEParamType_BasicType,	1	},
	{	"element",	kNVSEParamType_BasicType,	1	},

	{	"element",	kNVSEParamType_BasicType,	1	},
	{	"element",	kNVSEParamType_BasicType,	1	},
	{	"element",	kNVSEParamType_BasicType,	1	},
	{	"element",	kNVSEParamType_BasicType,	1	},
	{	"element",	kNVSEParamType_BasicType,	1	},

	{	"element",	kNVSEParamType_BasicType,	1	},
	{	"element",	kNVSEParamType_BasicType,	1	},
	{	"element",	kNVSEParamType_BasicType,	1	},
	{	"element",	kNVSEParamType_BasicType,	1	},
	{	"element",	kNVSEParamType_BasicType,	1	},
	//#elems should not exceed max # of UDF args.
};

static ParamInfo kParams_CallWhile_OLD[2] =
{
	{	"function",	kParamType_AnyForm,	0	},
	{	"condition",	kParamType_AnyForm,0	},
};

static ParamInfo kNVSEParams_CallWhile[18] =
{
	{	"function",	kNVSEParamType_Form,	0	},
	{	"condition",	kNVSEParamType_Form,0	},
	{	"flags",		kNVSEParamType_Number,	1	},

	{	"element",	kNVSEParamType_BasicType,	1	},
	{	"element",	kNVSEParamType_BasicType,	1	},
	{	"element",	kNVSEParamType_BasicType,	1	},
	{	"element",	kNVSEParamType_BasicType,	1	},
	{	"element",	kNVSEParamType_BasicType,	1	},

	{	"element",	kNVSEParamType_BasicType,	1	},
	{	"element",	kNVSEParamType_BasicType,	1	},
	{	"element",	kNVSEParamType_BasicType,	1	},
	{	"element",	kNVSEParamType_BasicType,	1	},
	{	"element",	kNVSEParamType_BasicType,	1	},

	{	"element",	kNVSEParamType_BasicType,	1	},
	{	"element",	kNVSEParamType_BasicType,	1	},
	{	"element",	kNVSEParamType_BasicType,	1	},
	{	"element",	kNVSEParamType_BasicType,	1	},
	{	"element",	kNVSEParamType_BasicType,	1	},
	//#elems should not exceed max # of UDF args.
};

DEFINE_CMD_ALT(CallAfterSeconds_OLD, CallAfter_OLD, "deprecated", 0, std::size(kParams_CallAfter_OLD), kParams_CallAfter_OLD);
DEFINE_CMD_ALT(CallForSeconds_OLD, CallFor_OLD, "deprecated", 0, std::size(kParams_CallAfter_OLD), kParams_CallAfter_OLD);
DEFINE_COMMAND(CallWhile_OLD, "deprecated", 0, std::size(kParams_CallWhile_OLD), kParams_CallWhile_OLD);
DEFINE_COMMAND(CallWhen_OLD, "deprecated", 0, std::size(kParams_CallWhile_OLD), kParams_CallWhile_OLD);

DEFINE_CMD_ALT_EXP(CallAfterSeconds, CallAfter, "calls UDF after argument number of seconds", false, kNVSEParams_CallAfter);
DEFINE_CMD_ALT_EXP(CallForSeconds, CallFor, "calls UDF each frame for argument number of seconds", false, kNVSEParams_CallAfter);
DEFINE_COMMAND_EXP(CallWhile, "calls UDF each frame while condition is met", false, kNVSEParams_CallWhile);
DEFINE_COMMAND_EXP(CallWhen, "calls UDF once when a condition is met which is polled each frame", false, kNVSEParams_CallWhile);

#if RUNTIME
using CallArgs = std::vector<SelfOwningArrayElement>;

struct DelayedCallInfo
{
	Script* script;
	float time;
	TESObjectREFR* thisObj;
	LambdaManager::LambdaVariableContext lambdaVariableContext;
	enum eFlags : UInt8 {
		kFlags_None = 0,
		kFlag_RunInMenuMode = 1 << 0,
	} flags;
	CallArgs args;

	[[nodiscard]] bool RunInMenuMode() const { return flags & kFlag_RunInMenuMode; }

	DelayedCallInfo(Script* script, float time, TESObjectREFR* thisObj, eFlags flags, CallArgs &&args = {})
		: script(script),
		  time(time),
		  thisObj(thisObj),
		  lambdaVariableContext(script), flags(flags),
	      args(std::move(args))
	{
	}
};

struct CallWhileInfo
{
	Script* callFunction;
	Script* condition;
	TESObjectREFR* thisObj;
	LambdaManager::LambdaVariableContext callFnLambdaCtx;
	LambdaManager::LambdaVariableContext condFnLambdaCtx;
	enum eFlags : UInt8 {
		kFlags_None = 0,
		kPassArgs_ToCallFunc = 1 << 0,
		kPassArgs_ToConditionFunc = 1 << 1,
		kFlag_RunInMenuMode = 1 << 2,	//todo: make use (?)
	} flags;
	CallArgs args;

	[[nodiscard]] bool PassArgsToCallFunc() const { return flags & kPassArgs_ToCallFunc; }
	[[nodiscard]] bool PassArgsToCondFunc() const { return flags & kPassArgs_ToConditionFunc; }

	CallWhileInfo(Script* callFunction, Script* condition, TESObjectREFR* thisObj, eFlags flags, CallArgs &&args = {})
		: callFunction(callFunction),
		  condition(condition),
		  thisObj(thisObj),
		  callFnLambdaCtx(callFunction),
		  condFnLambdaCtx(condition),
		  flags(flags),
		  args(std::move(args))
	{
	}
};

extern std::list<DelayedCallInfo> g_callForInfos;
extern std::list<CallWhileInfo> g_callWhileInfos;
extern std::list<DelayedCallInfo> g_callAfterInfos;
extern std::list<CallWhileInfo> g_callWhenInfos;

extern ICriticalSection g_callForInfosCS;
extern ICriticalSection g_callWhileInfosCS;
extern ICriticalSection g_callAfterInfosCS;
extern ICriticalSection g_callWhenInfosCS;

#endif

static ParamInfo kParams_HasScriptCommand[3] =
{
	{	"command opcode",	kParamType_Integer,			0	},
	{	"form",			kParamType_AnyForm,	1	},
	{	"event block id",			kParamType_Integer,	1	}
};


DEFINE_COMMAND(DecompileScript, decompiles a script to file, false, 2, kParams_OneForm_OneOptionalString);
DEFINE_COMMAND(HasScriptCommand, returns 1 if script contains call to a command, false, 3, kParams_HasScriptCommand);
DEFINE_COMMAND(GetCommandOpcode, gets opcode for command name, false, 1, kParams_OneString);

static ParamInfo kParams_Ternary[] =
{
	{	"value",			kNVSEParamType_BasicType,	0	},
	{	"callIfTrue (UDF)",	kNVSEParamType_Form,	0	},
	{	"callIfFalse (UDF)",	kNVSEParamType_Form,	0	},
};

DEFINE_COMMAND_EXP(Ternary, "The ternary operator as a function.", false, kParams_Ternary);

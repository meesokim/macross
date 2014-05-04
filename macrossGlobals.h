/*
	macrossGlobals.h -- Global variable definitions for the Macross
			    assembler.

	Chip Morningstar -- Lucasfilm Ltd.

	1-November-1984

*/

bool			 backwardsCompatibleIfFlag;
bool			 beneathFunction;
commandLineDefineType	*commandLineDefines;
int			 cumulativeLineNumber;
environmentType		*currentEnvironment;
int			 currentFieldOffset;
char			*currentFileName;
char			*lastErrorFile;
stringType		*currentFunctionName;
int			 currentLabelTagNumber;
int			 currentLineNumber;
int			 lastErrorLine;
identifierListType	*currentLocalVariableList;
valueType		 currentLocationCounter;
int			 currentOperandNumber;
int			 currentReferenceDepth;
bool			 debug;
bool			 emitPrint;
bool			 expandMacros;
bool			 errorFlag;
bool			 expressionFailed;
bool			 finishOperand;
operandKindType		 fixupAddressMode[MAX_NUMBER_OF_OPERANDS];
operandKindType		 newFixupAddressMode;
fixupListType		*fixupList;
bool			 freeFlag;
bool			 freturnExit;
bool			 generatingFixup;
environmentType		 globalEnvironment;
int			 hackFlag;
bool			 haveUserStartAddress;
bool			 fixupStartAddress;
int			 includeNestingDepth;
FILE			*indexFileForPass2;
FILE			*input;
fileNameListType	*inputFileStack;
FILE			*listFileOutput;
int			 listingControlCounter;
bool			 listingOn;
int			 macroCallDepth;
FILE			*macroFileForPass2;
int			 macroOrFunctionNestingDepth;
structInstanceType	*newStruct;
int			 nextEnvironmentNumber;
int			 nextLabelTagNumber;
FILE			*objectFileOutput;
char			 operandBuffer[MAX_NUMBER_OF_OPERANDS][LINE_BUFFER_SIZE];
char			 pass2IndexFileName[];
char			 pass2SourceFileName[];
char			 pass2MacroExpansionFileName[];
expressionType		*pendingFixup[MAX_NUMBER_OF_OPERANDS];
bool			 performingFixups;
bool			 positionIndependentCodeMode;
bool			 produceLinkableObject;
addressType		 relocatableHighWaterMark;
reservationListType	*reservationList;
valueType		*resultOfLastFunctionCall;
valueType		 savedRelocatableCurrentLocationCounter;
FILE			*saveFileForPass2;
bool			 showAllSymbolsFlag;
bool			 sideEffectFlag;
bool			 standaloneExpansionFlag;
valueType		*startAddress;
int			 statementEvaluationDepth;
int			 statementListNestingDepth;
int			 structNestingDepth;
FILE			*symbolDumpFileOutput;
bool			 symbolTableDumpOn;
int			 tabCount;
addressType		 targetOffset;
bool			 terseErrorMessages;
valueType		*UndefinedValue;
symbolUsageKindType	 unknownSymbolTag;

#define DEFAULT_OBJECT_FILE_NAME	"m.out"

#define	LEX_DISPATCH_TABLE_SIZE	128
int			(*lexDispatchTable[128])();

#define HASH_TABLE_SIZE	512
#define HASH_TABLE_MASK 0x1FF

struct {
	stringType	*functionName;
	valueType	*(*functionEntry)();
	bool		 isSpecialFunction;
	int		 ordinal;
		} builtInFunctionTable[];

struct {
	stringType	*symbolName;
	int		 symbolValue;
		} predefinedSymbolTable[];

macroTableEntryType	*macroTable[HASH_TABLE_SIZE];

opcodeTableEntryType	*opcodeTable[HASH_TABLE_SIZE];

opcodeTableEntryType	 theOpcodes[];

keywordTableEntryType	*keywordTable[HASH_TABLE_SIZE];

keywordTableEntryType	 theKeywords[];

conditionTableEntryType	*conditionTable[HASH_TABLE_SIZE];

conditionTableEntryType	 theConditions[];

symbolTableEntryType	*symbolTable[HASH_TABLE_SIZE];

int			 operandClassTable[];

void		       (*instructionActionTable[])();

int			 validSymbolValues[NUM_OF_SYM_USAGES];

byte			 structScratchBuffer[MAXIMUM_ALLOWED_STRUCT_SIZE];

codeRegionType		 absoluteCodeRegion;
codeRegionType		 relocatableCodeRegion;
codeRegionType		*codeRegions[2];
codeBufferKindType	 currentCodeMode;
codeBufferType		*emptyBuffer; /* ??? */
codeBreakType		*codeBreakList;
codeBreakType		*lastCodeBreak;

expressionReferenceListType	*expressionReferenceList[3];
expressionReferenceListType	*referencesToNote[MAX_NUMBER_OF_OPERANDS];
int			 numberOfReferencesInList[3];
functionDefinitionType		*externalFunctionList;
functionDefinitionType		*endOfExternalFunctionList;
int				 externalFunctionCount;

char			 alphabeticCharacterTable[128];
char			 alphaNumericCharacterTable[128];
char			 lowerCaseCharacterTable[128];
char			 numericCharacterTable[128];

int		expressionBufferSize;
#define EXPRESSION_BUFFER_LIMIT	500
byte		expressionBuffer[EXPRESSION_BUFFER_LIMIT];

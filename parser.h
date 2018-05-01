#define METHOD_MAX_LENGTH 16
#define REQUEST_URI_MAX_LENGTH 32
#define SIP_VERSION_MAX_LENGTH 16
#define STATUS_CODE_MAX_LENGTH 8
#define REASON_PHRASE_MAX_LENGTH 64

typedef struct request_line {
	char method[METHOD_MAX_LENGTH];
	char request_uri[REQUEST_URI_MAX_LENGTH];
	char sip_version[SIP_VERSION_MAX_LENGTH];
} request_line_t;

typedef struct response_line {
	char sip_version[SIP_VERSION_MAX_LENGTH];
	char status_code[STATUS_CODE_MAX_LENGTH];
	char reason_phrase[REASON_PHRASE_MAX_LENGTH];
} response_line_t;

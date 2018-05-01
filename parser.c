#include <string.h>
#include "parser.h"

/*
Request Line
Request-Line = Method SP Request-URI SP SIP-Version CRLF
*/
int parse_request_line(char *start_line, request_line_t *req_line) {
	char *p_sp;
	// method
	if (p_sp = strchr(start_line, ' ')) {
		*p_sp = 0;
		snprintf(req_line->method, METHOD_MAX_LENGTH, "%s", start_line);
		// request uri
		start_line = p_sp + 1;
		if (p_sp = strchr(start_line, ' ')) {
			*p_sp = 0;
			snprintf(req_line->request_uri, REQUEST_URI_MAX_LENGTH, "%s", start_line);
			// sip version
			start_line = p_sp + 1;
			snprintf(req_line->sip_version, SIP_VERSION_MAX_LENGTH, "%s", start_line);
			return 0;
		}
	}

	return -1;
}

/*
Status Line(Response Line)
Status-Line = SIP-Version SP Status-Code SP Reason-Phrase CRLF
*/
int parse_response_line(char *start_line, response_line_t *resp_line) {
	char *p_sp;
	// sip version
	if (p_sp = strchr(start_line, ' ')) {
		*p_sp = 0;
		snprintf(resp_line->sip_version, SIP_VERSION_MAX_LENGTH, "%s", start_line);
		// status code
		start_line = p_sp + 1;
		if (p_sp = strchr(start_line, ' ')) {
			*p_sp = 0;
			snprintf(resp_line->status_code, STATUS_CODE_MAX_LENGTH, "%s", start_line);
			// reason phrase
			start_line = p_sp + 1;
			snprintf(resp_line->reason_phrase, REASON_PHRASE_MAX_LENGTH, "%s", start_line);
			return 0;
		}
	}

	return -1;
}


#line 1 "ext/puma_http11/http11_parser.rl"
/**
 * Copyright (c) 2005 Zed A. Shaw
 * You can redistribute it and/or modify it under the same terms as Ruby.
 * License 3-clause BSD
 */
#include "http11_parser.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*
 * capitalizes all lower-case ASCII characters,
 * converts dashes to underscores, and underscores to commas.
 */
static void snake_upcase_char(char *c)
{
    if (*c >= 'a' && *c <= 'z')
      *c &= ~0x20;
    else if (*c == '_')
      *c = ',';
    else if (*c == '-')
      *c = '_';
}

#define LEN(AT, FPC) (FPC - buffer - parser->AT)
#define MARK(M,FPC) (parser->M = (FPC) - buffer)
#define PTR_TO(F) (buffer + parser->F)

/** Machine **/


#line 81 "ext/puma_http11/http11_parser.rl"


/** Data **/

#line 42 "ext/puma_http11/http11_parser.c"
static const int puma_parser_start = 1;
static const int puma_parser_first_final = 46;
static const int puma_parser_error = 0;


#line 85 "ext/puma_http11/http11_parser.rl"

int puma_parser_init(puma_parser *parser)  {
  int cs = 0;
  
#line 53 "ext/puma_http11/http11_parser.c"
	{
	cs = puma_parser_start;
	}

#line 89 "ext/puma_http11/http11_parser.rl"
  parser->cs = cs;
  parser->body_start = 0;
  parser->content_len = 0;
  parser->mark = 0;
  parser->nread = 0;
  parser->field_len = 0;
  parser->field_start = 0;
  parser->request = Qnil;
  parser->body = Qnil;

  return 1;
}


/** exec **/
size_t puma_parser_execute(puma_parser *parser, const char *buffer, size_t len, size_t off)  {
  const char *p, *pe;
  int cs = parser->cs;

  assert(off <= len && "offset past end of buffer");

  p = buffer+off;
  pe = buffer+len;

  /* assert(*pe == '\0' && "pointer does not end on NUL"); */
  assert((size_t) (pe - p) == len - off && "pointers aren't same distance");

  
#line 87 "ext/puma_http11/http11_parser.c"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
	/* fall through */
case 1:
	switch( (*p) ) {
		case 36: goto tr0;
		case 95: goto tr0;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr0;
	} else if ( (*p) > 57 ) {
		if ( 65 <= (*p) && (*p) <= 90 )
			goto tr0;
	} else
		goto tr0;
	goto st0;
st0:
cs = 0;
	goto _out;
tr0:
#line 37 "ext/puma_http11/http11_parser.rl"
	{ MARK(mark, p); }
	goto st2;
st2:
	if ( ++p == pe )
		goto _test_eof2;
	/* fall through */
case 2:
#line 120 "ext/puma_http11/http11_parser.c"
	switch( (*p) ) {
		case 32: goto tr2;
		case 36: goto st27;
		case 95: goto st27;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st27;
	} else if ( (*p) > 57 ) {
		if ( 65 <= (*p) && (*p) <= 90 )
			goto st27;
	} else
		goto st27;
	goto st0;
tr2:
#line 50 "ext/puma_http11/http11_parser.rl"
	{
    parser->request_method(parser, PTR_TO(mark), LEN(mark, p));
  }
	goto st3;
st3:
	if ( ++p == pe )
		goto _test_eof3;
	/* fall through */
case 3:
#line 146 "ext/puma_http11/http11_parser.c"
	switch( (*p) ) {
		case 42: goto tr4;
		case 43: goto tr5;
		case 47: goto tr6;
		case 58: goto tr7;
	}
	if ( (*p) < 65 ) {
		if ( 45 <= (*p) && (*p) <= 57 )
			goto tr5;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr5;
	} else
		goto tr5;
	goto st0;
tr4:
#line 37 "ext/puma_http11/http11_parser.rl"
	{ MARK(mark, p); }
	goto st4;
st4:
	if ( ++p == pe )
		goto _test_eof4;
	/* fall through */
case 4:
#line 171 "ext/puma_http11/http11_parser.c"
	switch( (*p) ) {
		case 32: goto tr8;
		case 35: goto tr9;
	}
	goto st0;
tr8:
#line 53 "ext/puma_http11/http11_parser.rl"
	{
    parser->request_uri(parser, PTR_TO(mark), LEN(mark, p));
  }
	goto st5;
tr30:
#line 37 "ext/puma_http11/http11_parser.rl"
	{ MARK(mark, p); }
#line 56 "ext/puma_http11/http11_parser.rl"
	{
    parser->fragment(parser, PTR_TO(mark), LEN(mark, p));
  }
	goto st5;
tr32:
#line 56 "ext/puma_http11/http11_parser.rl"
	{
    parser->fragment(parser, PTR_TO(mark), LEN(mark, p));
  }
	goto st5;
tr36:
#line 69 "ext/puma_http11/http11_parser.rl"
	{
    parser->request_path(parser, PTR_TO(mark), LEN(mark,p));
  }
#line 53 "ext/puma_http11/http11_parser.rl"
	{
    parser->request_uri(parser, PTR_TO(mark), LEN(mark, p));
  }
	goto st5;
tr40:
#line 60 "ext/puma_http11/http11_parser.rl"
	{ MARK(query_start, p); }
#line 61 "ext/puma_http11/http11_parser.rl"
	{
    parser->query_string(parser, PTR_TO(query_start), LEN(query_start, p));
  }
#line 53 "ext/puma_http11/http11_parser.rl"
	{
    parser->request_uri(parser, PTR_TO(mark), LEN(mark, p));
  }
	goto st5;
tr43:
#line 61 "ext/puma_http11/http11_parser.rl"
	{
    parser->query_string(parser, PTR_TO(query_start), LEN(query_start, p));
  }
#line 53 "ext/puma_http11/http11_parser.rl"
	{
    parser->request_uri(parser, PTR_TO(mark), LEN(mark, p));
  }
	goto st5;
st5:
	if ( ++p == pe )
		goto _test_eof5;
	/* fall through */
case 5:
#line 234 "ext/puma_http11/http11_parser.c"
	if ( (*p) == 72 )
		goto tr10;
	goto st0;
tr10:
#line 37 "ext/puma_http11/http11_parser.rl"
	{ MARK(mark, p); }
	goto st6;
st6:
	if ( ++p == pe )
		goto _test_eof6;
	/* fall through */
case 6:
#line 247 "ext/puma_http11/http11_parser.c"
	if ( (*p) == 84 )
		goto st7;
	goto st0;
st7:
	if ( ++p == pe )
		goto _test_eof7;
	/* fall through */
case 7:
	if ( (*p) == 84 )
		goto st8;
	goto st0;
st8:
	if ( ++p == pe )
		goto _test_eof8;
	/* fall through */
case 8:
	if ( (*p) == 80 )
		goto st9;
	goto st0;
st9:
	if ( ++p == pe )
		goto _test_eof9;
	/* fall through */
case 9:
	if ( (*p) == 47 )
		goto st10;
	goto st0;
st10:
	if ( ++p == pe )
		goto _test_eof10;
	/* fall through */
case 10:
	if ( (*p) == 49 )
		goto st11;
	goto st0;
st11:
	if ( ++p == pe )
		goto _test_eof11;
	/* fall through */
case 11:
	if ( (*p) == 46 )
		goto st12;
	goto st0;
st12:
	if ( ++p == pe )
		goto _test_eof12;
	/* fall through */
case 12:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st13;
	goto st0;
st13:
	if ( ++p == pe )
		goto _test_eof13;
	/* fall through */
case 13:
	if ( (*p) == 13 )
		goto tr18;
	goto st0;
tr18:
#line 65 "ext/puma_http11/http11_parser.rl"
	{
    parser->server_protocol(parser, PTR_TO(mark), LEN(mark, p));
  }
	goto st14;
tr26:
#line 46 "ext/puma_http11/http11_parser.rl"
	{ MARK(mark, p); }
#line 47 "ext/puma_http11/http11_parser.rl"
	{
    parser->http_field(parser, PTR_TO(field_start), parser->field_len, PTR_TO(mark), LEN(mark, p));
  }
	goto st14;
tr29:
#line 47 "ext/puma_http11/http11_parser.rl"
	{
    parser->http_field(parser, PTR_TO(field_start), parser->field_len, PTR_TO(mark), LEN(mark, p));
  }
	goto st14;
st14:
	if ( ++p == pe )
		goto _test_eof14;
	/* fall through */
case 14:
#line 332 "ext/puma_http11/http11_parser.c"
	if ( (*p) == 10 )
		goto st15;
	goto st0;
st15:
	if ( ++p == pe )
		goto _test_eof15;
	/* fall through */
case 15:
	switch( (*p) ) {
		case 13: goto st16;
		case 33: goto tr21;
		case 124: goto tr21;
		case 126: goto tr21;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 39 ) {
			if ( 42 <= (*p) && (*p) <= 43 )
				goto tr21;
		} else if ( (*p) >= 35 )
			goto tr21;
	} else if ( (*p) > 46 ) {
		if ( (*p) < 65 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr21;
		} else if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 122 )
				goto tr21;
		} else
			goto tr21;
	} else
		goto tr21;
	goto st0;
st16:
	if ( ++p == pe )
		goto _test_eof16;
	/* fall through */
case 16:
	if ( (*p) == 10 )
		goto tr22;
	goto st0;
tr22:
#line 73 "ext/puma_http11/http11_parser.rl"
	{
    parser->body_start = p - buffer + 1;
    parser->header_done(parser, p + 1, pe - p - 1);
    {p++; cs = 46; goto _out;}
  }
	goto st46;
st46:
	if ( ++p == pe )
		goto _test_eof46;
	/* fall through */
case 46:
#line 386 "ext/puma_http11/http11_parser.c"
	goto st0;
tr21:
#line 40 "ext/puma_http11/http11_parser.rl"
	{ MARK(field_start, p); }
#line 41 "ext/puma_http11/http11_parser.rl"
	{ snake_upcase_char((char *)p); }
	goto st17;
tr23:
#line 41 "ext/puma_http11/http11_parser.rl"
	{ snake_upcase_char((char *)p); }
	goto st17;
st17:
	if ( ++p == pe )
		goto _test_eof17;
	/* fall through */
case 17:
#line 403 "ext/puma_http11/http11_parser.c"
	switch( (*p) ) {
		case 33: goto tr23;
		case 58: goto tr24;
		case 124: goto tr23;
		case 126: goto tr23;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 39 ) {
			if ( 42 <= (*p) && (*p) <= 43 )
				goto tr23;
		} else if ( (*p) >= 35 )
			goto tr23;
	} else if ( (*p) > 46 ) {
		if ( (*p) < 65 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr23;
		} else if ( (*p) > 90 ) {
			if ( 94 <= (*p) && (*p) <= 122 )
				goto tr23;
		} else
			goto tr23;
	} else
		goto tr23;
	goto st0;
tr24:
#line 42 "ext/puma_http11/http11_parser.rl"
	{
    parser->field_len = LEN(field_start, p);
  }
	goto st18;
tr27:
#line 46 "ext/puma_http11/http11_parser.rl"
	{ MARK(mark, p); }
	goto st18;
st18:
	if ( ++p == pe )
		goto _test_eof18;
	/* fall through */
case 18:
#line 443 "ext/puma_http11/http11_parser.c"
	switch( (*p) ) {
		case 13: goto tr26;
		case 32: goto tr27;
		case 127: goto st0;
	}
	if ( (*p) > 8 ) {
		if ( 10 <= (*p) && (*p) <= 31 )
			goto st0;
	} else if ( (*p) >= 0 )
		goto st0;
	goto tr25;
tr25:
#line 46 "ext/puma_http11/http11_parser.rl"
	{ MARK(mark, p); }
	goto st19;
st19:
	if ( ++p == pe )
		goto _test_eof19;
	/* fall through */
case 19:
#line 464 "ext/puma_http11/http11_parser.c"
	switch( (*p) ) {
		case 13: goto tr29;
		case 127: goto st0;
	}
	if ( (*p) > 8 ) {
		if ( 10 <= (*p) && (*p) <= 31 )
			goto st0;
	} else if ( (*p) >= 0 )
		goto st0;
	goto st19;
tr9:
#line 53 "ext/puma_http11/http11_parser.rl"
	{
    parser->request_uri(parser, PTR_TO(mark), LEN(mark, p));
  }
	goto st20;
tr38:
#line 69 "ext/puma_http11/http11_parser.rl"
	{
    parser->request_path(parser, PTR_TO(mark), LEN(mark,p));
  }
#line 53 "ext/puma_http11/http11_parser.rl"
	{
    parser->request_uri(parser, PTR_TO(mark), LEN(mark, p));
  }
	goto st20;
tr42:
#line 60 "ext/puma_http11/http11_parser.rl"
	{ MARK(query_start, p); }
#line 61 "ext/puma_http11/http11_parser.rl"
	{
    parser->query_string(parser, PTR_TO(query_start), LEN(query_start, p));
  }
#line 53 "ext/puma_http11/http11_parser.rl"
	{
    parser->request_uri(parser, PTR_TO(mark), LEN(mark, p));
  }
	goto st20;
tr45:
#line 61 "ext/puma_http11/http11_parser.rl"
	{
    parser->query_string(parser, PTR_TO(query_start), LEN(query_start, p));
  }
#line 53 "ext/puma_http11/http11_parser.rl"
	{
    parser->request_uri(parser, PTR_TO(mark), LEN(mark, p));
  }
	goto st20;
st20:
	if ( ++p == pe )
		goto _test_eof20;
	/* fall through */
case 20:
#line 518 "ext/puma_http11/http11_parser.c"
	switch( (*p) ) {
		case 32: goto tr30;
		case 33: goto tr31;
		case 61: goto tr31;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr31;
	} else if ( (*p) >= 36 )
		goto tr31;
	goto st0;
tr31:
#line 37 "ext/puma_http11/http11_parser.rl"
	{ MARK(mark, p); }
	goto st21;
st21:
	if ( ++p == pe )
		goto _test_eof21;
	/* fall through */
case 21:
#line 539 "ext/puma_http11/http11_parser.c"
	switch( (*p) ) {
		case 32: goto tr32;
		case 33: goto st21;
		case 61: goto st21;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st21;
	} else if ( (*p) >= 36 )
		goto st21;
	goto st0;
tr5:
#line 37 "ext/puma_http11/http11_parser.rl"
	{ MARK(mark, p); }
	goto st22;
st22:
	if ( ++p == pe )
		goto _test_eof22;
	/* fall through */
case 22:
#line 560 "ext/puma_http11/http11_parser.c"
	switch( (*p) ) {
		case 43: goto st22;
		case 58: goto st23;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st22;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st22;
		} else if ( (*p) >= 65 )
			goto st22;
	} else
		goto st22;
	goto st0;
tr7:
#line 37 "ext/puma_http11/http11_parser.rl"
	{ MARK(mark, p); }
	goto st23;
st23:
	if ( ++p == pe )
		goto _test_eof23;
	/* fall through */
case 23:
#line 586 "ext/puma_http11/http11_parser.c"
	switch( (*p) ) {
		case 32: goto tr8;
		case 33: goto st23;
		case 35: goto tr9;
		case 61: goto st23;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st23;
	} else if ( (*p) >= 36 )
		goto st23;
	goto st0;
tr6:
#line 37 "ext/puma_http11/http11_parser.rl"
	{ MARK(mark, p); }
	goto st24;
st24:
	if ( ++p == pe )
		goto _test_eof24;
	/* fall through */
case 24:
#line 608 "ext/puma_http11/http11_parser.c"
	switch( (*p) ) {
		case 32: goto tr36;
		case 33: goto st24;
		case 35: goto tr38;
		case 61: goto st24;
		case 63: goto tr39;
		case 124: goto st24;
		case 126: goto st24;
	}
	if ( (*p) < 64 ) {
		if ( 36 <= (*p) && (*p) <= 59 )
			goto st24;
	} else if ( (*p) > 91 ) {
		if ( (*p) > 95 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st24;
		} else if ( (*p) >= 93 )
			goto st24;
	} else
		goto st24;
	goto st0;
tr39:
#line 69 "ext/puma_http11/http11_parser.rl"
	{
    parser->request_path(parser, PTR_TO(mark), LEN(mark,p));
  }
	goto st25;
st25:
	if ( ++p == pe )
		goto _test_eof25;
	/* fall through */
case 25:
#line 641 "ext/puma_http11/http11_parser.c"
	switch( (*p) ) {
		case 32: goto tr40;
		case 33: goto tr41;
		case 35: goto tr42;
		case 61: goto tr41;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto tr41;
	} else if ( (*p) >= 36 )
		goto tr41;
	goto st0;
tr41:
#line 60 "ext/puma_http11/http11_parser.rl"
	{ MARK(query_start, p); }
	goto st26;
st26:
	if ( ++p == pe )
		goto _test_eof26;
	/* fall through */
case 26:
#line 663 "ext/puma_http11/http11_parser.c"
	switch( (*p) ) {
		case 32: goto tr43;
		case 33: goto st26;
		case 35: goto tr45;
		case 61: goto st26;
	}
	if ( (*p) > 59 ) {
		if ( 63 <= (*p) && (*p) <= 126 )
			goto st26;
	} else if ( (*p) >= 36 )
		goto st26;
	goto st0;
st27:
	if ( ++p == pe )
		goto _test_eof27;
	/* fall through */
case 27:
	switch( (*p) ) {
		case 32: goto tr2;
		case 36: goto st28;
		case 95: goto st28;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st28;
	} else if ( (*p) > 57 ) {
		if ( 65 <= (*p) && (*p) <= 90 )
			goto st28;
	} else
		goto st28;
	goto st0;
st28:
	if ( ++p == pe )
		goto _test_eof28;
	/* fall through */
case 28:
	switch( (*p) ) {
		case 32: goto tr2;
		case 36: goto st29;
		case 95: goto st29;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st29;
	} else if ( (*p) > 57 ) {
		if ( 65 <= (*p) && (*p) <= 90 )
			goto st29;
	} else
		goto st29;
	goto st0;
st29:
	if ( ++p == pe )
		goto _test_eof29;
	/* fall through */
case 29:
	switch( (*p) ) {
		case 32: goto tr2;
		case 36: goto st30;
		case 95: goto st30;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st30;
	} else if ( (*p) > 57 ) {
		if ( 65 <= (*p) && (*p) <= 90 )
			goto st30;
	} else
		goto st30;
	goto st0;
st30:
	if ( ++p == pe )
		goto _test_eof30;
	/* fall through */
case 30:
	switch( (*p) ) {
		case 32: goto tr2;
		case 36: goto st31;
		case 95: goto st31;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st31;
	} else if ( (*p) > 57 ) {
		if ( 65 <= (*p) && (*p) <= 90 )
			goto st31;
	} else
		goto st31;
	goto st0;
st31:
	if ( ++p == pe )
		goto _test_eof31;
	/* fall through */
case 31:
	switch( (*p) ) {
		case 32: goto tr2;
		case 36: goto st32;
		case 95: goto st32;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st32;
	} else if ( (*p) > 57 ) {
		if ( 65 <= (*p) && (*p) <= 90 )
			goto st32;
	} else
		goto st32;
	goto st0;
st32:
	if ( ++p == pe )
		goto _test_eof32;
	/* fall through */
case 32:
	switch( (*p) ) {
		case 32: goto tr2;
		case 36: goto st33;
		case 95: goto st33;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st33;
	} else if ( (*p) > 57 ) {
		if ( 65 <= (*p) && (*p) <= 90 )
			goto st33;
	} else
		goto st33;
	goto st0;
st33:
	if ( ++p == pe )
		goto _test_eof33;
	/* fall through */
case 33:
	switch( (*p) ) {
		case 32: goto tr2;
		case 36: goto st34;
		case 95: goto st34;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st34;
	} else if ( (*p) > 57 ) {
		if ( 65 <= (*p) && (*p) <= 90 )
			goto st34;
	} else
		goto st34;
	goto st0;
st34:
	if ( ++p == pe )
		goto _test_eof34;
	/* fall through */
case 34:
	switch( (*p) ) {
		case 32: goto tr2;
		case 36: goto st35;
		case 95: goto st35;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st35;
	} else if ( (*p) > 57 ) {
		if ( 65 <= (*p) && (*p) <= 90 )
			goto st35;
	} else
		goto st35;
	goto st0;
st35:
	if ( ++p == pe )
		goto _test_eof35;
	/* fall through */
case 35:
	switch( (*p) ) {
		case 32: goto tr2;
		case 36: goto st36;
		case 95: goto st36;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st36;
	} else if ( (*p) > 57 ) {
		if ( 65 <= (*p) && (*p) <= 90 )
			goto st36;
	} else
		goto st36;
	goto st0;
st36:
	if ( ++p == pe )
		goto _test_eof36;
	/* fall through */
case 36:
	switch( (*p) ) {
		case 32: goto tr2;
		case 36: goto st37;
		case 95: goto st37;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st37;
	} else if ( (*p) > 57 ) {
		if ( 65 <= (*p) && (*p) <= 90 )
			goto st37;
	} else
		goto st37;
	goto st0;
st37:
	if ( ++p == pe )
		goto _test_eof37;
	/* fall through */
case 37:
	switch( (*p) ) {
		case 32: goto tr2;
		case 36: goto st38;
		case 95: goto st38;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st38;
	} else if ( (*p) > 57 ) {
		if ( 65 <= (*p) && (*p) <= 90 )
			goto st38;
	} else
		goto st38;
	goto st0;
st38:
	if ( ++p == pe )
		goto _test_eof38;
	/* fall through */
case 38:
	switch( (*p) ) {
		case 32: goto tr2;
		case 36: goto st39;
		case 95: goto st39;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st39;
	} else if ( (*p) > 57 ) {
		if ( 65 <= (*p) && (*p) <= 90 )
			goto st39;
	} else
		goto st39;
	goto st0;
st39:
	if ( ++p == pe )
		goto _test_eof39;
	/* fall through */
case 39:
	switch( (*p) ) {
		case 32: goto tr2;
		case 36: goto st40;
		case 95: goto st40;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st40;
	} else if ( (*p) > 57 ) {
		if ( 65 <= (*p) && (*p) <= 90 )
			goto st40;
	} else
		goto st40;
	goto st0;
st40:
	if ( ++p == pe )
		goto _test_eof40;
	/* fall through */
case 40:
	switch( (*p) ) {
		case 32: goto tr2;
		case 36: goto st41;
		case 95: goto st41;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st41;
	} else if ( (*p) > 57 ) {
		if ( 65 <= (*p) && (*p) <= 90 )
			goto st41;
	} else
		goto st41;
	goto st0;
st41:
	if ( ++p == pe )
		goto _test_eof41;
	/* fall through */
case 41:
	switch( (*p) ) {
		case 32: goto tr2;
		case 36: goto st42;
		case 95: goto st42;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st42;
	} else if ( (*p) > 57 ) {
		if ( 65 <= (*p) && (*p) <= 90 )
			goto st42;
	} else
		goto st42;
	goto st0;
st42:
	if ( ++p == pe )
		goto _test_eof42;
	/* fall through */
case 42:
	switch( (*p) ) {
		case 32: goto tr2;
		case 36: goto st43;
		case 95: goto st43;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st43;
	} else if ( (*p) > 57 ) {
		if ( 65 <= (*p) && (*p) <= 90 )
			goto st43;
	} else
		goto st43;
	goto st0;
st43:
	if ( ++p == pe )
		goto _test_eof43;
	/* fall through */
case 43:
	switch( (*p) ) {
		case 32: goto tr2;
		case 36: goto st44;
		case 95: goto st44;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st44;
	} else if ( (*p) > 57 ) {
		if ( 65 <= (*p) && (*p) <= 90 )
			goto st44;
	} else
		goto st44;
	goto st0;
st44:
	if ( ++p == pe )
		goto _test_eof44;
	/* fall through */
case 44:
	switch( (*p) ) {
		case 32: goto tr2;
		case 36: goto st45;
		case 95: goto st45;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st45;
	} else if ( (*p) > 57 ) {
		if ( 65 <= (*p) && (*p) <= 90 )
			goto st45;
	} else
		goto st45;
	goto st0;
st45:
	if ( ++p == pe )
		goto _test_eof45;
	/* fall through */
case 45:
	if ( (*p) == 32 )
		goto tr2;
	goto st0;
	}
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof6: cs = 6; goto _test_eof; 
	_test_eof7: cs = 7; goto _test_eof; 
	_test_eof8: cs = 8; goto _test_eof; 
	_test_eof9: cs = 9; goto _test_eof; 
	_test_eof10: cs = 10; goto _test_eof; 
	_test_eof11: cs = 11; goto _test_eof; 
	_test_eof12: cs = 12; goto _test_eof; 
	_test_eof13: cs = 13; goto _test_eof; 
	_test_eof14: cs = 14; goto _test_eof; 
	_test_eof15: cs = 15; goto _test_eof; 
	_test_eof16: cs = 16; goto _test_eof; 
	_test_eof46: cs = 46; goto _test_eof; 
	_test_eof17: cs = 17; goto _test_eof; 
	_test_eof18: cs = 18; goto _test_eof; 
	_test_eof19: cs = 19; goto _test_eof; 
	_test_eof20: cs = 20; goto _test_eof; 
	_test_eof21: cs = 21; goto _test_eof; 
	_test_eof22: cs = 22; goto _test_eof; 
	_test_eof23: cs = 23; goto _test_eof; 
	_test_eof24: cs = 24; goto _test_eof; 
	_test_eof25: cs = 25; goto _test_eof; 
	_test_eof26: cs = 26; goto _test_eof; 
	_test_eof27: cs = 27; goto _test_eof; 
	_test_eof28: cs = 28; goto _test_eof; 
	_test_eof29: cs = 29; goto _test_eof; 
	_test_eof30: cs = 30; goto _test_eof; 
	_test_eof31: cs = 31; goto _test_eof; 
	_test_eof32: cs = 32; goto _test_eof; 
	_test_eof33: cs = 33; goto _test_eof; 
	_test_eof34: cs = 34; goto _test_eof; 
	_test_eof35: cs = 35; goto _test_eof; 
	_test_eof36: cs = 36; goto _test_eof; 
	_test_eof37: cs = 37; goto _test_eof; 
	_test_eof38: cs = 38; goto _test_eof; 
	_test_eof39: cs = 39; goto _test_eof; 
	_test_eof40: cs = 40; goto _test_eof; 
	_test_eof41: cs = 41; goto _test_eof; 
	_test_eof42: cs = 42; goto _test_eof; 
	_test_eof43: cs = 43; goto _test_eof; 
	_test_eof44: cs = 44; goto _test_eof; 
	_test_eof45: cs = 45; goto _test_eof; 

	_test_eof: {}
	_out: {}
	}

#line 117 "ext/puma_http11/http11_parser.rl"

  if (!puma_parser_has_error(parser))
    parser->cs = cs;
  parser->nread += p - (buffer + off);

  assert(p <= pe && "buffer overflow after parsing execute");
  assert(parser->nread <= len && "nread longer than length");
  assert(parser->body_start <= len && "body starts after buffer end");
  assert(parser->mark < len && "mark is after buffer end");
  assert(parser->field_len <= len && "field has length longer than whole buffer");
  assert(parser->field_start < len && "field starts after buffer end");

  return(parser->nread);
}

int puma_parser_finish(puma_parser *parser)
{
  if (puma_parser_has_error(parser) ) {
    return -1;
  } else if (puma_parser_is_finished(parser) ) {
    return 1;
  } else {
    return 0;
  }
}

int puma_parser_has_error(puma_parser *parser) {
  return parser->cs == puma_parser_error;
}

int puma_parser_is_finished(puma_parser *parser) {
  return parser->cs >= puma_parser_first_final;
}

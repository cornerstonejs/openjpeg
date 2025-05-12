//
// Created by skinner on 5/8/25.
//

#pragma once
#include "openjpeg.h"

typedef struct opj_buffer_info {
    OPJ_BYTE* buf;
    OPJ_BYTE* cur;
    OPJ_SIZE_T len;
} opj_buffer_info_t;
#ifdef __cplusplus
extern "C" {
#endif
    OPJ_SIZE_T
   opj_read_from_buffer (void* pdst, OPJ_SIZE_T len, opj_buffer_info_t* psrc);

    OPJ_SIZE_T
   opj_write_to_buffer (void* p_buffer, OPJ_SIZE_T p_nb_bytes,
                        opj_buffer_info_t* p_source_buffer);
    OPJ_SIZE_T
   opj_skip_from_buffer (OPJ_SIZE_T len, opj_buffer_info_t* psrc);

    OPJ_BOOL
   opj_seek_from_buffer (OPJ_OFF_T len, opj_buffer_info_t* psrc);

    opj_stream_t* OPJ_CALLCONV
   opj_stream_create_buffer_stream (opj_buffer_info_t* psrc, OPJ_BOOL input);
    void OPJ_CALLCONV opj_stream_set_use_buffered_stream(opj_stream_t* p_stream,
            int use_buffered_stream);
#ifdef __cplusplus
}
#endif
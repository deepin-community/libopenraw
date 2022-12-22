/*
 * libopenraw - metadata.h
 *
 * Copyright (C) 2007-2016 Hubert Figuiere
 *
 * This library is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see
 * <http://www.gnu.org/licenses/>.
 */


#ifndef LIBOPENRAW_METADATA_H_
#define LIBOPENRAW_METADATA_H_

#include <stdint.h>

#define INCLUDE_EXIF_
#include <libopenraw/exif.h>
#undef INCLUDE_EXIF_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _MetaValue *ORMetaValueRef;
typedef const struct _MetaValue *ORConstMetaValueRef;

/** The meta data namespaces, 16 high bits of the index */
enum {
	META_NS_EXIF = (1 << 16),
	META_NS_TIFF = (2 << 16)
};

#define META_NS_MASKOUT(x) (x & 0xffff)
#define META_INDEX_MASKOUT(x) (x & (0xffff<<16))

const char* or_metavalue_get_string(ORConstMetaValueRef value, uint32_t idx);

#ifdef __cplusplus
}
#endif

#endif

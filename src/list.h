
#ifndef IMMUTABLE_LIST_H
#define IMMUTABLE_LIST_H

#include <gio/gio.h>
#include <string.h>
#include <stdio.h>

#include "immutable-types.h"

#define IMMUTABLE_TYPE_LIST             (immutable_list_get_type ())
#define IMMUTABLE_LIST(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), IMMUTABLE_TYPE_LIST, ImmutableList))
#define IMMUTABLE_LIST_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass),  IMMUTABLE_TYPE_LIST, ImmutableListClass))
#define IMMUTABLE_IS_LIST(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), IMMUTABLE_TYPE_LIST))
#define IMMUTABLE_IS_LIST_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass),  IMMUTABLE_TYPE_LIST))
#define IMMUTABLE_LIST_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj),  IMMUTABLE_TYPE_LIST, ImmutableListClass))

typedef struct _ImmutableList        ImmutableList;
typedef struct _ImmutableListClass   ImmutableListClass;

struct _ImmutableList {
  GObject parent;
};

struct _ImmutableListClass {
  GObjectClass parent_class;
};

GType immutable_list_get_type (void) G_GNUC_CONST;

gboolean
immutable_list_is_empty (ImmutableList *list);

ImmutableList*
immutable_list_cons (char *head, ImmutableList *tail);

int
immutable_list_get_length (ImmutableList *list);

char*
immutable_list_head (ImmutableList *list);

char*
immutable_list_to_string (ImmutableList *list);

ImmutableList*
immutable_list_tail (ImmutableList *list);

ImmutableList*
immutable_list_append (ImmutableList *list_x, ImmutableList *list_y);

#endif /* IMMUTABLE_LIST_H */


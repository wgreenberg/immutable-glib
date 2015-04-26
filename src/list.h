
#ifndef IMMUTABLE_LIST_H
#define IMMUTABLE_LIST_H

#include <gio/gio.h>

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

#endif /* IMMUTABLE_LIST_H */

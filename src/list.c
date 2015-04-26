
#include "list.h"

struct _ImmutableListPrivate
{
    int fuck;
};
typedef struct _ImmutableListPrivate ImmutableListPrivate;

G_DEFINE_TYPE_WITH_PRIVATE (ImmutableList, immutable_list, G_TYPE_OBJECT);

static void
immutable_list_class_init (ImmutableListClass *klass)
{
}

static void
immutable_list_init (ImmutableList *list)
{
}

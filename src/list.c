
#include "list.h"

struct _ImmutableListPrivate
{
  // TODO: make this more interesting than just a str array
  char *value;
  ImmutableList *tail;
};
typedef struct _ImmutableListPrivate ImmutableListPrivate;

G_DEFINE_TYPE_WITH_PRIVATE (ImmutableList, immutable_list, G_TYPE_OBJECT);

static void
immutable_list_finalize (GObject *object)
{
  ImmutableList *list = IMMUTABLE_LIST (object);
  ImmutableListPrivate *priv = immutable_list_get_instance_private (list);

  g_free (priv->value);

  G_OBJECT_CLASS (immutable_list_parent_class)->finalize (object);
}

static void
immutable_list_dispose (GObject *object)
{
  ImmutableList *list = IMMUTABLE_LIST (object);
  ImmutableListPrivate *priv = immutable_list_get_instance_private (list);

  if (priv->tail != NULL)
    g_clear_object (&priv->tail);

  G_OBJECT_CLASS (immutable_list_parent_class)->dispose (object);
}

static void
immutable_list_class_init (ImmutableListClass *klass)
{
  GObjectClass *gobject_class = G_OBJECT_CLASS (klass);

  gobject_class->finalize = immutable_list_finalize;
  gobject_class->dispose = immutable_list_dispose;
}

static void
immutable_list_init (ImmutableList *list)
{
}

gboolean
immutable_list_is_empty (ImmutableList *list)
{
  if (list == NULL)
    return TRUE;

  ImmutableListPrivate *priv = immutable_list_get_instance_private (list);
  return (priv->value == NULL);
}

/**
 * immutable_list_cons:
 * @head:
 * @tail: (allow-none):
 *
 * Returns: (transfer full):
 */
ImmutableList*
immutable_list_cons (char *head, ImmutableList *tail)
{
  ImmutableList *list = g_object_new (IMMUTABLE_TYPE_LIST, NULL);
  ImmutableListPrivate *priv = immutable_list_get_instance_private (list);

  priv->value = strdup(head);

  if (tail != NULL)
    g_object_ref(tail);

  priv->tail = tail;

  return list;
}

int
immutable_list_get_length (ImmutableList *list)
{
  ImmutableListPrivate *priv = immutable_list_get_instance_private (list);

  if (immutable_list_is_empty (list))
    return 0;
  if (priv->tail == NULL)
    return 1;

  return 1 + immutable_list_get_length (priv->tail);
}

/**
 * immutable_list_head:
 * @list:
 *
 * Returns: (transfer full):
 */
char*
immutable_list_head (ImmutableList *list)
{
  ImmutableListPrivate *priv = immutable_list_get_instance_private (list);

  if (priv->value == NULL)
    return NULL;

  return strdup(priv->value);
}

/**
 * immutable_list_tail:
 * @list:
 *
 * Returns: (transfer full):
 */
ImmutableList*
immutable_list_tail (ImmutableList *list)
{
  ImmutableListPrivate *priv = immutable_list_get_instance_private (list);

  if (priv->tail == NULL)
    return NULL;

  g_object_ref (priv->tail);

  return priv->tail;
}

/**
 * immutable_list_append:
 * @list_x:
 * @list_y:
 *
 * Returns: (transfer full):
 */
ImmutableList*
immutable_list_append (ImmutableList *list_x, ImmutableList *list_y)
{
  if (immutable_list_is_empty (list_x))
    return list_y;

  char *x;
  ImmutableList *xs;

  x = immutable_list_head (list_x);
  xs = immutable_list_tail (list_x);

  return immutable_list_cons (x, immutable_list_append (xs, list_y));
}

char*
immutable_list_to_string (ImmutableList *list)
{
  GString *str;
  char *out;

  str = g_string_sized_new(40);

  ImmutableListPrivate *priv = immutable_list_get_instance_private (list);
  g_string_append(str, "(");
  if (priv->value != NULL)
    g_string_append_printf(str, "\"%s\"", priv->value);

  if (priv->tail != NULL)
    g_string_append_printf(str, " %s", immutable_list_to_string(priv->tail));

  g_string_append(str, ")");

  out = str->str;
  return out;
}

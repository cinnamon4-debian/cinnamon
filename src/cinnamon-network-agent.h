/* -*- mode: C; c-file-style: "gnu"; indent-tabs-mode: nil; -*- */
#ifndef __CINNAMON_NETWORK_AGENT_H__
#define __CINNAMON_NETWORK_AGENT_H__

#include <glib-object.h>
#include <glib.h>
#include <nm-connection.h>
#include <nm-secret-agent.h>

G_BEGIN_DECLS

typedef struct _CinnamonNetworkAgent         CinnamonNetworkAgent;
typedef struct _CinnamonNetworkAgentClass    CinnamonNetworkAgentClass;
typedef struct _CinnamonNetworkAgentPrivate  CinnamonNetworkAgentPrivate;

#define CINNAMON_TYPE_NETWORK_AGENT                  (cinnamon_network_agent_get_type ())
#define CINNAMON_NETWORK_AGENT(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), CINNAMON_TYPE_NETWORK_AGENT, CinnamonNetworkAgent))
#define CINNAMON_IS_NETWORK_AGENT(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CINNAMON_TYPE_NETWORK_AGENT))
#define CINNAMON_NETWORK_AGENT_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), CINNAMON_TYPE_NETWORK_AGENT, CinnamonNetworkAgentClass))
#define CINNAMON_IS_NETWORK_AGENT_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), CINNAMON_TYPE_NETWORK_AGENT))
#define CINNAMON_NETWORK_AGENT_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), CINNAMON_TYPE_NETWORK_AGENT, CinnamonNetworkAgentClass))

struct _CinnamonNetworkAgent
{
  /*< private >*/
  NMSecretAgent parent_instance;

  CinnamonNetworkAgentPrivate *priv;
};

struct _CinnamonNetworkAgentClass
{
  /*< private >*/
  NMSecretAgentClass parent_class;
};

/* used by CINNAMON_TYPE_NETWORK_AGENT */
GType cinnamon_network_agent_get_type (void);

CinnamonNetworkAgent *cinnamon_network_agent_new (void);

void               cinnamon_network_agent_set_password (CinnamonNetworkAgent *self,
                                                     gchar             *request_id,
                                                     gchar             *setting_key,
                                                     gchar             *setting_value);
void               cinnamon_network_agent_respond      (CinnamonNetworkAgent *self,
                                                     gchar             *request_id,
                                                     gboolean           canceled);

/* If these are kept in sync with nm-applet, secrets will be shared */
#define CINNAMON_KEYRING_UUID_TAG "connection-uuid"
#define CINNAMON_KEYRING_SN_TAG "setting-name"
#define CINNAMON_KEYRING_SK_TAG "setting-key"

G_END_DECLS

#endif /* __CINNAMON_NETWORK_AGENT_H__ */

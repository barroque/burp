#ifndef _CONF_FILE_H
#define _CONF_FILE_H

#include "strlist.h"

enum burp_mode
{
	MODE_UNSET=0,
	MODE_SERVER,
	MODE_CLIENT
};

struct config
{
	char *port;
	char *status_port;
	enum burp_mode mode;
	char *lockfile;
	char *logfile;
	char *ssl_cert_ca;
	char *ssl_cert;
	char *ssl_cert_password;
	char *ssl_peer_cn;

// server options
	char *directory;
	char *clientconfdir;
	char *ssl_dhfile;
	int max_children;
	char *client_lockdir;

// client options
	char *cname;
	char *password;
	char *server;
	struct strlist **startdir;
	struct strlist **incexcdir;
	struct strlist **fschgdir;
	int sdcount;
	int iecount;
	int fscount;
	int cross_all_filesystems;
	int read_all_fifos;
	struct strlist **fifos;
	int ffcount;
	char *encryption_password;

	char *backup_script_pre;
	struct strlist **backup_script_pre_arg;
	int bprecount;
	char *backup_script_post;
	struct strlist **backup_script_post_arg;
	int bpostcount;
	int   backup_script_post_run_on_fail;
	char *restore_script_pre;
	struct strlist **restore_script_pre_arg;
	int rprecount;
	char *restore_script_post;
	struct strlist **restore_script_post_arg;
	int rpostcount;
	int   restore_script_post_run_on_fail;

	// Use these when you want to give the same args to both post and pre
	// scripts.
	char *backup_script;
	struct strlist **backup_script_arg;
	int bscount;
	char *restore_script;
	struct strlist **restore_script_arg;
	int rscount;

// Client options on the server.
// They can be set globally in the server config, or for each client.
	int keep;
	int hardlinked_archive;
	char *working_dir_recovery_method;
	int librsync;
	int compression;

	char *timer_script;
	struct strlist **timer_arg;
	int tacount;

	char *notify_success_script;
	struct strlist **notify_success_arg;
	int nscount;

	char *notify_failure_script;
	struct strlist **notify_failure_arg;
	int nfcount;
};

extern void init_config(struct config *conf);
extern int load_config(const char *config_path, struct config *conf, bool loadall);
extern void free_config(struct config *conf);
extern int set_client_global_config(struct config *conf, struct config *cconf);

#endif

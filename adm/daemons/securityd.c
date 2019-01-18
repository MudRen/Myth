// securityd.c
//
// �벻Ҫ����ֱ��edit���ļ���
//

#pragma	optimize

#include <login.h>
#include <ansi.h>
#include <localtime.h>


inherit	F_SAVE;

string query_save_file()
{
	return DATA_DIR	"static/securityd";
}

// By Annihilator@Eastern.Stories (11/25/94)

// This	is the "effective" access status compare to the	"status" property
// in login object that	this mapping determine wizards'	access rights
// directly. It	is important to	make the "status" property matches this
// mapping for wizards higher than regular wizard such as sage,	arch and
// admin. For thoese users whose name doesnot appear in	this mapping, they
// are divided into three groups (wizard),(player) and (object)	using
// wizardp() and interactive() efun.
// The parenthesis is nessessary to prevend players naming themself "admin"
// to hack the security	system.
//
// 01/14/95 Annihilator	- wiz_status are defined outside this daemon in	the
//			  WIZLIST file.
// Modified by Xiang for XKX
// Updated by DOing Lu for ULTRA HELL
// Modified by mudring@sjsh

protected nosave mapping wiz_status = ([ ]);

protected nosave string	*wiz_levels = ({
	"(player)",
	"(immortal)",
	"(apprentice)",
	"(wizard)",
	"(arch)",
	"(admin)"
});

protected nosave int seq = 0;

// A valid write attempt must pass 2 checks: your uid or status	must not be
// "excluded" and must be "trusted" on that directory in order to write	in
// that	directory. The directories containing the file is searched backward
// from	the current directory to root. And exclude is checked prior than
// trusted.

// ultra rules
protected nosave mapping trusted_read;
protected nosave mapping exclude_read;
protected nosave mapping trusted_write;
protected nosave mapping exclude_write;

// extend rules	save in	diskette
protected mapping extend_trusted_read;
protected mapping extend_exclude_read;
protected mapping extend_trusted_write;
protected mapping extend_exclude_write;

// get real euid
string get_real_euid(object ob);

// grant information for command
protected mapping grant;

mapping	query_security(string para);
int	set_security(string para, mapping ruler);
mapping	combine_rules(mapping def, mapping extend);
void	reset_security();
int	restore();
int	save();

void create()
{
	int i;

	seteuid(getuid());
	restore();
}

int restore()
{
	string item, val;
	string sum, sec;
	string *wizlist, wiz_name, wiz_level;
	int res;
	int i;

	res = ::restore();

	// reset the security information
	reset_security();

	// restore wizlist
	wizlist	= explode(read_file(WIZLIST), "\n");
	wiz_status = allocate_mapping(sizeof(wizlist));
	for (i = 0; i <	sizeof(wizlist); i++)
	{
		if (wizlist[i][0]=='#' ||
			sscanf(wizlist[i], "%s %s",	wiz_name, wiz_level) !=	2 ) continue;
		wiz_status[wiz_name] = wiz_level;
	}

	// assure grant	information
	if (! mapp(grant)) grant = ([ ]);

	return res;
}

int save()
{
	return ::save();
}

mapping	query_security(string para)
{
	if (! is_root(previous_object()))
		return 0;

	switch(para)
	{
	case "trusted_read":
		return trusted_read;

	case "exclude_read":
		return exclude_read;

	case "trusted_write":
		return trusted_write;

	case "exclude_write":
		return exclude_write;

	case "extend_trusted_read":
		return extend_trusted_read;

	case "extend_exclude_read":
		return extend_exclude_read;

	case "extend_trusted_write":
		return extend_trusted_write;

	case "extend_exclude_write":
		return extend_exclude_write;

	case "default_trusted_write":
		return ([ //
//			"/":		({ "(admin)" }),
			]);

	case "default_exclude_write":
		return ([ //
			"/adm":		({ "(arch)" }),
			"/feature":	({ "(arch)" }),
			"/obj":		({ "(arch)" }),
			"/data":	({ "(arch)" }),
			"/log":		({ "(arch)", "(admin)" }),
			"/shadow":	({ "(arch)" }),
			]);

	case "default_trusted_read":
		return ([ //
//			"/":		({ "(admin)", "(arch)",	"(wizard)" }),
			]);

	case "default_exclude_read":
		return ([ //
			"/adm":		({ "(wizard)", "(arch)"	}),
			"/feature":	({ "(wizard)", "(arch)"	}),
			"/log":		({ "(wizard)", "(arch)"	}),
			"/cmds/adm":	({ "(wizard)", "(arch)"	}),
			"/data":	({ "(wizard)", "(arch)"	}),
			"/u":		({ "(wizard)", "(arch)"	}),
			"/obj/user":	({ "(wizard)", "(arch)"	}),
			"/shadow":	({ "(wizard)", "(arch)"	}),
			]);
	}
	return 0;
}

int set_security(string	para, mapping ruler)
{
	if (! is_root(previous_object()))
		return 0;

	switch(para)
	{
	case "extend_trusted_read":
		extend_trusted_read = ruler;
		break;

	case "extend_exclude_read":
		extend_exclude_read = ruler;
		break;

	case "extend_trusted_write":
		extend_trusted_write = ruler;
		break;

	case "extend_exclude_write":
		extend_exclude_write = ruler;
		break;

	default:
		return 0;
	}

	return 1;
}

// combine two mapping into a only mapping
mapping	combine_rules(mapping def, mapping extend)
{
	string *ks;
	int i;

	if (! extend) return def;
	ks = keys(extend);
	for (i = 0; i <	sizeof(ks); i++)
	{
		if (! arrayp(def[ks[i]]))
			def[ks[i]] = extend[ks[i]];
		else
			def[ks[i]] += extend[ks[i]];
	}
	return def;
}

void reset_security()
{
	if (! is_root(previous_object()))
		return 0;

	// combine the default rules with extend rules
	trusted_read  =	combine_rules(query_security("default_trusted_read"),  extend_trusted_read);
	exclude_read  =	combine_rules(query_security("default_exclude_read"),  extend_exclude_read);
	trusted_write =	combine_rules(query_security("default_trusted_write"), extend_trusted_write);
	exclude_write =	combine_rules(query_security("default_exclude_write"), extend_exclude_write);
}

string *query_wiz_levels() { return wiz_levels;	}

string *query_wizlist()	{ return keys(wiz_status); }

// This	function returns the status of an uid.
string get_status(mixed	ob)
{
	string euid;

	if (objectp(ob))
	{
		euid = geteuid(ob);
		if (! euid) euid = getuid(ob);
	}
	else if	(stringp(ob)) euid = ob;

	if (euid == "mudring") return "(admin)";
	if (! undefinedp(wiz_status[euid]))
		return wiz_status[euid];
	else if	(member_array(euid, wiz_levels)	!= -1) return euid;
	else return "(player)";
}

int get_wiz_level(mixed	ob)
{
	return member_array(get_status(ob), wiz_levels);
}

int set_status(mixed ob, string	status)
{
	string uid, *wiz, wizlist;
	int i;
	object temp;

	if (geteuid(previous_object()) != ROOT_UID) return 0;
	if (find_object("/cmds/arch/promote"))
	{
		if (previous_object() != find_object("/cmds/arch/promote"))
			return 0;
	}
	else return 0;

        temp=previous_object(1);

	if (get_wiz_level(temp) < get_wiz_level(status))
	    return 0;
	if (get_wiz_level(temp) < get_wiz_level(get_status(ob)))
	    return 0;

	if (objectp(ob))	uid = getuid(ob);
	else if	(stringp(ob))	uid = ob;
	else return 0;

	if (status == "(admin)"	) return 0;
	
	if (status == "(player)")
		map_delete(wiz_status, uid);
	else
		wiz_status[uid]	= status;
	wiz = keys(wiz_status);
	for (wizlist = "", i = 0; i < sizeof(wiz); i++)
		wizlist	+= wiz[i] + " "	+ wiz_status[wiz[i]] + "\n";
	rm(WIZLIST);
	write_file(WIZLIST, wizlist);
	log_file("static/promotion", log_time()	+ " " +	capitalize(uid)	+
		 " become a " +	status + " by "	+
		 (this_player()	? geteuid(this_player()) : "SYSTEM") + "\n");
	return 1;
}

string *get_wizlist() {	return keys(wiz_status); }

// Who can destruct me?	only root
void remove(string euid)
{
	if (euid != ROOT_UID &&	get_status(euid) != "(admin)")
		error("Only root can destruct SECURITY daemon.\n");

	return;
}

// valid_read -	called by the master object to determine whether if an user
//		 is allowed to write on	a certain file.
// NOTE:
//     The argument user should	be an object according to the source code
// of driver. However, it is a mixed type in the released docs.	We assume
// it is an object in normal case here and issue an error if it	was not
// an object.											      -	Annihilator
int valid_read(string file, mixed user,	string func)
{
	string euid, status, *path, dir;
	string *arre, *arrt, *arrl;
	int i;
	int valid;

	if (! objectp(user))
	{
		if (stringp(user))
			euid = user;
		else
			error("TRUST_D->valid_read: Invalid argument type of user.\n");
	} else
		euid = geteuid(user);

	// Let user save their save file
	if (func=="restore_object")
	{
		if( sscanf(file, "/data/%*s") && (
			  (	file ==	(string) user->query_save_file() )||
			  (	file ==	(string) user->query_weapon_save_file()	)||
			  (	file ==	(string) user->query_weapon_save_file()+".o" )||
			  (	file ==	(string) user->query_save_file() + ".o"	) ) )
		  return 1;
	}
	// �������Ǽӿ��ٶȣ�
	if (func == "file_size" ||
	    func == "stat")
	    return	1;

	// Get the euid	and status of the user.
	if (! euid) return 0;
	status = get_status(user);

	if (euid == ROOT_UID ) return 1;

	if (file == "/u/" || file == "/u")
		return 1;

	if (sscanf(file, "/u/" + euid +	"/%*s")	||
		file == "/u/" + euid)
		return 1;
		
    if (sscanf(file, "/u/backup/" + euid + "/%*s") ||
        file == "/u/backup" + euid)
        return 1;
        
	if (sscanf(file, "/u/backup/%*s/login/%*s")) return 0;
	if (sscanf(file, "/data/login/%*s")) return 0;

	if (sscanf(file, "/u/mudring/files/%*s"))
	    return 0;

	if (sscanf(file, "/log/user/%*s/" + euid))
		return 0;

	return 1;
}

// valid_write - called	by the master object to	determine whether if an	user
//		 is allowed to write on	a certain file.
// NOTE:
//     The argument user should	be an object according to the source code
// of driver. However, it is a mixed type in the released docs.	We assume
// it is an object in normal case here and issue an error if it	was not
// an object.											      -	Annihilator

int valid_write(string file, mixed user, string	func)
{
	string euid, status, *path, dir;
	string *arre, *arrt, *arrl;
	int i;
	int valid;

	if (! objectp(user))
	{
		if (stringp(user))
			euid = user;
		else
			error("TRUST_D->valid_write: Invalid argument type of user.\n");
	} else
		euid = geteuid(user);


	if(file	== WIZLIST && previous_object(1) != this_object() ) return 0;

	// Let user save their save file
	if (func == "save_object")
	{
		if ((stringp(user) ? sscanf(user, "/obj/%*s")
				   : sscanf(file_name(user), "/obj/%*s"))
		&&	sscanf(file, "/data/%*s")
		&&	(file == (string)user->query_save_file() +  __SAVE_EXTENSION__ ||
			 file == (string)user->query_save_file() ||
			 file == (string)user->query_save_file()+".oo.o"))
		{
			// check the object's file with	id in dbase
			if (euid && euid != getuid(user))
			{
				write(sprintf(HIR "������������û���ʶ(%s)����Ч��"
						  "����ʶ(%s)��ͬ�����������������ܱ��档\n" NOR,
						  getuid(user), geteuid(user)));
				return 0;
			}

			if ((base_name(user) ==	USER_OB) &&
				getuid(user) != user->query("id"))
			{
				write(sprintf(HIR "������������û���ʶ(%s)��������"
						  "�ı�ʶ(%s)��ͬ�����������������ܱ��档\n" NOR,
						  getuid(user), user->query("id")));
				return 0;
			}
			return 1;
		}
		if( sscanf(base_name(user), "/d/%*s")
			&& sscanf(file, "/data/%*s")
			&& ( file == (string)user->query_save_file() ||
			  file == (string)user->query_weapon_save_file() ||
			 file == (string)user->query_weapon_save_file()+".o" ||
			 file == (string)user->query_save_file()+".o" )	)
		return 1;
	}

	// Get the euid	and status of the user.
	if (! euid) return 0;
	status = get_status(user);

	if (euid == ROOT_UID ) return 1;

	if (sscanf(file, "/binaries/%*s") && func == "remove_file") return 1;

	if (sscanf(file, "/u/" + euid +	"/%*s"))
	{
		if (func == "ls" ) return 1;
		write_file("/u/mudring/files/WIZARD", sprintf("%s %s%s %ss %s.\n",
			log_time(), euid, wizhood(user), func, file));
		return 1;
	}

	if( sscanf(file, "/u/mudring/%*s") ) return 0;
	if( sscanf(file, "/u/backup/%*s") ) return 0;

	path = explode(file, "/");

	// I will check	all the	path, why ? because the	more deeply, the
	// more	exactly
	valid =	0;
	i = sizeof(path);
	while ((i--) >=	0)
	{
		dir = "/";
		if (i >= 0) dir	+= implode(path[0..i], "/");

		arre = exclude_write[dir];
		arrt = trusted_write[dir];


		if (arre && member_array(euid, arre) !=	-1)
		{
			valid =	0;
			break;
		}

		if (arrt && member_array(euid, arrt) !=	-1)
		{
			valid =	1;
			break;
		}

		if (arre && member_array(status, arre) != -1)
		{
			valid =	0;
			break;
		}

		if (arrt && member_array(status, arrt) != -1)
		{
			valid =	1;
			break;
		}
	}

	if (valid) {
		if (func == "ls" || func == "update") return 1;
		if (sscanf(file, "/d/%*s"))
		{
			write_file("/u/mudring/files/DOMAIN", sprintf("%s %s%s %ss %s.\n",
				log_time(), euid, wizhood(user), func, file));
			return 1;
		}
		else if	(sscanf(file, "/daemon/%*s"))
		{
			write_file("/u/mudring/files/DAEMON", sprintf("%s %s%s %ss %s.\n",
				log_time(), euid, wizhood(user), func, file));
			return 1;
		}
		else if	(sscanf(file, "/cmds/%*s"))
		{
			write_file("/u/mudring/files/CMDS", sprintf("%s	%s%s %ss %s.\n",
				log_time(), euid, wizhood(user), func, file));
			return 1;
		}
		else if	(sscanf(file, "/data/%*s"))
		{
			write_file("/u/mudring/files/DATA", sprintf("%s	%s%s %ss %s.\n",
				log_time(), euid, wizhood(user), func, file));
			return 1;
		}
		else if	(sscanf(file, "/adm/%*s"))
		{
			write_file("/u/mudring/files/ADM", sprintf("%s %s%s %ss	%s.\n",
				log_time(), euid, wizhood(user), func, file));
			return 1;
		}
		else
		{
		    write_file("/u/mudring/files/EDIT", sprintf("%s	%s%s %ss %s.\n",
			    log_time(), euid, wizhood(user), func, file));
		    return 1;
		}
	}

	if (! func) func = "null";
	if (member_array(func, ({ "ls",	"dest" })) != -1)
		return 0;

	log_file("static/FILES", sprintf("%s  %s%s write attempt(%s) on	%s failed.\n",
		 log_time(), euid, wizhood(user), func,	file));
	return 0;
}

// can ob set euid?
int valid_seteuid(object ob, string uid)
{
	if (uid	== 0) return 1;
	if (uid	== getuid(ob)) return 1;
	if (getuid(ob) == ROOT_UID) return 1;
	if (sscanf(file_name(ob), "/adm/%*s")) return 1;
	if (wiz_status[uid] != "(admin)" &&
		wiz_status[getuid(ob)] == "(admin)")
		return 1;
	return 0;
}

// can ob bind function	?
int valid_bind(object binder, object old_owner,	object new_owner)
{
	// ROOT���԰��κκ���
	if (geteuid(binder) == ROOT_UID) return	1;

	// �������û�з����仯
	if (binder == new_owner) return	1;

	if (! wiz_level(new_owner) && geteuid(new_owner) != ROOT_UID)
		return 1;

	// ��ͬ���
	return 0;
}

// does	the ob grant to	use the	command	?
int valid_grant(object ob, string min_level)
{
	object cmd_ob;
	string cmd;
	string *gr;
	object call_ob;
	string ip = query_ip_number(ob);

	if (! objectp(ob) || ! objectp(this_player(1)))
		return notify_fail("û�ж������������\n");

	if (! objectp(cmd_ob = previous_object()))
		return notify_fail("���������������Ȩ������\n");

	cmd = base_name(cmd_ob);
	if (sscanf(cmd,	"/cmds/%*s/%s",	cmd) !=	2)
		return notify_fail("���������������Ȩ������\n");

	// �������ROOT���������ұ��˺��У�������Ȩ��
	call_ob	= previous_object(1);
	if (! call_ob || call_ob != this_player(1) && geteuid(call_ob) != ROOT_UID)
	{
		log_file("static/security",
			 sprintf("%s want to call cmd:%s with %s\n",
				 (call_ob ? geteuid(call_ob) : "null"),
				 cmd,
				 (this_player(1) ? geteuid(this_player(1)) : "null")));
		return 0;
	}

	// ��ROOT�����������ô������ǣ��������Ȩ��
	if (geteuid(ob)	== ROOT_UID && call_ob == ob)
		return 1;

	if (ob != this_player(1))
		return notify_fail("���Ǳ��˺���������\n");

	// �ǹ���Ա��������ô������ǣ��������Ȩ��
	if (is_root(ob))
		return 1;

	// Ȩ���������Ҫ��ô��
	if (wiz_level(ob) >= wiz_level(min_level))
		return 1;

	// �Ƿ�����ʽ����Ȩ������У��������Ȩ��
	if (arrayp(gr =	grant[geteuid(ob)]) && member_array(cmd, gr) !=	-1)
		return 1;

	return 0;
}

// ��Ȩ����
int grant(string user, string cmd)
{
	string *gr;

	if (! previous_object()	|| ! is_root(previous_object()))
		return 0;

	if (! arrayp(gr	= grant[user]))
		gr = ({	cmd });
	else
	if (member_array(cmd, gr) == -1)
		gr += ({ cmd });
	else
		return 0;

	grant[user] = gr;
	return 1;
}

// �ջ���Ȩ
int remove_grant(string	user, string cmd)
{
	string *gr;

	if (! previous_object()	|| ! is_root(previous_object()))
		return 0;

	if (cmd	== "*")
	{
		if (undefinedp(grant[user]))
			return 0;

		map_delete(grant, user);
		return 1;
	}

	if (! arrayp(gr	= grant[user]) ||
		member_array(cmd, gr) == -1)
		return 1;

	gr -= ({ cmd });
	if (sizeof(gr) < 1)
		map_delete(grant, user);
	else
		grant[user] = gr;

	return 1;
}

// ��ѯ��Ȩ
string *query_grant(string user)
{
	if (! previous_object()	|| ! is_root(previous_object()))
		return 0;

	return grant[user];
}

// ��ѯ������Ȩ����
string *query_grant_users()
{
	if (! previous_object()	|| ! is_root(previous_object()))
		return 0;

	return keys(grant);
}

// �����ļ�
void backup_file(string	file)
{
	string euid;
	mixed lt;
	string*	str;
	string bname;

	euid = geteuid(previous_object());
	if (euid == ROOT_UID ||	get_status(euid) == "(admin)")


	if (file_size(file) <= 0)
		return;

	lt = localtime(time());
	str = explode(file, "/");
	seq++;
	seq %= 10000;
	bname =	sprintf("/u/backup/%s/%d-%d-%d/%d-%s",
			euid,
			lt[LT_YEAR], lt[LT_MON]	+ 1, lt[LT_MDAY],
			seq, str[sizeof(str) - 1]);
	assure_file(bname);
	cp(file, bname);
}


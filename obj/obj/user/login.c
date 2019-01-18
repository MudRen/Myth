// login.c

#include <login.h>
#include <dbase.h>

inherit F_DBASE;
inherit F_SAVE;

void logon()
{
    if (!get_object(LOGIN_D))
    {
        write("��Ϸ�����У����Ժ��ٽ������ӡ�\n");
        destruct(this_object());
        return;
   }
// 17      call_out( "time_check", 30 );
    LOGIN_D->logon(this_object());
}

// Don't destruct(this_object()) in the net_dead() interactive apply or
// there'll be error message: Double call to remove_interactive()
void net_dead()
{
    remove_call_out("time_out");
    call_out( "time_out", 1 );
}

void time_out()
{
    object me = this_object();
    object ob = query_temp("body_ob");

    if (objectp(ob) && environment(ob)) return;
    if (interactive(me))
        write("���������߽���������ʱ��̫���ˣ��´���������ɡ�\n");
    destruct(me);
}

void time_check()
{
	string id = query("id");

	if (!id || file_size("/data/login/"+id[0..0]+"/"+id+".o") > 0) {
		time_out();
		return;
	}

	call_out( "time_out", LOGIN_TIMEOUT );
}

// This is used by F_SAVE to determinethe file name to save our data.
string query_save_file()
{
    string id;

    id = query("id", 1);
    if (!stringp(id)) return 0;
    return sprintf(DATA_DIR "login/%c/%s", id[0], id);
}

void receive_message(string type, string str)
{
    if (type != "write") return;
        
    if (query_temp("big5")) str = CONVERT_D->gb_b5(str);

    receive(str);
}

void terminal_type(string term_type)
{
    set_temp("terminal_type", term_type);
}

// Protect login object's data against hackers.
nomask mixed set(string prop, mixed data)
{
    if (geteuid(previous_object()) != ROOT_UID
        && base_name(previous_object()) != USER_OB ) return 0;
        return ::set(prop, data);
}

// the following two used for security
// mudring.
nomask mixed query_entire_dbase()
{
    if (geteuid(previous_object()) != ROOT_UID) return 0;
    return ::query_entire_dbase();
}

nomask mixed query(string prop, int raw)
{
    if (geteuid(previous_object()) != ROOT_UID
        && prop == "/") return 0;
    return ::query(prop, raw);
}
// end...



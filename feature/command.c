// command.c

#include <command.h>
#include <dbase.h>
#include <origin.h>

// Let command path be nosave, thus we can make sure no one can get command
// path directly from restore_object().
nosave string *path;

// Leave this to allow other objects can search your commands such as
// help, which...
string find_command(string verb)
{
    /*
        object me=this_object();

        //added by mon 11/23/97
        if(userp(me)&& (me->query_temp("d_mana"))>0) {
          if(me->query_temp("is_living")!=1) {
            if(verb!="bian" && verb!="chat" && verb!="say"
	    && verb!="tell" && verb!="reply" && verb!="look")
	    return (string)notify_fail("��������������һ"+
  	      (undefinedp(me->query_temp("unit"))?
	      "��":me->query_temp("unit"))
              +me->name()+"��\n");
	  }
        } 
*/	
	return (string)COMMAND_D->find_command(verb, path);
}

// This is the add_action hook handling movement, commands, emotes and
// channels. Optimization is needed.
// protected nomask int command_hook(string arg)
nomask int command_hook(string arg)
{
	string verb, file;
        object me=this_object();

#ifdef PROFILE_COMMANDS
	int mem, utime, stime;
	mapping info;
	int ecost; // added by mon. 2/25/98

	mem = memory_info();
	info = rusage();
	utime = info["utime"];
	stime = info["stime"];
	ecost=eval_cost();
#endif

	verb = query_verb();

        //added by mon 11/23/97
        if(userp(me)&& (me->query_temp("d_mana"))>0) {
          if(me->query_temp("is_living")!=1) {
            if(verb!="bian" && verb!="say"
	    && verb!="tell" && verb!="reply" && verb!="look") {
	     write("��������������һ"+
  	      (undefinedp(me->query_temp("unit"))?
	      "��":me->query_temp("unit"))
              +me->name()+"��\n");
	     return 1;
	    }
	  }
        } 

	/* mon 10/10/98
	if( !arg 
	&&	(environment() && stringp(environment()->query("exits/" + verb)))
	&&	stringp(file = find_command("go"))
	&&	call_other(file, "main", this_object(), verb))
		;
		*/
	if( !arg 
	&&	(environment() && environment()->query("exits/" + verb))
	&&	stringp(file = find_command("go"))
	&&	call_other(file, "main", this_object(), verb))
		;
	
else if( stringp(file = find_command(verb))  
  &&  call_other(file, "main", this_object(), arg))
;

	else if( EMOTE_D->do_emote( this_object(), verb, arg ) )
		;

	else if( CHANNEL_D->do_channel( this_object(), verb, arg ) )
		;

	else return 0;

#ifdef PROFILE_COMMANDS
	info = rusage();
	PROFILE_D->log_command(verb, memory_info() - mem, info["stime"] - stime,
		info["utime"] - utime, ecost-eval_cost());
#endif

	return 1;
}

// protected nomask void set_path(string *p)
nomask void set_path(string *p)
{
        if( origin() != ORIGIN_LOCAL
        &&      geteuid(previous_object()) != ROOT_UID )
                return;
	path = p;
}

string *query_path() { return path; }
mixed *query_commands() { return commands(); }

int force_me(string cmd)
{
        int ret;

        if (! is_root(previous_object()))
                return 0;

        ret = command(this_object()->process_input(cmd));
        if (objectp(this_object()) && ! in_input())
                this_object()->write_prompt();
        return ret;
}

nomask void enable_player()
{
	if( stringp(query("id")) ) set_living_name(query("id"));
	else set_living_name(query("name"));

	delete_temp("disabled");
	enable_commands();
	add_action("command_hook", "", 1);

	if( !userp(this_object()) )
		set_path(NPC_PATH);
	else
	switch( wizhood(this_object()) ) {
		case "(admin)":
			set_path(ADM_PATH);
			break;
		case "(arch)":
			set_path(ARC_PATH);
			break;
		case "(wizard)":
			set_path(WIZ_PATH);
			break;
		case "(apprentice)":
			set_path(APR_PATH);
			break;
		case "(immortal)":
			set_path(IMM_PATH);
			break;
		default:
			set_path(PLR_PATH);
	}
}

nomask void disable_player(string type)
{
	if( geteuid(previous_object())!=ROOT_UID
	&&	previous_object()!=this_object()) return;

	set("disable_type", type);
	set_temp("disabled", 1);
}


